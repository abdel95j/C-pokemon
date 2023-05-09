#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/physic.h"
#include "../headers/talkbis.h"

void write_flush(WINDOW* win, int x, int y,char* phrase){
    for (int i = 0; phrase[i]!='\0'; i++)
        {
            mvwprintw(win,x,y+i,"%c",phrase[i]);
            fflush(stdout);
            wrefresh(win);
            usleep(50000);
        }
}

void talkto_cashier(WINDOW* shop_map, trainer* player){
    int finish=0,ch=ERR;
    int x=4;

    write_flush(shop_map,15,37,"Hello! What do you want");
    write_flush(shop_map,16,37,"to buy today ?");

    while(finish==0)
    {
        WINDOW* buy_stuff=subwin(shop_map,16,40,36,45);
        box(buy_stuff,0,0);
        int howmany=0;

        mvwprintw(buy_stuff,1,16,"PokeShop");
        mvwprintw(buy_stuff,1,2,"%d$",player->money);

        mvwprintw(buy_stuff,4,4,"Pokeball [20$]");
        mvwprintw(buy_stuff,4,20,"%d in the bag",player->inventory[POKEBALLS].quant);

        mvwprintw(buy_stuff,6,4,"Potion [15$]");
        mvwprintw(buy_stuff,6,20,"%d in the bag",player->inventory[POTIONS].quant);

        mvwprintw(buy_stuff,8,4,"Candy [40$]");
        mvwprintw(buy_stuff,8,20,"%d in the bag",player->inventory[CANDYS].quant);

        mvwprintw(buy_stuff,10,4,"CT");

        mvwprintw(buy_stuff,12,4,"EXIT");

        mvwprintw(buy_stuff,x,2,">");
        wrefresh(shop_map);  

        ch=getch();

        switch (ch)
        {
        case ' ':
            mvwprintw(shop_map,15,37,"                       ");
            mvwprintw(shop_map,16,37,"              ");
            write_flush(shop_map,15,37,"Have a nice day sir !");
            sleep(2);
            finish=1;
            break;

        case 's':
        case KEY_DOWN:
            if (x!=12)
            {
                x+=2;
            }
            break;

        case 'z':
        case KEY_UP:
            if (x!=4)
            {
                x-=2;
            }
            break;

        case 'e':
        case '\n':
        case '\r':
            switch (x)
            {
            case 4:  //  pokeball
                mvwprintw(shop_map,15,37,"                       ");
                mvwprintw(shop_map,16,37,"              ");
                write_flush(shop_map,15,37,"How many pokeballs");
                write_flush(shop_map,16,37,"do you need ?");
                
                curs_set(1);
                wmove(shop_map,18,37);
                echo();
                nodelay(stdscr,FALSE);
                
                while (howmany<=0)
                {
                    wscanw(shop_map,"%d",&howmany);
                    if (howmany<=0)
                    {
                        curs_set(0);
                        mvwprintw(shop_map,15,37,"                       ");
                        mvwprintw(shop_map,16,37,"              ");
                        write_flush(shop_map,15,37,"Sir, that's");
                        write_flush(shop_map,16,37,"not possible !");
                        sleep(1);
                        mvwprintw(shop_map,15,37,"                       ");
                        mvwprintw(shop_map,16,37,"              ");
                        write_flush(shop_map,15,37,"How many pokeballs");
                        write_flush(shop_map,16,37,"do you need ?");
                        mvwprintw(shop_map,18,37,"                             "); // clear scan zone
                        wmove(shop_map,18,37);
                        curs_set(1);
                    }  
                }

                noecho();
                nodelay(stdscr,TRUE);
                curs_set(0);

                if (player->money>=20*howmany)
                {
                    player->money-=20*howmany;
                    player->inventory[POKEBALLS].quant+=howmany;
                    mvwprintw(shop_map,15,37,"                       ");
                    mvwprintw(shop_map,16,37,"              ");
                    write_flush(shop_map,15,37,"You bought");
                    mvwprintw(shop_map,15,48,"%d",howmany);
                    write_flush(shop_map,16,37,"pokeballs !");   
                    sleep(2);
                    mvwprintw(shop_map,15,37,"                       ");
                    mvwprintw(shop_map,16,37,"              ");
                    write_flush(shop_map,15,37,"What do you want");
                    write_flush(shop_map,16,37,"to buy today ?");
                }     

                else
                {
                    mvwprintw(shop_map,15,37,"                       ");
                    mvwprintw(shop_map,16,37,"              ");
                    write_flush(shop_map,15,37,"Sorry, you don't have");
                    write_flush(shop_map,16,37,"enough money for this");
                    sleep(2);
                    mvwprintw(shop_map,15,37,"                     ");
                    mvwprintw(shop_map,16,37,"                     ");
                    write_flush(shop_map,15,37,"What do you want");
                    write_flush(shop_map,16,37,"to buy today ?");
                }   
                break;
            
            case 6:  //  potion
                mvwprintw(shop_map,15,37,"                       ");
                mvwprintw(shop_map,16,37,"              ");
                write_flush(shop_map,15,37,"How many candys");
                write_flush(shop_map,16,37,"do you need ?");
                
                curs_set(1);
                wmove(shop_map,18,37);
                echo();
                nodelay(stdscr,FALSE);
                
                while (howmany<=0)
                {
                    wscanw(shop_map,"%d",&howmany);
                    if (howmany<=0)
                    {
                        curs_set(0);
                        mvwprintw(shop_map,15,37,"                       ");
                        mvwprintw(shop_map,16,37,"              ");
                        write_flush(shop_map,15,37,"Sir, that's");
                        write_flush(shop_map,16,37,"not possible !");
                        sleep(1);
                        mvwprintw(shop_map,15,37,"                       ");
                        mvwprintw(shop_map,16,37,"              ");
                        write_flush(shop_map,15,37,"How many candys");
                        write_flush(shop_map,16,37,"do you need ?");
                        mvwprintw(shop_map,18,37,"                             "); // clear scan zone
                        wmove(shop_map,18,37);
                        curs_set(1);
                    }  
                }

                noecho();
                nodelay(stdscr,TRUE);
                curs_set(0);

                if (player->money>=15*howmany)
                {
                    player->money-=15*howmany;
                    player->inventory[POTIONS].quant+=howmany;
                    mvwprintw(shop_map,15,37,"                       ");
                    mvwprintw(shop_map,16,37,"              ");
                    write_flush(shop_map,15,37,"You bought");
                    mvwprintw(shop_map,15,48,"%d",howmany);
                    write_flush(shop_map,16,37,"candys !");   
                    sleep(2);
                    mvwprintw(shop_map,15,37,"                       ");
                    mvwprintw(shop_map,16,37,"              ");
                    write_flush(shop_map,15,37,"What do you want");
                    write_flush(shop_map,16,37,"to buy today ?");
                }     

                else
                {
                    mvwprintw(shop_map,15,37,"                       ");
                    mvwprintw(shop_map,16,37,"              ");
                    write_flush(shop_map,15,37,"Sorry, you don't have");
                    write_flush(shop_map,16,37,"enough money for this");
                    sleep(2);
                    mvwprintw(shop_map,15,37,"                     ");
                    mvwprintw(shop_map,16,37,"                     ");
                    write_flush(shop_map,15,37,"What do you want");
                    write_flush(shop_map,16,37,"to buy today ?");
                }
                break;

            case 8:  //  candy
                mvwprintw(shop_map,15,37,"                       ");
                mvwprintw(shop_map,16,37,"              ");
                write_flush(shop_map,15,37,"How many candys");
                write_flush(shop_map,16,37,"do you need ?");
                
                curs_set(1);
                wmove(shop_map,18,37);
                echo();
                nodelay(stdscr,FALSE);
                
                while (howmany<=0)
                {
                    wscanw(shop_map,"%d",&howmany);
                    if (howmany<=0)
                    {
                        curs_set(0);
                        mvwprintw(shop_map,15,37,"                       ");
                        mvwprintw(shop_map,16,37,"              ");
                        write_flush(shop_map,15,37,"Sir, that's");
                        write_flush(shop_map,16,37,"not possible !");
                        sleep(1);
                        mvwprintw(shop_map,15,37,"                       ");
                        mvwprintw(shop_map,16,37,"              ");
                        write_flush(shop_map,15,37,"How many candys");
                        write_flush(shop_map,16,37,"do you need ?");
                        mvwprintw(shop_map,18,37,"                             "); // clear scan zone
                        wmove(shop_map,18,37);
                        curs_set(1);
                    }  
                }

                noecho();
                nodelay(stdscr,TRUE);
                curs_set(0);

                if (player->money>=40*howmany)
                {
                    player->money-=40*howmany;
                    player->inventory[CANDYS].quant+=howmany;
                    mvwprintw(shop_map,15,37,"                       ");
                    mvwprintw(shop_map,16,37,"              ");
                    write_flush(shop_map,15,37,"You bought");
                    mvwprintw(shop_map,15,48,"%d",howmany);
                    write_flush(shop_map,16,37,"candys !");   
                    sleep(2);
                    mvwprintw(shop_map,15,37,"                       ");
                    mvwprintw(shop_map,16,37,"              ");
                    write_flush(shop_map,15,37,"What do you want");
                    write_flush(shop_map,16,37,"to buy today ?");
                }     

                else
                {
                    mvwprintw(shop_map,15,37,"                       ");
                    mvwprintw(shop_map,16,37,"              ");
                    write_flush(shop_map,15,37,"Sorry, you don't have");
                    write_flush(shop_map,16,37,"enough money for this");
                    sleep(2);
                    mvwprintw(shop_map,15,37,"                     ");
                    mvwprintw(shop_map,16,37,"                     ");
                    write_flush(shop_map,15,37,"What do you want");
                    write_flush(shop_map,16,37,"to buy today ?");
                }
                break;

            case 10: // CT
                int finishCT=0;
                x=4;

                mvwprintw(shop_map,15,37,"                       ");
                mvwprintw(shop_map,16,37,"                     ");
                write_flush(shop_map,15,37,"What CT do you want");
                write_flush(shop_map,16,37,"to buy ?");
                while (finishCT==0)
                {
                    wclear(buy_stuff);
                    WINDOW* blank=subwin(shop_map,16,40,36,45);
                    wrefresh(blank);
                    box(buy_stuff,0,0);
                    mvwprintw(buy_stuff,1,16,"PokeShop");
                    mvwprintw(buy_stuff,1,2,"%d$",player->money);

                    mvwprintw(buy_stuff,4,4,"Surf (util) [200$]");
                    mvwprintw(buy_stuff,6,4,"Leer (stat) [100$]");
                    mvwprintw(buy_stuff,8,4,"Roar (stat) [100$]");
                    mvwprintw(buy_stuff,10,4,"EXIT");
                    mvwprintw(buy_stuff,x,2,">");

                    wrefresh(buy_stuff);
                    ch=getch();
                    switch (ch)
                    {
                    case 's':
                    case KEY_DOWN:
                        if (x!=10)
                        {
                            x+=2;
                        }
                        break;

                    case 'z':
                    case KEY_UP:
                        if (x!=4)
                        {
                            x-=2;
                        }
                        break;

                    case ' ':
                        mvwprintw(shop_map,15,37,"                       ");
                        mvwprintw(shop_map,16,37,"              ");
                        write_flush(shop_map,15,37,"What do you want");
                        write_flush(shop_map,16,37,"to buy today ?");
                        wclear(buy_stuff);
                        wrefresh(blank);
                        finishCT=1;
                        break;

                    case 'e':
                    case '\n':
                    case '\r':
                        if (x==10)
                        {
                            mvwprintw(shop_map,15,37,"                       ");
                            mvwprintw(shop_map,16,37,"              ");
                            write_flush(shop_map,15,37,"What do you want");
                            write_flush(shop_map,16,37,"to buy today ?");
                            wclear(buy_stuff);
                            wrefresh(blank);
                            finishCT=1;
                        }
                        switch (x)
                        {
                        case 4:  // surf
                            if (player->money<200)
                            {
                                mvwprintw(shop_map,15,37,"                       ");
                                mvwprintw(shop_map,16,37,"              ");
                                write_flush(shop_map,15,37,"Sorry, you don't have");
                                write_flush(shop_map,16,37,"enough money for this");
                                sleep(2);
                                mvwprintw(shop_map,15,37,"                     ");
                                mvwprintw(shop_map,16,37,"                     ");
                                write_flush(shop_map,15,37,"What CT do you want");
                                write_flush(shop_map,16,37,"to buy ?");
                            }
                            else
                            {
                                if (player->inventory[3].type==SURF)
                                {
                                    player->inventory[3].quant=player->inventory[3].quant+1;
                                    player->money-=200;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Surf !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }
                                else if (player->inventory[4].type==SURF)
                                {
                                    player->inventory[4].quant=player->inventory[4].quant+1;
                                    player->money-=200;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Surf !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }
                                else if (player->inventory[5].type==SURF)
                                {
                                    player->inventory[5].quant=player->inventory[5].quant+1;
                                    player->money-=200;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Surf !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }

                                else if (player->inventory[3].type==EMPTY)
                                {
                                    player->inventory[3].type=SURF;
                                    player->inventory[3].quant=1;
                                    sprintf(player->inventory[3].name,"surf");
                                    player->money-=200;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Surf !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }

                                else if (player->inventory[4].type==EMPTY)
                                {
                                    player->inventory[4].type=SURF;
                                    player->inventory[4].quant=1;
                                    sprintf(player->inventory[4].name,"surf");
                                    player->money-=200;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Surf !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }
                                
                                else if (player->inventory[5].type==EMPTY)
                                {
                                    player->inventory[5].type=SURF;
                                    player->inventory[5].quant=1;
                                    sprintf(player->inventory[5].name,"surf");
                                    player->money-=200;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Surf !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }

                                else
                                {
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"Sorry, you don't have");
                                    write_flush(shop_map,16,37,"enough space in your bag");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                } 
                            }
                            
                            break;

                        case 6:  // leer
                            if (player->money<100)
                            {
                                mvwprintw(shop_map,15,37,"                       ");
                                mvwprintw(shop_map,16,37,"              ");
                                write_flush(shop_map,15,37,"Sorry, you don't have");
                                write_flush(shop_map,16,37,"enough money for this");
                                sleep(2);
                                mvwprintw(shop_map,15,37,"                     ");
                                mvwprintw(shop_map,16,37,"                     ");
                                write_flush(shop_map,15,37,"What CT do you want");
                                write_flush(shop_map,16,37,"to buy ?");
                            }
                            else
                            {
                                if (player->inventory[3].type==LEER)
                                {
                                    player->inventory[3].quant++;
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Leer !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }
                                else if (player->inventory[4].type==LEER)
                                {
                                    player->inventory[4].quant++;
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Leer !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }
                                else if (player->inventory[5].type==LEER)
                                {
                                    player->inventory[5].quant++;
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Leer !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }

                                else if (player->inventory[3].type==EMPTY)
                                {
                                    player->inventory[3].type=LEER;
                                    player->inventory[3].quant=1;
                                    sprintf(player->inventory[3].name,"Leer");
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Leer !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }

                                else if (player->inventory[4].type==EMPTY)
                                {
                                    player->inventory[4].type=LEER;
                                    player->inventory[4].quant=1;
                                    sprintf(player->inventory[4].name,"Leer");
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Leer !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }
                                
                                else if (player->inventory[5].type==EMPTY)
                                {
                                    player->inventory[5].type=LEER;
                                    player->inventory[5].quant=1;
                                    sprintf(player->inventory[5].name,"Leer");
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Leer !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }

                                else
                                {
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"Sorry, you don't have");
                                    write_flush(shop_map,16,37,"enough space in your bag");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                } 
                            }
                            break;

                        case 8:  // roar
                            if (player->money<100)
                            {
                                mvwprintw(shop_map,15,37,"                       ");
                                mvwprintw(shop_map,16,37,"              ");
                                write_flush(shop_map,15,37,"Sorry, you don't have");
                                write_flush(shop_map,16,37,"enough money for this");
                                sleep(2);
                                mvwprintw(shop_map,15,37,"                     ");
                                mvwprintw(shop_map,16,37,"                     ");
                                write_flush(shop_map,15,37,"What CT do you want");
                                write_flush(shop_map,16,37,"to buy ?");
                            }
                            else
                            {
                                if (player->inventory[3].type==ROAR)
                                {
                                    player->inventory[3].quant++;
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Roar !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }
                                else if (player->inventory[4].type==ROAR)
                                {
                                    player->inventory[4].quant++;
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Roar !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }
                                else if (player->inventory[5].type==ROAR)
                                {
                                    player->inventory[5].quant++;
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Roar !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }

                                else if (player->inventory[3].type==EMPTY)
                                {
                                    player->inventory[3].type=ROAR;
                                    player->inventory[3].quant=1;
                                    sprintf(player->inventory[3].name,"Roar");
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Roar !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }

                                else if (player->inventory[4].type==EMPTY)
                                {
                                    player->inventory[4].type=ROAR;
                                    player->inventory[4].quant=1;
                                    sprintf(player->inventory[4].name,"Roar");
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Roar !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }
                                
                                else if (player->inventory[5].type==EMPTY)
                                {
                                    player->inventory[5].type=ROAR;
                                    player->inventory[5].quant=1;
                                    sprintf(player->inventory[5].name,"Roar");
                                    player->money-=100;
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"You bought a CT");
                                    write_flush(shop_map,16,37,"of Roar !");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
                                }

                                else
                                {
                                    mvwprintw(shop_map,15,37,"                       ");
                                    mvwprintw(shop_map,16,37,"              ");
                                    write_flush(shop_map,15,37,"Sorry, you don't have");
                                    write_flush(shop_map,16,37,"enough space in your bag");
                                    sleep(2);
                                    mvwprintw(shop_map,15,37,"                     ");
                                    mvwprintw(shop_map,16,37,"                     ");
                                    write_flush(shop_map,15,37,"What CT do you want");
                                    write_flush(shop_map,16,37,"to buy ?");
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
                    if (delwin(blank)==ERR)
                    {
                        exit(33);
                    }
                }
                break;

            case 12:  //  EXIT
                mvwprintw(shop_map,15,37,"                       ");
                mvwprintw(shop_map,16,37,"              ");
                write_flush(shop_map,15,37,"Have a nice day sir !");
                sleep(2);
                finish=1;
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }  
        mvwprintw(shop_map,18,37,"            "); // clear scan zone
        usleep(16667);
        wclear(buy_stuff);
        if (delwin(buy_stuff)==ERR)
        {
            exit(23);
        }   
    }
}

void talkto_mom(WINDOW* house_map, trainer* player){
    int finish=0,ch=ERR;
    int x=1;

    write_flush(house_map,17,9,"Hello honey !");
    sleep(1);
    mvwprintw(house_map,17,9,"                      ");
    write_flush(house_map,17,9,"Do you want me to heal your team ?");

    while(finish==0)
    {
        WINDOW* chat=subwin(house_map,5,10,31,90);
        box(chat,0,0);

        mvwprintw(chat,1,4,"Yes");
        mvwprintw(chat,3,4,"No");
        mvwprintw(chat,x,2,">");
        wrefresh(chat);

        ch=getch();
        switch (ch)
        {
        case ' ':
            mvwprintw(house_map,17,9,"                                   ");
            write_flush(house_map,17,9,"Have a good day sweetheart <3");
            sleep(2);
            mvwprintw(house_map,17,9,"                                   ");
            finish=1;
            break;
            
        case 'z':
        case KEY_UP:
            if (x!=1)
            {
                x-=2;
            }
            break;
        
        case 's':
        case KEY_DOWN:
            if (x!=3)
            {
                x+=2;
            }
            break;

        case 'e':
        case '\n':
        case '\r':
            switch (x)
            {
            case 1:
                mvwprintw(house_map,17,9,"                                   ");
                player->poke1.pv=player->poke1.pv_save;
                player->poke2.pv=player->poke2.pv_save;
                player->poke3.pv=player->poke3.pv_save;
                player->poke4.pv=player->poke4.pv_save;
                player->poke5.pv=player->poke5.pv_save;
                player->poke6.pv=player->poke6.pv_save;
                write_flush(house_map,17,9,"Done ! They're all healed :)");    
                sleep(2);            
                mvwprintw(house_map,17,9,"                                   ");
                finish=1;
                break;
            
            case 3:
                mvwprintw(house_map,17,9,"                                   ");
                write_flush(house_map,17,9,"Have a good day sweetheart <3");
                sleep(2);
                mvwprintw(house_map,17,9,"                                   ");
                finish=1;
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }

        wclear(chat);
        usleep(16667);
        if (delwin(chat)==ERR)
        {
            exit(26);
        }
    }
}

void talkto_champion(WINDOW* league_map,trainer*player,trainer champion){
    int finish=0,ch=ERR;
    int x=1;

    if (champion.art==CHAMPIONRED)
    {
        write_flush(league_map,13,72,"What ? You want to");
        write_flush(league_map,14,72,"challenge me ?");

        while (finish==0)
        {
            WINDOW* chat=subwin(league_map,5,8,29,126);
            box(chat,0,0);

            mvwprintw(chat,x,1,">");
            mvwprintw(chat,1,3,"Yes");
            mvwprintw(chat,3,3,"No");
            wrefresh(chat);

            ch=getch();
            switch (ch)
            {
            case 'z':
            case KEY_UP:
                if (x!=1)
                {
                    mvwprintw(chat,x,1," ");
                    x=1;
                }
                break;

            case 's':
            case KEY_DOWN:
                if (x!=3)
                {
                    mvwprintw(chat,x,1," ");
                    x=3;
                }

                break;

            case ' ':
                mvwprintw(league_map,13,72,"                  ");
                mvwprintw(league_map,14,72,"              ");
                write_flush(league_map,13,72,"Yeah, wise choice, don't");
                write_flush(league_map,14,72,"try me, you'll loose");
                sleep(1);
                mvwprintw(league_map,13,72,"                        ");
                mvwprintw(league_map,14,72,"                     ");
                finish=1;
                break;

            case 'e':
            case '\r':
            case '\n':
                if (x==3)
                {
                    mvwprintw(league_map,13,72,"                  ");
                    mvwprintw(league_map,14,72,"              ");
                    write_flush(league_map,13,72,"Yeah, wise choice, don't");
                    write_flush(league_map,14,72,"try me, you'll loose");
                    sleep(1);
                    mvwprintw(league_map,13,72,"                        ");
                    mvwprintw(league_map,14,72,"                     ");
                    finish=1;
                }

                else
                if (x==1)
                {
                    wclear(chat);
                    mvwprintw(league_map,13,72,"                  ");
                    mvwprintw(league_map,14,72,"              ");
                    write_flush(league_map,13,72,"Ho ? You say you'll win ?");
                    write_flush(league_map,14,72,"You fool ... Let's see");
                    write_flush(league_map,15,72,"what you've got");
                    sleep(1);
                    mvwprintw(league_map,13,72,"                         ");
                    mvwprintw(league_map,14,72,"                         ");
                    mvwprintw(league_map,15,72,"                         ");
                    duel(player,champion);
                }
                break;

            default:
                break;
            }

            usleep(16667);
            if (delwin(chat)==ERR)
            {
                exit(41);
            }
        }
    }   

    else if (champion.art==CHAMPIONBLUE)
    {
        mvwprintw(league_map,13,72,"Z");
        wrefresh(league_map);
        sleep(1);
        mvwprintw(league_map,13,73,"z");
        wrefresh(league_map);
        sleep(1);
        mvwprintw(league_map,13,74,"z");
        wrefresh(league_map);
        sleep(1);
        mvwprintw(league_map,13,72,"                 ");
        write_flush(league_map,13,72,"AAH WHAT ?! A DUEL ?");

        while (finish==0)
        {
            WINDOW* chat=subwin(league_map,5,8,29,126);
            box(chat,0,0);

            mvwprintw(chat,x,1,">");
            mvwprintw(chat,1,3,"Yes");
            mvwprintw(chat,3,3,"No");
            wrefresh(chat);

            ch=getch();
            switch (ch)
            {
            case 'z':
            case KEY_UP:
                if (x!=1)
                {
                    mvwprintw(chat,x,1," ");
                    x=1;
                }
                break;

            case 's':
            case KEY_DOWN:
                if (x!=3)
                {
                    mvwprintw(chat,x,1," ");
                    x=3;
                }

                break;

            case ' ':
                mvwprintw(league_map,13,72,"                    ");
                write_flush(league_map,13,72,"OKAY THEN ...");
                sleep(1);
                mvwprintw(league_map,13,72,"                        ");
                mvwprintw(league_map,13,72,"Z");
                wrefresh(league_map);
                sleep(1);
                mvwprintw(league_map,13,73,"z");
                wrefresh(league_map);
                sleep(1);
                mvwprintw(league_map,13,74,"z");
                wrefresh(league_map);
                sleep(1);
                mvwprintw(league_map,13,72,"                        ");
                finish=1;
                break;

            case 'e':
            case '\r':
            case '\n':
                if (x==3)
                {
                    mvwprintw(league_map,13,72,"                    ");
                write_flush(league_map,13,72,"OKAY THEN ...");
                sleep(1);
                mvwprintw(league_map,13,72,"                        ");
                mvwprintw(league_map,13,72,"Z");
                wrefresh(league_map);
                sleep(1);
                mvwprintw(league_map,13,73,"z");
                wrefresh(league_map);
                sleep(1);
                mvwprintw(league_map,13,74,"z");
                wrefresh(league_map);
                sleep(1);
                mvwprintw(league_map,13,72,"                        ");
                finish=1;
                }

                else
                if (x==1)
                {
                    wclear(chat);
                    mvwprintw(league_map,13,72,"                    ");
                    write_flush(league_map,13,72,"AAAAAH DON'T HURT ME,");
                    write_flush(league_map,14,72,"TAKE MY MONEY AAAAH");
                    sleep(1);
                    mvwprintw(league_map,13,72,"                        ");
                    mvwprintw(league_map,14,72,"                        ");
                    duel(player,champion);
                }
                break;

            default:
                break;
            }

            usleep(16667);
            if (delwin(chat)==ERR)
            {
                exit(41);
            }
        }
    }  

    else if (champion.art==CHAMPIONYELLOW)
    {
        write_flush(league_map,13,72,"HEY YOU !");
        write_flush(league_map,14,72,"I challenge you");

        while (finish==0)
        {
            WINDOW* chat=subwin(league_map,5,8,29,126);
            box(chat,0,0);

            mvwprintw(chat,x,1,">");
            mvwprintw(chat,1,3,"Ok");
            mvwprintw(chat,3,3,"No");
            wrefresh(chat);

            ch=getch();
            switch (ch)
            {
            case 'z':
            case KEY_UP:
                if (x!=1)
                {
                    mvwprintw(chat,x,1," ");
                    x=1;
                }
                break;

            case 's':
            case KEY_DOWN:
                if (x!=3)
                {
                    mvwprintw(chat,x,1," ");
                    x=3;
                }

                break;

            case ' ':
                mvwprintw(league_map,13,72,"                    ");
                mvwprintw(league_map,14,72,"                    ");
                write_flush(league_map,13,72,"Oh ... haha that's okay");
                write_flush(league_map,14,72,"I can't force you anyways");
                sleep(1);
                mvwprintw(league_map,13,72,"                        ");
                mvwprintw(league_map,14,72,"                         ");
                finish=1;
                break;

            case 'e':
            case '\r':
            case '\n':
                if (x==3)
                {
                    mvwprintw(league_map,13,72,"                    ");
                    mvwprintw(league_map,14,72,"                    ");
                    write_flush(league_map,13,72,"Oh ... haha that's okay");
                    write_flush(league_map,14,72,"I can't force you anyways");
                    sleep(1);
                    mvwprintw(league_map,13,72,"                        ");
                    mvwprintw(league_map,14,72,"                         ");
                    finish=1;
                }

                else
                if (x==1)
                {
                    wclear(chat);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    write_flush(league_map,13,72,"YEEES THANK YOU AHAHAHA");
                    write_flush(league_map,14,72,"let's see who's the");
                    write_flush(league_map,15,72,"strongest !");
                    sleep(1);
                    mvwprintw(league_map,13,72,"                          ");
                    mvwprintw(league_map,14,72,"                     ");
                    mvwprintw(league_map,15,72,"                    ");
                    duel(player,champion);
                }
                break;

            default:
                break;
            }

            usleep(16667);
            if (delwin(chat)==ERR)
            {
                exit(41);
            }
        }
    }  
}