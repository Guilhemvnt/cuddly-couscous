#ifndef PACKET_PARSER_H
#define PACKET_PARSER_H

#include <vector>
#include <string>
#include <regex>
#include <map>
#include <fstream>
#include <iostream>

class PacketParser {
public:
    PacketParser();
    ~PacketParser();
    void parse(const std::string&);

    void addPacket(std::map<std::string, std::string> packet);
    std::vector<std::map<std::string, std::string>> getPackets() const;
    void parsePacket(const std::string&);
    void displayPackets();

private:
    std::vector<std::map<std::string, std::string>> packets;
};

#endif
