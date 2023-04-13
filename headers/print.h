#ifndef PRINT_H
#define PRINT_H
#include "structs.h"
#include "game.h"
#include <curses.h>

void print_player(WINDOW* win,double x,double y);
void print_menu(WINDOW* win,double x,double y);
void print_map(WINDOW* map);

#endif