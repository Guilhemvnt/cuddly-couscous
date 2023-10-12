#include "parser.hpp"

PacketParser::PacketParser() {
}

PacketParser::~PacketParser() {
}

void PacketParser::parse(const std::string& input_text) {
    std::regex packet_pattern(R"regex(Timestamp: (\d{4}-\d{2}-\d{2} \d{2}:\d{2}:\d{2}) Length: (\d+) bytes Source MAC: ([\dA-Fa-f:]+) Destination MAC: ([\dA-Fa-f:]+))regex");
    std::smatch match;
    std::string::const_iterator textIterator(input_text.cbegin());

    while (regex_search(textIterator, input_text.cend(), match, packet_pattern)) {
        std::map<std::string, std::string> packet_data;
        packet_data["Timestamp"] = match[1];
        packet_data["Length"] = match[2];
        packet_data["Source MAC"] = match[3];
        packet_data["Destination MAC"] = match[4];
        packets.push_back(packet_data);
        textIterator = match.suffix().first;
    }
}

std::vector<std::map<std::string, std::string>> PacketParser::get_packets() const {
    return packets;
}
