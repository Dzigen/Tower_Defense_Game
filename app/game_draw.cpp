#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,Map &map,Hero &tank,Base &base){

    /*отрисовываем элементы в окне*/
    window.clear();

    /*игровое поле и его объекты*/
    window.draw(map.battleField);
    window.draw(base.base);
    window.draw(tank.hero);



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
    window.draw(lowerParametr.valueHHPof);

    window.draw(lowerParametr.hp_base_red_orange);
    window.draw(lowerParametr.hp_base_green);
    window.draw(lowerParametr.textBHP);
    window.draw(lowerParametr.valueBHPof);


}
