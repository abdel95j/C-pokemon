#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

    int chinv=ERR,ch=ERR,x,y;
    WINDOW* map=newwin(LINES,COLS,0,0);
    WINDOW* menu=newwin(LINES/1.5,COLS/1.5,0,0);

    x=LINES/2-1;
    y=COLS/2;
    wmove(map,x,y);

    while(ch!='p'){
        box(map,0,0);
        ch=getch();
                
        switch (ch)
        {
        case 'z':
            wclear(map);
            x=x-1;

            if (x<=0)
            {
                x=x+1;
            }

            break;

        case 's':
            wclear(map);
            x=x+1;

            if (x>=LINES-3)
            {
                x=x-1;
            }

            break;

        case 'd':
            wclear(map);
            y=y+2;

            if (y>=COLS-2)
            {
                y=y-2;
            }

            break;

        case 'q':
            wclear(map);
            y=y-2;

            if (y<=0)
            {
                y=y+2;
            }
            
            break;
        
        case 'i':
            while(chinv!='i')
            {
                wclear(menu);
                box(menu,0,0);

                mvwin(menu,LINES/6,COLS/6);
                wrefresh(menu);
                chinv=getchar();
                sleep(1/60);
            }
            chinv=ERR;
        }

        wmove(map,x,y);
        printplayer(map,x,y);

        wrefresh(map);
        sleep(1/60);
    }

    endwin();

    return 0;
}