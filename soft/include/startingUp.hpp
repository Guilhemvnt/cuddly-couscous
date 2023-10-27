/*
** cuddly-couscous
** File description:
** startingUp
*/

#ifndef STARTINGUP_HPP_
#define STARTINGUP_HPP_

    #include <stdio.h>
    #include <sstream>
    #include <pcap.h>

    #include "Sniffer.hpp"
    #include <csignal>
    #include <memory>
    #include "PacketParser.hpp"
    #include "TTL.hpp"
    #include "LAND.hpp"

    int startingUp(char *device_name);

#endif /* !STARTINGUP_HPP_ */