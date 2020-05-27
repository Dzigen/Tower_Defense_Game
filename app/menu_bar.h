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

        sf::Sprite PauseMenu;

        sf::Sprite PauseMenuButtonExit;
        sf::Text ExitText;
        sf::Sprite PauseMenuButtonContinue;
        sf::Text ContinueText;

    MenuBar(){
        /*загружаем текст шрифта*/
        font.loadFromFile("../../Tower_Defense_Game/external/Text/Roboto-Italic.ttf");

        /*инициализируем первый раунд*/
        std::string strR = "Round ";
        round = 1;

    //=====
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

        /*загржаем фон меню-паузы*/
        PM.loadFromFile("../../Tower_Defense_Game/external/Sprites/pauseMenu.png");
        PauseMenu.setTexture(PM);
        PauseMenu.setPosition(0,56);

        /*загружаем кнопку меню-паузы:Продолжить игру*/
        PMBC.loadFromFile("../../Tower_Defense_Game/external/Sprites/pauseMenuButton.png");
        PauseMenuButtonContinue.setTexture(PMBC);
        PauseMenuButtonContinue.setPosition(20, 96);

        /*загружаем текст кнопки*/
        ContinueText.setFont(font);
        ContinueText.setString("Continue game");
        ContinueText.setPosition(50,106);

        /*загружаем кнопку меню-паузы:Выход в главное меню*/
        PMBE.loadFromFile("../../Tower_Defense_Game/external/Sprites/pauseMenuButton.png");
        PauseMenuButtonExit.setTexture(PMBE);
        PauseMenuButtonExit.setPosition(20, 166);

        /*загружаем текст кнопки*/
        ExitText.setFont(font);
        ExitText.setString("Exit in main menu");
        ExitText.setPosition(35,170);
    //=====

    }

    private:
        sf::Font font;

        sf::Texture shapePB;
        sf::Texture shapeMBL;

        sf::Texture PM;
        sf::Texture PMBE;
        sf::Texture PMBC;

        sf::Image pausePict;
        sf::Texture shapePBT;

};

#endif // MENU_BAR_H
