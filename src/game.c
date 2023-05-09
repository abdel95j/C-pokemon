#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/physic.h"
#include "../headers/talk.h"
#include "../headers/talkbis.h"

void init_champions(trainer*player,trainer*blue, trainer*red, trainer*yellow){
    int sort1=rand()%3;
    int sort2=rand()%2;
    pokemon charmander,pokenull,bulbasaur,squirtle;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle);

    sprintf(blue->name,"Blue");
    blue->poke1=charmander;
    blue->poke1=bulbasaur;
    blue->poke1=squirtle;
    blue->art=CHAMPIONBLUE;

    sprintf(red->name,"Red");
    red->poke1=charmander;
    red->poke1=bulbasaur;
    red->poke1=squirtle;
    red->art=CHAMPIONRED;

    sprintf(yellow->name,"Yellow");
    yellow->poke1=charmander;
    yellow->poke1=bulbasaur;
    yellow->poke1=squirtle;
    yellow->art=CHAMPIONYELLOW;

    switch (sort2)
    {
    case 0: // MINUS
        switch (sort1)
        {
        case 0:
            red->lvl=player->lvl;
            blue->lvl=player->lvl;
            yellow->lvl=player->lvl;
            //lvl poke adjustment
            break;
        
        case 1:
            red->lvl=player->lvl-1;
            blue->lvl=player->lvl-1;
            yellow->lvl=player->lvl-1;
            //lvl poke adjustment
            break;
        
        case 2:
            red->lvl=player->lvl-2;
            blue->lvl=player->lvl-2;
            yellow->lvl=player->lvl-2;
            //lvl poke adjustment
            break;
        
        default:
            break;
        }
        break;

    case 1: // ADD
        switch (sort1)
        {
        case 0:
            red->lvl=player->lvl;
            blue->lvl=player->lvl;
            yellow->lvl=player->lvl;
            //lvl poke adjustment
            break;
        
        case 1:
            red->lvl=player->lvl+1;
            blue->lvl=player->lvl+1;
            yellow->lvl=player->lvl+1;
            //lvl poke adjustment
            break;
        
        case 2:
            red->lvl=player->lvl+2;
            blue->lvl=player->lvl+2;
            yellow->lvl=player->lvl+2;
            //lvl poke adjustment
            break;
        
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void init_poke(pokemon* pokenull, pokemon* charmander, pokemon* bulbasaur, pokemon* squirtle){
    
    //pokenull
    pokenull->atk=0;
    pokenull->def=0;
    pokenull->dodge=0;
    pokenull->pv=0;
    pokenull->pv_save=0;
    pokenull->lvl=0;
    pokenull->catchrate=0;
    pokenull->art_box=NOPOKEMON;
    pokenull->art_front=NOPOKEMON;
    pokenull->art_behind=NOPOKEMON;
    pokenull->type=NOPOKEMON;
    pokenull->CTstat->type=0; 
    pokenull->CTutil->type=0; 
    pokenull->CTstat->quant=0;
    pokenull->CTutil->quant=0;
    sprintf(pokenull->basicatk,"none");
    sprintf(pokenull->speatk,"none");
    sprintf(pokenull->CTutil->name,"none");
    sprintf(pokenull->CTstat->name,"none");
    sprintf(pokenull->name,"no-pokemon");

    //charmander -
    charmander->atk=10.0;
    charmander->def=30.0/100;
    charmander->dodge=15;
    charmander->pv=35.0;
    charmander->pv_save=35.0;
    charmander->lvl=1;
    charmander->catchrate=50;
    charmander->art_box=CHARMANDER;
    charmander->art_front=CHARMANDER;
    charmander->art_behind=CHARMANDER;
    charmander->type=FIRE;
    charmander->CTstat->type=0;     
    charmander->CTutil->type=0; 
    charmander->CTstat->quant=0;
    charmander->CTutil->quant=0;    
    sprintf(charmander->basicatk,"fire-punch");
    sprintf(charmander->speatk,"flamethrower");
    sprintf(charmander->CTutil->name,"none");
    sprintf(charmander->CTstat->name,"none");
    sprintf(charmander->name,"Charmander");
    
    //bulbasaur -
    bulbasaur->atk=8.0;
    bulbasaur->def=45.0/100;
    bulbasaur->dodge=10;
    bulbasaur->pv=40.0;
    bulbasaur->pv_save=40.0;
    bulbasaur->lvl=1;
    bulbasaur->catchrate=50;
    bulbasaur->art_box=BULBASAUR;
    bulbasaur->art_behind=BULBASAUR;
    bulbasaur->art_front=BULBASAUR;
    bulbasaur->type=GRASS;
    bulbasaur->CTstat->type=0; 
    bulbasaur->CTutil->type=0; 
    bulbasaur->CTstat->quant=0;
    bulbasaur->CTutil->quant=0;    
    sprintf(bulbasaur->basicatk,"bullet-seed");
    sprintf(bulbasaur->speatk,"solar-beam");
    sprintf(bulbasaur->CTutil->name,"none");
    sprintf(bulbasaur->CTstat->name,"none");
    sprintf(bulbasaur->name,"Bulbasaur");

    //squirtle -
    squirtle->atk=9.0;
    squirtle->def=35.0/100;
    squirtle->dodge=18;
    squirtle->pv=33.0;
    squirtle->pv_save=33.0;
    squirtle->lvl=1;
    squirtle->catchrate=50;
    squirtle->art_box=SQUIRTLE;
    squirtle->art_behind=SQUIRTLE;
    squirtle->art_front=SQUIRTLE;
    squirtle->type=WATER;
    squirtle->CTstat->type=0; 
    squirtle->CTutil->type=0; 
    squirtle->CTstat->quant=0;
    squirtle->CTutil->quant=0;    
    sprintf(squirtle->basicatk,"water-gun");
    sprintf(squirtle->speatk,"hydropump");
    sprintf(squirtle->CTutil->name,"none");
    sprintf(squirtle->CTstat->name,"none");
    sprintf(squirtle->name,"Squirtle");  
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

    while (wscanw(write,"%s",newplayer->name)!=1)
    {
        mvwprintw(write,2,22,"                 ");
        wmove(write,2,22);
    }

    newplayer->lvl=1;
    newplayer->money=200;
    newplayer->xp=0;
    newplayer->is_on_water=0;

    newplayer->inventory[POKEBALLS].quant=10;
    newplayer->inventory[POKEBALLS].type=OTHER;
    sprintf(newplayer->inventory[POKEBALLS].name,"pokeballs"); 

    newplayer->inventory[POTIONS].quant=5;
    newplayer->inventory[POTIONS].type=OTHER;
    sprintf(newplayer->inventory[POTIONS].name,"potions"); 

    newplayer->inventory[CANDYS].quant=2;
    newplayer->inventory[CANDYS].type=OTHER;
    sprintf(newplayer->inventory[CANDYS].name,"candys"); 

    newplayer->inventory[SLOT4].quant=0;
    newplayer->inventory[SLOT4].type=EMPTY;
    sprintf(newplayer->inventory[SLOT4].name,"empty"); 

    newplayer->inventory[SLOT5].quant=0;
    newplayer->inventory[SLOT5].type=EMPTY;
    sprintf(newplayer->inventory[SLOT5].name,"empty"); 

    newplayer->inventory[SLOT6].quant=EMPTY;
    newplayer->inventory[SLOT6].type=0;
    sprintf(newplayer->inventory[SLOT6].name,"empty"); 



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

void duel(trainer* player, trainer champion){
    WINDOW* blackscreen=newwin(LINES-1,COLS-1,0,0);
    int finish=0, ch=ERR;   

    system("killall -9 vlc"); // stop main theme
    system("cvlc ressources/Battle-Theme.mp3 &"); // start battle theme

    wrefresh(blackscreen);
    while(finish==0)
    {
        WINDOW* match=newwin(LINES/1.5,COLS/1.5,LINES/6+1,COLS/6);
        box(match,0,0);

        wrefresh(match);

        usleep(16667);
        if (delwin(match)==ERR)
            {
                exit(42);
            }  
    }
    system("killall -9 vlc"); // stop battle theme
    system("cvlc ressources/Main-Theme.mp3 &"); // restart main theme
    if (delwin(blackscreen)==ERR)
    {
        exit(47);
    }
}

void house(trainer* player){
    int quit=0,finish=0,ch=ERR;
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
                if (x<=19 && x>=18 && y<=9) // mom area
                {
                    talkto_mom(house_map,player);
                }

                if (x==34 && y>=121 && y<=129) // exit area
                {
                    chargement();
                    finish=1;
                }  
                break;

            case 'm':
                menu(&quit,player);
                break;

            case 'i':
                inventory(player);
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

void league(trainer* player){
    int finish=0,ch=ERR,quit=0;
    int x=34,y=71;

    trainer red,blue,yellow,champion;
    init_champions(player,&blue,&red,&yellow);

    int sort=rand()%3+1;

    if (sort==1)
    {
        champion=red;
    }
    else if (sort==2)
    {
        champion=blue;
    }
    else if (sort==3)
    {
        champion=yellow;
    }
    
    while (finish==0)
    {
        WINDOW* league_map=newwin(40,150,13,43);
        WINDOW* line_wall_league=subwin(league_map,1,148,22,44);
        WINDOW* arena_zone=subwin(league_map, 25, 50, 25, 92);
        box(line_wall_league,0,0);
        box(arena_zone, 0, 0);
        box(league_map,0,0);
        
        print_league(league_map,x,y,champion);
        wrefresh(league_map);
        physic_league(ch,&x,&y);
        ch=getch();
        switch (ch)
        {
        case 'e':
        case '\r':
        case '\n':
            if (x==34 && y>68 && y<79) // exit area
            {
                chargement(); 
                finish=1;   
            }

            if (x==14 && y>61 && y<69) // champion of the ligue area
            {
                talkto_champion(league_map,player,champion);                
            }
            break;

        case 'm':
            menu(&quit,player);
            break;

        case 'i':
            inventory(player);
            break;
        default:
            break;
        }

        usleep(16667);
        if (delwin(line_wall_league)==ERR)
        {
            exit(37);
        }
        if (delwin(arena_zone)==ERR)
        {
            exit(38);
        }
        if (delwin(league_map)==ERR)
        {
            exit(36);
        }
    }
}

void lab(trainer* player){
    int quit=0,ch=ERR, finish=0;
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
                talkto_prof(lab_map,player);                
            }

            if (x==7 && y>=35 && y<=41)
            {
                computer(player);                
            }
            break;

        case 'm':
            menu(&quit,player);
            break;
        
        case 'i':
            inventory(player);
            break;
        
        default:
            break;
        }

        usleep(16667);
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
    int quit=0,finish=0,ch=ERR;
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

            case 'm':
                menu(&quit,player);
                break;

            case 'i':
                inventory(player);
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

void your_team(trainer* player){
    WINDOW* blackscreen=newwin(LINES-1,COLS-1,0,0);
    int finish=0,ch=ERR;
    int x=1,y=1;
    
     while (finish==0)
    {
        WINDOW* yourteam = newwin(40,155,14,40);
        WINDOW* yourteam_array=newwin(4,50,10,50);
        WINDOW* box1=subwin(yourteam,20,50,14,41);
        WINDOW* box2=subwin(yourteam,20,51,14,92);
        WINDOW* box3=subwin(yourteam,20,50,14,144);
        WINDOW* box4=subwin(yourteam,20,50,34,41);
        WINDOW* box5=subwin(yourteam,20,51,34,92);
        WINDOW* box6=subwin(yourteam,20,50,34,144);
        box(yourteam,0,0);
        box(box1,0,0);
        box(box2,0,0);
        box(box3,0,0);
        box(box4,0,0);
        box(box5,0,0);
        box(box6,0,0);

        mvwprintw(yourteam_array,0,0,"__  ______  __  _____    _____________   __  ___");
        mvwprintw(yourteam_array,0+1,0,"\\ \\/ / __ \\/ / / / _ \\  /_  __/ __/ _ | /  |/  /");
        mvwprintw(yourteam_array,0+2,0," \\  / /_/ / /_/ / , _/   / / / _// __ |/ /|_/ / ");
        mvwprintw(yourteam_array,0+3,0," /_/\\____/\\____/_/|_|   /_/ /___/_/ |_/_/  /_/  ");
                                  
        ch=getch();
        print_yourteam(box1,box2,box3,box4,box5,box6,player,x,y);        
        wrefresh(yourteam);
        wrefresh(yourteam_array);

        physic_yourteam(ch,&x,&y); // colisions

        switch (ch) // actions
        {
        case ' ':
            wrefresh(blackscreen);
            finish=1;
            break;
        case 'e':
        case '\n':
        case '\r':
            int finishact=0;
            int xact=5;
            pokemon tmp;

            while(finishact==0)
            {
                WINDOW* actions=newwin(10,20,20,10);
                box(actions,0,0);

                mvwprintw(actions,1,2,"What do you want");
                mvwprintw(actions,2,2,"to do ?");
                mvwprintw(actions,5,6,"Move");
                mvwprintw(actions,7,6,"Nothing");
                mvwprintw(actions,xact,4,">");
                wrefresh(actions);

                ch=getch();

                switch (ch)
                {
                case 'z':
                case KEY_UP:
                    if (xact!=5)
                    {
                        mvwprintw(actions,xact,4," ");
                        xact-=2;
                    }
                    break;

                case 's':
                case KEY_DOWN:
                    if (xact!=7)
                    {
                        mvwprintw(actions,xact,4," ");
                        xact+=2;
                    }
                    break;

                case ' ':
                    wclear(actions);
                    wrefresh(actions);
                    finishact=1;
                    break;
                
                case 'e':
                case '\r':
                case '\n':
                    if (xact==7)
                    {
                        wclear(actions);
                        wrefresh(actions);
                        finishact=1;
                    }
                    
                    else if (xact==5)
                    {
                        int whatpoke=0;
                        if (x==1)
                        {
                            switch (y)
                            {
                            case 1:
                                tmp=player->poke1; 
                                whatpoke=1;
                                break;

                            case 2:
                                tmp=player->poke2; 
                                whatpoke=2;
                                break;

                            case 3:
                                tmp=player->poke3; 
                                whatpoke=3;
                                break;

                            default:
                                break;
                            }
                        }

                        if (x==2)
                        {
                            switch (y)
                            {
                            case 1:
                                tmp=player->poke4; 
                                whatpoke=4;
                                break;

                            case 2:
                                tmp=player->poke5; 
                                whatpoke=5;
                                break;

                            case 3:
                                tmp=player->poke6; 
                                whatpoke=6;
                                break;

                            default:
                                break;
                            }
                        }
                        
                        int xmove=1,ymove=1,moved=0;
                        while (moved==0)
                        {
                            box(yourteam,0,0);
                            box(box1,0,0);
                            box(box2,0,0);
                            box(box3,0,0);
                            box(box4,0,0);
                            box(box5,0,0);
                            box(box6,0,0);
                            print_yourteam(box1,box2,box3,box4,box5,box6,player,xmove,ymove);
                            physic_yourteam(ch,&xmove,&ymove);
                            wrefresh(yourteam);

                            ch=getch();
                            switch (ch)
                            {
                            
                            case ' ':
                                moved=1;
                                finishact=1;
                                wclear(actions);
                                wrefresh(actions);
                                break;
                            
                            case 'e':
                            case '\n':
                            case '\r':

                                if (whatpoke==1)
                                {
                                    if (xmove==1)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke1=player->poke1;
                                            player->poke1=tmp;
                                            break;

                                        case 2:
                                            player->poke1=player->poke2;
                                            player->poke2=tmp;
                                            break;

                                        case 3:
                                            player->poke1=player->poke3;
                                            player->poke3=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }

                                    if (xmove==2)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke1=player->poke4;
                                            player->poke4=tmp;
                                            break;

                                        case 2:
                                            player->poke1=player->poke5;
                                            player->poke5=tmp;
                                            break;

                                        case 3:
                                            player->poke1=player->poke6;
                                            player->poke6=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }
                                }

                                else if (whatpoke==2)
                                {
                                    if (xmove==1)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke2=player->poke1;
                                            player->poke1=tmp;
                                            break;

                                        case 2:
                                            player->poke2=player->poke2;
                                            player->poke2=tmp;
                                            break;

                                        case 3:
                                            player->poke2=player->poke3;
                                            player->poke3=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }

                                    if (xmove==2)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke2=player->poke4;
                                            player->poke4=tmp;
                                            break;

                                        case 2:
                                            player->poke2=player->poke5;
                                            player->poke5=tmp;
                                            break;

                                        case 3:
                                            player->poke2=player->poke6;
                                            player->poke6=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }
                                }

                                else if (whatpoke==3)
                                {
                                    if (xmove==1)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke3=player->poke1;
                                            player->poke1=tmp;
                                            break;

                                        case 2:
                                            player->poke3=player->poke2;
                                            player->poke2=tmp;
                                            break;

                                        case 3:
                                            player->poke3=player->poke3;
                                            player->poke3=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }

                                    if (xmove==2)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke3=player->poke4;
                                            player->poke4=tmp;
                                            break;

                                        case 2:
                                            player->poke3=player->poke5;
                                            player->poke5=tmp;
                                            break;

                                        case 3:
                                            player->poke3=player->poke6;
                                            player->poke6=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }
                                }

                                else if (whatpoke==4)
                                {
                                    if (xmove==1)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke4=player->poke1;
                                            player->poke1=tmp;
                                            break;

                                        case 2:
                                            player->poke4=player->poke2;
                                            player->poke2=tmp;
                                            break;

                                        case 3:
                                            player->poke4=player->poke3;
                                            player->poke3=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }

                                    if (xmove==2)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke4=player->poke4;
                                            player->poke4=tmp;
                                            break;

                                        case 2:
                                            player->poke4=player->poke5;
                                            player->poke5=tmp;
                                            break;

                                        case 3:
                                            player->poke4=player->poke6;
                                            player->poke6=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }
                                }

                                else if (whatpoke==5)
                                {
                                    if (xmove==1)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke5=player->poke1;
                                            player->poke1=tmp;
                                            break;

                                        case 2:
                                            player->poke5=player->poke2;
                                            player->poke2=tmp;
                                            break;

                                        case 3:
                                            player->poke5=player->poke3;
                                            player->poke3=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }

                                    if (xmove==2)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke5=player->poke4;
                                            player->poke4=tmp;
                                            break;

                                        case 2:
                                            player->poke5=player->poke5;
                                            player->poke5=tmp;
                                            break;

                                        case 3:
                                            player->poke5=player->poke6;
                                            player->poke6=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }
                                }

                                else if (whatpoke==6)
                                {
                                    if (xmove==1)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke6=player->poke1;
                                            player->poke1=tmp;
                                            break;

                                        case 2:
                                            player->poke6=player->poke2;
                                            player->poke2=tmp;
                                            break;

                                        case 3:
                                            player->poke6=player->poke3;
                                            player->poke3=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }

                                    if (xmove==2)
                                    {
                                        switch (ymove)
                                        {
                                        case 1:
                                            player->poke6=player->poke4;
                                            player->poke4=tmp;
                                            break;

                                        case 2:
                                            player->poke6=player->poke5;
                                            player->poke5=tmp;
                                            break;

                                        case 3:
                                            player->poke6=player->poke6;
                                            player->poke6=tmp;
                                            break;

                                        default:
                                            break;
                                        }
                                    }
                                }

                                moved=1;
                                finishact=1;
                                wclear(actions);
                                wrefresh(actions);
                                break;

                            default:
                                break;
                            }

                            usleep(16667);
                            wclear(yourteam);
                        }
                    }
                    
                    break;
                default:
                    break;
                }

                usleep(16667);
                if(delwin(actions)==ERR)
                {
                    exit(45);
                } 
            }
            break;
        default:
            break;
        }

        usleep(16667);
        if(delwin(box1)==ERR)
        {
            exit(36);
        }
        if(delwin(box2)==ERR)
        {
            exit(37);
        }
        if(delwin(box3)==ERR)
        {
            exit(38);
        }
        if(delwin(box4)==ERR)
        {
            exit(39);
        }
        if(delwin(box5)==ERR)
        {
            exit(40);
        }
        if(delwin(box6)==ERR)
        {
            exit(41);
        }
        if(delwin(yourteam)==ERR)
        {
            exit(34);
        }
        if(delwin(yourteam_array)==ERR)
        {
            exit(33);
        }   
    }
    wrefresh(blackscreen);
        if (delwin(blackscreen)==ERR)
        {
            exit(32);
        }
}

