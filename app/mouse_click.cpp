#include "mouse_click.h"

bool mouse_click(MenuBar &menubar,ToolBar &toolbar,GameObject &object,sf::Clock &globalTime,Cursors &cursor,sf::RenderWindow &window){

    bool inBtnField;
    bool runFlag=true;

    inBtnField = false;
    menubar.pauseButtonText.setColor(sf::Color::White);

    if (sf::IntRect(menubar.pauseButton.getPosition().x, menubar.pauseButton.getPosition().y, menubar.w,menubar.h ).contains(sf::Mouse::getPosition(window))){
        menubar.pauseButtonText.setColor(sf::Color::Black);
        inBtnField = true;
    }

    /*Если была нажата левая кнопка мыши,*/
    /*то проверяем:была ли она нажата в области кнопки "Пауза"*/
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        if (inBtnField){
            /*получаем знак о нажатой кнопке меню "Пауза"*/
            runFlag=pause_menu(window,menubar,toolbar,cursor,object,globalTime);
        }

    /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
    sf::Vector2i Mouse = sf::Mouse::getPosition(window);
    cursor.cursore.setPosition(Mouse.x,Mouse.y);

        return runFlag;
}
