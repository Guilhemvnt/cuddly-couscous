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
        public:
            DeauthFrames(void);
            ~DeauthFrames(void);

            void addPacket(Packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet);
            std::string getName(void) const { return "DeauthFrames"; };
    };
#endif /* !DEAUTHFRAMES_HPP_ */