/*
** cuddly-couscous
** File description:
** startingUp
*/

#include "startingUp.hpp"

volatile bool shouldExit = false;
Sniffer sniffer;
NcursesGUI ncursesGUI;
IAttacks* array[] = {
    new LAND(),
    new TTL(),
    new THA(),
    new DecoyScanningAttempts(),
    new DeauthFrames(),
    new SMURF(),
};


void signalHandler(int signum) {
    if (signum == SIGINT) {
        shouldExit = true;
    }
}

// Function to get subnet mask for a given device
std::string getSubnetMask(const char* dev) {
    bpf_u_int32 net, mask;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Get network and mask for the specified device
    if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
        
        return "<>";
    }

    // Convert mask to string format
    struct in_addr addr;
    addr.s_addr = mask;
    return std::string(inet_ntoa(addr));
}

void writeLogs(std::ostringstream &logLine)
{
    std::ofstream outputFile("logs/" + sniffer.getLogsName(), std::ios::app | std::ios::out);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the output file." << std::endl;
        shouldExit = true;
    }
    outputFile << std::endl << logLine.str();
    outputFile.close();
}

void attackHandler(Packet &packet) {
    for (auto atk : array) {
        atk->analysePackets(packet);
    }
}

void packetHandler(u_char *, const struct pcap_pkthdr *pkthdr, const u_char *packetData) {
    std::ostringstream logLine;
    Packet packet;

    logLine << "Timestamp: " << sniffer.getTimestamp() << " ";
    packet.setTimeStamp(sniffer.getTimestamp());
    logLine << "Length: " << sniffer.getLength(pkthdr) << " ";
    packet.setLength(sniffer.getLength(pkthdr));

    struct ethhdr *ethHeader = (struct ethhdr *)packetData;
    logLine << "Source MAC: " << sniffer.getMac(ethHeader, 0) << " ";
    logLine << "Destination MAC: " << sniffer.getMac(ethHeader, 1) << " ";
    packet.setSrcMAC(sniffer.getMac(ethHeader, 0));
    sniffer.setDevice(sniffer.getMac(ethHeader, 0));
    packet.setDstMAC(sniffer.getMac(ethHeader, 1));

    if (ntohs(ethHeader->h_proto) == ETHERTYPE_IP) {
        struct ip *ipHeader = (struct ip *)(packetData + sizeof(struct ethhdr));
        logLine << "Source IP: " << sniffer.getIp(ipHeader, 0) << " ";
        packet.setSrcIp(sniffer.getIp(ipHeader, 0));
        logLine << "Destination IP: " << sniffer.getIp(ipHeader, 1) << " ";
        packet.setDstIp(sniffer.getIp(ipHeader, 1));

        logLine << "TTL: " << sniffer.getTTL(ipHeader) << " ";
        packet.setTTL(sniffer.getTTL(ipHeader));

        std::string subnetMask = getSubnetMask(sniffer.getNetworkInterface().c_str());
        logLine << "Subnet Mask: " << subnetMask << " ";
        packet.setSubNetMask(subnetMask);

        if (ipHeader->ip_p == IPPROTO_ICMP) {
            struct icmphdr *icmpHeader = (struct icmphdr *)(packetData + sizeof(struct ethhdr) + ipHeader->ip_hl * 4);
            logLine << "ICMP Type: " << sniffer.getIcmpType(icmpHeader) << " ";
            packet.setProtocol(sniffer.getIcmpType(icmpHeader));
        } else if (ipHeader->ip_p == IPPROTO_TCP) {
            struct tcphdr *tcpHeader = (struct tcphdr *)(packetData + sizeof(struct ethhdr) + ipHeader->ip_hl * 4);
            logLine << "Source Port (TCP): " << sniffer.getPortTCP(tcpHeader, 0) << " ";
            packet.setSrcPortTCP(sniffer.getPortTCP(tcpHeader, 0));
            logLine << "Destination Port (TCP): " << sniffer.getPortTCP(tcpHeader, 1) << " ";
            packet.setDstPortTCP(sniffer.getPortTCP(tcpHeader, 1));
            logLine << "RST_Flag: " << sniffer.getRSTflag(tcpHeader) << " ";
            packet.setRSTflag(sniffer.getRSTflag(tcpHeader));
            logLine << "SYN_Flag: " << sniffer.getSYNflag(tcpHeader) << " ";
            packet.setSYNflag(sniffer.getSYNflag(tcpHeader));
            logLine << "ACK_Flag: " << sniffer.getACKflag(tcpHeader) << " ";
            packet.setACKflag(sniffer.getACKflag(tcpHeader));
            logLine << "FIN_Flag: " << sniffer.getFINflag(tcpHeader) << " ";
            packet.setFINflag(sniffer.getFINflag(tcpHeader));
        } else if (ipHeader->ip_p == IPPROTO_UDP) {
            struct udphdr *udpHeader = (struct udphdr *)(packetData + sizeof(struct ethhdr) + ipHeader->ip_hl * 4);
            logLine << "Source Port (UDP): " << sniffer.getPortUDP(udpHeader, 0) << " ";
            packet.setSrcPortUDP(sniffer.getPortUDP(udpHeader, 0));
            logLine << "Destination Port (UDP): " << sniffer.getPortUDP(udpHeader, 1) << " ";
            packet.setDstPortUDP(sniffer.getPortUDP(udpHeader, 1));
        }
    }
    writeLogs(logLine);
    attackHandler(packet);

}


int startingUp(char *device_name)
{
    char errbuf[PCAP_ERRBUF_SIZE];
    std::vector<std::string> devices;
    pcap_t *handle = pcap_open_live(device_name, BUFSIZ, 1, 1000, errbuf);

    ncursesGUI.init();

    sniffer.setLogsName(sniffer.getTimestamp() + ".txt");
    signal(SIGINT, signalHandler);
    
    if (handle == nullptr) {
        return 0;
    }

    while (!shouldExit) {
        ncursesGUI.draw();
        ncursesGUI.handleInput();
        ncursesGUI.update(&sniffer, array);
        if (pcap_dispatch(handle, 0, packetHandler, NULL) < 0) {
            std::cout << "Error in pcap_dispatch" << std::endl;
            break;
        }
    }
    ncursesGUI.close();
    pcap_close(handle);

}
