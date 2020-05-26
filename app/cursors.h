#ifndef CURSORS_H
#define CURSORS_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Cursors
{
public:

    /*храним кастомный курсор*/
    sf::Sprite cursore;

    /*Конструктор*/
    /*Получает название курсора,который нужно отображать*/
    Cursors(std::string typeCrs ){

        /*курсор-прицел*/
       if(typeCrs=="aim"){
         pict.loadFromFile("../../Tower_Defense_Game/external/Sprites/aim.png");

         /*обычный кастомный курсор*/
       }else if(typeCrs=="normal"){
         pict.loadFromFile("../../Tower_Defense_Game/external/Sprites/cursor.png");

         /*если была введена некорректная конструкция,то выводим предупреждающее сообщение*/
       }else{
           std::cout<<"Not correct typeCrs in construcor Cursors"<<std::endl;
           exit(1);
       }
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
