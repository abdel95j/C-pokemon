#ifndef PRINT_H
#define PRINT_H
#include "structs.h"
#include "game.h"
#include <curses.h>

void print_player(WINDOW* win);
void print_menu(WINDOW* win,int x,int y);
void create_map(WINDOW* map);
void print_inventory(WINDOW* sac,int x, int y);
void print_main_menu(WINDOW* win,int x,int y);
void print_newtrainer(WINDOW* chat);
void print_get_firstpoke(WINDOW* win,int x,int y);
void chargement();

#endif