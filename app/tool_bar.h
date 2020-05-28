#ifndef TOOL_BAR_H
#define TOOL_BAR_H

#include<SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <stdio.h>

class ToolBar{

    public:
        /*полоска toolbar внизу экрана*/
        sf::Sprite toolbarline;

        /*таймер*/
        sf::Text timer;
        sf::Sprite iconClock;

        /*здоровье танка*/
        sf::Sprite hp_hero_red;
        sf::Sprite hp_hero_green;
        sf::Text textHHP;
        sf::Text valueHHPof;

        /*здоровье базы*/
        sf::Sprite hp_base_red_orange;
        sf::Sprite hp_base_green;
        sf::Text textBHP;
        sf::Text valueBHPof;

        /*получить строку с текущим временем игры: hh:mm:ss*/
        void get_time(){
            int seconds=0;
            int minutes=0;
            int hours=0;
            char str[10]="";

            time=clock.getElapsedTime();
            seconds = time.asSeconds();

            seconds+=addToTimer;

            minutes=seconds / 60;
            seconds=seconds % 60;
            hours=seconds / 3600;

            sprintf(str,"%d:%d:%d",hours,minutes,seconds);
            timer.setString(str);

        }

        /*получаем время,с которого должен пойти отсчёт при возвражении в игру после паузы*/
        void add_to_time(){
            time=clock.getElapsedTime();
            addToTimer+=time.asSeconds();
        }

        /*функция перезагрузки времени*/
        void reset_clock(){
            clock.restart();
        }

        void change_hero_base_hp(std::string object,std::string str,int value,int &objecthealth){
            char strHP[4]="";

            if(str=="healing"){
                objecthealth+=value;
                if(objecthealth>100 && object=="hero"){
                    objecthealth=100;
                } else if(objecthealth>200 && object=="base"){
                    objecthealth=200;
                }
            }else if(str=="damaging"){
                objecthealth-=value;
                if(objecthealth<0)
                  objecthealth=0;
            }else{
                std::cout<<"Введена неверная команда для изменения здоровья героя: "<<str<<std::endl;
                exit(1);
            }

            if(object=="hero"){
                hp_hero_green.setTextureRect(sf::IntRect(0,0,objecthealth*2,shapeHPF.getSize().y));
                sprintf(strHP,"%d",objecthealth);
                valueHHPof.setString(strHP);
            }else if(object=="base"){
                hp_base_green.setTextureRect(sf::IntRect(0,0,objecthealth,shapeHPF.getSize().y));
                sprintf(strHP,"%d",objecthealth);
                valueBHPof.setString(strHP);
            }else{
                std::cout<<"Введена неверная команда для определения объекта: "<<object<<std::endl;
                exit(1);
            }

        }


    ToolBar(){
        /*инициализация добавочного значения к таймеру игры*/
        addToTimer=0;

        /*загружаем текст шрифта*/
        font.loadFromFile("../../Tower_Defense_Game/external/Text/Roboto-Italic.ttf");

        /*загружаем полоску tool bar*/
        shapeTBL.loadFromFile("../../Tower_Defense_Game/external/Sprites/line.png");
        toolbarline.setTexture(shapeTBL);
        toolbarline.setPosition(0,685);

        /*загружаем иконку часов для таймера*/
        shape.loadFromFile("../../Tower_Defense_Game/external/Sprites/iconTime.png");
        shape.createMaskFromColor(sf::Color(255,255,255));
        shapeIC.loadFromImage(shape);
        iconClock.setTexture(shapeIC);
        iconClock.setPosition(5,692);

        /*начинаем отсчёт времени*/
        clock.restart();

        /*опредеояем шрифт,цыет и расположение таймера*/
        timer.setFont(font);
        timer.setPosition(50,693);
        timer.setFillColor(sf::Color(0,0,0));

        /*загружаем полоску здоровья танка и соответствующий текст "Здоровье Героя"*/
        shapeHPF.loadFromFile("../../Tower_Defense_Game/external/Sprites/hp_foreground.png");
        hp_hero_green.setTexture(shapeHPF);
        hp_hero_green.setPosition(300,720);

        shapeHPB.loadFromFile("../../Tower_Defense_Game/external/Sprites/hp_background.png");
        hp_hero_red.setTexture(shapeHPB);
        hp_hero_red.setPosition(300,720);

        textHHP.setFont(font);
        textHHP.setString("Hero HP");
        textHHP.setFillColor(sf::Color::Black);
        textHHP.setCharacterSize(20);
        textHHP.setPosition(300,695);

        valueHHPof.setFont(font);
        valueHHPof.setString("100");
        valueHHPof.setFillColor(sf::Color::Black);
        valueHHPof.setCharacterSize(20);
        valueHHPof.setPosition(470,695);

        /*загружаем полоску здоровья базы и соответствующий текст "Здоровье базы"*/
        shapeHPF.loadFromFile("../../Tower_Defense_Game/external/Sprites/hp_foreground.png");
        hp_base_green.setTexture(shapeHPF);
        hp_base_green.setPosition(520,720);

        shapeHPAB.loadFromFile("../../Tower_Defense_Game/external/Sprites/hp_additnly_background.png");
        hp_base_red_orange.setTexture(shapeHPAB);
        hp_base_red_orange.setPosition(520,720);

        textBHP.setFont(font);
        textBHP.setString("Base HP");
        textBHP.setFillColor(sf::Color::Black);
        textBHP.setCharacterSize(20);
        textBHP.setPosition(520,695);

        valueBHPof.setFont(font);
        valueBHPof.setString("200");
        valueBHPof.setFillColor(sf::Color::Black);
        valueBHPof.setCharacterSize(20);
        valueBHPof.setPosition(690,695);

    }

    private:
        int addToTimer;

        sf::Font font;

        sf::Clock clock;
        sf::Time time;

        sf::Texture shapeHPB;
        sf::Texture shapeHPAB;
        sf::Texture shapeHPF;

        sf::Image shape;
        sf::Texture shapeIC;

        sf::Texture shapeTBL;
};

#endif // TOOL_BAR_H
