/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** DecoyScanningAttempts
*/

#include "DecoyScanningAttempts.hpp"
#include <sstream>

DecoyScanningAttempts::DecoyScanningAttempts()
{
    Packet packet = Packet();
    addPacket(packet);
}

DecoyScanningAttempts::~DecoyScanningAttempts()
{
}

void DecoyScanningAttempts::addPacket(Packet packet)
{
    _map[packet.getSrcIp()].push_back(packet);
}

std::vector<Packet> DecoyScanningAttempts::getPackets(void)
{
    std::vector<Packet> largestVector;
    for (const auto& pair : _map) {
        if (pair.second.size() > largestVector.size() && pair.first != "<>") {
            largestVector = pair.second;
        }
    }
    return largestVector;
}

void DecoyScanningAttempts::displayPackets(void)
{
    for (auto packet : _packets) {
        std::cout << &packet << std::endl;
    }
}

// Function to check the type of IP address
bool checkIPRange(const std::string& ip) {
    std::vector<int> ipParts;
    std::istringstream ss(ip);
    std::string part;

    while (getline(ss, part, '.')) {
        ipParts.push_back(std::stoi(part));
    }
    if (ipParts[0] == 0 && ipParts[1] == 0 && ipParts[2] == 0 && ipParts[3] != 0) {
        return false;
    }
    return true;
}

void DecoyScanningAttempts::analysePackets(Packet packet)
{
    if (packet.getSrcIp() != "<>" || packet.getDstIp() != "<>") {
        if (!checkIPRange(packet.getDstIp()) || !checkIPRange(packet.getSrcIp())) {
            addPacket(packet);
        } else {
            return;
        }
    } else {
        return;
    }
    addPacket(packet);
}


std::string DecoyScanningAttempts::getName(void) const
{
    return "DecoyScanning";
}