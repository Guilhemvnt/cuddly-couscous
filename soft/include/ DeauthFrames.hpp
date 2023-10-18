/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
**  DeauthFrames
*/

#ifndef DEAUTHFRAMES_HPP_
#define DEAUTHFRAMES_HPP_
    #include <vector>
    #include <map>
    #include <string>

    class DeauthFrames
    {
        private:
        protected:
        public:
            DeauthFrames();
            ~DeauthFrames();

            void parse(const std::string&);
            void addPacket(std::map<std::string, std::string> packet);
            std::vector<std::map<std::string, std::string>> getPackets() const;
            void parsePacket(const std::string&);
            void displayPackets();
    };
#endif /* !DEAUTHFRAMES_HPP_ */