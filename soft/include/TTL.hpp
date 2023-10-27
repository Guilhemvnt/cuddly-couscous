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
        private:
        public:
            TTL();
            ~TTL();

            void addPacket(Packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet);
    };

#endif /* !TTL_HPP_ */
