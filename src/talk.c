#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/physic.h"

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

        mvwprintw(buy_stuff,10,4,"EXIT");

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
            
            case 10:  //  EXIT
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

void talkto_prof(WINDOW* lab_map, trainer* player){
    int finish=0,ch=ERR;
    int x=2;

    object leer;
    sprintf(leer.name,"leer");
    leer.type=SURF;
    leer.quant=1;

    write_flush(lab_map,3,108,"Hey");
    mvwprintw(lab_map,3,112,"%s !",player->name);
    wrefresh(lab_map);
    sleep(2);
    mvwprintw(lab_map,3,108,"                                         ");
    write_flush(lab_map,3,108,"Do you want something from me ?");

    while(finish==0)
    {
        WINDOW* chat=subwin(lab_map,7,18,25,115);
        box(chat,0,0);

        mvwprintw(chat,x,2,">");
        mvwprintw(chat,2,5,"Buy a CT");
        mvwprintw(chat,4,5,"EXIT");

        wrefresh(chat);

        ch=getch();
        switch (ch)
        {
        case 'z':
        case KEY_UP:
            if (x!=2)
            {
                x-=2;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (x!=4)
            {
                x+=2;
            }  
            break;

        case 'e':
        case '\r':
        case '\n':
            if (x==2)
            {
                mvwprintw(lab_map,3,108,"                                         ");
                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                wclear(chat);
                wrefresh(chat);
                mvwin(chat,25,110);
                wresize(chat,10,25);

                int CTfinish=0;
                int x=2;
                while (CTfinish==0)
                {
                    WINDOW* blank = newwin(10,25,25,110);
                    box(chat,0,0);
                    mvwprintw(chat,x,2,">");
                    mvwprintw(chat,2,5,"Surf (util) [200$]");
                    mvwprintw(chat,4,5,"Leer (stat) [100$]");
                    mvwprintw(chat,6,5,"EXIT");
                    wrefresh(chat);

                    ch=getch();
                    switch (ch)
                    {
                    case 'z':
                    case KEY_UP:
                        if (x!=2)
                        {
                            x-=2;
                        }
                        break;
                    
                    case 's':
                    case KEY_DOWN:
                        if (x!=6)
                        {
                            x+=2;
                        }
                        break;
                    
                    case ' ':
                        mvwprintw(lab_map,3,108,"                                         ");
                        write_flush(lab_map,3,108,"Do you want something else from me ?");
                        wrefresh(blank);
                        CTfinish=1;
                        break;

                    case 'e':
                    case '\n':
                    case '\r':
                        if (x==6)
                        {
                            mvwprintw(lab_map,3,108,"                                         ");
                            write_flush(lab_map,3,108,"Do you want something else from me ?");
                            wrefresh(blank);
                            CTfinish=1;
                        }
                        
                        else if (x==2)
                        {
                            if (player->money<200)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"You don't have enough money for this");
                                sleep(2);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                            }

                            else if (player->lvl<5)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"Level 5 is required to buy surf !");
                                sleep(2);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                            }
                            
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to learn surf ?");
                                int finishchoice=0,x=2;
                                while (finishchoice==0)
                                {   
                                    box(chat,0,0);
                                    mvwprintw(chat,2,5,"%s",player->poke1.name);
                                    mvwprintw(chat,3,5,"%s",player->poke2.name);
                                    mvwprintw(chat,4,5,"%s",player->poke3.name);
                                    mvwprintw(chat,5,5,"%s",player->poke4.name);
                                    mvwprintw(chat,6,5,"%s",player->poke5.name);
                                    mvwprintw(chat,7,5,"%s",player->poke6.name);
                                    mvwprintw(chat,x,2,">");
                                    wrefresh(chat);

                                    ch=getch();
                                    switch (ch)
                                    {
                                    case 'z':
                                    case KEY_UP:
                                        if (x!=2)
                                        {
                                            x-=1;
                                        }
                                        break;

                                    case 's':
                                    case KEY_DOWN:
                                        if (x!=7)
                                        {
                                            x+=1;
                                        }
                                        break;

                                    case ' ':
                                        mvwprintw(lab_map,3,108,"                                         ");
                                        write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                        finishchoice=1;
                                        break;

                                    case 'e':
                                    case '\n':
                                    case '\r':
                                        switch (x)
                                        {
                                        case 2:
                                            if (player->poke1.type==WATER)
                                            {
                                                player->poke1.CTutil->quant=1;
                                                player->poke1.CTutil->type=SURF;
                                                sprintf(player->poke1.CTutil->name,"surf");

                                                mvwprintw(lab_map,3,108,"                                         ");
                                                mvwprintw(lab_map,3,108,"%s",player->poke1.name);
                                                write_flush(lab_map,3,120,"learned surf !");
                                                sleep(2);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                finishchoice=1;
                                            }
                                            else
                                            {
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"Surf can't be learned by this pokemon");
                                                sleep(1);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What pokemon you want to learn surf ?");
                                                }

                                                break;

                                        case 3:
                                            if (player->poke2.type==WATER)
                                            {
                                                player->poke2.CTutil->quant=1;
                                                player->poke2.CTutil->type=SURF;
                                                sprintf(player->poke2.CTutil->name,"surf");

                                                mvwprintw(lab_map,3,108,"                                         ");
                                                mvwprintw(lab_map,3,108,"%s",player->poke2.name);
                                                write_flush(lab_map,3,120,"learned surf !");
                                                sleep(2);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                finishchoice=1;
                                            }
                                            else
                                            {
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"Surf can't be learned by this pokemon");
                                                sleep(1);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What pokemon you want to learn surf ?");
                                                }

                                                break;

                                        case 4:
                                            if (player->poke3.type==WATER)
                                            {
                                                player->poke3.CTutil->quant=1;
                                                player->poke3.CTutil->type=SURF;
                                                sprintf(player->poke3.CTutil->name,"surf");

                                                mvwprintw(lab_map,3,108,"                                         ");
                                                mvwprintw(lab_map,3,108,"%s",player->poke3.name);
                                                write_flush(lab_map,3,120,"learned surf !");
                                                sleep(2);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                finishchoice=1;
                                            }
                                            else
                                            {
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"Surf can't be learned by this pokemon");
                                                sleep(1);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What pokemon you want to learn surf ?");
                                                }

                                                break;

                                        case 5:
                                            if (player->poke4.type==WATER)
                                            {
                                                player->poke4.CTutil->quant=1;
                                                player->poke4.CTutil->type=SURF;
                                                sprintf(player->poke4.CTutil->name,"surf");

                                                mvwprintw(lab_map,3,108,"                                         ");
                                                mvwprintw(lab_map,3,108,"%s",player->poke4.name);
                                                write_flush(lab_map,3,120,"learned surf !");
                                                sleep(2);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                finishchoice=1;
                                            }
                                            else
                                            {
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"Surf can't be learned by this pokemon");
                                                sleep(1);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What pokemon you want to learn surf ?");
                                                }

                                                break;

                                        case 6:
                                            if (player->poke5.type==WATER)
                                            {
                                                player->poke5.CTutil->quant=1;
                                                player->poke5.CTutil->type=SURF;
                                                sprintf(player->poke5.CTutil->name,"surf");

                                                mvwprintw(lab_map,3,108,"                                         ");
                                                mvwprintw(lab_map,3,108,"%s",player->poke5.name);
                                                write_flush(lab_map,3,120,"learned surf !");
                                                sleep(2);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                finishchoice=1;
                                            }
                                            else
                                            {
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"Surf can't be learned by this pokemon");
                                                sleep(1);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What pokemon you want to learn surf ?");
                                                }

                                                break;

                                        case 7:
                                            if (player->poke6.type==WATER)
                                            {
                                                player->poke6.CTutil->quant=1;
                                                player->poke6.CTutil->type=SURF;
                                                sprintf(player->poke6.CTutil->name,"surf");

                                                mvwprintw(lab_map,3,108,"                                         ");
                                                mvwprintw(lab_map,3,108,"%s",player->poke6.name);
                                                write_flush(lab_map,3,118,"learned surf !");
                                                sleep(2);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                finishchoice=1;
                                            }
                                            else
                                            {
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"Surf can't be learned by this pokemon");
                                                sleep(1);
                                                mvwprintw(lab_map,3,108,"                                         ");
                                                write_flush(lab_map,3,108,"What pokemon you want to learn surf ?");
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
                                    wclear(chat);
                                    wrefresh(blank);
                                }
                            }  
                        }

                        else if (x==4)
                        {
                            if (player->money<100)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"You don't have enough money for this");
                                sleep(2);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                            }

                            else if (player->lvl<2)
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"Level 2 is required to buy leer !");
                                sleep(2);
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                            }
                            
                            else
                            {
                                mvwprintw(lab_map,3,108,"                                         ");
                                write_flush(lab_map,3,108,"What pokemon you want to learn leer ?");
                                int finishchoice=0,x=2;
                                while (finishchoice==0)
                                {   
                                    box(chat,0,0);
                                    mvwprintw(chat,2,5,"%s",player->poke1.name);
                                    mvwprintw(chat,3,5,"%s",player->poke2.name);
                                    mvwprintw(chat,4,5,"%s",player->poke3.name);
                                    mvwprintw(chat,5,5,"%s",player->poke4.name);
                                    mvwprintw(chat,6,5,"%s",player->poke5.name);
                                    mvwprintw(chat,7,5,"%s",player->poke6.name);
                                    mvwprintw(chat,x,2,">");
                                    wrefresh(chat);

                                    ch=getch();
                                    switch (ch)
                                    {
                                    case 'z':
                                    case KEY_UP:
                                        if (x!=2)
                                        {
                                            x-=1;
                                        }
                                        break;

                                    case 's':
                                    case KEY_DOWN:
                                        if (x!=7)
                                        {
                                            x+=1;
                                        }
                                        break;

                                    case ' ':
                                        mvwprintw(lab_map,3,108,"                                         ");
                                        write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                        finishchoice=1;
                                        break;

                                    case 'e':
                                    case '\n':
                                    case '\r':
                                        switch (x)
                                        {
                                        case 2:
                                                player->poke1.CTstat->quant=1;
                                                player->poke1.CTstat->type=LEER;
                                                sprintf(player->poke1.CTstat->name,"leer");

                                                if (player->poke1.type!=0)
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    mvwprintw(lab_map,3,108,"%s",player->poke1.name);
                                                    write_flush(lab_map,3,120,"learned leer !");
                                                    sleep(2);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                    finishchoice=1;
                                                }
                                                else
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"leer can't be learned by this pokemon");
                                                    sleep(1);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What pokemon you want to learn leer ?");
                                                }
                                                break;

                                        case 3:
                                                player->poke2.CTstat->quant=1;
                                                player->poke2.CTstat->type=LEER;
                                                sprintf(player->poke2.CTstat->name,"leer");

                                                if (player->poke2.type!=0)
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    mvwprintw(lab_map,3,108,"%s",player->poke2.name);
                                                    write_flush(lab_map,3,120,"learned leer !");
                                                    sleep(2);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                    finishchoice=1;
                                                }
                                                else
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"leer can't be learned by this pokemon");
                                                    sleep(1);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What pokemon you want to learn leer ?");
                                                }
                                                break;

                                        case 4:
                                                player->poke3.CTstat->quant=1;
                                                player->poke3.CTstat->type=LEER;
                                                sprintf(player->poke3.CTstat->name,"leer");

                                                if (player->poke3.type!=0)
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    mvwprintw(lab_map,3,108,"%s",player->poke3.name);
                                                    write_flush(lab_map,3,120,"learned leer !");
                                                    sleep(2);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                    finishchoice=1;
                                                }
                                                else
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"leer can't be learned by this pokemon");
                                                    sleep(1);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What pokemon you want to learn leer ?");
                                                }
                                                break;

                                        case 5:
                                                player->poke4.CTstat->quant=1;
                                                player->poke4.CTstat->type=LEER;
                                                sprintf(player->poke4.CTstat->name,"leer");

                                                if (player->poke4.type!=0)
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    mvwprintw(lab_map,3,108,"%s",player->poke4.name);
                                                    write_flush(lab_map,3,120,"learned leer !");
                                                    sleep(2);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                    finishchoice=1;
                                                }
                                                else
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"leer can't be learned by this pokemon");
                                                    sleep(1);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What pokemon you want to learn leer ?");
                                                }
                                                break;

                                        case 6:
                                                player->poke5.CTstat->quant=1;
                                                player->poke5.CTstat->type=LEER;
                                                sprintf(player->poke5.CTstat->name,"leer");

                                                if (player->poke5.type!=0)
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    mvwprintw(lab_map,3,108,"%s",player->poke5.name);
                                                    write_flush(lab_map,3,120,"learned leer !");
                                                    sleep(2);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                    finishchoice=1;
                                                }
                                                else
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"leer can't be learned by this pokemon");
                                                    sleep(1);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What pokemon you want to learn leer ?");
                                                }
                                                break;

                                        case 7:
                                                player->poke6.CTstat->quant=1;
                                                player->poke6.CTstat->type=LEER;
                                                sprintf(player->poke6.CTstat->name,"leer");

                                                if (player->poke6.type!=0)
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    mvwprintw(lab_map,3,108,"%s",player->poke6.name);
                                                    write_flush(lab_map,3,120,"learned leer !");
                                                    sleep(2);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What CT you want to teach to your pokemon");
                                                    finishchoice=1;
                                                }
                                                else
                                                {
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"leer can't be learned by this pokemon");
                                                    sleep(1);
                                                    mvwprintw(lab_map,3,108,"                                         ");
                                                    write_flush(lab_map,3,108,"What pokemon you want to learn leer ?");
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
                                    wclear(chat);
                                    wrefresh(blank);
                                }
                            }  
                        }
                        
                        break;

                    default:
                        break;
                    }

                    usleep(16667);
                    wclear(chat);
                    if (delwin(blank)==ERR)
                    {
                        exit(34);
                    }  
                }
            }
            
            else if (x==4)
            {
                mvwprintw(lab_map,3,108,"                                         ");
                write_flush(lab_map,3,108,"See you soon !");
                sleep(1);
                mvwprintw(lab_map,3,108,"                                         ");
                finish=1;
            }
            
            break;

        case ' ':
            mvwprintw(lab_map,3,108,"                                         ");
            write_flush(lab_map,3,108,"See you soon !");
            sleep(1);
            mvwprintw(lab_map,3,108,"                                         ");
            finish=1; 
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
        exit(26);
    }
    if (delwin(MDP)==ERR)
    {
        exit(27);
    }
    if (delwin(pc)==ERR)
    {
        exit(25);
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
            exit(29);
        }
        if (delwin(in)==ERR)
        {
            exit(30);
        }
        if (delwin(pc)==ERR)
        {
            exit(28);
        }
    }
}