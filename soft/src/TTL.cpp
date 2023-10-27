/*
** cuddly-couscous
** File description:
** TTL
*/

#include "TTL.hpp"

TTL::TTL()
{
}

TTL::~TTL()
{
}

void TTL::addPacket(Packet packet)
{
    _packets.push_back(packet);
}

std::vector<Packet> TTL::getPackets(void)
{
}

void TTL::displayPackets(void)
{
    for (auto packet : _packets)
        std::cout << &packet << std::endl;
}

void TTL::analysePackets(Packet packet)
{
    if(packet.getTTL() <= 5 && packet.getTTL() >= 0)
        std::cout << "TTL attack detected = " << packet.getTTL() <<std::endl;
    else
        return;
    return;
}
