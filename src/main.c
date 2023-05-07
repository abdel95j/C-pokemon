#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/physic.h"
#include "../headers/talk.h"

int main(){
    initscr();
    cbreak();
    noecho();
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

    //launch music
    system("cvlc ../ressources/Main-Theme.mp3 &");  // sudo aapt_get install vlc

    // INIT COLOR PAIR FOR WATTR
    init_pair(1,COLOR_RED,COLOR_BLACK);     // red = 1
    init_pair(2,COLOR_MAGENTA,COLOR_BLACK); // magenta = 2
    init_pair(3,COLOR_YELLOW,COLOR_BLACK);  // yellow = 3
    init_pair(4,COLOR_BLUE,COLOR_BLACK);    // blue = 4
    init_pair(5,COLOR_GREEN,COLOR_BLACK);    // green = 5


    int quit=0,exitmenu=0;
    int l=52,c=130; //position caméra
    int x=28,y=8; //position curseur menu principal

    trainer player;

    while (quit==0)
    {
        while (exitmenu==0)
        {
            main_menu(&player,&exitmenu,&x,&y);
        }

        game(&player,&quit,&l,&c);
    }
    
    //end music
    system("killall -9 vlc");
    endwin();
    return 0;
}