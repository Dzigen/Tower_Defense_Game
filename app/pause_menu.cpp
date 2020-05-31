#include "pause_menu.h"

bool pause_menu(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,Cursors &cursor, GameObject &object,sf::Clock &globalTime)
{


    lowerParametr.add_to_time(globalTime);

    bool exitFlag=false;
    int numButton;
    bool loopflag = true;

    while(loopflag){

        numButton=0;

        /*получаем координаты курсора мыши, для отрисовки в этой позиции кастомного курсора*/
        sf::Vector2i Mouse = sf::Mouse::getPosition(window);
        cursor.cursore.setPosition(Mouse.x,Mouse.y);

        upperParametr.ContinueText.setFillColor(sf::Color::White);
        upperParametr.ExitText.setFillColor(sf::Color::White);

        /*Если мышь была наведена на одну из кнопок, то меняем цвет текста соответствующей кнопки на чёрный.*/
        /*Также в переменную NumMenu записываем номер кнопки, на которую навели мышь*/
        if (sf::IntRect(20, 96, 260,60 ).contains(sf::Mouse::getPosition(window)))
        {
             upperParametr.ContinueText.setFillColor(sf::Color::Black);
             numButton=1;
        }
        if (sf::IntRect(20, 166, 260,60 ).contains(sf::Mouse::getPosition(window)))
        {
            upperParametr.ExitText.setFillColor(sf::Color::Black);
            numButton=2;
        }

        /*Если была нажата левая кнопка мыши,*/
        /*то проверяем:была ли она нажата в области одной из кнопок*/
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (numButton == 1)
            {
                loopflag = false;
            }
            if (numButton == 2)
            {
                loopflag = false;
                exitFlag = true;
            }
        }

        game_draw(window,upperParametr,lowerParametr,object);
        window.draw(upperParametr.PauseMenu);

        window.draw(upperParametr.PauseMenuButtonContinue);
        window.draw(upperParametr.PauseMenuButtonExit);

        window.draw(upperParametr.ContinueText);
        window.draw(upperParametr.ExitText);

        window.draw(cursor.cursore);
        window.display();
    }

    lowerParametr.reset_clock(globalTime);

    return exitFlag;
}
