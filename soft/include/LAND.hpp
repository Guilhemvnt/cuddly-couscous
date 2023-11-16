/*

** cuddly-couscous
** File description:
** LAND
*/

#ifndef LAND_HPP_
    #define LAND_HPP_

    #include "IAttacks.hpp"

    class LAND : public virtual IAttacks{
        protected:
            std::vector<Packet> _packets;
        private:
        public:
            LAND();
            ~LAND();

            void addPacket(Packet);
            std::vector<Packet> getPackets(void);
            void displayPackets(void);
            void analysePackets(Packet);
            std::string getName(void) const { return "LAND"; };
    };

#endif /* !LAND_HPP_ */
