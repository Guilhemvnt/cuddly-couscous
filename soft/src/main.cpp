/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** main
*/

#include "main.hpp"

int main(int argc, char **argv) {

    PacketParser parser;
    bool isFile = false;
    std::string file;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-f") == 0) {
            isFile = true;
            file = argv[i + 1];
            break;
        }
    }
    if (isFile) {
        parser.parse(file);
        parser.display_packets();
    }
    else
	    startingUp(argv[1]);
    return 0;
}