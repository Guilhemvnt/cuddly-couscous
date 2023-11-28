/*
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
    #include <netinet/ip_icmp.h>

    class Sniffer {
        private:
        protected:
            std::vector<std::string> devices;
            std::string _networkInterface;
            std::string logs_name;
        public:
            Sniffer();
            ~Sniffer();

            std::string getTimestamp() const;
            int getLength(const pcap_pkthdr *pkthdr) const;

            char *getMac(struct ethhdr *ethHeader, int dest) const;
            char *getIp(struct ip *ipHeader, int dest) const;
            std::string getPortTCP(struct tcphdr *tcpHeader, int dest) const;
            std::string getPortUDP(struct udphdr *udpHeader, int dest) const;
            std::string getIcmpType(struct icmphdr *icmpHeader) const;
            int getTTL(struct ip *ipHeader) const;

            int getRSTflag(struct tcphdr *tcpHeader) const;
            int getSYNflag(struct tcphdr *tcpHeader) const;
            int getACKflag(struct tcphdr *tcpHeader) const;
            int getFINflag(struct tcphdr *tcpHeader) const;
            
            std::string getNetworkInterface() const;
            void setNetworkInterface(std::string networkInterface);

            void setDevice(std::string device);
            std::vector<std::string> getDevices() const;

            void setLogsName(std::string logs_name);
            std::string getLogsName() const;
            void displayDevices();
    };
#endif /* !PACKETHANDLER_HPP_ */
