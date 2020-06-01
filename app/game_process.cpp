#include "game_process.h"
#include <random>

void game_process(sf::RenderWindow &window, Cursors &cursor){

    MenuBar upperParametr;
    ToolBar lowerParametr;
    GameObject object;

    bool gameRun=true;

    sf::Clock globalTime;

    sf::Clock gameTime;
    float runeUPDATEtime=0;

    std::minstd_rand simple_rand;

    while(gameRun){

        float time = gameTime.getElapsedTime().asMicroseconds();
        gameTime.restart();
        time = time / 800;

        /*проверяем:где была нажата левая кнопка мыши*/
        gameRun=mouse_click(upperParametr,lowerParametr,object,globalTime,cursor,window);

        /*двигаем главного героя ,если были нажати клавиши управления*/
        move_hero(object,time);

        /*если на карте есть заспавненная руна, то обрабатываем её взаимодействие с героем*/
        if(lowerParametr.typeRandomedRune!=-1)
            take_rune(object,lowerParametr,upperParametr);

        /*обновляем игровой таймер*/
        lowerParametr.get_time(globalTime,simple_rand);

        /*если прошло 10 минут,то начинается следующий раунд*/
        upperParametr.check_for_next_round(globalTime);

        /*производим анимацию руны или её появление на карте*/
        update_spawn_rune(object,lowerParametr,runeUPDATEtime,time,simple_rand);

        /*отрисовываем элементы в окне*/
        game_draw(window,upperParametr,lowerParametr,object);
        window.draw(cursor.cursore);
        window.display();
    }


}
