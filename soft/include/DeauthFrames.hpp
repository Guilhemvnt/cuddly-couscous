/*
** cuddly-couscous
** File description:
**  DeauthFrames
*/

#ifndef DEAUTHFRAMES_HPP_
#define DEAUTHFRAMES_HPP_

    #include "IAttacks.hpp"

    class DeauthFrames : public virtual IAttacks {
        private:
        protected:
            std::vector<Packet> _packets;
            std::map<std::string, std::vector<Packet>> _map;
        public:
            DeauthFrames(void);
            ~DeauthFrames(void);

            void addPacket(Packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet);
            std::string getName(void) const;
    };
#endif /* !DEAUTHFRAMES_HPP_ */