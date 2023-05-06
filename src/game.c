#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/physic.h"
#include "../headers/talk.h"

void init_poke(pokemon* pokenull, pokemon* charmander, pokemon* bulbasaur, pokemon* squirtle){
    
    //pokenull
    pokenull->atk=0;
    pokenull->def=0;
    pokenull->dodge=0;
    pokenull->pv=0;
    pokenull->lvl=0;
    pokenull->catchrate=0;
    pokenull->art=0;
    pokenull->type=0;
    sprintf(pokenull->basicatk,"none");
    sprintf(pokenull->speatk,"none");
    sprintf(pokenull->name,"no-pokemon");

    //charmander -
    charmander->atk=10.0;
    charmander->def=30.0/100;
    charmander->dodge=15;
    charmander->pv=35.0;
    charmander->lvl=1;
    charmander->catchrate=50;
    charmander->art=4;
    charmander->type=FIRE;
    sprintf(charmander->basicatk,"fire-punch");
    sprintf(charmander->speatk,"flamethrower");
    sprintf(charmander->name,"charmander");
    
    //bulbasaur -
    bulbasaur->atk=8.0;
    bulbasaur->def=45.0/100;
    bulbasaur->dodge=10;
    bulbasaur->pv=40.0;
    bulbasaur->lvl=1;
    bulbasaur->catchrate=50;
    bulbasaur->art=1;
    bulbasaur->type=GRASS;
    sprintf(bulbasaur->basicatk,"bullet-seed");
    sprintf(bulbasaur->speatk,"solar-beam");
    sprintf(bulbasaur->name,"bulbasaur");

    //squirtle -
    squirtle->atk=9.0;
    squirtle->def=35.0/100;
    squirtle->dodge=18;
    squirtle->pv=33.0;
    squirtle->lvl=1;
    squirtle->catchrate=50;
    squirtle->art=7;
    squirtle->type=WATER;
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

    pokemon pokenull,charmander,bulbasaur,squirtle;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle);

    box(write,0,0);
    print_newtrainer(chatwin);
    wrefresh(chatwin);
    wmove(write,2,22);
    wscanw(write,"%s",newplayer->name);

    newplayer->lvl=1;
    newplayer->money=200;
    newplayer->xp=0;
    newplayer->is_on_water=0;

    newplayer->inventory[0].type=1; // pokeballs
    newplayer->inventory[1].type=2; // potions
    newplayer->inventory[2].type=3; // bonbons

    for (int i = 3; i < 12 ; i++)
    {
        newplayer->inventory[i].type=0; // no obj
    }

    for (int i = 0; i < 20; i++)
    {
        newplayer->pc[i]=pokenull;
    }

    newplayer->pokefight=pokenull;
    newplayer->poke1=pokenull;
    newplayer->poke2=pokenull;
    newplayer->poke3=pokenull;
    newplayer->poke4=pokenull;
    newplayer->poke5=pokenull;
    newplayer->poke6=pokenull;
    
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
    int x=50,y=50;

    pokemon pokenull, charmander, bulbasaur, squirtle;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle);

    while (finish==0)
    {
        WINDOW* pokewin=newwin(LINES-1,COLS-1,0,0);
        print_get_firstpoke(pokewin,x,y);   
        wrefresh(pokewin);
        ch=getch();

        physic_get_firstpoke(ch,&y); // colisions
        switch (ch) // actions
        {
        case 'e':
        case '\n':
        case '\r':
            switch (y)
            {
            case 50:
                player->poke1=bulbasaur;
                finish=1;
                break;

            case 115:
                player->poke1=charmander;
                finish=1;
                break;

            case 183:
                player->poke1=squirtle;
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
        wrefresh(house_map);

        ch=getch();

        physic_house(ch,&x,&y); // colisions

        switch (ch) // actions
        {
            case 'e':
            case '\r':
            case '\n':
                if (x<=19 && x>=13 && y<=9) // mom area
                {
                    //talk to mom
                    chargement();
                }

                if (x==34 && y>=121 && y<=129) // exit area
                {
                    chargement();
                    finish=1;
                }  
                break;

            default:
                break;
        }

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

void lab(trainer* player){
    int ch=ERR, finish=0;
    int x=34,y=73;

    while(finish==0)
    {
        WINDOW* lab_map=newwin(40,150,13,43);
        WINDOW* line_wall_lab=subwin(lab_map,1,148,22,44);
        
        box(lab_map,0,0);
        box(line_wall_lab,0,0);

        print_lab(lab_map,x,y);
        physic_lab(ch,&x,&y);
        wrefresh(lab_map);

        ch=getch();

        switch (ch)
        {
        case 'e':
        case '\n':
        case '\r':
            if (x==34 && y>=69 && y<=77)
            {
                chargement();
                finish=1;
            }

            if (x<=7 && y>=95 && y<=105)
            {
                chargement();
                //talk to prof
            }

            if (x==7 && y>=35 && y<=41)
            {
                chargement();
                //pc
            }
            break;
        
        default:
            break;
        }

        if(delwin(line_wall_lab)==ERR)
        {
            exit(19);
        }
        if(delwin(lab_map)==ERR)
        {
            exit(20);
        }
    }
}

void shop(trainer* player){
    int finish=0,ch=ERR;
    int x=34,y=125;

    while (finish==0)
    {
        WINDOW* shop_map=newwin(40,150,13,43);
        WINDOW* line_wall=subwin(shop_map,1,148,22,44);
        box(shop_map,0,0);
        box(line_wall,0,0);

        print_shop(shop_map,x,y);
        wrefresh(shop_map);

        ch=getch();

        physic_shop(ch,&x,&y); // colisions

        switch (ch) // actions
        {
            case 'e':
            case '\r':
            case '\n':
                if (x==18 && y>=29 && y<=33) // cashier area
                {
                    talkto_cashier(shop_map,player);
                }

                if (x==34 && y>=121 && y<=129) // exit area
                {
                    chargement();
                    finish=1;
                }  
                break;

            default:
                break;
        }

        usleep(16667);
        if (delwin(line_wall)==ERR)
        {
            exit(12);
        }
        if (delwin(shop_map)==ERR)
        {
            exit(11);
        }
    }
}

void menu(int* quit){
    int chmenu=ERR,menuexit=0;
    int x=13,y=95;
    
    while(chmenu!='m' && menuexit==0)
        {            
            WINDOW* winmenu=newwin(LINES/1.5,COLS/1.5,LINES/6,COLS/6);
            print_menu(winmenu,x,y);

            box(winmenu,0,0);
            wrefresh(winmenu);  
            
            chmenu=getch();        

            physic_menu(chmenu,&x); // colisions
            switch (chmenu) // actions
            {
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

        physic_inventory(ch,&x,&y); // colisions

        switch (ch) // actions
        {
        case 'i':
            finish=1;
            break;
        case 'e':
        case '\n':
        case '\r':
            // à faire
            break;
        default:
            break;
        }

        usleep(16667);
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

void roadto_league(trainer* player){
    int l=97,c=70;
    int finish=0, ch=ERR;

    while(finish==0)
    {
        WINDOW* road = newwin(200,400, 0, 0);
        WINDOW* cam= subwin(road,LINES-1,COLS-1,l,c);
        WINDOW* cadre= subwin(road,111,150,29,116);
        WINDOW* chute= subwin(road,10,150,139,116);
        WINDOW* limite_bas= subwin(road,1,150,110,116);
        WINDOW* limite_haut= subwin(road,1,150,84,116);
        WINDOW* blackscreen= newwin(LINES-1,COLS-1,0,0);

        box(cadre,0,0);
        box(chute,0,0);
        box(limite_bas,0,0);
        box(limite_haut,0,0);
        mvwin(cam,0,0);
        print_roadto_league(road);
        print_player(cam,player);
        physic_roadto_league(ch,&l,&c);

        wrefresh(cam);

        ch=getch();

        switch (ch)
        {
        case 'e':
        case '\n':
        case '\r':
            if (l==103 && c<=74 && c>=68)  //  exit zone
            {
                finish=1;
                chargement;
            }

            if (l==76)  // border water down 
            {
                l-=2;
                player->is_on_water=1;
            }

            else if (l==74)  // border water down 
            {
                l+=2;
                player->is_on_water=0;
            }

            if (l==50) // border water up
            {
                l-=2;
                player->is_on_water=0;
            }
            
            else if (l==48) // border water up
            {
                l+=2;
                player->is_on_water=1;
            }

            
            break;
        
        default:
            break;
        }

        usleep(16667);
        if(delwin(cam)==ERR)
        {
            exit(15);
        }
        if(delwin(cadre)==ERR)
        {
            exit(16);
        }
        if(delwin(chute)==ERR)
        {
            exit(21);
        }
        if(delwin(limite_bas)==ERR)
        {
            exit(22);
        }
        if(delwin(limite_haut)==ERR)
        {
            exit(23);
        }
        if(delwin(road)==ERR)
        {
            exit(17);
        }
        if(delwin(blackscreen)==ERR)
        {
            exit(18);
        }
    }
}

void main_menu(trainer* player,int* quit,int* x, int* y){
    WINDOW* win=newwin(LINES-1,COLS-1,0,0);
    int ch=ERR;
    
    ch=getch();
    print_main_menu(win,*x,*y);

    wrefresh(win);
    switch (ch)
    {
        // colisions
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

        // actions
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
            //shop(player);
            roadto_league(player);
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

void game(trainer* player, int* quit,int* l,int* c){
    int ch=ERR;int i;int j;
    WINDOW* map = newwin(170,500, 0, 0);
    WINDOW* cadre= subwin(map,111, 266, 29,116);      //cadre = map réelle : origine sur map (29;116), dimensions (111;268)
    WINDOW* cam=subwin(map,LINES-1,COLS-1,*l,*c);
    box(cadre,0,0);                                   //repérage : x_map = x_cadre + 29      y_map = y_cadre + 116

    mvwin(cam,0,0);
    create_map(map);
    print_player(cam,player); 
    wrefresh(cam); 

    ch=getch();

    physic_map(ch,l,c); // colisions
    switch (ch) // actions
    {
        case 'e':
        case '\r':
        case '\n':
            if (*l==10 && *c<=28 && *c>=24) // house area
            {
                chargement();
                house(player);
            }  

            if (*l==50 && *c>=14 && *c<=18) // shop area
            {
                chargement();
                shop(player);
            } 

            if (*l==10 && *c>=238 && *c<=242) // lab area
            {
                chargement();
                lab(player);
            }

            if (*c==0 && *l>=70 && *l<=76) // lab area
            {
                chargement();
                roadto_league(player);
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