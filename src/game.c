#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"

void init_poke(pokemon* pokenull, pokemon* charmander, pokemon* bulbasaur, pokemon* squirtle){
    
    //  PAS FAIT, SYSTEME À RÉALISER ENCORE

    //pokenull
    pokenull->atk=0;
    pokenull->def=0;
    pokenull->dodge=0;
    pokenull->pv=0;
    pokenull->lvl=0;
    pokenull->spetaux=0;
    pokenull->catchrate=0;
    pokenull->art=0;
    sprintf(pokenull->basicatk,"none");
    sprintf(pokenull->speatk,"none");
    sprintf(pokenull->name,"no-pokemon");

    //charmander -
    charmander->atk=10.0;
    charmander->def=30.0/100;
    charmander->dodge=18;
    charmander->pv=35.0;
    charmander->lvl=1;
    charmander->spetaux=30;
    charmander->catchrate=50;
    charmander->art=4;
    sprintf(charmander->basicatk,"fire-punch");
    sprintf(charmander->speatk,"flamethrower");
    sprintf(charmander->name,"charmander");
    
    //bulbasaur -
    bulbasaur->atk=10.0;
    bulbasaur->def=45.0/100;
    bulbasaur->dodge=10;
    bulbasaur->pv=40.0;
    bulbasaur->lvl=1;
    bulbasaur->spetaux=22;
    bulbasaur->catchrate=50;
    bulbasaur->art=1;
    sprintf(bulbasaur->basicatk,"bullet-seed");
    sprintf(bulbasaur->speatk,"solar-beam");
    sprintf(bulbasaur->name,"bulbasaur");

    //squirtle -
    squirtle->atk=10.0;
    squirtle->def=35.0/100;
    squirtle->dodge=15;
    squirtle->pv=35.0;
    squirtle->lvl=1;
    squirtle->spetaux=21;
    squirtle->catchrate=50;
    squirtle->art=7;
    sprintf(squirtle->basicatk,"water-gun");
    sprintf(squirtle->speatk,"hydropump");
    sprintf(squirtle->name,"squirtle");

}

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
    newplayer->lvl=1;
    newplayer->money=200;

    curs_set(0);
    nodelay(stdscr,TRUE);
    noecho();
    if(delwin(write)==ERR)
    {
        exit(1);
    }
    if(delwin(chatwin)==ERR)
    {
        exit(2);
    }

}

