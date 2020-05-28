#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <SFML/Graphics.hpp>

class Map{

    public:
        sf::Sprite battleField;
        int w;
        int h;

    Map(){

        /*загружаем игровую карту*/
        shapeBF.loadFromFile("../../Tower_Defense_Game/external/Sprites/battle_field.png");
        battleField.setTexture(shapeBF);
        w=1200;
        h=630;

    }

    private:
        sf::Texture shapeBF;
};

class Base{

    public:
        sf::Sprite base;
        int health;
        int w;
        int h;

    Base(){
        /*Загружаем базу,которую нужно будет оборонять.*/
        /*Также указываем её позицию на карте*/
        imageB.loadFromFile("../../Tower_Defense_Game/external/Sprites/Base.png");
        imageB.createMaskFromColor(sf::Color::White);
        shapeB.loadFromImage(imageB);

        base.setTexture(shapeB);
        base.setPosition(500,300);
        w=130;
        h=144;
        health=200;
    }

    private:
        sf::Image imageB;
        sf::Texture shapeB;
};

class Hero{

    public:
        sf::Sprite hero;
        int h;
        int w;
        int health;

    Hero(){
        heroImage.loadFromFile("../../Tower_Defense_Game/external/Sprites/hero.png");
        heroImage.createMaskFromColor(sf::Color(255,255,255));
        heroTexture.loadFromImage(heroImage);
        hero.setTexture(heroTexture);
        hero.setPosition(200,200);
        h=63;
        w=62;
        hero.setTextureRect(sf::IntRect(0,0,w,h));

        health =100;


    }

    private:
        sf::Texture heroTexture;
        sf::Image heroImage;

};

#endif // GAME_OBJECTS_H
