#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
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
            sleep(1/60);
        }
        delwin(winmenu);
}

void game(int* exit,int* l,int* c){
    int ch=ERR;int i;int j;
    struct timespec trm, trq = { 0,10000000 };
    WINDOW* map = newwin(170,500, 0, 0);
    WINDOW* cam=subwin(map,LINES-1,COLS-1,*l,*c);
    WINDOW* fenetre_backup= newwin(170, 500, 0, 0);
    box(map,0,0);
    box(fenetre_backup,0,0);

    for(i=((LINES-2)/2);i<169-((LINES-2)/2);i++){ /*i=abscisse de @ dans map d'affichage +1; i< nombre lignes map - abscisse de @ dans fenêtre d'affichage -1*/
        mvwprintw(map,i,1,"░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░");/*"ordonnée de @ dans map d'affichage" d'espaces*/
        for(j=126;j<500-((COLS-2)/2);j++){/*j= ordonnée qui suit;j< nombre colonnes fenêtre - ordonnée de @ dans fenêtre d'affichage -1 */
          mvwprintw(map,i,j,"░");
        }
    }

    fenetre_backup=dupwin(map);

    mvwin(cam,0,0);
    mvwprintw(cam,(LINES-2)/2,(COLS-2)/2,"@"); //10,40

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
            if (*l!=108)
            {
                *l=*l+1;
            }
            
            break;
        case KEY_RIGHT:
        case 'd':
            if (*c!=265)
            {
                *c=*c+1;
            }
            
            break;
        case KEY_LEFT:
        case 'q':
            if (*c!=0)
            {
                *c=*c-1;
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
    delwin(fenetre_backup);
}