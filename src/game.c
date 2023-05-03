#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"

void create_newplayer(trainer* newplayer){
    WINDOW* chatwin=newwin(LINES-1,COLS-1,0,0);
    WINDOW* write=subwin(chatwin,5,50,30,55);
    nodelay(stdscr,FALSE);
    echo();
    curs_set(1);

    box(chatwin,0,0);
    box(write,0,0);
    print_newtrainer(chatwin);
    wrefresh(chatwin);
    wmove(write,2,22);
    wscanw(write,"%s",newplayer->name);

    curs_set(0);
    nodelay(stdscr,TRUE);
    noecho();
    delwin(chatwin);
    delwin(write);
}

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
                        chargement();
                        break;

                    case 13:
                        break;
                    }
                    break;

                default:
                    break;
            } 
            usleep(16667);
            delwin(winmenu);
        }
}

void inventory(){
    int finish=0,ch=ERR;
    int x=12,y=17;

    while (finish==0)
    {
        WINDOW* sac = newwin(LINES/1.5,COLS/1.5,(LINES/6)+5,(COLS/6)+1);
        WINDOW* bag_array=newwin(5,COLS/1.5,(LINES/6),COLS/6+1);
        box(sac,0,0);

        mvwprintw(bag_array,1,12," ___   _   ___ ");
        mvwprintw(bag_array,1+1,12,"| _ ) /_\\ / __|");
        mvwprintw(bag_array,1+2,12,"| _ \\/ _ \\ (_ |");
        mvwprintw(bag_array,1+3,12,"|___/_/ \\_\\___|");
                                  
        ch=getch();
        print_inventory(sac,x,y);        
        wrefresh(sac);
        wrefresh(bag_array);
        switch (ch)
        {
        case 'i':
            finish=1;
            break;

        case 'q' :
        case KEY_LEFT :
            if (y!=17)
            {
                y-=40;
            }
            break;

        case 'd' :
        case KEY_RIGHT :
            if (y!=137)
            {
                y+=40;
            }
            break;

        case 'z' :
        case KEY_UP :
            if (x==39)
            {
                x=26;
            }

            else if (x==26)
            {
                x=12;
            }
            break;

        case 's' :
        case KEY_DOWN :
            if (x==12)
            {
                x=26;
            }

            else if (x==26)
            {
                x=39;
            }
            break;
        
        default:
            break;
        }
        delwin(sac);
        delwin(bag_array);
        
    }
}

void main_menu(trainer* player,int* exit,int* x, int* y){
    WINDOW* win=newwin(LINES-1,COLS-1,0,0);
    int ch=ERR;
    
    box(win,0,0);
    ch=getch();
    print_main_menu(win,*x,*y);

    wrefresh(win);
    switch (ch)
    {

    case 'z':
    case KEY_UP:
        if (*x==38)
        {
            *x=28;
        }
        
        break;

    case 's':
    case KEY_DOWN:
        if (*x==28)
        {
            *x=38;
        }
        break; 

    case 'e' :
    case '\n' :
    case '\r' :
        switch (*x)
        {
        case 28:
            create_newplayer(player);
            *exit=1;
            chargement();
            break;

        case 38:
            *exit=1;
            chargement();
            break;
        
        default:
            break;
        }
        break;  
    
    default:
        break;
    }
    usleep(16667);
    delwin(win);
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

        case 'i':
            inventory();
            break;

        case 'p':
            *exit=1;
                break;

        default:
            break;
    }                 
    wrefresh(cam);       
    map=dupwin(fenetre_backup);
    usleep(16667);
    delwin(cam);
    delwin(map);
    delwin(cadre);
    delwin(fenetre_backup);
}