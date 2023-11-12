/*
** cuddly-couscous
** File description:
** NcursesGUI
*/

#include <ncurses.h>
#include <string>
#include "IGUI.hpp"
#include "Block.hpp"
#include <vector>

class NcursesGUI : public virtual IGUI {
    private:
        std::vector<Block> arrayBlocks;
        void drawBlock(Block);
        void drawBlocks(std::vector<Block>);
    public:
        NcursesGUI();
        ~NcursesGUI();

        void init();
        void draw();
        void handleInput();
        void update();
        void clear();
        void refresh();
        void close();
};
