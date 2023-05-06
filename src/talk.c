#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/physic.h"

void talkto_cashier(WINDOW* shop_map, trainer* player){
    int finish=0,ch=ERR;

    while(finish==0)
    {
        WINDOW* buy_stuff=subwin(shop_map,15,20,27,44);
        box(buy_stuff,0,0);

        mvwprintw(shop_map,15,37,"Hello, what do you want");
        mvwprintw(shop_map,16,37,"to buy today ?");

        ch=getch();
        wrefresh(shop_map);
        
        usleep(16667);
        if (delwin(buy_stuff)==ERR)
        {
            exit(23);
        }
        
    }

}