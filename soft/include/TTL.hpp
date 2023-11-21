/*
** cuddly-couscous
** File description:
** TTL
*/

#ifndef TTL_HPP_
    #define TTL_HPP_

    #include "IAttacks.hpp"

    class TTL : public virtual IAttacks{
        protected:
            std::vector<Packet> _packets;
            std::map<std::string, std::vector<Packet>> _map;
        private:
        public:
            TTL();
            ~TTL();

            void addPacket(Packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet);
            std::string getName(void) const { return "IP time to live"; };
    };

#endif /* !TTL_HPP_ */
