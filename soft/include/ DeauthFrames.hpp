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
        public:
            DeauthFrames(void);
            ~DeauthFrames(void);

            void addPacket(std::map<std::string, std::string>);
            std::vector<std::map<std::string, std::string>> getPackets(void);
            void displayPackets(void);
            void analysePackets(void);
    };
#endif /* !DEAUTHFRAMES_HPP_ */