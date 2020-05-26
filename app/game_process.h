#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include <SFML/Graphics.hpp>

#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObjects &object,Cursors &cursor);

bool pause_menu(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObjects &object,Cursors &cursor);

#endif // GAME_PROCESS_H
