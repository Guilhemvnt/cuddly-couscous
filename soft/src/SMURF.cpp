/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** SMURF
*/

#include "SMURF.hpp"
#include <arpa/inet.h>

SMURF::SMURF()
{
    Packet packet = Packet();
    addPacket(packet); 
}

SMURF::~SMURF()
{
}

void SMURF::addPacket(Packet packet)
{
    _map[packet.getSrcIp()].push_back(packet);
}

std::vector<Packet> SMURF::getPackets(void)
{
    std::vector<Packet> largestVector;
    for (const auto& pair : _map) {
        if (pair.second.size() > largestVector.size() && pair.first != "<>") {
            largestVector = pair.second;
        }
    }
    return largestVector;
}

void SMURF::displayPackets(void)
{
    for (auto packet : _packets) {
        std::cout << &packet << std::endl;
    }
}

void SMURF::analysePackets(Packet packet)
{
    if (packet.getProtocol() == "8" ) {
        addPacket(packet);
    } else
        return;
    return;
}

std::string SMURF::getName(void) const
{
    return std::string("SMURF");
}


