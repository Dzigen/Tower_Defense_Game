#include "game_process.h"

void game_process(sf::RenderWindow &window, Cursors &cursor){

;
    GameObjects object;
    MenuBar upperParametr;
    ToolBar lowerParametr;

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
                //exitFlag=pause_menu(window,upperParametr,lowerParametr,object,cursor);
                /*если true, то была нажата кнопка "выход в главное меню"*/
                if(exitFlag)
                    break;
            }

        /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
        sf::Vector2i Mouse = sf::Mouse::getPosition(window);
        cursor.cursore.setPosition(Mouse.x,Mouse.y);

        /*отрисовываем элементы в окне*/
        game_draw(window,upperParametr,lowerParametr,object,cursor);
        window.display();
    }


}
