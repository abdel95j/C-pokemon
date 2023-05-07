#ifndef TALK_H
#define TALK_H

void talkto_cashier(WINDOW* shop_map, trainer* player);
void talkto_mom(WINDOW* house_map, trainer* player);
void talkto_prof(WINDOW* lab_map, trainer* player);
void write_flush(WINDOW* win, int x, int y, char phrase[]);
void change_poke(WINDOW* in,trainer* player,int* xin,int* yin,int whatpoke);
void computer(trainer* player);
#endif