void get_firstpoke(trainer* player){
    int finish=0,ch=ERR;
    int x=50,y=60;

    while (finish==0)
    {
        WINDOW* pokewin=newwin(LINES-1,COLS-1,0,0);
        print_get_firstpoke(pokewin,x,y);   
        wrefresh(pokewin);
        ch=getch();

        switch (ch)
        {
        case 'd':
        case KEY_RIGHT:
            if (y==60)
            {
                y=115;
            }

            else if (y==115)
            {
                y=180;
            }
            break;

        case 'q':
        case KEY_LEFT :
            if (y==115)
            {
                y=60;
            }

            else if (y==180)
            {
                y=115;
            }
            break;

        case 'e':
        case '\n':
        case '\r':
            switch (y)
            {
            case 60:
                //trainer->poke1=bulbasaur
                finish=1;
                break;

            case 115:
                //trainer->poke1=charmander
                finish=1;
                break;

            case 180:
                //trainer->poke1=squirtle
                finish=1;
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }  

        usleep(16667);
        if(delwin(pokewin)==ERR)
        {
            exit(3);
        }
    } 
}

void house(trainer* player){
    int finish=0,ch=ERR;
    int x=34,y=125;

    while (finish==0)
    {
        WINDOW* house_map=newwin(40,150,13,43);
        WINDOW* line_wall=subwin(house_map,1,148,22,44);
        box(house_map,0,0);
        box(line_wall,0,0);

        print_house(house_map,x,y);

        ch=getch();

        switch (ch)
        {

        case 'z':
        case KEY_UP:
            if (x!=6 || y>=127)
            {
                x--;
            }

            if (x==6 && y<=31)  // lavabo + frigo + poubelle
            {
                x++;
            }

            if (x==6 && y>=41 && y<=53)  // four
            {
                x++;
            }

            if (x==9 && y>=67 && y<=93)  // télé
            {
                x++;
            }

            if (x==18 && y>=67 && y<=93)  // sofa
            {
                x++;
            }

            if (x==9 && y>=125)  // stairs
            {
                x++;
            }

            if (x==31 && y>=7 && y<=27)
            {
                x++;
            }
            
            if (y<=7 && x==18) // mom
            {
                x++;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (x!=34)
            {
                x++;
            }

            if (x==13 && y>=67 && y<=93)  // sofa
            {
                x--;
            }

            if (x==23 && y>=7 && y<=27) // table
            {
                x--;
            }

            if (y<=7 && x==14) // mom
            {
                x--;
            }
            break;

        case 'q':
        case KEY_LEFT:
            if (y!=1)
            {
                y-=2;
            }

            if (x==6 && y==31)  // lavabo + frigo + poubelle
            {
                y+=2;
            }

            if (x==6 && y==53)  // four
            {
                y+=2;
            }

            if (x>=6 && x<=9 && y==93)  // télé
            {
                y+=2;
            }

            if (x>=13 && x<=18 && y==93)  // sofa
            {
                y+=2;
            }

            if (y==27 && x>=23 && x<=31) // table
            {
                y+=2;
            }

            if (y==7 && x<=18 && x>=14) // mom
            {
                y+=2;
            }
            
            
            
            break;
        
        case 'd':
        case KEY_RIGHT:
            if (y!=143)
            {
                y+=2;
            }

            if (x==6 && y==41)  // four
            {
                y-=2;
            }

            if (x>=6 && x<=9 && y==67)  // télé
            {
                y-=2;
            }

            if (x>=13 && x<=18 && y==67)  // télé
            {
                y-=2;
            }

            if (x>=6 && x<=9 && y==125)  // stairs
            {
                y-=2; 
            }

            if (y==7 && x<=31 && x>=23) // table
            {
                y-=2;
            }
            break;

        case 'e':
        case '\r':
        case '\n':
            if (x<=19 && x>=13 && y<=9)
            {
                //talk to mom
            }  
            break;

        case 'p':
            finish=1;
            break;
        
        default:
            break;
        }

        wrefresh(house_map);
        usleep(16667);
        if (delwin(line_wall)==ERR)
        {
            exit(12);
        }
        if (delwin(house_map)==ERR)
        {
            exit(11);
        }
    }
}

void menu(int* quit){
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
                        *quit=1;
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
            if(delwin(winmenu)==ERR)
            {
                exit(4);
            }
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
        if(delwin(sac)==ERR)
        {
            exit(5);
        }
        if(delwin(bag_array)==ERR)
        {
            exit(6);
        }
        
    }
}

void main_menu(trainer* player,int* quit,int* x, int* y){
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
            get_firstpoke(player);
            *quit=1;
            chargement();
            break;

        case 38:
            wclear(win);
            wrefresh(win);
            house(player);
            *quit=1;
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
    if(delwin(win)==ERR)
    {
        exit(7);
    }
}

void game(int* quit,int* l,int* c){
    int ch=ERR;int i;int j;
    WINDOW* map = newwin(170,500, 0, 0);
    WINDOW* cadre= subwin(map,111, 266, 29,116);      //cadre = map réelle : origine sur map (29;116), dimensions (111;268)
    WINDOW* cam=subwin(map,LINES-1,COLS-1,*l,*c);
    box(cadre,0,0);                                   //repérage : x_map = x_cadre + 29      y_map = y_cadre + 116


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
            menu(quit);
            break;

        case 'i':
            inventory();
            break;

        case 'p':
            *quit=1;
                break;

        default:
            break;
    }                 
    wrefresh(cam);       
    usleep(16667);

    if(delwin(cam)==ERR)
    {
        exit(8);
    }
    if(delwin(cadre)==ERR)
    {
        exit(9);
    }
    if(delwin(map)==ERR)
    {
        exit(10);
    }
}