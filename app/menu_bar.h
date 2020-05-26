#ifndef MENU_BAR_H
#define MENU_BAR_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class MenuBar{

    public:

        int round;

        sf::Sprite menubarline;
        sf::Sprite pauseButton;
        sf::Sprite pauseButtonText;

    MenuBar(){

        std::string strR = "Round ";
        round = 1;

        /*загружаем полоску меню бара*/
        shapeMBL.loadFromFile("../../Tower_Defense_Game/external/Sprites/line.png");
        menubarline.setTexture(shapeMBL);

        /*загружаем кнопку меню бара*/
        shapePB.loadFromFile("../../Tower_Defense_Game/external/Sprites/pauseButton.png");
        pauseButton.setTexture(shapePB);
        pauseButton.setPosition(7,7);

        /*загружаем содержимое кнопки*/
        pausePict.loadFromFile("../../Tower_Defense_Game/external/Sprites/pauseButtonText.png");
        pausePict.createMaskFromColor(sf::Color(0,0,0));
        shapePBT.loadFromImage(pausePict);
        pauseButtonText.setTexture(shapePBT);
        pauseButtonText.setPosition(7,7);

    }

    private:
        sf::Texture shapePB;
        sf::Texture shapeMBL;

        sf::Image pausePict;
        sf::Texture shapePBT;

};

#endif // MENU_BAR_H
