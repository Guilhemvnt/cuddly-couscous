/*

** cuddly-couscous
** File description:
** LAND
*/

#ifndef LAND_HPP_
#define LAND_HPP_
    #include "IAttacks.hpp"
    class LAND {
        protected:
        private:
        public:
            LAND();
            ~LAND();

            void addPacket(std::map<std::string, std::string>);
            std::vector<std::map<std::string, std::string>> getPackets(void);
            void displayPackets(void);
            void analysePackets(void);
    };

#endif /* !LAND_HPP_ */