void menu(int* quit,trainer* player){
    WINDOW* blackscreen=newwin(LINES-1,COLS-1,0,0);
    int chmenu=ERR,menuexit=0;
    int x=13,y=95;
    
    while(chmenu!='m' && menuexit==0)
        {            
            WINDOW* winmenu=newwin(LINES/1.5,COLS/1.5,LINES/6+1,COLS/6);
            
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
                        //end music
                        system("killall -9 vlc");
                        endwin();
                        exit(0);
                        break;

                    case 22:
                        chargement();
                        break;

                    case 13:
                        wrefresh(blackscreen);
                        your_team(player);
                        break;
                    }
                    break;

                case ' ':
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    menuexit=1;
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
        wclear(blackscreen);
        wrefresh(blackscreen);
        if (delwin(blackscreen)==ERR)
        {
            exit(24);
        }      
}

void inventory(trainer* player){
    WINDOW* blackscreen=newwin(LINES-1,COLS-1,0,0);
    int finish=0,ch=ERR;
    int x=12,y=17;

    while (finish==0)
    {
        WINDOW* sac = newwin(29,118,20,60);
        WINDOW* bag_array=newwin(5,50,15,60);
        box(sac,0,0);

        mvwprintw(bag_array,1,12," ___   _   ___ ");
        mvwprintw(bag_array,1+1,12,"| _ ) /_\\ / __|");
        mvwprintw(bag_array,1+2,12,"| _ \\/ _ \\ (_ |");
        mvwprintw(bag_array,1+3,12,"|___/_/ \\_\\___|");
                                  
        ch=getch();
        print_inventory(sac,player,x,y);        
        wrefresh(sac);
        wrefresh(bag_array);

        physic_inventory(ch,&x,&y); // colisions

        switch (ch) // actions
        {
        case 'i':
        case ' ':
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
    wrefresh(blackscreen);
        if (delwin(blackscreen)==ERR)
        {
            exit(25);
        } 
}

void roadto_league(trainer* player){
    int l=97,c=70;
    int quit=0,finish=0, ch=ERR;

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
                chargement();
            }

            if (l==13 && c>=66 && c<=74) // league door
            {
                chargement();
                league(player);
            }
            

            if (l==76)  // border water down 
            {
                if (player->poke1.CTutil->type==SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke1.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke2.CTutil->type==SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke2.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke3.CTutil->type==SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke3.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke4.CTutil->type==SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke4.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke5.CTutil->type==SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke5.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke6.CTutil->type==SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke6.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else
                {
                    write_flush(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"None of your pokemon does have surf !");
                    sleep(1);
                }
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
                if (player->poke1.CTutil->type=SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke1.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke2.CTutil->type=SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke2.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke3.CTutil->type=SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke3.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke4.CTutil->type=SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke4.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke5.CTutil->type=SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke5.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke6.CTutil->type=SURF)
                {
                    mvwprintw(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"%s uses surf !",player->poke6.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else
                {
                    write_flush(cam,((LINES-2)/2)-1,((COLS-2)/2)+5,"None of your pokemon have surf !");
                    sleep(1);
                }
            }
            break;
        
        case 'm':
            menu(&quit,player);
            break;

        case 'i':
            inventory(player);
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
    WINDOW* blackscreen=newwin(LINES-1,COLS-1,0,0);
    int ch=ERR;
    
    ch=getch();
    print_main_menu(win,*x,*y);

    wrefresh(blackscreen);
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
            create_newplayer(player);
            get_firstpoke(player);
            league(player);
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
    if(delwin(blackscreen)==ERR)
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
            menu(quit,player);
            break;

        case 'i':
            inventory(player);
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