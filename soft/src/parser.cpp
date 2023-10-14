#include "parser.hpp"

PacketParser::PacketParser() {
}

PacketParser::~PacketParser() {
}

void PacketParser::parse(const std::string& file) {
    std::ifstream stream(file);

    if (!stream.is_open()) {
        return;
    }

    std::map<std::string, std::string> packet;
    std::string line;

    while (std::getline(stream, line)) {
        std::istringstream lineStream(line);
        while (lineStream) {
            std::string key;
            std::string value;

            getline(lineStream, key, ':');
            lineStream >> value;
            if (!value.empty() && !key.empty())
                packet[key] = value;
        }
        if (!packet.empty())
            addPacket(packet);
        packet.clear();
    }
}



void PacketParser::addPacket(std::map<std::string, std::string> packet) {
    packets.push_back(packet);
}

std::vector<std::map<std::string, std::string>> PacketParser::get_packets() const {
    return packets;
}

void PacketParser::parse_packet(const std::string&) {
    std::map<std::string, std::string> packet_map;
    addPacket(packet_map);
}

void PacketParser::display_packets()
{
    std::cout << "Parsed " << get_packets().size() << " packets." << std::endl;
    for (auto packet : get_packets()) {
        std::cout << "Packet: " << std::endl;
        for (auto pair : packet) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
        std::cout << std::endl;
    }
}