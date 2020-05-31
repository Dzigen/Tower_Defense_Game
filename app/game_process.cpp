#include "game_process.h"

void game_process(sf::RenderWindow &window, Cursors &cursor){

    MenuBar upperParametr;
    ToolBar lowerParametr;
    GameObject object;

    bool inBtnField;
    bool exitFlag=false;

    sf::Clock globalTime;

    sf::Clock gameTime;
    float runeUPDATEtime=0;

    lowerParametr.change_hero_base_hp("hero","damaging",50,object.hero.health);
    lowerParametr.change_hero_base_hp("base","damaging",120,object.base.health);

    while(true){


        float time = gameTime.getElapsedTime().asMicroseconds();
        gameTime.restart();
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
                exitFlag=pause_menu(window,upperParametr,lowerParametr,cursor,object,globalTime);
                /*если true, то была нажата кнопка "выход в главное меню"*/
                if(exitFlag)
                    break;
            }

        /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
        sf::Vector2i Mouse = sf::Mouse::getPosition(window);
        cursor.cursore.setPosition(Mouse.x,Mouse.y);


        /*двигаем главного героя ,если были нажати клавиши управления*/
        move_hero(object,time);

        /*если на карте есть заспавненная руна, то обрабатываем её взаимодействие с героем*/
        if(lowerParametr.typeRandomedRune!=-1)
            take_rune(object,lowerParametr,upperParametr);

        /*обновляем игровой таймер*/
        lowerParametr.get_time(globalTime);

        /*если прошло 10 минут,то начинается следующий раунд*/
        upperParametr.check_for_next_round(globalTime);

        /*если прошло 60 секунд то выбираем случайные координаты для новой случайной руны*/
        if(lowerParametr.randomizeCoordinates){
            randomizeRuneCoordinates(object,lowerParametr);
        }else{
            /*иначе продолжаем выводить текущую руну на игровом поле*/
            runeUPDATEtime+=time;
            if(runeUPDATEtime>250){
                runeUPDATEtime=0;
                if(lowerParametr.typeRandomedRune==0)
                    object.rune.update_frame(0);
                else if(lowerParametr.typeRandomedRune==1)
                    object.rune.update_frame(1);
                else if(lowerParametr.typeRandomedRune==2)
                    object.rune.update_frame(2);
                else if(lowerParametr.typeRandomedRune==3)
                    object.rune.update_frame(3);
             }
        }

        /*отрисовываем элементы в окне*/
        game_draw(window,upperParametr,lowerParametr,object);
        window.draw(cursor.cursore);
        window.display();
    }


}
