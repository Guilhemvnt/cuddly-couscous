/*
** cuddly-couscous
** File description:
** IAttacks
*/

#ifndef IATTACKS_HPP_
#define IATTACKS_HPP_

    #include <vector>
    #include <map>
    #include <string>

    class IAttacks {
        public:
            virtual ~IAttacks(void) = default;
            virtual void addPacket(std::map<std::string, std::string>) = 0;
            virtual std::vector<std::map<std::string, std::string>> getPackets(void) = 0;
            virtual void displayPackets(void) = 0;
            virtual void analysePackets(void) = 0;
    };

#endif /* !IATTACKS_HPP_ */
