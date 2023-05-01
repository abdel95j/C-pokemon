#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"

void menu(int* exit){
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
            usleep(16666.67);
            delwin(winmenu);
        }
}

void game(int* exit,int* l,int* c){
    int ch=ERR;int i;int j;
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
            if (*l!=0)  //physic bordermap
            {
                *l=*l-1;
            }

            if (*c<=36 && *l==54)   //physic pokeshop
            {
                *l=*l+1;
            }

            if (*c<=36 && *l==14)   //physic home
            {
                *l=*l+1;
            }

            if (*c>=220 && *l==14)   //physic lab
            {
                *l=*l+1;
            }

            if (*c>=220 && *l==54)   //physic house 3
            {
                *l=*l+1;
            }

            if (*c>=220 && *l==79)   //physic house 4
            {
                *l=*l+1;
            }

            if (*c>=246 && *l==23)   //physic "OUTDSIDE"
            {
                *l=*l+1;
            }

            break;

        case KEY_DOWN:
        case 's':
            if (*l!=103)    //physic bordermap
            {
                *l=*l+1;
            }

            if (*c<=36 && *l==39)   //physic pokeshop
            {
                *l=*l-1;
            }

            if (*c<=36 && *l==87)   //physic house 2
            {
                *l=*l-1;
            }

            if (*c>=220 && *l==37)   //physic house 3
            {
                *l=*l-1;
            }

            if (*c>=220 && *l==62)   //physic house 4
            {
                *l=*l-1;
            }

            if (*c>=220 && *l==87)   //physic house 5
            {
                *l=*l-1;
            }

            if (*c>=246 && *l==16)   //physic "OUTDSIDE"
            {
                *l=*l-1;
            }
            
            
            break;
        case KEY_RIGHT:
        case 'd':
            if (*c!=256)    //physic bordermap
            {
                *c=*c+2;
            }

            if (*c==220 && *l<=14)  //physic lab
            {
                *c=*c-2;
            }

            if (*c==220 && *l>=37 && *l<=54)  //physic house 3
            {
                *c=*c-2;
            }

            if (*c==220 && *l>=62 && *l<=79)  //physic house 4
            {
                *c=*c-2;
            }

            if (*c==220 && *l>=87)  //physic house 5
            {
                *c=*c-2;
            }

            if (*c==246 && *l>=16 && *l<=23)  //physic "OUTSIDE"
            {
                *c=*c-2;
            }
            
            
            break;
        case KEY_LEFT:
        case 'q':
            if (*c!=0)  //physic bordermap
            {
                *c=*c-2;
            }
            
            if (*c==36 && *l>=39 && *l<=54) //physic pokeshop
            {
                *c=*c+2;
            }

            if (*c==36 && *l<=14) //physic home
            {
                *c=*c+2;
            }
            
            if (*c==36 && *l>=87) //physic house 2
            {
                *c=*c+2;
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
    }                 
    wrefresh(cam);       
    map=dupwin(fenetre_backup);
    usleep(16666.67);
    delwin(cam);
    delwin(map);
    delwin(cadre);
    delwin(fenetre_backup);
}