#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"

int main(){
    initscr();
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
        system("xdotool key FN+F11"); //sudo apt install xdotool
    }  

    int exit=0;
    int l=0,c=0;

    while (exit==0)
    {
        game(&exit,&l,&c);

    }
    
    endwin();
    return 0;
}