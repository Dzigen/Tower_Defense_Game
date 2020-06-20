#ifndef CURSORS_H
#define CURSORS_H

#include <SFML/Graphics.hpp>

class Cursors{

    public:

        /*храним кастомный курсор*/
        sf::Sprite cursore;

    Cursors(){

        /*обычный кастомный курсор*/
        pict.loadFromFile("../../Tower_Defense_Game/external/Sprites/cursor.png");

        /*ставим прозрачность белых пискселей*/
        pict.createMaskFromColor(sf::Color(255,255,255));

        /*загружаем в спрайт полученную картинку*/
        shape.loadFromImage(pict);
        cursore.setTexture(shape);
    }

    private:

        sf::Image pict;
        sf::Texture shape;

};

#endif // CURSORS_H
