/*
** EPITECH PROJECT, 2023
** cuddly-couscous
** File description:
** Block
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_
    #include <vector>

    class Block {
        protected:
            int x;
            int y;
            int width;
            int height;

            int borderColor;
            int borderSize;

        public:
            Block(int x, int y, int width, int weight, int borderColor, int borderSize);
            ~Block();

            void setSize(int, int);
            void setPos(int, int);
            void setBorderColor(int);
            void setBorderSize(int);

            std::vector<int> getSize();
            std::vector<int> getPos();
            std::vector<int> getBorderSize();
        
        protected:
        private:
    };

#endif /* !BLOCK_HPP_ */
