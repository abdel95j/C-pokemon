#include <curses.h>
#include <stdio.h>
#include <unistd.h>

void printplayer(WINDOW* win,int x,int y){
    wprintw(win,"o");
    wmove(win,x+1,y-1);
    wprintw(win,"/0\\");
    wmove(win,x+2,y);
    wprintw(win,"ll");
}

int main(){
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr,TRUE);
    curs_set(0);

    int chinv=ERR,ch=ERR,x,y;
    WINDOW* win=newwin(LINES-1,COLS-1,0,0);
    WINDOW* invwin=newwin(LINES/1.5,COLS/1.5,0,0);
    keypad(win,TRUE);

    x=LINES/2;
    y=COLS/2;
    wmove(win,x,y);
    printplayer(win,x,y);
    wrefresh(win);

    

    while(ch!='p'){
        box(win,0,0);
        ch=getch();
        
        touchwin(win);
        wrefresh(win);
        
        switch (ch)
        {
        case 'z':
            wclear(win);
            x=x-1;

            if (x<=0)
            {
                x=x+1;
            }

            break;

        case 's':
            wclear(win);
            x=x+1;

            if (x>=LINES-4)
            {
                x=x-1;
            }

            break;

        case 'd':
            wclear(win);
            y=y+2;

            if (y>=COLS-2)
            {
                y=y-2;
            }

            break;

        case 'q':
            wclear(win);
            y=y-2;

            if (y<=0)
            {
                y=y+2;
            }
            
            break;
        
        case 'i':
            while(chinv!='i')
            {
                wclear(invwin);
                box(invwin,0,0);
    
                mvwin(invwin,10,40);
                overlay(win,invwin);
                wrefresh(invwin);
                chinv=getchar();
                sleep(1/60);
            }
            chinv=ERR;
        }



        wmove(win,x,y);
        printplayer(win,x,y);
        sleep(1/60);
    }

    endwin();

    return 0;
}