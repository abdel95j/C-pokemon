#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/physic.h"
#include "../headers/talk.h"

void talkto_prof(WINDOW* lab_map, trainer* player){
    int finish=0,ch=ERR;
    int x=2;

    write_flush(lab_map,3,108,"Hey %s",player->name);
    wrefresh(lab_map);
    sleep(2);
    mvwprintw(lab_map,3,108,"                                         ");
    write_flush(lab_map,3,108,"What CT do you want to use ?");

    while(finish==0)
    {
        WINDOW* chat=subwin(lab_map,11,18,25,115);
        box(chat,0,0);
        
        mvwprintw(chat,x,4,">");
        mvwprintw(chat,2,7,"Surf");
        mvwprintw(chat,4,7,"Leer");
        mvwprintw(chat,6,7,"Roar");
        mvwprintw(chat,8,7,"EXIT");

        wrefresh(chat);

        ch=getch();
        switch (ch)
        {
        case 'z':
        case KEY_UP:
            if (x!=2)
            {
                mvwprintw(chat,x,4," ");
                x-=2;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (x!=8)
            {
                mvwprintw(chat,x,4," ");
                x+=2;
            }  
            break;

        case ' ':
            mvwprintw(lab_map,3,108,"                                         ");
            write_flush(lab_map,3,108,"See ya !");
            sleep(1);
            finish=1;
            break;

        case 'e':
        case '\r':
        case '\n':
            switch (x)
            {
            case 8:
                mvwprintw(lab_map,3,108,"                                         ");
                write_flush(lab_map,3,108,"See ya !");
                sleep(1);
                finish=1;
                break;

            case 2: // Surf
                mvwprintw(lab_map,3,108,"                                         ");
                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                int finish_SURF=0;
                int xSURF=2;
                while (finish_SURF==0)
                {
                    WINDOW* blank=subwin(lab_map,11,18,25,115);
                    wclear(chat);
                    wrefresh(blank);

                    box(chat,0,0);
                    mvwprintw(chat,xSURF,2,">");
                    mvwprintw(chat,2,5,"%s",player->poke1.name);
                    mvwprintw(chat,3,5,"%s",player->poke2.name);
                    mvwprintw(chat,4,5,"%s",player->poke3.name);
                    mvwprintw(chat,5,5,"%s",player->poke4.name);
                    mvwprintw(chat,6,5,"%s",player->poke5.name);
                    mvwprintw(chat,7,5,"%s",player->poke6.name);
                    wrefresh(chat);

                    ch=getch();
                    switch (ch)
                    {
                    case 'z':
                    case KEY_UP:
                        if (xSURF!=2)
                        {
                            mvwprintw(chat,xSURF,2," ");
                            xSURF-=1;
                        }
                        break;

                    case 's':
                    case KEY_DOWN:
                        if (xSURF!=7)
                        {
                            mvwprintw(chat,xSURF,2," ");
                            xSURF+=1;
                        }  
                        break;

                    case ' ':
                    mvwprintw(lab_map,3,108,"                                         ");
                    write_flush(lab_map,3,108,"What CT do you want to use ?");
                    wrefresh(blank);
                    wclear(chat);
                    sleep(1);
                    finish_SURF=1;
                    break;

                    case 'e':
                    case '\n':
                    case '\r':
                        switch (xSURF)
                        {
                        case 2:
                            if (player->poke1.type!=WATER)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Surf");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[3].type==SURF)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke1.CTutil->quant=1;
                                player->poke1.CTutil->type=SURF;
                                sprintf(player->poke1.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke1.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[4].type==SURF)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke1.CTutil->quant=1;
                                player->poke1.CTutil->type=SURF;
                                sprintf(player->poke1.CTutil->name,"Surf");
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke1.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[5].type==SURF)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke1.CTutil->quant=1;
                                player->poke1.CTutil->type=SURF;
                                sprintf(player->poke1.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke1.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Surf CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            break;

                        case 3:
                            if (player->poke2.type!=WATER)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Surf");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[3].type==SURF)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke2.CTutil->quant=1;
                                player->poke2.CTutil->type=SURF;
                                sprintf(player->poke2.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke2.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[4].type==SURF)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke2.CTutil->quant=1;
                                player->poke2.CTutil->type=SURF;
                                sprintf(player->poke2.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke2.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[5].type==SURF)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke2.CTutil->quant=1;
                                player->poke2.CTutil->type=SURF;
                                sprintf(player->poke2.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke2.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Surf CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            break;
                        
                        case 4:
                            if (player->poke3.type!=WATER)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Surf");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[3].type==SURF)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke3.CTutil->quant=1;
                                player->poke3.CTutil->type=SURF;
                                sprintf(player->poke3.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke3.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[4].type==SURF)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke3.CTutil->quant=1;
                                player->poke3.CTutil->type=SURF;
                                sprintf(player->poke3.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke3.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[5].type==SURF)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke3.CTutil->quant=1;
                                player->poke3.CTutil->type=SURF;
                                sprintf(player->poke3.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke3.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Surf CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            break;

                        case 5:
                            if (player->poke4.type!=WATER)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Surf");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[3].type==SURF)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke4.CTutil->quant=1;
                                player->poke4.CTutil->type=SURF;
                                sprintf(player->poke4.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke4.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[4].type==SURF)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke4.CTutil->quant=1;
                                player->poke4.CTutil->type=SURF;
                                sprintf(player->poke4.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke4.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[5].type==SURF)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke4.CTutil->quant=1;
                                player->poke4.CTutil->type=SURF;
                                sprintf(player->poke4.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke4.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Surf CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            break;

                        case 6:
                            if (player->poke5.type!=WATER)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Surf");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[3].type==SURF)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke5.CTutil->quant=1;
                                player->poke5.CTutil->type=SURF;
                                sprintf(player->poke5.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke5.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[4].type==SURF)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke5.CTutil->quant=1;
                                player->poke5.CTutil->type=SURF;
                                sprintf(player->poke5.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke5.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[5].type==SURF)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke5.CTutil->quant=1;
                                player->poke5.CTutil->type=SURF;
                                sprintf(player->poke5.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke5.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Surf CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            break;

                        case 7:
                            if (player->poke6.type!=WATER)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Surf");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[3].type==SURF)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke6.CTutil->quant=1;
                                player->poke6.CTutil->type=SURF;
                                sprintf(player->poke6.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke6.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[4].type==SURF)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke6.CTutil->quant=1;
                                player->poke6.CTutil->type=SURF;
                                sprintf(player->poke6.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke6.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else if (player->inventory[5].type==SURF)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke6.CTutil->quant=1;
                                player->poke6.CTutil->type=SURF;
                                sprintf(player->poke6.CTutil->name,"Surf");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Surf successfully !",player->poke6.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Surf CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Surf ?");
                            }
                            break;
                        
                        default:
                            break;
                        }
                        break;

                    
                    
                    default:
                        break;
                    }

                    usleep(16667);
                    if (delwin(blank)==ERR)
                    {
                        system("killall -9 vlc >/dev/null 2>&1 &");
                        exit(84);
                    }
                }
                
                break;

            case 4: // Leer
                mvwprintw(lab_map,3,108,"                                         ");
                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                int finish_LEER=0;
                int xLEER=2;
                while (finish_LEER==0)
                {
                    WINDOW* blank=subwin(lab_map,11,18,25,115);
                    wclear(chat);
                    wrefresh(blank);

                    box(chat,0,0);
                    mvwprintw(chat,xLEER,2,">");
                    mvwprintw(chat,2,5,"%s",player->poke1.name);
                    mvwprintw(chat,3,5,"%s",player->poke2.name);
                    mvwprintw(chat,4,5,"%s",player->poke3.name);
                    mvwprintw(chat,5,5,"%s",player->poke4.name);
                    mvwprintw(chat,6,5,"%s",player->poke5.name);
                    mvwprintw(chat,7,5,"%s",player->poke6.name);
                    wrefresh(chat);

                    ch=getch();
                    switch (ch)
                    {
                    case 'z':
                    case KEY_UP:
                        if (xLEER!=2)
                        {
                            mvwprintw(chat,xLEER,2," ");
                            xLEER-=1;
                        }
                        break;

                    case 's':
                    case KEY_DOWN:
                        if (xLEER!=7)
                        {
                            mvwprintw(chat,xLEER,2," ");
                            xLEER+=1;
                        }  
                        break;

                    case ' ':
                    mvwprintw(lab_map,3,108,"                                         ");
                    write_flush(lab_map,3,108,"What CT do you want to use ?");
                    wrefresh(blank);
                    wclear(chat);
                    sleep(1);
                    finish_LEER=1;
                    break;

                    case 'e':
                    case '\n':
                    case '\r':
                        switch (xLEER)
                        {
                        case 2:
                            if (player->poke1.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Leer");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[3].type==LEER)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke1.CTstat->quant=1;
                                player->poke1.CTstat->type=LEER;
                                sprintf(player->poke1.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke1.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[4].type==LEER)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke1.CTstat->quant=1;
                                player->poke1.CTstat->type=LEER;
                                sprintf(player->poke1.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke1.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[5].type==LEER)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke1.CTstat->quant=1;
                                player->poke1.CTstat->type=LEER;
                                sprintf(player->poke1.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke1.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Leer CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            break;

                        case 3:
                            if (player->poke2.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Leer");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[3].type==LEER)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke2.CTstat->quant=1;
                                player->poke2.CTstat->type=LEER;
                                sprintf(player->poke2.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke2.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[4].type==LEER)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke2.CTstat->quant=1;
                                player->poke2.CTstat->type=LEER;
                                sprintf(player->poke2.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke2.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[5].type==LEER)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke2.CTstat->quant=1;
                                player->poke2.CTstat->type=LEER;
                                sprintf(player->poke2.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke2.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Leer CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            break;
                        
                        case 4:
                            if (player->poke3.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Leer");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[3].type==LEER)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke3.CTstat->quant=1;
                                player->poke3.CTstat->type=LEER;
                                sprintf(player->poke3.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke3.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[4].type==LEER)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke3.CTstat->quant=1;
                                player->poke3.CTstat->type=LEER;
                                sprintf(player->poke3.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke3.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[5].type==LEER)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke3.CTstat->quant=1;
                                player->poke3.CTstat->type=LEER;
                                sprintf(player->poke3.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke3.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Leer CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            break;

                        case 5:
                            if (player->poke4.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Leer");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[3].type==LEER)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke4.CTstat->quant=1;
                                player->poke4.CTstat->type=LEER;
                                sprintf(player->poke4.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke4.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[4].type==LEER)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke4.CTstat->quant=1;
                                player->poke4.CTstat->type=LEER;
                                sprintf(player->poke4.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke4.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[5].type==LEER)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke4.CTstat->quant=1;
                                player->poke4.CTstat->type=LEER;
                                sprintf(player->poke4.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke4.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Leer CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            break;

                        case 6:
                            if (player->poke5.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Leer");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[3].type==LEER)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke5.CTstat->quant=1;
                                player->poke5.CTstat->type=LEER;
                                sprintf(player->poke5.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke5.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[4].type==LEER)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke5.CTstat->quant=1;
                                player->poke5.CTstat->type=LEER;
                                sprintf(player->poke5.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke5.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[5].type==LEER)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke5.CTstat->quant=1;
                                player->poke5.CTstat->type=LEER;
                                sprintf(player->poke5.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke5.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Leer CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            break;

                        case 7:
                            if (player->poke6.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Leer");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[3].type==LEER)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke6.CTstat->quant=1;
                                player->poke6.CTstat->type=LEER;
                                sprintf(player->poke6.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke6.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[4].type==LEER)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke6.CTstat->quant=1;
                                player->poke6.CTstat->type=LEER;
                                sprintf(player->poke6.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke6.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else if (player->inventory[5].type==LEER)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke6.CTstat->quant=1;
                                player->poke6.CTstat->type=LEER;
                                sprintf(player->poke6.CTstat->name,"Leer");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Leer successfully !",player->poke6.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Leer CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Leer ?");
                            }
                            break;
                        
                        default:
                            break;
                        }
                        break;

                    
                    
                    default:
                        break;
                    }

                    usleep(16667);
                    if (delwin(blank)==ERR)
                    {
                        system("killall -9 vlc >/dev/null 2>&1 &");
                        exit(85);
                    }
                }
                
                break;

            case 6: // Roar
                mvwprintw(lab_map,3,108,"                                         ");
                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                int finish_ROAR=0;
                int xROAR=2;
                while (finish_ROAR==0)
                {
                    WINDOW* blank=subwin(lab_map,11,18,25,115);
                    wclear(chat);
                    wrefresh(blank);

                    box(chat,0,0);
                    mvwprintw(chat,xROAR,2,">");
                    mvwprintw(chat,2,5,"%s",player->poke1.name);
                    mvwprintw(chat,3,5,"%s",player->poke2.name);
                    mvwprintw(chat,4,5,"%s",player->poke3.name);
                    mvwprintw(chat,5,5,"%s",player->poke4.name);
                    mvwprintw(chat,6,5,"%s",player->poke5.name);
                    mvwprintw(chat,7,5,"%s",player->poke6.name);
                    wrefresh(chat);

                    ch=getch();
                    switch (ch)
                    {
                    case 'z':
                    case KEY_UP:
                        if (xROAR!=2)
                        {
                            mvwprintw(chat,xROAR,2," ");
                            xROAR-=1;
                        }
                        break;

                    case 's':
                    case KEY_DOWN:
                        if (xROAR!=7)
                        {
                            mvwprintw(chat,xROAR,2," ");
                            xROAR+=1;
                        }  
                        break;

                    case ' ':
                    mvwprintw(lab_map,3,108,"                                         ");
                    write_flush(lab_map,3,108,"What CT do you want to use ?");
                    wrefresh(blank);
                    wclear(chat);
                    sleep(1);
                    finish_ROAR=1;
                    break;

                    case 'e':
                    case '\n':
                    case '\r':
                        switch (xROAR)
                        {
                        case 2:
                            if (player->poke1.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Roar");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[3].type==ROAR)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke1.CTstat->quant=1;
                                player->poke1.CTstat->type=ROAR;
                                sprintf(player->poke1.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke1.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[4].type==ROAR)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke1.CTstat->quant=1;
                                player->poke1.CTstat->type=ROAR;
                                sprintf(player->poke1.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke1.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[5].type==ROAR)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke1.CTstat->quant=1;
                                player->poke1.CTstat->type=ROAR;
                                sprintf(player->poke1.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke1.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Roar CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            break;

                        case 3:
                            if (player->poke2.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Roar");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[3].type==ROAR)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke2.CTstat->quant=1;
                                player->poke2.CTstat->type=ROAR;
                                sprintf(player->poke2.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke2.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[4].type==ROAR)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke2.CTstat->quant=1;
                                player->poke2.CTstat->type=ROAR;
                                sprintf(player->poke2.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke2.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[5].type==ROAR)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke2.CTstat->quant=1;
                                player->poke2.CTstat->type=ROAR;
                                sprintf(player->poke2.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke2.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Roar CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            break;
                        
                        case 4:
                            if (player->poke3.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Roar");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[3].type==ROAR)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke3.CTstat->quant=1;
                                player->poke3.CTstat->type=ROAR;
                                sprintf(player->poke3.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke3.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[4].type==ROAR)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke3.CTstat->quant=1;
                                player->poke3.CTstat->type=ROAR;
                                sprintf(player->poke3.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke3.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[5].type==ROAR)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke3.CTstat->quant=1;
                                player->poke3.CTstat->type=ROAR;
                                sprintf(player->poke3.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke3.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Roar CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            break;

                        case 5:
                            if (player->poke4.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Roar");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[3].type==ROAR)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke4.CTstat->quant=1;
                                player->poke4.CTstat->type=ROAR;
                                sprintf(player->poke4.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke4.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[4].type==ROAR)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke4.CTstat->quant=1;
                                player->poke4.CTstat->type=ROAR;
                                sprintf(player->poke4.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke4.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[5].type==ROAR)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke4.CTstat->quant=1;
                                player->poke4.CTstat->type=ROAR;
                                sprintf(player->poke4.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke4.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Roar CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            break;

                        case 6:
                            if (player->poke5.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Roar");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[3].type==ROAR)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke5.CTstat->quant=1;
                                player->poke5.CTstat->type=ROAR;
                                sprintf(player->poke5.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke5.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[4].type==ROAR)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke5.CTstat->quant=1;
                                player->poke5.CTstat->type=ROAR;
                                sprintf(player->poke5.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke5.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[5].type==ROAR)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke5.CTstat->quant=1;
                                player->poke5.CTstat->type=ROAR;
                                sprintf(player->poke5.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke5.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Roar CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            break;

                        case 7:
                            if (player->poke6.type==NOPOKEMON)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"This pokemon can't learn Roar");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[3].type==ROAR)
                            {
                                player->inventory[3].quant-=1;
                                if (player->inventory[3].quant==0)
                                {
                                    player->inventory[3].type=EMPTY;
                                    sprintf(player->inventory[3].name,"empty");
                                }

                                player->poke6.CTstat->quant=1;
                                player->poke6.CTstat->type=ROAR;
                                sprintf(player->poke6.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke6.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[4].type==ROAR)
                            {
                                player->inventory[4].quant-=1;
                                if (player->inventory[4].quant==0)
                                {
                                    player->inventory[4].type=EMPTY;
                                    sprintf(player->inventory[4].name,"empty");
                                }

                                player->poke6.CTstat->quant=1;
                                player->poke6.CTstat->type=ROAR;
                                sprintf(player->poke6.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke6.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else if (player->inventory[5].type==ROAR)
                            {
                                player->inventory[5].quant-=1;
                                if (player->inventory[5].quant==0)
                                {
                                    player->inventory[5].type=EMPTY;
                                    sprintf(player->inventory[5].name,"empty");
                                }

                                player->poke6.CTstat->quant=1;
                                player->poke6.CTstat->type=ROAR;
                                sprintf(player->poke6.CTstat->name,"Roar");

                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"%s learned Roar successfully !",player->poke6.name);
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,118,"You don't have any Roar CT");
                                sleep(1);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to teach Roar ?");
                            }
                            break;
                        
                        default:
                            break;
                        }
                        break;
                    
                    default:
                        break;
                    }

                    usleep(16667);
                    if (delwin(blank)==ERR)
                    {
                        system("killall -9 vlc >/dev/null 2>&1 &");
                        exit(86);
                    }
                }
                
                break;

            default:
                break;
            }  
        } 
        usleep(16667);
        if (delwin(chat)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(87);
        }  
    }
}

void change_poke(WINDOW* in,trainer* player,int* xin,int* yin,int whatpoke){
    int ch=ERR,finish=0;
    pokemon tmp;

    while (finish==0)
    {
        mvwprintw(in,*xin,*yin,">");
        wrefresh(in);

        ch=getch();
        switch (ch)
        {
        case ' ':
            mvwprintw(in,*xin,*yin," ");
            finish=1;
            break;
        
        case 'z':
        case KEY_UP:
            if (*xin!=6)
            {
                mvwprintw(in,*xin,*yin," ");
                *xin-=2;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (*xin!=24)
            {
                mvwprintw(in,*xin,*yin," ");
                *xin+=2;
            }     
            break;

        case 'd':
        case KEY_RIGHT:
            if (*yin==11)
            {
                mvwprintw(in,*xin,*yin," ");
                *yin=47;
            }
            break;

        case 'q':
        case KEY_LEFT:
            if (*yin==47)
            {
                mvwprintw(in,*xin,*yin," ");
                *yin=11;
            } 
            break;

        case 'e':
        case '\n':
        case '\r':
            switch (whatpoke)
            {
            case 1:
                tmp=player->poke1;
                if (*yin==11)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke1=player->pc[0];
                        player->pc[0]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke1=player->pc[1];
                        player->pc[1]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke1=player->pc[2];
                        player->pc[2]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke1=player->pc[3];
                        player->pc[3]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke1=player->pc[4];
                        player->pc[4]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke1=player->pc[5];
                        player->pc[5]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke1=player->pc[6];
                        player->pc[6]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke1=player->pc[7];
                        player->pc[7]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke1=player->pc[8];
                        player->pc[8]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke1=player->pc[9];
                        player->pc[9]=tmp;
                        finish=1;
                        break;

                    default:
                        break;
                    }
                }

                else if (*yin==47)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke1=player->pc[10];
                        player->pc[10]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke1=player->pc[11];
                        player->pc[11]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke1=player->pc[12];
                        player->pc[12]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke1=player->pc[13];
                        player->pc[13]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke1=player->pc[14];
                        player->pc[14]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke1=player->pc[15];
                        player->pc[15]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke1=player->pc[16];
                        player->pc[16]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke1=player->pc[17];
                        player->pc[17]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke1=player->pc[18];
                        player->pc[18]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke1=player->pc[19];
                        player->pc[19]=tmp;
                        finish=1;
                        break;
                        
                    default:
                        break;
                    }
                }
                break;

            case 2:
                tmp=player->poke2;
                if (*yin==11)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke2=player->pc[0];
                        player->pc[0]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke2=player->pc[1];
                        player->pc[1]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke2=player->pc[2];
                        player->pc[2]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke2=player->pc[3];
                        player->pc[3]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke2=player->pc[4];
                        player->pc[4]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke2=player->pc[5];
                        player->pc[5]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke2=player->pc[6];
                        player->pc[6]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke2=player->pc[7];
                        player->pc[7]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke2=player->pc[8];
                        player->pc[8]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke2=player->pc[9];
                        player->pc[9]=tmp;
                        finish=1;
                        break;

                    default:
                        break;
                    }
                }

                else if (*yin==47)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke2=player->pc[10];
                        player->pc[10]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke2=player->pc[11];
                        player->pc[11]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke2=player->pc[12];
                        player->pc[12]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke2=player->pc[13];
                        player->pc[13]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke2=player->pc[14];
                        player->pc[14]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke2=player->pc[15];
                        player->pc[15]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke2=player->pc[16];
                        player->pc[16]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke2=player->pc[17];
                        player->pc[17]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke2=player->pc[18];
                        player->pc[18]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke2=player->pc[19];
                        player->pc[19]=tmp;
                        finish=1;
                        break;
                        
                    default:
                        break;
                    }
                }
                break;

            case 3:
                tmp=player->poke3;
                if (*yin==11)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke3=player->pc[0];
                        player->pc[0]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke3=player->pc[1];
                        player->pc[1]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke3=player->pc[2];
                        player->pc[2]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke3=player->pc[3];
                        player->pc[3]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke3=player->pc[4];
                        player->pc[4]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke3=player->pc[5];
                        player->pc[5]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke3=player->pc[6];
                        player->pc[6]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke3=player->pc[7];
                        player->pc[7]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke3=player->pc[8];
                        player->pc[8]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke3=player->pc[9];
                        player->pc[9]=tmp;
                        finish=1;
                        break;

                    default:
                        break;
                    }
                }

                else if (*yin==47)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke3=player->pc[10];
                        player->pc[10]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke3=player->pc[11];
                        player->pc[11]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke3=player->pc[12];
                        player->pc[12]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke3=player->pc[13];
                        player->pc[13]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke3=player->pc[14];
                        player->pc[14]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke3=player->pc[15];
                        player->pc[15]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke3=player->pc[16];
                        player->pc[16]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke3=player->pc[17];
                        player->pc[17]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke3=player->pc[18];
                        player->pc[18]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke3=player->pc[19];
                        player->pc[19]=tmp;
                        finish=1;
                        break;
                        
                    default:
                        break;
                    }
                }
                break;

            case 4:
                tmp=player->poke4;
                if (*yin==11)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke4=player->pc[0];
                        player->pc[0]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke4=player->pc[1];
                        player->pc[1]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke4=player->pc[2];
                        player->pc[2]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke4=player->pc[3];
                        player->pc[3]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke4=player->pc[4];
                        player->pc[4]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke4=player->pc[5];
                        player->pc[5]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke4=player->pc[6];
                        player->pc[6]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke4=player->pc[7];
                        player->pc[7]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke4=player->pc[8];
                        player->pc[8]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke4=player->pc[9];
                        player->pc[9]=tmp;
                        finish=1;
                        break;

                    default:
                        break;
                    }
                }

                else if (*yin==47)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke4=player->pc[10];
                        player->pc[10]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke4=player->pc[11];
                        player->pc[11]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke4=player->pc[12];
                        player->pc[12]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke4=player->pc[13];
                        player->pc[13]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke4=player->pc[14];
                        player->pc[14]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke4=player->pc[15];
                        player->pc[15]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke4=player->pc[16];
                        player->pc[16]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke4=player->pc[17];
                        player->pc[17]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke4=player->pc[18];
                        player->pc[18]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke4=player->pc[19];
                        player->pc[19]=tmp;
                        finish=1;
                        break;
                        
                    default:
                        break;
                    }
                }
                break;

            case 5:
                tmp=player->poke5;
                if (*yin==11)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke5=player->pc[0];
                        player->pc[0]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke5=player->pc[1];
                        player->pc[1]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke5=player->pc[2];
                        player->pc[2]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke5=player->pc[3];
                        player->pc[3]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke5=player->pc[4];
                        player->pc[4]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke5=player->pc[5];
                        player->pc[5]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke5=player->pc[6];
                        player->pc[6]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke5=player->pc[7];
                        player->pc[7]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke5=player->pc[8];
                        player->pc[8]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke5=player->pc[9];
                        player->pc[9]=tmp;
                        finish=1;
                        break;

                    default:
                        break;
                    }
                }

                else if (*yin==47)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke5=player->pc[10];
                        player->pc[10]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke5=player->pc[11];
                        player->pc[11]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke5=player->pc[12];
                        player->pc[12]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke5=player->pc[13];
                        player->pc[13]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke5=player->pc[14];
                        player->pc[14]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke5=player->pc[15];
                        player->pc[15]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke5=player->pc[16];
                        player->pc[16]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke5=player->pc[17];
                        player->pc[17]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke5=player->pc[18];
                        player->pc[18]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke5=player->pc[19];
                        player->pc[19]=tmp;
                        finish=1;
                        break;
                        
                    default:
                        break;
                    }
                }
                break;

            case 6:
                tmp=player->poke6;
                if (*yin==11)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke6=player->pc[0];
                        player->pc[0]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke6=player->pc[1];
                        player->pc[1]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke6=player->pc[2];
                        player->pc[2]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke6=player->pc[3];
                        player->pc[3]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke6=player->pc[4];
                        player->pc[4]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke6=player->pc[5];
                        player->pc[5]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke6=player->pc[6];
                        player->pc[6]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke6=player->pc[7];
                        player->pc[7]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke6=player->pc[8];
                        player->pc[8]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke6=player->pc[9];
                        player->pc[9]=tmp;
                        finish=1;
                        break;

                    default:
                        break;
                    }
                }

                else if (*yin==47)
                {
                    switch (*xin)
                    {
                    case 6:
                        player->poke6=player->pc[10];
                        player->pc[10]=tmp;
                        finish=1;
                        break;

                    case 8:
                        player->poke6=player->pc[11];
                        player->pc[11]=tmp;
                        finish=1;
                        break;
                    
                    case 10:
                        player->poke6=player->pc[12];
                        player->pc[12]=tmp;
                        finish=1;
                        break;
                    
                    case 12:
                        player->poke6=player->pc[13];
                        player->pc[13]=tmp;
                        finish=1;
                        break;
                    
                    case 14:
                        player->poke6=player->pc[14];
                        player->pc[14]=tmp;
                        finish=1;
                        break;

                    case 16:
                        player->poke6=player->pc[15];
                        player->pc[15]=tmp;
                        finish=1;
                        break;

                    case 18:
                        player->poke6=player->pc[16];
                        player->pc[16]=tmp;
                        finish=1;
                        break;

                    case 20:
                        player->poke6=player->pc[17];
                        player->pc[17]=tmp;
                        finish=1;
                        break;

                    case 22:
                        player->poke6=player->pc[18];
                        player->pc[18]=tmp;
                        finish=1;
                        break;

                    case 24:
                        player->poke6=player->pc[19];
                        player->pc[19]=tmp;
                        finish=1;
                        break;
                        
                    default:
                        break;
                    }
                }
                break;
            
            default:
                break;
            }
            break;

        default:
            break;
        }
    usleep(16667);
    }
}


void computer(trainer* player){
    int finish=0,ch=ERR;
    int xout=9,xin=6,yin=11,whatpoke=0;
    

    // CONNEXION
    WINDOW* pc=newwin(40,150,13,43);
    WINDOW* ID=subwin(pc,3,60,31,88);
    WINDOW* MDP=subwin(pc,3,60,38,88);
    box(pc,0,0);
    box(ID,0,0);
    box(MDP,0,0);

    print_computer_connect(pc,player);
    wrefresh(pc);

    char id[20];
    strcpy(id,player->name);
    strcat(id,"123");
    for (int i = 0; id[i]!='\0'; i++)
    {
        mvwprintw(ID,1,2+i,"%c",id[i]);
        fflush(stdout);
        wrefresh(ID);
        usleep(100000);
    }

    char pass[]="***********";
    for (int i = 0; pass[i]!='\0'; i++)
    {
        mvwprintw(MDP,1,2+i,"%c",pass[i]);
        fflush(stdout);
        wrefresh(MDP);
        usleep(100000);
    }
    
    if (delwin(ID)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(88);
    }
    if (delwin(MDP)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(89);
    }
    if (delwin(pc)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(90);
    }

    //UTILISATION DU PC
    while (finish==0)
    {
        WINDOW* pc=newwin(40,150,13,43);
        WINDOW* out=subwin(pc,30,75,23,43);
        WINDOW* in=subwin(pc,30,75,23,118);
        box(pc,0,0);
        box(out,0,0);
        box(in,0,0);

        mvwprintw(pc,2,5,"User : %s connected",id);

        // OUT
        mvwprintw(pc,6,20,"  ____  __  ________");
        mvwprintw(pc,6+1,20," / __ \\/ / / /_  __/");
        mvwprintw(pc,6+2,20,"/ /_/ / /_/ / / /   ");
        mvwprintw(pc,6+3,20,"\\____/\\____/ /_/    ");

        mvwprintw(out,9,25,"%s",player->poke1.name);
        mvwprintw(out,9+2,25,"%s",player->poke2.name);
        mvwprintw(out,9+4,25,"%s",player->poke3.name);
        mvwprintw(out,9+6,25,"%s",player->poke4.name);
        mvwprintw(out,9+8,25,"%s",player->poke5.name);
        mvwprintw(out,9+10,25,"%s",player->poke6.name);

        mvwprintw(out,9,40,"lvl %d",player->poke1.lvl);
        mvwprintw(out,9+2,40,"lvl %d",player->poke2.lvl);
        mvwprintw(out,9+4,40,"lvl %d",player->poke3.lvl);
        mvwprintw(out,9+6,40,"lvl %d",player->poke4.lvl);
        mvwprintw(out,9+8,40,"lvl %d",player->poke5.lvl);
        mvwprintw(out,9+10,40,"lvl %d",player->poke6.lvl);
        mvwprintw(out,xout,22,">");

        // IN
        mvwprintw(pc,6,115,"   _____  __");
        mvwprintw(pc,6+1,115,"  /  _/ |/ /");
        mvwprintw(pc,6+2,115," _/ //    / ");
        mvwprintw(pc,6+3,115,"/___/_/|_/  ");

        for (int i = 0; i < 28; i++)
        {
            mvwprintw(in,1+i,38,"|");
        }
        
        int j=6 ;
        for (int i = 0; i < 10; i++)
        {
            mvwprintw(in,j,14,"%s",player->pc[i].name);
            mvwprintw(in,j,29,"%d",player->pc[i].lvl);
            j+=2;
        }

        j=6 ;
        for (int i = 10; i < 20; i++)
        {
            mvwprintw(in,j,50,"%s",player->pc[i].name);
            mvwprintw(in,j,65,"%d",player->pc[i].lvl);
            j+=2;
        }   

        ch=getch();

        switch (ch)
        {
        case ' ':
            mvwprintw(pc,2,5,"User : %s disconnected",id);
            wrefresh(pc);
            sleep(2);
            finish=1;
            break;
        
        case 'z':
        case KEY_UP:
            if (xout!=9)
            {
                xout-=2;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (xout!=19)
            {
                xout+=2;
            }  
            break;

        case 'e':
        case '\r':
        case '\n':
            switch (xout)
            {
            case 9: // poke1
                whatpoke=1;
                mvwprintw(pc,2,115,"%s moved succesfully",player->poke1.name);
                change_poke(in,player,&xin,&yin,whatpoke);
                wrefresh(pc);
                sleep(1);
                mvwprintw(pc,2,115,"                                ");
                break;
            
            case 11: // poke2
                whatpoke=2;
                mvwprintw(pc,2,115,"%s moved succesfully",player->poke2.name);
                change_poke(in,player,&xin,&yin,whatpoke);
                wrefresh(pc);
                sleep(1);
                mvwprintw(pc,2,115,"                                ");
                break;
            
            case 13:  // poke3
                whatpoke=3;
                mvwprintw(pc,2,115,"%s moved succesfully",player->poke3.name);
                change_poke(in,player,&xin,&yin,whatpoke);
                wrefresh(pc);
                sleep(1);
                mvwprintw(pc,2,115,"                                ");
                break;
            
            case 15:  // poke4
                whatpoke=4;
                mvwprintw(pc,2,115,"%s moved succesfully",player->poke4.name);
                change_poke(in,player,&xin,&yin,whatpoke);
                wrefresh(pc);
                sleep(1);
                mvwprintw(pc,2,115,"                                ");
                break;
            
            case 17:  // poke5
                whatpoke=5;
                mvwprintw(pc,2,115,"%s moved succesfully",player->poke5.name);
                change_poke(in,player,&xin,&yin,whatpoke);
                wrefresh(pc);
                sleep(1);
                mvwprintw(pc,2,115,"                                ");
                break;
            
            case 19:  // poke6
                whatpoke=6;
                mvwprintw(pc,2,115,"%s moved succesfully",player->poke6.name);
                change_poke(in,player,&xin,&yin,whatpoke);
                wrefresh(pc);
                sleep(1);
                mvwprintw(pc,2,115,"                                ");
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }

        wrefresh(pc);


        usleep(16667);
        if (delwin(out)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(91);
        }
        if (delwin(in)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(92);
        }
        if (delwin(pc)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(93);
        }
    }
}