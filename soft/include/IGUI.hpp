/*
** cuddly-couscous
** File description:
** IGUI
*/

class IGUI {
public:
    virtual ~IGUI() {}

    virtual void init() = 0;
    virtual void draw() = 0;
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void clear() = 0;
    virtual void refresh() = 0;
    virtual void close() = 0;
};
