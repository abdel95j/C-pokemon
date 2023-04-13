#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"

int main(){
    initscr();
    noecho();
    cbreak();
    start_color();
    nodelay(stdscr,TRUE);
    keypad(stdscr,TRUE);
    curs_set(0);

    if(has_colors()==FALSE){
        printf("Your terminal does not support colors");
        exit(1);
    }

    if(can_change_color()==FALSE){
        printf("Your terminal does not support color changing");
        exit(1);
    }


    int exit=0,x,y;

    x=LINES/2-1;
    y=COLS/2;

    while (exit==0)
    {
        game(&exit,&x,&y);
    }
    
    endwin();
    return 0;
}