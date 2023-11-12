/*
** cuddly-couscous
** File description:
** Block
*/

#include "Block.hpp"

Block::Block(int x, int y, int width, int height, int borderColor, int borderSize)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    this->borderColor = borderColor;
    this->borderSize = borderSize;
}

Block::~Block()
{
}

void Block::setSize(int width, int height)
{
    this->width = width;
    this->height = height;
}

void Block::setPos(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Block::setBorderColor(int borderColor)
{
    this->borderColor = borderColor;
}

void Block::setBorderSize(int borderSize)
{
    this->borderSize = borderSize;
}

std::vector<int> Block::getSize() const
{
    std::vector<int> size;

    size.push_back(this->width);
    size.push_back(this->height);
    return (size);
}

std::vector<int> Block::getPos() const
{
    std::vector<int> pos;

    pos.push_back(this->x);
    pos.push_back(this->y);
    return (pos);
}

std::vector<int> Block::getBorderSize() const
{
    std::vector<int> borderSize;

    borderSize.push_back(this->borderColor);
    borderSize.push_back(this->borderSize);
    return (borderSize);
}

void Block::setContent(std::string key, std::string value)
{
    this->mapContent[key] = value;
}

std::map<std::string, std::string> Block::getContent() const
{
    return (this->mapContent);
}

