#ifndef PACKET_PARSER_H
#define PACKET_PARSER_H

#include <vector>
#include <string>
#include <regex>
#include <map>

class PacketParser {
public:
    PacketParser();
    ~PacketParser();
    void parse(const std::string& input_text);
    std::vector<std::map<std::string, std::string>> get_packets() const;

private:
    std::vector<std::map<std::string, std::string>> packets;
};

#endif
