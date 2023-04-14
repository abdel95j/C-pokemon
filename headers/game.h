#ifndef GAME_H
#define GAME_H
#include "structs.h"
#include <curses.h>

void printplayer(WINDOW* win,double x,double y);
void game(int* exit,double* x,double* y);
void menu(int* exit);

#endif