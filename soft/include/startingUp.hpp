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
    #include <csignal>
    #include <memory>
    #include <vector>

    #include "Sniffer.hpp"
    #include "PacketParser.hpp"
    #include "DeauthFrames.hpp"
    #include "TTL.hpp"
    #include "LAND.hpp"
    #include "TCH.hpp"
    #include "THA.hpp"
    #include "TTL.hpp"
    #include "NcursesGUI.hpp"

    int startingUp(char *device_name);

#endif /* !STARTINGUP_HPP_ */