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

void computer(trainer* player){
    int finish=0,ch=ERR;
    int x=1;

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

        mvwprintw(pc,17,25,"%s",player->poke1.name);
        mvwprintw(pc,20,25,"%s",player->poke2.name);
        mvwprintw(pc,23,25,"%s",player->poke3.name);
        mvwprintw(pc,26,25,"%s",player->poke4.name);
        mvwprintw(pc,29,25,"%s",player->poke5.name);
        mvwprintw(pc,32,25,"%s",player->poke6.name);

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