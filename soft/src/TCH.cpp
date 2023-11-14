/*
** cuddly-couscous
** File description:
** TCH (TCP Connection Hijacking)
*/

#include "TCH.hpp"

TCH::TCH()
{
}

TCH::~TCH()
{
}

void TCH::addPacket(Packet packet)
{
    _packets.push_back(packet);
}

std::vector<Packet> TCH::getPackets(void)
{
    return (_packets);
}

void TCH::displayPackets(void)
{
    for (auto packet : _packets)
    std::cout << &packet << std::endl;
}

void TCH::analysePackets(Packet packet)
{
    if (packet.getRSTflag() == 0 && packet.getSYNflag() == 0 && packet.getACKflag() == 0 && packet.getFINflag() == 0) {
        addPacket(packet);
        //std::cout << "TCH attack detected" << std::endl;
    } else {
        return;
    }
}