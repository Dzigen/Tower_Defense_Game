#ifndef MOUSE_CLICK_H
#define MOUSE_CLICK_H

#include<SFML/Graphics.hpp>
#include "menu_bar.h"
#include "tool_bar.h"
#include "cursors.h"
#include "game_objects.h"

bool pause_menu(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,Cursors &cursor, GameObject &object,sf::Clock &globalTime);


#endif // MOUSE_CLICK_H
