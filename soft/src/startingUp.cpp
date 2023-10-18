/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** startingUp
*/

#include "startingUp.hpp"

volatile bool shouldExit = false;
Sniffer sniffer;
PacketParser parser;

void signalHandler(int signum) {
    if (signum == SIGINT) {
        std::cout << "Capture terminated by user (Ctrl+C)." << std::endl;
        shouldExit = true;
    }
}

void packetHandler(u_char *, const struct pcap_pkthdr *pkthdr, const u_char *packetData) {
    std::ostringstream logLine;

    logLine << "Timestamp: " << sniffer.getTimestamp() << " ";
    logLine << "Length: " << sniffer.getLength(pkthdr) << " ";

    struct ethhdr *ethHeader = (struct ethhdr *)packetData;
    logLine << "Source MAC: " << sniffer.getMac(ethHeader, 0) << " ";
    logLine << "Destination MAC: " << sniffer.getMac(ethHeader, 1) << " ";
    sniffer.setDevice(sniffer.getMac(ethHeader, 0));

    uint16_t frameControl = *(reinterpret_cast<const uint16_t*>(packetData + 22));
    if ((frameControl & 0b0000000011111100) >> 2 == 0xC) {
        uint16_t reasonCode = *(reinterpret_cast<const uint16_t*>(packetData + 26));
        logLine << "Reason Code: " << reasonCode << " ";
    }

    if (ntohs(ethHeader->h_proto) == ETHERTYPE_IP) {
        struct ip *ipHeader = (struct ip *)(packetData + sizeof(struct ethhdr));
        logLine << "Source IP: " << sniffer.getIp(ipHeader, 0) << " ";
        logLine << "Destination IP: " << sniffer.getIp(ipHeader, 1) << " ";

        if (ipHeader->ip_p == IPPROTO_TCP) {
            struct tcphdr *tcpHeader = (struct tcphdr *)(packetData + sizeof(struct ethhdr) + ipHeader->ip_hl * 4);
            logLine << "Source Port (TCP): " << sniffer.getPortTCP(tcpHeader, 0) << " ";
            logLine << "Destination Port (TCP): " << sniffer.getPortTCP(tcpHeader, 1) << " ";

            if (tcpHeader->rst && !(tcpHeader->syn) && !(tcpHeader->fin)) {
                logLine << "RST Flag: " << tcpHeader->rst << " ";
            }
        } else if (ipHeader->ip_p == IPPROTO_UDP) {
            struct udphdr *udpHeader = (struct udphdr *)(packetData + sizeof(struct ethhdr) + ipHeader->ip_hl * 4);
            logLine << "Source Port (UDP): " << sniffer.getPortUDP(udpHeader, 0) << " ";
            logLine << "Destination Port (UDP): " << sniffer.getPortUDP(udpHeader, 1) << " ";
        }
    }

    std::ofstream outputFile("logs/packet_logs.txt", std::ios::app | std::ios::out);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the output file." << std::endl;
        return;
    }

    outputFile << std::endl << logLine.str();
    parser.parsePacket(logLine.str());
    outputFile.close();
}

int startingUp(char *device_name)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    std::vector<std::string> devices;

    pcap_t *handle = pcap_open_live(device_name, BUFSIZ, 1, 1000, errbuf);

    signal(SIGINT, signalHandler);

    if (handle == nullptr) {
        sniffer.displayDevices();
        //parser.displayPackets();
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
