/*
** cuddly-couscous
** File description:
** Block
*/

#ifndef BLOCK_HPP_
#define BLOCK_HPP_
    #include <vector>
    #include <map>
    #include <string>

    class Block {
        protected:
            int x;
            int y;
            int width;
            int height;

            int borderColor;
            int borderSize;

            std::map<std::string, std::string> mapContent;

        public:
            Block(int x, int y, int width, int weight, int borderColor, int borderSize);
            ~Block();

            void setSize(int, int);
            void setPos(int, int);
            void setBorderColor(int);
            void setBorderSize(int);
            void setContent(std::string, std::string);

            std::vector<int> getSize() const;
            std::vector<int> getPos() const;
            std::vector<int> getBorderSize() const;
            std::map<std::string, std::string> getContent() const;
        
        protected:
        private:
    };

#endif /* !BLOCK_HPP_ */
