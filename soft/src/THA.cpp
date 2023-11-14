/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** THA
*/

#include "THA.hpp"

THA::THA()
{
}

THA::~THA()
{
}

void THA::addPacket(Packet packet)
{
    _packets.push_back(packet);
}

std::vector<Packet> THA::getPackets(void)
{
    return _packets;
}

void THA::displayPackets(void)
{
    for (auto packet : _packets)
        std::cout << &packet << std::endl;
}

void THA::analysePackets(Packet packet)
{
    if (packet.getRSTflag() == 0 && packet.getSYNflag() == 0 && packet.getACKflag() == 0 && packet.getFINflag() == 0) {
        addPacket(packet);
        //std::cout << "THA attack detected" << std::endl;
    } else {
        return;
    }
}