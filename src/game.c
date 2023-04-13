#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"


void printplayer(WINDOW* win,int x,int y){
    init_pair(1,COLOR_RED,COLOR_BLACK);
    wattron(win,COLOR_PAIR(1));
    mvwprintw(win,x+1,y,"   _");                
    mvwprintw(win,x+2,y,"  '_'");                
    mvwprintw(win,x+3,y," /| |\\");
    mvwprintw(win,x+4,y,"* |_| *");
    mvwprintw(win,x+5,y,"  | |");
    mvwprintw(win,x+6,y,"  - -");
    wattroff(win,COLOR_PAIR(1));
}

void print_menu(WINDOW* win,int x,int y){

    mvwprintw(win,2,COLS/5,"88b           d88  88888888888  888b      88  88        88\n");
    mvwprintw(win,3,COLS/5,"888b         d888  88           8888b     88  88        88\n");
    mvwprintw(win,4,COLS/5,"88`8b       d8'88  88           88 `8b    88  88        88\n");
    mvwprintw(win,5,COLS/5,"88 `8b     d8' 88  88aaaaa      88  `8b   88  88        88\n");
    mvwprintw(win,6,COLS/5,"88  `8b   d8'  88  88           88   `8b  88  88        88\n");
    mvwprintw(win,7,COLS/5,"88   `8b d8'   88  88           88    `8b 88  88        88\n");
    mvwprintw(win,8,COLS/5,"88    `888'    88  88           88     `8888  Y8a.    .a8P\n"); 
    mvwprintw(win,9,COLS/5,"88     `8'     88  88888888888  88      `888    `Y8888Y  '\n");
        
    mvwprintw(win,13,COLS/15,"__   _____  _   _ ____    _____ _____    _    __  __ ");
    mvwprintw(win,13+1,COLS/15,"\\ \\ / / _ \\| | | |  _ \\  |_   _| ____|  / \\  |  \\/  |");
    mvwprintw(win,13+2,COLS/15," \\ V / | | | | | | |_) |   | | |  _|   / _ \\ | |\\/| |");
    mvwprintw(win,13+3,COLS/15,"  | || |_| | |_| |  _ <    | | | |___ / ___ \\| |  | |");
    mvwprintw(win,13+4,COLS/15,"  |_| '___/ '___/|_| '_\\   |_| |_____/_/   \\_\\_|  |_|");

    mvwprintw(win,22,COLS/15," ____    ___     _______ ");
    mvwprintw(win,22+1,COLS/15,"/ ___|  / \\ \\   / / ____|");
    mvwprintw(win,22+2,COLS/15,"'___ ' / _ \\ \\ / /|  _|  ");
    mvwprintw(win,22+3,COLS/15," ___) / ___ \\ V / | |___ ");
    mvwprintw(win,22+4,COLS/15,"|____/_/   '_\\_/  |_____|");

    mvwprintw(win,31,COLS/15,"  ___  _   _ ___ _____ ");
    mvwprintw(win,31+1,COLS/15," / _ \\| | | |_ _|_   _|");
    mvwprintw(win,31+2,COLS/15,"| | | | | | || |  | |  ");
    mvwprintw(win,31+3,COLS/15,"| |_| | |_| || |  | |  ");
    mvwprintw(win,31+4,COLS/15," '__\\_\\\\___/|___| |_|  ");

    mvwprintw(win,x,y,"    .");
    mvwprintw(win,x+1,y,"  .;;............");
    mvwprintw(win,x+2,y,".;;;;::::::::::::");
    mvwprintw(win,x+3,y," ':;;::::::::::::");
    mvwprintw(win,x+4,y,"   ':");
}

void menu(){
    WINDOW* winmenu=newwin(LINES/1.5,COLS/1.5,LINES/6,COLS/6);
    int chmenu=ERR;
    int x=13,y=COLS/3;

    while(chmenu!='i')
        {
            wclear(winmenu);
            
            print_menu(winmenu,x,y);

            box(winmenu,0,0);
            wrefresh(winmenu);  
            
            chmenu=getchar();                                         

            switch (chmenu)
            {
            case 'z':
                if (x==13)
                {
                    //nothin happens
                }
                else if (x==22)
                {
                    x=13;
                }
                else if (x==31)
                {
                    x=22;
                }
                break;
            
            case 's':
                if (x==31)
                {
                    //nothin happens
                }
                else if (x==22)
                {
                    x=31;
                }
                else if (x==13)
                {
                    x=22;
                }
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

        if (*x<0)
        {
            *x=*x+1;
        }
        break;

    case 's':
        wclear(map);
        *x=*x+1;

        if (*x>=LINES-7)
        {
            *x=*x-1;
        }
        break;

    case 'd':
        wclear(map);
        *y=*y+2;

        if (*y>=COLS-8)
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
    box(map,0,0);
    printplayer(map,*x,*y);
    wrefresh(map);
    sleep(1/60);
    delwin(map);
}