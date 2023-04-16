#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"

void menu(int* exit){
    WINDOW* winmenu=newwin(LINES/1.5,COLS/1.5,LINES/6,COLS/6);
    int chmenu=ERR,menuexit=0;
    int x=13,y=90;
    
    while(chmenu!='i' && menuexit==0)
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
            
            case 'e':
                switch (x)
                {
                case 31:
                    menuexit=1;
                    *exit=1;
                    break;
                
                case 22:
                    /* code */
                    break;

                case 13:
                    break;
                }
                break;
            
            default:
                break;
            }
            sleep(1/60);
        }
        delwin(winmenu);
}

void game(int* exit,int* x,int* y){
    WINDOW* map=newwin(LINES,COLS-1,*x,*y);
    WINDOW* affichage=subwin(map,20,50,LINES/2-7,COLS/2-21);

    int Xaff,Yaff;
    getmaxyx(affichage,Xaff,Yaff);

    int ch=ERR;
        
    ch=getch();
            
    switch (ch)
    {
    case 's':
        wclear(map);
        *x=*x-1;
        
        break;

    case 'z':
        wclear(map);
        *x=*x+1;
        
        break;

    case 'q':
        wclear(map);
        *y=*y+2;

        break;

    case 'd':
        wclear(map);
        *y=*y-2;

        break;
    
    case 'i':
        menu(exit);
        break;
    
    default:
        break;
    }

    box(map,0,0);
    box(affichage,0,0);
    print_player(affichage,Xaff/2-3,Yaff/2-4);
    print_map(map);
    wrefresh(map);
    sleep(1/60);
    delwin(map);
    delwin(affichage);
}