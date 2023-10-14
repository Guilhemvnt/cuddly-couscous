/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** startingUp
*/

#include "startingUp.hpp"
#include <csignal>
#include <memory>

// Define a signal handler function
volatile bool shouldExit = false;
Sniffer sniffer;

void signalHandler(int signum) {
    if (signum == SIGINT) {
        std::cout << "Capture terminated by user (Ctrl+C)." << std::endl;
        shouldExit = true;
    }
}

void packetHandler(u_char *, const struct pcap_pkthdr *pkthdr, const u_char *packetData) {
    // Create a stringstream to construct the log line
    std::ostringstream logLine;

    logLine << "Timestamp: " << sniffer.getTimestamp() << " ";
    logLine << "Length: " << sniffer.getLength(pkthdr) << " ";

    struct ethhdr *ethHeader = (struct ethhdr *)packetData;
    logLine << "Source MAC: " << sniffer.getMac(ethHeader, 0) << " ";
    logLine << "Destination MAC: " << sniffer.getMac(ethHeader, 1) << " ";
    sniffer.setDevice(sniffer.getMac(ethHeader, 0));

    if (ntohs(ethHeader->h_proto) == ETHERTYPE_IP) {
        struct ip *ipHeader = (struct ip *)(packetData + sizeof(struct ethhdr));
        logLine << "Source IP: " << sniffer.getIp(ipHeader, 0) << " ";
        logLine << "Destination IP: " << sniffer.getIp(ipHeader, 1) << " ";

        if (ipHeader->ip_p == IPPROTO_TCP) {
            struct tcphdr *tcpHeader = (struct tcphdr *)(packetData + sizeof(struct ethhdr) + ipHeader->ip_hl * 4);
            logLine << "Source Port (TCP): " << sniffer.getPortTCP(tcpHeader, 0) << " ";
            logLine << "Destination Port (TCP): " << sniffer.getPortTCP(tcpHeader, 1) << " ";
        } else if (ipHeader->ip_p == IPPROTO_UDP) {
            struct udphdr *udpHeader = (struct udphdr *)(packetData + sizeof(struct ethhdr) + ipHeader->ip_hl * 4);
            logLine << "Source Port (UDP): " << sniffer.getPortUDP(udpHeader, 0) << " ";
            logLine << "Destination Port (UDP): " << sniffer.getPortUDP(udpHeader, 1) << " ";
        }
    }

    // Open the output file
    std::ofstream outputFile("logs/packet_logs.txt", std::ios::app | std::ios::out);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the output file." << std::endl;
        return;
    }

    // Write the log line to the file
    outputFile << std::endl << logLine.str();
    outputFile.close();
}


int startingUp(char *device_name)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    std::vector<std::string> devices;

    pcap_t *handle = pcap_open_live(device_name, BUFSIZ, 1, 1000, errbuf);

    signal(SIGINT, signalHandler);

    if (handle == nullptr) {
        for (auto &device : sniffer.getDevices()) {
            std::cout << "Device " << device << std::endl;
        }
        return 1;
    }

    while (!shouldExit) {
        if (pcap_dispatch(handle, 0, packetHandler, NULL) < 0) {
            std::cout << "Error in pcap_dispatch" << std::endl;
            break;
        }
    }
    pcap_close(handle);
}