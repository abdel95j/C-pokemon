#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

void printscreen(WINDOW* win){
    int i;
    int frames;

    move(2,5);
    for ( i = 0; i < 150; i++)
    {
        addstr("_");
    }

    move(50,5);
    for ( i = 0; i < 150; i++)
    {
        addstr("_");
    }

    for ( i = 3; i < 51; i++)
    {
        move(i,5);
        addstr("|");
    }

    for ( i = 3; i < 51; i++)
    {
        move(i,155);
        addstr("|");
    }
    refresh();
}

int main(){
    initscr();
    noecho();

    WINDOW* win=newwin(LINES-1,COLS-1,0,0);
    int exit=ERR,finish=1,i,ch=ERR;

    nodelay(stdscr, TRUE);

    refresh();


    /*for ( i = 0; i < COLS; i++)
    {
        mvprintw(0,i,"_");
    }

    for ( i = 0; i < COLS; i++)
    {
        mvprintw(LINES-1,i,"_");
    }

    for ( i = 1; i < LINES; i++)
    {
        mvprintw(i,0,"|");
    }
    
    for ( i = 1; i < LINES; i++)
    {
        mvprintw(i,COLS-1,"|");
    }*/

while(finish==1){
    box(win,0,0);
    while (ch!=10)
    {
        ch=getch();
        wrefresh(win);

        if (ch==10)
        {
            while (exit!=10)
            {
                mvwprintw(win,LINES/2,COLS/2,"wsh");
                exit=getch();   
                wrefresh(win);
            }
        }  
    }
    finish=0;
}    
    endwin();

    

    return 0;
}