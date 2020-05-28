#include "game_objects.h"
#include <iostream>

void move_hero(Map &map,Base &base,Hero &tank,float time){

    std::cout<<tank.hero.getPosition().y<<std::endl;

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
        tank.hero.setTextureRect(sf::IntRect(0,1*tank.h,tank.w,tank.h));

        if((tank.hero.getPosition().x-(0.2*time))<0){
            tank.hero.setPosition(0,tank.hero.getPosition().y);
        }else{
            if(sf::IntRect(base.base.getPosition().x+base.w, base.base.getPosition().y, map.w-base.base.getPosition().x+base.w, base.h).contains(tank.hero.getPosition().x,tank.hero.getPosition().y+tank.h-10)
                &&((tank.hero.getPosition().x-(base.base.getPosition().x+base.w))<(0.2*time))){

                tank.hero.setPosition((base.base.getPosition().x+base.w),tank.hero.getPosition().y);

            }else{
                tank.hero.move(-0.2*time, 0);
            }
        }
    }else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))){
        tank.hero.setTextureRect(sf::IntRect(0,2*tank.h,tank.w,tank.h));

        if(((tank.hero.getPosition().x+tank.w)+(0.2*time))>map.w){
            tank.hero.setPosition((map.w-tank.w),tank.hero.getPosition().y);
        }else{
            if(sf::IntRect(0, base.base.getPosition().y,(base.base.getPosition().x+18), base.h).contains(tank.hero.getPosition().x,tank.hero.getPosition().y+tank.h-10)
                &&(((base.base.getPosition().x+18)-(tank.hero.getPosition().x+tank.w))<(0.2*time))){

                tank.hero.setPosition(((base.base.getPosition().x+18)-tank.w),tank.hero.getPosition().y);

            }else{
                tank.hero.move(0.2*time, 0);
            }
        }
    }else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) {
        tank.hero.setTextureRect(sf::IntRect(0,3*tank.h,tank.w,tank.h));

        if((tank.hero.getPosition().y-55)<(0.2*time)){
            tank.hero.setPosition(tank.hero.getPosition().x,55);
        }else{
            /*if(){

            }else{*/
                tank.hero.move(0, -0.2*time);
            //}
        }
    }else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) {
        tank.hero.setTextureRect(sf::IntRect(0,0*tank.h,tank.w,tank.h));

        if(((map.h+55)-(tank.hero.getPosition().y+tank.h))<(0.2*time)){
            tank.hero.setPosition(tank.hero.getPosition().x,((map.h+55)-tank.h));
        }else{
            if(sf::IntRect(base.base.getPosition().x,55,base.w,(map.h+55)).contains(tank.hero.getPosition().x,(tank.hero.getPosition().y+tank.h))
            &&((base.base.getPosition().y-(tank.hero.getPosition().y+tank.h))<(0.2*time))){

               // tank.hero.setPosition(tank.hero.getPosition().x,(base.base.getPosition().y-tank.h));
            }else{
                tank.hero.move(0, 0.2*time);
            }
        }
    }
}
