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
        public:
            THA();
            ~THA();

            void addPacket(Packet packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet packet);
            std::string getName(void) const { return "TCP Handshake Abnormalities"; };
        private:
    };

#endif /* !THA_HPP_ */
