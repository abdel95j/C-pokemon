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
void init_poke(pokemon* pokenull, pokemon* charmander, pokemon* bulbasaur, pokemon* squirtle,pokemon* pikachu, pokemon* charizard,pokemon* blastoise,pokemon* venusaur,pokemon* raichu);
void shop(trainer* player);
void forest(trainer* player);
void roadto_league(trainer* player);
void lab(trainer* player);
void inventory(trainer* player);
void league(trainer* player);
int duel(WINDOW* league_map,trainer* player, trainer champion);
int match(trainer* player,pokemon* player_poke, pokemon* champion_poke, int League0_Catch1, int* count_atk);
void pokelvlup(WINDOW* win,int x,int y,int times, pokemon* player_poke);
void silent_pokelvlup(int times, pokemon* player_poke);
void your_team(trainer* player);
void clignotement(WINDOW* fenetre);
void duel_forest(trainer * player,pokemon wild_poke);
void playerlvlup(trainer* player);
void evolvepoke(pokemon* poke);
void silent_evolvepoke(pokemon* poke);
void encounter_poke(WINDOW* forest_map, trainer* player);
void save(trainer* player);
int load(trainer* player);

#endif