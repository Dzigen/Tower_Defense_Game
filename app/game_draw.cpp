#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObject &object){

    /*отрисовываем элементы в окне*/
    window.clear();

    /*игровое поле и его объекты*/
    window.draw(object.map.sprite);
    window.draw(object.base.sprite);
    window.draw(object.rune.coin.sprite);
    window.draw(object.rune.hp_base.sprite);
    window.draw(object.rune.hp_hero.sprite);
    window.draw(object.rune.double_damage.sprite);
    window.draw(object.hero.sprite);
    window.draw(object.base.base_roof);


    /*меню бар с его датчиками*/
    window.draw(upperParametr.menubarline);

    window.draw(upperParametr.pauseButton);
    window.draw(upperParametr.pauseButtonText);

    /*тул бар с его датчиками*/
    window.draw(lowerParametr.toolbarline);

    window.draw(lowerParametr.timer);
    window.draw(lowerParametr.iconClock);

    window.draw(lowerParametr.hp_hero_red);
    window.draw(lowerParametr.hp_hero_green);
    window.draw(lowerParametr.textHHP);
    window.draw(lowerParametr.iconHPhero);
    window.draw(lowerParametr.valueHHPof);

    window.draw(lowerParametr.hp_base_red_orange);
    window.draw(lowerParametr.hp_base_green);
    window.draw(lowerParametr.textBHP);
    window.draw(lowerParametr.iconHPbase);
    window.draw(lowerParametr.valueBHPof);


}
