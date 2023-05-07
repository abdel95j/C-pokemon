#ifndef PRINT_H
#define PRINT_H
#include "structs.h"
#include "game.h"
#include <curses.h>

void print_player(WINDOW* win,trainer* player);
void print_menu(WINDOW* win,int x,int y);
void create_map(WINDOW* map);
void print_inventory(WINDOW* sac,trainer* player,int x, int y);
void print_main_menu(WINDOW* win,int x,int y);
void print_newtrainer(WINDOW* chat);
void print_get_firstpoke(WINDOW* win,int x,int y);
void print_house(WINDOW* house_map, int x, int y);
void print_shop(WINDOW*shop_map,int x, int y);
void print_lab(WINDOW*lab_map,int x, int y);
void print_roadto_league(WINDOW* road);
void print_computer_connect(WINDOW* pc, trainer* player);
void chargement();

#endif