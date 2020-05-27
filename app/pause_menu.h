#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObjects &object,Hero &tank);

#endif // PAUSE_MENU_H
