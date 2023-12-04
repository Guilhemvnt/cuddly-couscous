/*
** cuddly-couscous
** File description:
** main
*/

#include "main.hpp"
#include <criterion/criterion.h>

int main(int argc, char **argv) {

    PacketParser parser;
    bool isFile = false;
    std::string file;
    struct criterion_test_set *tests = criterion_initialize();
    int result = 0;

    if (argc == 1) {
        std::cout << "Usage: ./cuddly-couscous [network interface] || [-f file] || [-t -l]" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-f") == 0) {
            isFile = true;
            file = argv[i + 1];
            break;
        }
        if (strcmp(argv[i], "-h") == 0) {
            std::cout << "Usage: ./cuddly-couscous [network interface] || [-f file] || [-t -l]" << std::endl;
            return 0;
        }
        if (strcmp(argv[i], "-t") == 0) {
            std::cout << "test" << std::endl;
            if (criterion_handle_args(argc, argv, true))
                result = !criterion_run_all_tests(tests);

            criterion_finalize(tests);
            return result;
        }
    }
    if (isFile) { //read file and parse log file
        parser.parse(file);
        parser.displayPackets();
    }
    if (argc >= 2 && !isFile)
	    startingUp(argv[1]);
    return 0;
}