/*
** cuddly-couscous
** File description:
** FactoryBlock
*/

#include "FactoryBlock.hpp"

FactoryBlock::FactoryBlock()
{
    mapSize = {
        {"small", std::vector<int>{25, 5}},
        {"medium", std::vector<int>{25, 20}},
        {"large", std::vector<int>{100, 10}}
    };
}

FactoryBlock::~FactoryBlock()
{
}

Block FactoryBlock::createBlock(std::string type, std::vector<int> pos)
{
    if (type == "small")
        return Block(pos[0], pos[1], mapSize[type][0], mapSize[type][1], 1, 1);
    if (type == "medium")
        return Block(pos[0], pos[1], mapSize[type][0], mapSize[type][1], 1, 1);
    if (type == "large")
        return Block(pos[0], pos[1], mapSize[type][0], mapSize[type][1], 1, 1);
    return Block(0, 0, 0, 0, 0, 0);
}

std::vector<Block> FactoryBlock::createRowsBlock(std::string type, std::vector<int> pos, int nbRow)
{
    std::vector<Block> arrayBlocks;
    for (int i = 0; i < nbRow; i++) {
        arrayBlocks.push_back(createBlock(type, std::vector<int>{pos[0] + (i * mapSize[type][0]), pos[1]}));
    }
    return arrayBlocks;
}
