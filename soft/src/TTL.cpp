/*
** cuddly-couscous
** File description:
** TTL
*/

#include "TTL.hpp"

TTL::TTL()
{
    Packet packet = Packet();
    addPacket(packet);
}

TTL::~TTL()
{
}

void TTL::addPacket(Packet packet)
{
    _map[packet.getSrcIp()].push_back(packet);
}

std::vector<Packet> TTL::getPackets(void)
{
    std::vector<Packet> largestVector;
    for (const auto& pair : _map) {
        if (pair.second.size() > largestVector.size() && pair.first != "<>") {
            largestVector = pair.second;
        }
    }
    return largestVector;
}

void TTL::displayPackets(void)
{
    for (auto packet : _packets)
        std::cout << &packet << std::endl;
}

void TTL::analysePackets(Packet packet)
{
    if(packet.getTTL() <= 5 && packet.getTTL() >= 0) {
        addPacket(packet);
    } else
        return;
    return;
}
