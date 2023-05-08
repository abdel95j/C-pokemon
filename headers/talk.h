#ifndef TALK_H
#define TALK_H

void talkto_cashier(WINDOW* shop_map, trainer* player);
void talkto_mom(WINDOW* house_map, trainer* player);
void write_flush(WINDOW* win, int x, int y, char phrase[]);
#endif