/*
** cuddly-couscous
** File description:
** FactoryBlock
*/

#ifndef FACTORYBLOCK_HPP_
#define FACTORYBLOCK_HPP_
    #include "Block.hpp"
    #include <string>
    #include <vector>
    #include <map>

    class FactoryBlock {
        public:
            std::map<std::string, std::vector<int>> mapSize;
            
            FactoryBlock();
            ~FactoryBlock();

            Block createBlock(std::string type, std::vector<int> pos);
            std::vector<Block> createRowsBlock(std::string type, std::vector<int> pos, int nbRow);

        protected:
        private:
    };

#endif /* !FACTORYBLOCK_HPP_ */
