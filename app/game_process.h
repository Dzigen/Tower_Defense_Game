#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include <SFML/Graphics.hpp>

#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,Map &map,Hero &tank,Base &base);

bool pause_menu(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,Map &map,Cursors &cursor,Hero &tank,Base &base);

void move_hero(Map &map,Base &base,Hero &tank,float time);

#endif // GAME_PROCESS_H
