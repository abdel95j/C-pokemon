#ifndef GAME_H
#define GAME_H
#include "structs.h"
#include <curses.h>

void game(trainer* player, int* quit,int* l, int* c);
void main_menu(trainer* player,int* quit,int* x,int* y);
void menu(int* quit, trainer* player);
void create_newplayer(trainer* newplayer);
void get_firstpoke(trainer* player);
void house(trainer* player);
void init_poke(pokemon* pokenull, pokemon* charmander, pokemon* bulbasaur, pokemon* squirtle);
void shop(trainer* player);
void roadto_league(trainer* player);
void lab(trainer* player);
void inventory(trainer* player);
void league(trainer* player);
void duel(trainer* player, trainer champion);
void your_team(trainer* player);

#endif