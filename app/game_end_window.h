#ifndef GAME_END_WINDOW_H
#define GAME_END_WINDOW_H

#include <SFML/Graphics.hpp>

class GameEndWindow{

    public:

        sf::Sprite sprite;
        int w;
        int h;

        sf::Text timer;
        int secondsTillExit;

        sf::Text description;

    GameEndWindow(){

        w=300;
        h=200;
        secondsTillExit=10;
        bufferSeconds=0;

        shapeGEW.loadFromFile("../../Tower_Defense_Game/external/Sprites/endMenu.png");
        sprite.setTexture(shapeGEW);
        sprite.setPosition(((1200/2)-(w/2)),((740/2)-(h/2)));

        /*загружаем текст шрифта*/
        font.loadFromFile("../../Tower_Defense_Game/external/Text/Roboto-Italic.ttf");
        timer.setFont(font);
        timer.setFillColor(sf::Color::Black);

        description.setFont(font);
        description.setFillColor(sf::Color(171,14,21));

    }

    void setDescription(bool flag){

        if(flag){

            description.setString("The base is destroyed");
            description.setPosition(sprite.getPosition().x+(w*1/80),sprite.getPosition().y+(h*7/20));

        }else{

            description.setString("The hero is dead");
            description.setPosition(sprite.getPosition().x+(w*6/50),sprite.getPosition().y+(h*7/20));

        }

    }

    void check_timer(sf::Clock &clock){

        int seconds=0;

        time=clock.getElapsedTime();
        seconds = time.asSeconds();

        seconds=seconds % 60;

        if(bufferSeconds<seconds){

            bufferSeconds=seconds;
            if(secondsTillExit>0){

                secondsTillExit--;

            }

            update_timer();

        }

    }

    void update_timer(){

        const int lenght=4;
        char seconds[lenght]="";

        snprintf(seconds,lenght,"%d",secondsTillExit);
        timer.setString(seconds);
        timer.setPosition(sprite.getPosition().x+(w/2)-15,sprite.getPosition().y+((h*3)/4));

    }

    private:

        int bufferSeconds;
        sf::Time time;

        sf::Font font;
        sf::Texture shapeGEW;

};

#endif // GAME_END_WINDOW_H
