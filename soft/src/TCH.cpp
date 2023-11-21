/*
** cuddly-couscous
** File description:
** TCH (TCP Connection Hijacking)
*/

#include "TCH.hpp"

TCH::TCH()
{
    Packet packet = Packet();
    addPacket(packet);
}

TCH::~TCH()
{
}

void TCH::addPacket(Packet packet)
{
    _map[packet.getSrcIp()].push_back(packet);
}

std::vector<Packet> TCH::getPackets(void)
{
    std::vector<Packet> largestVector;
    for (const auto& pair : _map) {
        if (pair.second.size() > largestVector.size() && pair.first != "<>") {
            largestVector = pair.second;
        }
    }
    return largestVector;
}

void TCH::displayPackets(void)
{
    for (auto packet : _packets)
    std::cout << &packet << std::endl;
}

void TCH::analysePackets(Packet packet)
{
    if (
        (packet.getSYNflag() == 0 && packet.getACKflag() == 0 && packet.getFINflag() == 0) ||
        (packet.getSYNflag() == 0 && packet.getACKflag() == 0 && packet.getFINflag() == 0) ||
        (packet.getRSTflag() == 1) ||
        (packet.getFINflag() == 1)
    ) {
        addPacket(packet);
    } else {
        return;
    }
}
