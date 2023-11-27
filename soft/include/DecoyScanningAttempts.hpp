/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** DecoyScanningAttempts
*/

#ifndef DECOYSCANNINGATTEMPTS_HPP_
    #define DECOYSCANNINGATTEMPTS_HPP_
    #include "IAttacks.hpp"

    class DecoyScanningAttempts : public virtual IAttacks {
        private:
        protected:
            std::vector<Packet> _packets;
            std::map<std::string, std::vector<Packet>> _map;
        public:
            DecoyScanningAttempts();
            ~DecoyScanningAttempts();

            void addPacket(Packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet);
            std::string getName(void) const;

    };

#endif /* !DECOYSCANNINGATTEMPTS_HPP_ */
