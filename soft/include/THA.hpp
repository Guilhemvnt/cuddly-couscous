/*
** cuddly-couscous
** File description:
** THA (TCP Handshake Abnormalities)
*/

#ifndef THA_HPP_
    #define THA_HPP_

    #include "IAttacks.hpp"

    class THA : public virtual IAttacks {
        protected:
            std::vector<Packet> _packets;
            std::map<std::string, std::vector<Packet>> _map;

        public:
            THA();
            ~THA();

            void addPacket(Packet packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet packet);
            std::string getName(void) const { return "TCP Abnormalities"; };
        private:
    };

#endif /* !THA_HPP_ */
