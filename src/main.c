#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"

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

    //set fullscreen if not already set
    if (LINES== 59 || LINES<63 && COLS<236)
    {
        system("xdotool key F11"); //sudo apt install xdotool
    }  

    int exit=0;
    int x,y;

    x=0;
    y=0;

    while (exit==0)
    {
        game(&exit,&x,&y);
    }
    
    endwin();
    return 0;
}