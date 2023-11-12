/*
** cuddly-couscous
** File description:
** NcursesGUI
*/

#include "NcursesGUI.hpp"
#include <iostream>

NcursesGUI::NcursesGUI()
{
}

NcursesGUI::~NcursesGUI()
{
}

void NcursesGUI::init()
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    // Create your GUI components here
    arrayBlocks.push_back(Block(10, 10, 10, 10, 1, 1));
    arrayBlocks.push_back(Block(30, 10, 10, 10, 1, 1));

}

void NcursesGUI::draw() {
    clear();
    // Draw your GUI components here
    mvprintw(1, 1, "Intrusion Detection System GUI cuddly-couscous");
    mvprintw(3, 1, "-----------------------------");

    drawBlocks(arrayBlocks);
    refresh();
}

void NcursesGUI::handleInput() {
}

void NcursesGUI::update() {
}

void NcursesGUI::clear() {
    erase();
}

void NcursesGUI::refresh() {
    ::refresh();
}

void NcursesGUI::close() {
    endwin();
}

void NcursesGUI::drawBlock(Block block) {
    // Obtenez les coordonnées du bloc
    // Obtenez les coordonnées du bloc
    int x = block.getPos()[0];
    int y = block.getPos()[1];

    // Définissez la taille du bloc
    int size = block.getSize()[0];

    // Définissez la couleur de la bordure
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    wattron(stdscr, COLOR_PAIR(1));

    // Dessinez la bordure du carré
    for (int i = 0; i < size; ++i) {
        mvwaddch(stdscr, y, x + i, ACS_HLINE); // Dessinez la ligne supérieure
        mvwaddch(stdscr, y + size - 1, x + i, ACS_HLINE); // Dessinez la ligne inférieure
        mvwaddch(stdscr, y + i, x, ACS_VLINE); // Dessinez la colonne de gauche
        mvwaddch(stdscr, y + i, x + size - 1, ACS_VLINE); // Dessinez la colonne de droite
    }

    // Dessinez les coins du carré
    mvwaddch(stdscr, y, x, ACS_ULCORNER); // Coin supérieur gauche
    mvwaddch(stdscr, y, x + size - 1, ACS_URCORNER); // Coin supérieur droit
    mvwaddch(stdscr, y + size - 1, x, ACS_LLCORNER); // Coin inférieur gauche
    mvwaddch(stdscr, y + size - 1, x + size - 1, ACS_LRCORNER); // Coin inférieur droit

    wattroff(stdscr, COLOR_PAIR(1));
}

void NcursesGUI::drawBlocks(std::vector<Block> arrayBlocks) {
    for (size_t i = 0; i < arrayBlocks.size(); ++i) {
        drawBlock(arrayBlocks[i]);
    }
}