#include <game_objects.h>
#include <tool_bar.h>
#include <random>


void randomizeRuneCoordinates(GameObject &object,ToolBar &toolbar){

    std:: minstd_rand simple_rand;

    int x=simple_rand();
    int y=simple_rand();

    x=x%(1200-object.rune.hp_hero.w);
    y=((y%(630-object.rune.hp_hero.h))+toolbar.toolbarline.getScale().y);

    if(toolbar.typeRandomedRune==0)
        object.rune.hp_base.sprite.setPosition(x,y);
    else if(toolbar.typeRandomedRune==1)
        object.rune.hp_hero.sprite.setPosition(x,y);
    else if(toolbar.typeRandomedRune==2)
        object.rune.plus_damage.sprite.setPosition(x,y);
    else if(toolbar.typeRandomedRune==3)
        object.rune.coin.sprite.setPosition(x,y);

    toolbar.randomizeCoordinates=false;

}
