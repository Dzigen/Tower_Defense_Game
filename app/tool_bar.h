#ifndef TOOL_BAR_H
#define TOOL_BAR_H

#include<SFML/Graphics.hpp>
#include <string>
#include <stdio.h>

class ToolBar{

    public:
        sf::Sprite toolbarline;

        sf::Text timer;
        sf::Sprite iconClock;

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

        void add_to_time(){
            time=clock.getElapsedTime();
            addToTimer+=time.asSeconds();
        }

        void reset_clock(){
            clock.restart();
        }

    ToolBar(){
        /*загружаем текст шрифта*/
        font.loadFromFile("../../Tower_Defense_Game/external/Text/Roboto-Italic.ttf");

        shapeTBL.loadFromFile("../../Tower_Defense_Game/external/Sprites/line.png");
        toolbarline.setTexture(shapeTBL);
        toolbarline.setPosition(0,685);

        shape.loadFromFile("../../Tower_Defense_Game/external/Sprites/iconTime.png");
        shape.createMaskFromColor(sf::Color(255,255,255));
        shapeIC.loadFromImage(shape);
        iconClock.setTexture(shapeIC);
        iconClock.setPosition(5,692);

        clock.restart();
        timer.setFont(font);
        timer.setPosition(50,693);
        timer.setFillColor(sf::Color(0,0,0));
    }

    private:
        int addToTimer=0;

        sf::Clock clock;
        sf::Time time;

        sf::Font font;

        sf::Image shape;
        sf::Texture shapeIC;

        sf::Texture shapeTBL;
};

#endif // TOOL_BAR_H
