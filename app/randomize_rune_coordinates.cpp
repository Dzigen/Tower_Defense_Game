#include <game_objects.h>
#include <tool_bar.h>
#include <random>



void randomizeRuneCoordinates(GameObject &object,ToolBar &toolbar,std::minstd_rand &simple_rand){
    int x,y;

    int w=1200-object.rune.hp_hero.w;
    int h=630-object.rune.hp_hero.h;

    /*случайным образом получаем координаты точки на карте игрового процесса*/
    x=simple_rand()%w;
    y=((simple_rand()%h)+55);

    /*присваеваем их требуемой руне*/
    switch (toolbar.typeRandomedRune) {
        case 0:{object.rune.hp_base.sprite.setPosition(x,y); break;}
        case 1:{object.rune.hp_hero.sprite.setPosition(x,y); break;}
        case 2:{object.rune.plus_damage.sprite.setPosition(x,y); break;}
        case 3:{object.rune.coin.sprite.setPosition(x,y); break;}
        default:{toolbar.typeRandomedRune=-1; break;}
    }

    /*процесс получения параметров для спавна руны завершён*/
    toolbar.randomizeCoordinates=false;

}
