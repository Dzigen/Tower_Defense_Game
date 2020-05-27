#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <SFML/Graphics.hpp>

class GameObjects{

    public:
        sf::Sprite battleField;
        sf::Sprite base;

    GameObjects(){

        /*загружаем игровую карту*/
        shapeBF.loadFromFile("../../Tower_Defense_Game/external/Sprites/battle_field.png");
        battleField.setTexture(shapeBF);

        /*Загружаем базу,которую нужно будет оборонять.*/
        /*Также указываем её позицию на карте*/
        shapeB.loadFromFile("../../Tower_Defense_Game/external/Sprites/Base.png");
        base.setTexture(shapeB);
        base.setPosition(500,300);
    }

    private:
        sf::Texture shapeBF;
        sf::Texture shapeB;
};

class Hero{

    public:
        sf::Sprite hero;
        int h;
        int w;

    Hero(){
        heroImage.loadFromFile("../../Tower_Defense_Game/external/Sprites/hero.png");
        heroImage.createMaskFromColor(sf::Color(255,255,255));
        heroTexture.loadFromImage(heroImage);
        hero.setTexture(heroTexture);
        hero.setPosition(200,200);
        h=64;
        w=64;
        hero.setTextureRect(sf::IntRect(0,0,h,w));

    }

    private:
        sf::Texture heroTexture;
        sf::Image heroImage;

};

#endif // GAME_OBJECTS_H
