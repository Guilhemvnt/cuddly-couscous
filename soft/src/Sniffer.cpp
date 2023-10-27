/*
** cuddly-couscous
** File description:
** packetHandler
*/

#include "../include/Sniffer.hpp"

Sniffer::Sniffer()
{
}

Sniffer::~Sniffer()
{
}

const char *Sniffer::getTimestamp() const {
    std::time_t timestamp = std::time(nullptr);
    char *timeStr = new char[100];

    if (timeStr != nullptr) {
        strftime(timeStr, 100, "%Y-%m-%d/%H:%M:%S", std::localtime(&timestamp));
    } else {
        return "Allocation failed";
    }
    return timeStr;
}

int Sniffer::getLength(const pcap_pkthdr *pkthdr) const
{
    return  pkthdr->len;
}

char *Sniffer::getMac(struct ethhdr *ethHeader, int dest) const
{
    if (dest == 0) {
        return ether_ntoa((struct ether_addr *)&ethHeader->h_source);;
    } else if (dest == 1)
        return ether_ntoa((struct ether_addr *)&ethHeader->h_dest);
    return (char *)"none";
}

char *Sniffer::getIp(struct ip *ipHeader, int dest) const
{
    if (dest == 0)
        return inet_ntoa(ipHeader->ip_src);
    else if (dest == 1)
        return inet_ntoa(ipHeader->ip_dst);
    return (char *)"none";
}

std::string Sniffer::getPortTCP(struct tcphdr *tcpHeader, int dest) const
{
   if (dest == 0)
        return std::to_string(ntohs(tcpHeader->th_sport));
    else if (dest == 1)
        return std::to_string(ntohs(tcpHeader->th_dport));
    return std::string("none");
}

std::string Sniffer::getPortUDP(struct udphdr *udpHeader, int dest) const
{
    if (dest == 0)
        return std::to_string(ntohs(udpHeader->uh_sport));
    else if (dest == 1)
        return std::to_string(ntohs(udpHeader->uh_dport));
    return std::string("none");
}

void Sniffer::setDevice(std::string device) {
    for (auto it = this->devices.begin(); it != this->devices.end(); it++) {
        if (*it == device) {
            return;
        }
    }
    this->devices.push_back(device);
    std::cout << "Device added: " << device << std::endl;
}

std::vector<std::string> Sniffer::getDevices() const
{
    return this->devices;
}

void Sniffer::displayDevices()
{
    std::cout << "Devices: " << std::endl;
    for (auto device : this->devices) {
        std::cout << device << std::endl;
    }
}

std::string Sniffer::getIcmpType(struct icmphdr *icmpHeader) const
{
    return (std::to_string(icmpHeader->type));
}

int Sniffer::getTTL(struct ip *ipHeader) const
{
    return ipHeader->ip_ttl;
}
