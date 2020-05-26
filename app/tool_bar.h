#ifndef TOOL_BAR_H
#define TOOL_BAR_H

#include<SFML/Graphics.hpp>

class ToolBar{

    public:
        sf::Sprite toolbarline;

    ToolBar(){

        shapeTBL.loadFromFile("../../Tower_Defense_Game/external/Sprites/line.png");
        toolbarline.setTexture(shapeTBL);
        toolbarline.setPosition(0,685);
    }

    private:
        sf::Texture shapeTBL;
};

#endif // TOOL_BAR_H
