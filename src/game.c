#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"

void menu(int* exit){
    struct timespec trm, trq = { 0,10000000 };
    int chmenu=ERR,menuexit=0;
    int x=13,y=90;
    
    while(chmenu!='m' && menuexit==0)
        {            
            WINDOW* winmenu=newwin(LINES/1.5,COLS/1.5,LINES/6,COLS/6);
            print_menu(winmenu,x,y);

            box(winmenu,0,0);
            wrefresh(winmenu);  
            
            chmenu=getch();                                         

            switch (chmenu)
            {
                case KEY_UP:
                case 'z':
                    if (x==13)
                    {
                        //nothing happens
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
                        //nothing happens
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

                case KEY_ENTER:
                case 'e':
                case '\r':
                case '\n':
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
            nanosleep(&trq,&trm);
            delwin(winmenu);
        }
}

void game(int* exit,int* l,int* c){
    int ch=ERR;int i;int j;
    struct timespec trm, trq = { 0,10000000 };
    WINDOW* map = newwin(170,500, 0, 0);
    WINDOW* fenetre_backup= newwin(170, 500, 0, 0);
    WINDOW* cadre= subwin(map,111, 266, 29,116);      //cadre = map réelle : origine sur map (29;116), dimensions (111;268)
    WINDOW* cam=subwin(map,LINES-1,COLS-1,*l,*c);
    box(cadre,0,0);                                   //repérage : x_map = x_cadre + 29      y_map = y_cadre + 116
    box(fenetre_backup,0,0);

    fenetre_backup=dupwin(map);

    mvwin(cam,0,0);
    print_player(cam);
    create_map(map); 

    ch=getch();
    switch (ch)
    {
        case KEY_UP:
        case 'z':
            if (*l!=0)
            {
                *l=*l-1;
            }
            break;
        case KEY_DOWN:
        case 's':
            if (*l!=103)
            {
                *l=*l+1;
            }
            
            break;
        case KEY_RIGHT:
        case 'd':
            if (*c!=256)
            {
                *c=*c+2;
            }
            
            break;
        case KEY_LEFT:
        case 'q':
            if (*c!=0)
            {
                *c=*c-2;
            }
            
            break;
        case 'm':
            menu(exit);
            break;

        case 'p':
            *exit=1;
                break;

        default:
            break;
    }                     /*pour cadrer la camera la première fois sans cadrer à chaque fois dans la boucle*/
    wrefresh(cam);       //affichage camera
    map=dupwin(fenetre_backup);
    nanosleep(&trq,&trm);
    delwin(cam);
    delwin(map);
    delwin(cadre);
    delwin(fenetre_backup);
}