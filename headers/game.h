#ifndef GAME_H
#define GAME_H
#include "structs.h"
#include <curses.h>

void printplayer(WINDOW* win,int x,int y);
void game(int* exit,int* x,int* y);
void menu();

#endif