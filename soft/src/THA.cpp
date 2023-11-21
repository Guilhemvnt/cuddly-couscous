/*
** cuddly-couscous
** File description:
** TCP Hadnshake Abnormalities
*/

#include "THA.hpp"

THA::THA()
{
    Packet packet = Packet();
    addPacket(packet);
}

THA::~THA()
{
}

void THA::addPacket(Packet packet)
{
    _map[packet.getSrcIp()].push_back(packet);
}

std::vector<Packet> THA::getPackets(void)
{
    std::vector<Packet> largestVector;
    for (const auto& pair : _map) {
        if (pair.second.size() > largestVector.size() && pair.first != "<>") {
            largestVector = pair.second;
        }
    }
    return largestVector;
}

void THA::displayPackets(void)
{
    for (auto packet : _packets)
        std::cout << &packet << std::endl;
}

void THA::analysePackets(Packet packet)
{
    if (
        (packet.getRSTflag() == 0 && packet.getSYNflag() == 1 && packet.getACKflag() == 0 && packet.getFINflag() == 0) ||
        (packet.getRSTflag() == 0 && packet.getSYNflag() == 0 && packet.getACKflag() == 0 && packet.getFINflag() == 1) ||
        (packet.getFINflag() >= 2)
    ) {
        addPacket(packet);
    } else {
        return;
    }
}