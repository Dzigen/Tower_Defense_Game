#ifndef GAME_PROCESS_H
#define GAME_PROCESS_H

#include <SFML/Graphics.hpp>

#include "cursors.h"
#include "menu_bar.h"
#include "tool_bar.h"
#include "game_objects.h"

void game_draw(sf::RenderWindow &window,MenuBar &upperParametr,ToolBar &lowerParametr ,GameObject &object);

void move_hero(GameObject &object ,float time,int flag);

bool mouse_click(MenuBar &menubar,ToolBar &toolbar,GameObject &object,sf::Clock &globalTime,Cursors &cursor,sf::RenderWindow &window);

void update_spawn_rune(GameObject &object,ToolBar &toolbar,float &runeUPDATEtime,float &time,std::minstd_rand &simple_rand);

void take_rune(GameObject &object,ToolBar &toolbar,MenuBar &menubar);

#endif // GAME_PROCESS_H
