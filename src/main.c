#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/physic.h"
#include "../headers/talk.h"
#include "../headers/talkbis.h"

int main(){
    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    start_color();
    nodelay(stdscr,TRUE);
    keypad(stdscr,TRUE);
    curs_set(0);

    if(has_colors()==FALSE){
        printf("Your terminal does not support colors");
        exit(1000);
    }

    if(can_change_color()==FALSE){
        printf("Your terminal does not support color changing");
        exit(1000);
    }

    //set fullscreen if not already set
    if (LINES<63 || COLS<236)
    {
        system("xdotool key FN+F11"); //sudo apt install xdotool
    }  

    //63 = 63 , 236 = 236

    //launch music
    system("cvlc ressources/Main-Theme.mp3 >/dev/null 2>&1 &");  // sudo apt_get install vlc

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
    system("killall -9 vlc >/dev/null 2>&1 &");
    endwin();
    return 0;
}