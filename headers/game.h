#ifndef GAME_H
#define GAME_H
#include "structs.h"
#include <curses.h>

void game(int* exit,int* l, int* c);
void main_menu(trainer* player,int* exit,int* x,int* y);
void menu(int* exit);
void create_newplayer(trainer* newplayer);
void get_firstpoke(trainer* player);

#endif