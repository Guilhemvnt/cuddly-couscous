/*
** cuddly-couscous
** File description:
** SMURF
*/

#ifndef SMURF_HPP_
    #define SMURF_HPP_
    #include "IAttacks.hpp"

    class SMURF : public IAttacks {
        public:
            SMURF();
            ~SMURF();
            void addPacket(Packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet);
            std::string getName(void) const;
        protected:
            std::vector<Packet> _packets;
            std::map<std::string, std::vector<Packet>> _map;
        private:
    };

#endif /* !SMURF_HPP_ */
