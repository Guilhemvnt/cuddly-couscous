/*
** cuddly-couscous
** File description:
** TCH (TCP Connection Hijacking)
*/

#ifndef TCH_HPP_
    #define TCH_HPP_
    #include "IAttacks.hpp"

    class TCH : public virtual IAttacks{
        protected:
            std::vector<Packet> _packets;
            std::map<std::string, std::vector<Packet>> _map;
        public:
            TCH();
            ~TCH();

            void addPacket(Packet packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet packet);
            std::string getName(void) const { return "TCP Hijacking"; };
    };

#endif /* !TCH_HPP_ */
