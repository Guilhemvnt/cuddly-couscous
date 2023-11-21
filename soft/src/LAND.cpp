/*
** cuddly-couscous
** File description:
** LAND
*/

#include "LAND.hpp"

LAND::LAND()
{
    Packet packet = Packet();
    addPacket(packet);
}

LAND::~LAND()
{
}

void LAND::addPacket(Packet packet)
{
    _map[packet.getSrcIp()].push_back(packet);
}

std::vector<Packet> LAND::getPackets(void)
{
    std::vector<Packet> largestVector;
    for (const auto& pair : _map) {
        if (pair.second.size() > largestVector.size() && pair.first != "<>") {
            largestVector = pair.second;
        }
    }
    return largestVector;
}

void LAND::displayPackets(void)
{
    for (auto packet : _packets)
        std::cout << &packet << std::endl;
}

void LAND::analysePackets(Packet packet)
{
    if (packet.getSrcIp() != "<>" && packet.getDstIp() != "<>")
        if (packet.getDstIp() == packet.getSrcIp() && packet.getDstPortTCP() == packet.getSrcPortTCP()) {
            addPacket(packet);
        } else {
            return;
        }
    else
        return;
}
