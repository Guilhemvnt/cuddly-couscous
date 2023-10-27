/*
** cuddly-couscous
** File description:
** IAttacks
*/

#ifndef IATTACKS_HPP_
#define IATTACKS_HPP_

    #include <vector>
    #include <map>
    #include <string>
    #include "Packet.hpp"

    class IAttacks {
        public:
            virtual ~IAttacks(void) = default;
            virtual void addPacket(Packet) = 0;
            virtual std::vector<Packet> getPackets(void) = 0;
            virtual void displayPackets(void) = 0;
            virtual void analysePackets(Packet) = 0;
    };

#endif /* !IATTACKS_HPP_ */
