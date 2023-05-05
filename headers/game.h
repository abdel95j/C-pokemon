#ifndef GAME_H
#define GAME_H
#include "structs.h"
#include <curses.h>

void game(int* quit,int* l, int* c);
void main_menu(trainer* player,int* quit,int* x,int* y);
void menu(int* quit);
void create_newplayer(trainer* newplayer);
void get_firstpoke(trainer* player);
void house(trainer* player);
void init_poke(pokemon* pokenull, pokemon* charmander, pokemon* bulbasaur, pokemon* squirtle);

#endif