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
    _packets.push_back(packet);
}

std::vector<Packet> LAND::getPackets(void)
{
    return _packets;
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
            //std::cout << "LAND attack detected" << std::endl;
        } else {
            return;
        }
    else
        return;
}
