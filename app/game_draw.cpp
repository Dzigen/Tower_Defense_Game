#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObjects &object,Cursors &cursor){

    /*отрисовываем элементы в окне*/
    window.clear();

    window.draw(object.battleField);
    window.draw(object.base);

    window.draw(upperParametr.menubarline);
    window.draw(upperParametr.pauseButton);
    window.draw(upperParametr.pauseButtonText);

    window.draw(lowerParametr.toolbarline);

    window.draw(cursor.cursore);
}
