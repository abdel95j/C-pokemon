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
    WINDOW* winmenu=newwin(LINES/1.5,COLS/1.5,LINES/6,COLS/6);
    int chmenu=ERR;
    int finish=0;
    int maxx=0,maxy=0;

    getmaxyx(winmenu,maxx,maxy);

    while(finish==0)
        {
            wclear(winmenu);
            mvwprintw(winmenu,2,maxy/3,"88b           d88  88888888888  888b      88  88        88\n");
            mvwprintw(winmenu,3,maxy/3,"888b         d888  88           8888b     88  88        88\n");
            mvwprintw(winmenu,4,maxy/3,"88`8b       d8'88  88           88 `8b    88  88        88\n");
            mvwprintw(winmenu,5,maxy/3,"88 `8b     d8' 88  88aaaaa      88  `8b   88  88        88\n");
            mvwprintw(winmenu,6,maxy/3,"88  `8b   d8'  88  88           88   `8b  88  88        88\n");
            mvwprintw(winmenu,7,maxy/3,"88   `8b d8'   88  88           88    `8b 88  88        88\n");
            mvwprintw(winmenu,8,maxy/3,"88    `888'    88  88           88     `8888  Y8a.    .a8P\n"); 
            mvwprintw(winmenu,9,maxy/3,"88     `8'     88  88888888888  88      `888    `Y8888Y '\n");
            box(winmenu,0,0);
            wrefresh(winmenu);
            chmenu=getchar();                                               

            switch (chmenu)
            {
            case 'z':
                break;
            
            case 's':
                break;
            }

            sleep(1/60);
        }
        delwin(winmenu);
}

void game(int* exit,int* x,int* y){
    WINDOW* map=newwin(LINES,COLS-1,0,0);

    int ch=ERR;

    wmove(map,*x,*y);

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

        if (*x>=LINES-3)
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
        *exit=1;
        break;
    }

    wmove(map,*x,*y);
    printplayer(map,*x,*y);
    box(map,0,0);
    wrefresh(map);
    sleep(1/60);
    delwin(map);
}