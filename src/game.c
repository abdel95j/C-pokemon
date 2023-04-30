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
    
    while(chmenu!='m' && menuexit==0)
        {
            wclear(winmenu);
            
            print_menu(winmenu,x,y);

            box(winmenu,0,0);
            wrefresh(winmenu);  
            
            chmenu=getchar();                                         

            switch (chmenu)
            {
            case KEY_UP:
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
            
            case KEY_DOWN:
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

void game(int* exit,int* l,int* c){
    int ch=ERR;int i;int j;
    WINDOW* map = newwin(100+LINES/2+LINES/2, 350+COLS/2+COLS/2, 0, 0);
    WINDOW* cam=subwin(map,LINES-1,COLS-1,*l,*c);
    box(map,0,0);
    box(cam,0,0);
    
       mvwprintw(cam,LINES/2,COLS/2,"@");
                ch=getch();
                switch (ch)
                {
                case KEY_UP:
                case 'z':
                 *l=*l-1;
                    break;
                case KEY_DOWN:
                case 's':
                *l=*l+1;
                    break;
                case KEY_RIGHT:
                case 'd':
                  *c=*c+1;
                    break;
                case KEY_LEFT:
                case 'q':
                  *c=*c-1;
                    break;
                case 'm':
                menu(exit);
                case 'p':
                *exit=1;
                    break;
                default:
                    break;
                }     /*pour cadrer la camera la première fois sans cadrer à chaque fois dans la boucle*/
    wrefresh(cam);       //affichage camera
    sleep(1/60);
    delwin(cam);
    delwin(map);
}