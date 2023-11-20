/*
** cuddly-couscous
** File description:
** NcursesGUI
*/


#ifndef NCURSESGUI_HPP_
    #define NCURSESGUI_HPP_

    #include <ncurses.h>
    #include <string>
    #include "IGUI.hpp"
    #include "Block.hpp"
    #include <vector>
    #include "FactoryBlock.hpp"

    class NcursesGUI : public virtual IGUI {
        private:
            std::vector<Block> arrayBlocks;
            void drawBlock(Block);
            void drawBlocks(std::vector<Block> &);
            void drawContent(Block);
            FactoryBlock factoryBlock = FactoryBlock();
        public:
            NcursesGUI();
            ~NcursesGUI();

            void init();
            void draw();
            void handleInput();
            void update(Sniffer *sniffer, IAttacks *array[]);
            void clear();
            void refresh();
            void close();
    };

#endif /* !NCURSESGUI_HPP_ */
