#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"

void printplayer(WINDOW* win,int x,int y){
    init_pair(1,COLOR_RED,COLOR_BLACK);
    wattron(win,COLOR_PAIR(1));
    wprintw(win,"o");
    wmove(win,x+1,y-1);
    wprintw(win,"/0\\");
    wmove(win,x+2,y);
    wprintw(win,"ll");
    wattroff(win,COLOR_PAIR(1));
}

void menu(){
    WINDOW* winmenu=newwin(LINES/1.5,COLS/1.5,0,0);
    int chmenu=ERR;
    while(chmenu!='i')
        {
            wclear(winmenu);
            box(winmenu,0,0);

            mvwin(winmenu,LINES/6,COLS/6);
            wrefresh(winmenu);
            chmenu=getchar();
            sleep(1/60);
        }
        chmenu=ERR;
}

void game(int* exit,int* x,int* y){
    WINDOW* map=newwin(LINES,COLS-1,0,0);

    int ch=ERR;

    wmove(map,*x,*y);

    box(map,0,0);
    ch=getch();
            
    switch (ch)
    {
    case 'z':
        wclear(map);
        *x=*x-1;

        if (*x<=0)
        {
            *x=*x+1;
        }
        break;

    case 's':
        wclear(map);
        *x=*x+1;

        if (*x>=LINES-4)
        {
            *x=*x-1;
        }
        break;

    case 'd':
        wclear(map);
        *y=*y+2;

        if (*y>=COLS-2)
        {
            *y=*y-2;
        }
        break;

    case 'q':
        wclear(map);
        *y=*y-2;

        if (*y<=0)
        {
            *y=*y+2;
        }
        break;
    
    case 'i':
        menu();
        break;
    
    case 'p':
        *exit=0;
        break;
    }

    wmove(map,*x,*y);
    printplayer(map,*x,*y);
    wrefresh(map);
    sleep(1/60);
}