/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** packetHandler
*/

#ifndef PACKETHANDLER_HPP_
#define PACKETHANDLER_HPP_

    #include <iostream>
    #include <fstream>

    #include <ctime>
    #include <vector>
    #include <cstring>

    #include <pcap.h>
    #include <netinet/ether.h>
    #include <netinet/ip.h>
    #include <netinet/tcp.h>
    #include <netinet/udp.h>
    #include <arpa/inet.h>

    class Sniffer
    {
        private:
        protected:
            std::vector<std::string> devices;
        public:
            Sniffer();
            ~Sniffer();

            const char *getTimestamp() const;
            int getLength(const pcap_pkthdr *pkthdr) const;
            char *getMac(struct ethhdr *ethHeader, int dest) const;
            char *getIp(struct ip *ipHeader, int dest) const;
            std::string getPortTCP(struct tcphdr *tcpHeader, int dest) const;
            std::string getPortUDP(struct udphdr *udpHeader, int dest) const;

            void setDevice(std::string device);
            std::vector<std::string> getDevices() const;
    };
#endif /* !PACKETHANDLER_HPP_ */
