/*
** cuddly-couscous
** File description:
** Packet
*/

#include "Packet.hpp"

Packet::Packet()
{
}

Packet::~Packet()
{
}

void Packet::setTimeStamp(const std::string& timeStamp)
{
    _timeStamp = timeStamp;
}

void Packet::setSrcIp(const std::string& srcIp)
{
    _srcIp = srcIp;
}

void Packet::setDstIp(const std::string& dstIp)
{
    _dstIp = dstIp;
}

void Packet::setProtocol(const std::string& protocol)
{
    _protocol = protocol;
}

void Packet::setDstMAC(const std::string& dstMAC)
{
    _dstMAC = dstMAC;
}

void Packet::setSrcMAC(const std::string& srcMAC)
{
    _srcMAC = srcMAC;
}

void Packet::setLength(const int length)
{
    _length = length;
}


void Packet::setSrcPortTCP(const std::string& srcPortTCP)
{
    _srcPortTCP = std::stoi(srcPortTCP);
}

void Packet::setDstPortTCP(const std::string& dstPortTCP)
{
    _dstPortTCP = std::stoi(dstPortTCP);
}

void Packet::setSrcPortUDP(const std::string& srcPortUDP)
{
    _srcPortUDP = std::stoi(srcPortUDP);
}

void Packet::setDstPortUDP(const std::string& dstPortUDP)
{
    _dstPortUDP = std::stoi(dstPortUDP);
}

void Packet::setRSTflag(const std::string& RSTflag)
{
    _RSTflag = std::stoi(RSTflag);
}

std::string Packet::getTimeStamp() const
{
    return _timeStamp;
}

std::string Packet::getSrcIp() const
{
    return _srcIp;
}

std::string Packet::getDstIp() const
{
    return _dstIp;
}

std::string Packet::getProtocol() const
{
    return _protocol;
}

std::string Packet::getDstMAC() const
{
    return _dstMAC;
}

std::string Packet::getSrcMAC() const
{
    return _srcMAC;
}

int Packet::getLength() const
{
    return _length;
}

int Packet::getSrcPortTCP() const
{
    return _srcPortTCP;
}

int Packet::getDstPortTCP() const
{
    return _dstPortTCP;
}

int Packet::getSrcPortUDP() const
{
    return _srcPortUDP;
}

int Packet::getDstPortUDP() const
{
    return _dstPortUDP;
}

int Packet::getRSTflag() const
{
    return _RSTflag;
}

// Path: soft/src/Parser.cpp


