/*
** cuddly-couscous
** File description:
** Packet
*/

#ifndef PACKET_HPP_
#define PACKET_HPP_

    #include <iostream>
    #include <map>

    #define UNDEFINE 0

    class Packet {
        protected:
            std::string _timeStamp = "<>";

            std::string _srcIp = "<>";
            std::string _dstIp = "<>";

            std::string _protocol = "<>";

            std::string _dstMAC = "<>";
            std::string _srcMAC = "<>";

            int _length = UNDEFINE;

            int _srcPortTCP = UNDEFINE;
            int _dstPortTCP = UNDEFINE;

            int _srcPortUDP = UNDEFINE;
            int _dstPortUDP = UNDEFINE;

            int _RSTflag = UNDEFINE;

        public:
            Packet();
            ~Packet();

            void stringToPacket(const std::string&);
            void setTimeStamp(const std::string&);
            void setSrcIp(const std::string&);
            void setDstIp(const std::string&);
            void setProtocol(const std::string&);
            void setDstMAC(const std::string&);
            void setSrcMAC(const std::string&);
            void setLength(const int);
            void setSrcPortTCP(const std::string&);
            void setDstPortTCP(const std::string&);
            void setSrcPortUDP(const std::string&);
            void setDstPortUDP(const std::string&);
            void setRSTflag(const std::string&);

            std::string getTimeStamp() const;
            std::string getSrcIp() const;
            std::string getDstIp() const;
            std::string getProtocol() const;
            std::string getDstMAC() const;
            std::string getSrcMAC() const;

            int getLength() const;
            int getSrcPortTCP() const;
            int getDstPortTCP() const;
            int getSrcPortUDP() const;
            int getDstPortUDP() const;
            int getRSTflag() const;
        private:
    };
inline std::ostream &operator<<(std::ostream &out, const Packet *packet) {
    out << "Timestamp: " << packet->getTimeStamp() << " Length: " << packet->getLength()\
    <<" Protocol: " << packet->getProtocol() << " Source IP: " << packet->getSrcIp() << " Destination IP: " << packet->getDstIp()\
    << " Source MAC: " << packet->getSrcMAC() << " Destination MAC: "<< packet->getDstMAC() \
    << " Source Port TCP: " << packet->getSrcPortTCP() << " Destination Port TCP: "\
    << packet->getDstPortTCP() << " Source Port UDP: " << packet->getSrcPortUDP() << " Destination Port UDP: " << packet->getDstPortUDP()\
    << " RST Flag: " << packet->getRSTflag() << std::endl;
    return out;
}

#endif /* !PACKET_HPP_ */
