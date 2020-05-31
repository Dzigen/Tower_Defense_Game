#ifndef MENU_BAR_H
#define MENU_BAR_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class MenuBar{

    public:

        /*полоска меню-бара*/
        sf::Sprite menubarline;

        /*кнопка паузы*/
        sf::Sprite pauseButton;
        sf::Sprite pauseButtonText;

        /*окно паузы с кнопками*/
        sf::Sprite PauseMenu;

        sf::Sprite PauseMenuButtonExit;
        sf::Text ExitText;
        sf::Sprite PauseMenuButtonContinue;
        sf::Text ContinueText;

        /*текст с номером текущего раунда*/
        sf::Text roundText;

        /*счётчик подобранных рун-монеток*/
        sf::Sprite iconCounterCoins;
        sf::Text textCounterCoins;

        /*счётчик полобранных рун,увеличивающих урон героя*/
        /*счётчик показывает количество добавачного урона героя*/
        sf::Sprite iconCounterAddedDamage;
        sf::Text textCounterAddedDamage;


        void incr_counter_coins(int value){
            char strCoins[5]="";

            counterCoins+=value;
            sprintf(strCoins,"%d",counterCoins);

            textCounterCoins.setString(strCoins);
        }

        void incr_counter_added_damage(int value){
            char strAddedDamage[6]="";

            counterAddedDamage+=value;
            sprintf(strAddedDamage,"+%d",counterAddedDamage);

            textCounterAddedDamage.setString(strAddedDamage);
        }

        void check_for_next_round(sf::Clock clock){
            int time;
            int minutes;
            char strRound[10]="";

            sprintf(strRound,"Round %d",round);

            time=clock.getElapsedTime().asSeconds();
            minutes=((time / 60)%60);

            if(((minutes%10==0)&&(minutes==bufferTime))||((bufferTime==60)&&(minutes<10))){
                round++;
                roundText.setString(strRound);

                if(bufferTime==60)
                    bufferTime=10;
                else
                    bufferTime+=10;
            }
        }

    MenuBar(){
        /*загружаем текст шрифта*/
        font.loadFromFile("../../Tower_Defense_Game/external/Text/Roboto-Italic.ttf");

        /*инициализируем иекси "первый раунд"*/
        round = 1;
        roundText.setFont(font);
        roundText.setFillColor(sf::Color::Black);
        roundText.setPosition(520,7);
        roundText.setString("Round "+std::to_string(round));

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

        counterAddedDamage=0;
        counterCoins=0;

        /*инициализация счётчика добавочного урона*/
        shapeAddedDamage.loadFromFile("../../Tower_Defense_Game/external/Sprites/iconAddedDamage.png");
        iconCounterAddedDamage.setTexture(shapeAddedDamage);
        iconCounterAddedDamage.setPosition(900,7);

        textCounterAddedDamage.setFont(font);
        textCounterAddedDamage.setFillColor(sf::Color(5,171,5));
        textCounterAddedDamage.setPosition(950,7);
        incr_counter_added_damage(0);

        /*инициализация счётчика собранных монет*/
        shapeCoin.loadFromFile("../../Tower_Defense_Game/external/Sprites/iconCoin.png");
        iconCounterCoins.setTexture(shapeCoin);
        iconCounterCoins.setPosition(1050,7);

        textCounterCoins.setFont(font);
        textCounterCoins.setFillColor(sf::Color::Black);
        textCounterCoins.setPosition(1100,7);
        incr_counter_coins(0);

        bufferTime=10;

    }

    private:
        int round;
        int counterCoins;
        int counterAddedDamage;

        int bufferTime;

        sf::Font font;

        sf::Texture shapePB;
        sf::Texture shapeMBL;

        sf::Texture PM;
        sf::Texture PMBE;
        sf::Texture PMBC;

        sf::Image pausePict;
        sf::Texture shapePBT;

        sf::Texture shapeAddedDamage;

        sf::Texture shapeCoin;

};

#endif // MENU_BAR_H
