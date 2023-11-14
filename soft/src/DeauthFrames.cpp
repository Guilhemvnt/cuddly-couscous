/*
** cuddly-couscous
** File description:
** DeauthFrames
*/

#include "DeauthFrames.hpp"

DeauthFrames::DeauthFrames()
{
}

DeauthFrames::~DeauthFrames()
{
}

void DeauthFrames::addPacket(Packet packet)
{
    _packets.push_back(packet);
}

std::vector<Packet> DeauthFrames::getPackets(void)
{
}

void DeauthFrames::displayPackets(void)
{
    for (auto packet : _packets) {}
        //std::cout << &packet << std::endl;
}

void DeauthFrames::analysePackets(Packet packet)
{
    if (packet.getRSTflag() == 1) {
        addPacket(packet);
    } else
        return;
    return;
}
