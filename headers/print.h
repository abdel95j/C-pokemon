#ifndef PRINT_H
#define PRINT_H
#include "structs.h"
#include "game.h"
#include <curses.h>

void print_player(WINDOW* win,trainer* player);
void print_menu(WINDOW* win,int x,int y);
void create_map(WINDOW* map,trainer* player);
void print_inventory(WINDOW* sac,trainer* player,int x, int y);
void print_main_menu(WINDOW* win,int x,int y);
void print_newtrainer(WINDOW* chat);
void print_get_firstpoke(WINDOW* win,int x,int y);
void print_house(WINDOW* house_map, int x, int y);
void print_shop(WINDOW*shop_map,int x, int y);
void print_lab(WINDOW*lab_map,int x, int y);
void print_forest(WINDOW*forest_map,int x, int y);
void print_poke(WINDOW* win,pokemon poke,int x, int y,int FRONT0_BACK1);
void print_roadto_league(WINDOW* road);
void print_computer_connect(WINDOW* pc, trainer* player);
void print_yourteam( WINDOW* box1,WINDOW* box2,WINDOW* box3,WINDOW* box4,WINDOW* box5,WINDOW* box6,trainer* player, int x,int y);
void print_league(WINDOW* league_map,int x,int y,trainer champion);
void print_match(WINDOW* match,WINDOW* jauge_champion, WINDOW*jauge_player, pokemon player_poke, pokemon champion_poke,int x, int y);
void print_art_yourteam(WINDOW* yourteam,trainer player,int whatpoke);
void jauges_refresh(WINDOW* match,WINDOW* jauge_player,WINDOW* jauge_champion,pokemon player_poke,pokemon champion_poke);
void print_evolution(WINDOW* evolve_win, pokemon poke, pokemon evolution);
void cinematique_rock(WINDOW* map, WINDOW* cam, trainer* player);
void breaktherock(WINDOW*map,WINDOW*cam,trainer* player);
void print_save(WINDOW* win,FILE* save1,FILE* save2,FILE* save3,FILE* save4,FILE* save5,int x);
void print_load(WINDOW* win,FILE* save1r,FILE* save2r,FILE* save3r,FILE* save4r,FILE* save5r,int x);
void chargement();

#endif