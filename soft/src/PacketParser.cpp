#include "PacketParser.hpp"

PacketParser::PacketParser() {
}

PacketParser::~PacketParser() {
}

void PacketParser::parse(const std::string& file) {
    std::ifstream stream(file);

    if (!stream.is_open())
        return;
    std::map<std::string, std::string> packet;
    std::string line;

    while (std::getline(stream, line))
        parsePacket(line);
}

void PacketParser::addPacket(std::map<std::string, std::string> packet) {
    packets.push_back(packet);
}

std::vector<std::map<std::string, std::string>> PacketParser::getPackets() const {
    return packets;
}

void PacketParser::parsePacket(const std::string& packet) {
    std::map<std::string, std::string> packet_map;
    std::istringstream lineStream(packet);

    while (lineStream) {
        std::string key;
        std::string value;

        getline(lineStream, key, ':');
        lineStream >> value;
        if (!value.empty() && !key.empty())
            packet_map[key] = value;
    }
    if (!packet.empty())
        addPacket(packet_map);
    packet_map.clear();
}

void PacketParser::displayPackets()
{
    std::cout << "Parsed " << getPackets().size() << " packets." << std::endl;
    for (auto packet : getPackets()) {
        std::cout << "Packet: " << std::endl;
        for (auto pair : packet) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
        std::cout << std::endl;
    }
}
