#include "game_process.h"

void game_process(sf::RenderWindow &window, Cursors &cursor){

    MenuBar upperParametr;
    ToolBar lowerParametr;
    GameObject object;

    bool inBtnField;
    bool exitFlag=false;

    sf::Clock globalTime;
    float runeUPDATEtime=0;

    while(true){

        float time = globalTime.getElapsedTime().asMicroseconds();
        globalTime.restart();
        time = time / 800;

        inBtnField = false;
        upperParametr.pauseButtonText.setColor(sf::Color::White);

        if (sf::IntRect(7, 7, 40,40 ).contains(sf::Mouse::getPosition(window))){
             upperParametr.pauseButtonText.setColor(sf::Color::Black);
             inBtnField = true;
        }

        /*Если была нажата левая кнопка мыши,*/
        /*то проверяем:была ли она нажата в области кнопки "Пауза"*/
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            if (inBtnField){
                /*получаем знак о нажатой кнопке меню "Пауза"*/
                exitFlag=pause_menu(window,upperParametr,lowerParametr,cursor,object);
                /*если true, то была нажата кнопка "выход в главное меню"*/
                if(exitFlag)
                    break;
            }

        /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
        sf::Vector2i Mouse = sf::Mouse::getPosition(window);
        cursor.cursore.setPosition(Mouse.x,Mouse.y);

        runeUPDATEtime+=time;
        if(runeUPDATEtime>250){
            runeUPDATEtime=0;
            object.rune.update_frame("hp_hero");
            object.rune.update_frame("hp_base");
            object.rune.update_frame("double_damage");
            object.rune.update_frame("coin");
        }

        /*двигаем главного героя ,если были нажати клавиши управления*/
        move_hero(object,time);


        /*отрисовываем элементы в окне*/
        lowerParametr.get_time();
        game_draw(window,upperParametr,lowerParametr,object);
        window.draw(cursor.cursore);
        window.display();
    }


}
