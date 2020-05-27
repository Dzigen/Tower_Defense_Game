#include "game_process.h"

void game_process(sf::RenderWindow &window, Cursors &cursor){

;
    GameObjects object;
    MenuBar upperParametr;
    ToolBar lowerParametr;
    Hero tank;

    bool inBtnField;
    bool exitFlag=false;

    while(true){

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
                exitFlag=pause_menu(window,upperParametr,lowerParametr,object,cursor,tank);
                /*если true, то была нажата кнопка "выход в главное меню"*/
                if(exitFlag)
                    break;
            }

        /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
        sf::Vector2i Mouse = sf::Mouse::getPosition(window);
        cursor.cursore.setPosition(Mouse.x,Mouse.y);

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
            tank.hero.setTextureRect(sf::IntRect(0,1*tank.h,tank.w,tank.h));
            tank.hero.move(-5, 0);
        }else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))){
            tank.hero.setTextureRect(sf::IntRect(0,2*tank.h,tank.w,tank.h));
            tank.hero.move(5, 0);
        }else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) {
            tank.hero.setTextureRect(sf::IntRect(0,3*tank.h,tank.w,tank.h));
            tank.hero.move(0, -5);
        }else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) {
            tank.hero.setTextureRect(sf::IntRect(0,0*tank.h,tank.w,tank.h));
            tank.hero.move(0, 5);
        }



        /*отрисовываем элементы в окне*/
        lowerParametr.get_time();
        game_draw(window,upperParametr,lowerParametr,object,tank);
        window.draw(cursor.cursore);
        window.display();
    }


}
