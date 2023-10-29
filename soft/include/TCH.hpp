/*
** EPITECH PROJECT, 2023
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
        public:
            TCH();
            ~TCH();

            void addPacket(Packet packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet packet);
    };

#endif /* !TCH_HPP_ */
