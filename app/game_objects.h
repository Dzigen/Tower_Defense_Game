#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>

class GameObject{
    public:
        class Map{

           public:
                 sf::Sprite sprite;
                   int w;
                   int h;

            Map(){

                    /*загружаем игровую карту*/
                    shapeBF.loadFromFile("../../Tower_Defense_Game/external/Sprites/battle_field.png");
                    sprite.setTexture(shapeBF);
                    w=1200;
                    h=630;

            }

            private:
                    sf::Texture shapeBF;
            };

        class Base{

             public:

                    sf::Sprite sprite;
                    sf::Sprite base_roof;
                    int health;
                    int box_x;
                        int box_y;
                    int w;
                    int h;

              Base(){
                    /*Загружаем базу,которую нужно будет оборонять.*/
                    /*Также указываем её позицию на карте*/
                    imageB.loadFromFile("../../Tower_Defense_Game/external/Sprites/Base.png");
                    imageB.createMaskFromColor(sf::Color::White);
                    shapeB.loadFromImage(imageB);

                    sprite.setTexture(shapeB);
                    sprite.setPosition(500,300);
                    box_x=514;
                    box_y=317;
                    w=122;
                    h=107;
                    health=200;

                    imageBR.loadFromFile("../../Tower_Defense_Game/external/Sprites/Base_roof.png");
                    imageBR.createMaskFromColor(sf::Color::White);
                    shapeBR.loadFromImage(imageBR);
                    base_roof.setTexture(shapeBR);
                    base_roof.setPosition(526,300);
             }

             private:
                    sf::Image imageB;
                    sf::Texture shapeB;

                    sf::Image imageBR;
                    sf::Texture shapeBR;

             };

        class Hero{

             public:
                   sf::Sprite sprite;
                   int h;
                   int w;
                   int health;

                   int gun_deirection;
                   int pos_gun_dir_x;
                   int pos_gin_dir_y;


             Hero(){
                   heroImage.loadFromFile("../../Tower_Defense_Game/external/Sprites/hero.png");
                   heroImage.createMaskFromColor(sf::Color(255,255,255));
                   heroTexture.loadFromImage(heroImage);
                   sprite.setTexture(heroTexture);
                   sprite.setPosition(200,200);
                   h=63;
                   w=62;
                   sprite.setTextureRect(sf::IntRect(0,0,w,h));

                  health =100;


             }

                 private:
                     sf::Texture heroTexture;
                     sf::Image heroImage;
        };

        class Runes{
                public:

                    class Hp_hero{
                        public:
                            sf::Sprite sprite;
                            int w;
                            int h;
                            int frames;
                            int current_frame;
                            int regenHP;

                        Hp_hero(){
                            iconHPH.loadFromFile("../../Tower_Defense_Game/external/Sprites/rune_hp_hero.png");
                            iconHPH.createMaskFromColor(sf::Color::White);
                            shapeHPH.loadFromImage(iconHPH);
                            sprite.setTexture(shapeHPH);

                            w=53;
                            h=50;
                            frames=5;
                            current_frame=0;
                            regenHP=5;

                            sprite.setTextureRect(sf::IntRect(0,0,w,h));
                        }

                        private:
                            sf::Image iconHPH;
                            sf::Texture shapeHPH;
                    };


                    class Hp_base{
                        public:
                            sf::Sprite sprite;
                            int w;
                            int h;
                            int frames;
                            int current_frame;
                            int regenHP;

                        Hp_base(){
                            iconHPB.loadFromFile("../../Tower_Defense_Game/external/Sprites/rune_hp_base.png");
                            iconHPB.createMaskFromColor(sf::Color::White);
                            shapeHPB.loadFromImage(iconHPB);
                            sprite.setTexture(shapeHPB);

                            w=53;
                            h=50;
                            frames=5;
                            current_frame=0;
                            regenHP=10;

                            sprite.setTextureRect(sf::IntRect(0,0,w,h));
                        }

                        private:
                            sf::Image iconHPB;
                            sf::Texture shapeHPB;
                    };

                    class Plus_damage{
                        public:
                            sf::Sprite sprite;
                            int w;
                            int h;
                            int frames;
                            int current_frame;
                            int addedDamage;

                        Plus_damage(){
                            iconDD.loadFromFile("../../Tower_Defense_Game/external/Sprites/rune_plus_damage.png");
                            iconDD.createMaskFromColor(sf::Color(255,0,0));
                            shapeDD.loadFromImage(iconDD);
                            sprite.setTexture(shapeDD);

                            w=47;
                            h=47;
                            frames=10;
                            addedDamage=5;

                            sprite.setTextureRect(sf::IntRect(0,0,w,h));
                        }

                        private:
                            sf::Image iconDD;
                            sf::Texture shapeDD;
                    };



                    class Coin{
                        public:
                            sf::Sprite sprite;
                            int w;
                            int h;
                            int frames;
                            int current_frame;

                        Coin(){
                            iconC.loadFromFile("../../Tower_Defense_Game/external/Sprites/rune_point.png");
                            iconC.createMaskFromColor(sf::Color(0,255,0));
                            shapeC.loadFromImage(iconC);
                            sprite.setTexture(shapeC);

                            w=47;
                            h=47;
                            frames=10;
                            current_frame=0;

                            sprite.setTextureRect(sf::IntRect(0,0,w,h));
                        }

                        private:
                            sf::Image iconC;
                            sf::Texture shapeC;

                    };

                    void update_frame(int type){

                        int* current_frame=0;
                        int frames=0;
                        int rune_w=0;
                        int rune_h=0;
                        sf::Sprite* rune_sprite;

                        if(type==0){
                             current_frame=&hp_base.current_frame;
                             frames=hp_base.frames;
                             rune_w=hp_base.w;
                             rune_h=hp_base.h;
                             rune_sprite=&hp_base.sprite;

                        }else if(type==1){
                             current_frame=&hp_hero.current_frame;
                             frames=hp_hero.frames;
                             rune_w=hp_hero.w;
                             rune_h=hp_hero.h;
                             rune_sprite=&hp_hero.sprite;

                        }else if(type==2){
                             current_frame=&plus_damage.current_frame;
                             frames=plus_damage.frames;
                             rune_w=plus_damage.w;
                             rune_h=plus_damage.h;
                             rune_sprite=&plus_damage.sprite;

                        }else if(type==3){
                            current_frame=&coin.current_frame;
                            frames=coin.frames;
                            rune_w=coin.w;
                            rune_h=coin.h;
                            rune_sprite=&coin.sprite;

                        }else{
                            std::cout<<"Введён некорректный тип руны"<<std::endl;
                            exit(1);
                        }
                            (*current_frame)++;

                            if((*current_frame)>=frames){
                                (*current_frame)=0;
                                rune_sprite->setTextureRect(sf::IntRect(0,0,rune_w,rune_h));
                            }else{
                                rune_sprite->setTextureRect(sf::IntRect(rune_w*(*current_frame),0,rune_w,rune_h));
                            }
                    }

                    Hp_hero hp_hero;
                    Hp_base hp_base;
                    Plus_damage plus_damage;
                    Coin coin;
   };

        Map map;
        Base base;
        Hero hero;
        Runes rune;
};

#endif // GAME_OBJECTS_H
