#ifndef PHYSIC_H
#define PHYSIC_H
#include "structs.h"
#include <curses.h>

void physic_house(int ch, int* x, int* y);
void physic_map(int ch, int* l, int* c);
void physic_inventory(int ch, int* x, int* y);
void physic_menu(int chmenu, int* x);
void physic_get_firstpoke(int ch, int* y);
void physic_shop(int ch, int* x, int* y);
void physic_roadto_league(int ch, int* l, int* c);
void physic_lab(int ch, int* x, int* y);
void physic_yourteam(int ch,int*x,int*y);
void physic_league(int ch, int* x, int* y);


#endif