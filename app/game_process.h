#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include <SFML/Graphics.hpp>

#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObject &object);

bool pause_menu(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,Cursors &cursor, GameObject &object,sf::Clock &globalTime);

void move_hero(GameObject &object ,float time);

void randomizeRuneCoordinates(GameObject &object,ToolBar &toolbar);

void take_rune(GameObject &object,ToolBar &toolbar,MenuBar &menubar);

#endif // GAME_PROCESS_H
