#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/physic.h"


void print_player(WINDOW* cam){
    wattron(cam,COLOR_PAIR(1));
    mvwprintw(cam,((LINES-2)/2),((COLS-2)/2)+3,"_");                
    mvwprintw(cam,((LINES-2)/2)+1,((COLS-2)/2)+2,"'_'");                
    mvwprintw(cam,((LINES-2)/2)+2,((COLS-2)/2)+1,"/| |\\");
    mvwprintw(cam,((LINES-2)/2)+3,(COLS-2)/2,"' |_| '");
    mvwprintw(cam,((LINES-2)/2)+4,((COLS-2)/2)+2,"| |");
    mvwprintw(cam,((LINES-2)/2)+5,((COLS-2)/2)+2,"- -");
    wattroff(cam,COLOR_PAIR(1));
}

void chargement(int time){
    WINDOW* pikachu_screen=newwin(LINES-1,COLS-1,0,0);
    FILE* f = NULL;
    int sec=0,count_points=0, frame_number;

    f=fopen("../saves/pikachu_frames","r");
    if(f==NULL){
        printw("ouverture du fichier ratée");
        exit(1);
    }

    while(sec!=6){
        char ligne[101];int ligne_limite;

        for(frame_number=1;frame_number<=4;frame_number++) 
        {
            switch (frame_number)
            {
            case 1:
                ligne_limite=34;
                break;
            case 2:
                ligne_limite=29;    /*ligne_limite=nombre de lignes de l'image*/
                break;
            case 3:
                ligne_limite=30;
                break;
            case 4:
                ligne_limite=34;
                break;
            default:
                break;
            }
            
            int j=15; 
            for(int i=0;i<ligne_limite;i++){
                fgets(ligne,100,f);
                mvwprintw(pikachu_screen,j,60,"%s",ligne);
                j++;
            }

            // 4 affichages = 1sec
            if (count_points<4)
            {
                mvwprintw(pikachu_screen,15,160,"    __                    ___                   ");
                mvwprintw(pikachu_screen,15+1,160,"   / /   ____  ____ _____/ (_)___  ____ _       ");
                mvwprintw(pikachu_screen,15+2,160,"  / /   / __ \\/ __ `/ __  / / __ \\/ __ `/       ");
                mvwprintw(pikachu_screen,15+3,160," / /___/ /_/ / /_/ / /_/ / / / / / /_/ /  _ ");
                mvwprintw(pikachu_screen,15+4,160,"/_____/\\____/\\__,_/\\__,_/_/_/ /_/\\__, /  (_)");
                mvwprintw(pikachu_screen,15+5,160,"                                /____/          ");    
            }

            else if (count_points<8)
            {
                mvwprintw(pikachu_screen,15,160,"    __                    ___                   ");
                mvwprintw(pikachu_screen,15+1,160,"   / /   ____  ____ _____/ (_)___  ____ _       ");
                mvwprintw(pikachu_screen,15+2,160,"  / /   / __ \\/ __ `/ __  / / __ \\/ __ `/       ");
                mvwprintw(pikachu_screen,15+3,160," / /___/ /_/ / /_/ / /_/ / / / / / /_/ /  _ _");
                mvwprintw(pikachu_screen,15+4,160,"/_____/\\____/\\__,_/\\__,_/_/_/ /_/\\__, /  (_|_)");
                mvwprintw(pikachu_screen,15+5,160,"                                /____/          ");
            }
            
            else if (count_points<12)
            {
                mvwprintw(pikachu_screen,15,160,"    __                    ___                   ");
                mvwprintw(pikachu_screen,15+1,160,"   / /   ____  ____ _____/ (_)___  ____ _       ");
                mvwprintw(pikachu_screen,15+2,160,"  / /   / __ \\/ __ `/ __  / / __ \\/ __ `/       ");
                mvwprintw(pikachu_screen,15+3,160," / /___/ /_/ / /_/ / /_/ / / / / / /_/ /  _ _ _ ");
                mvwprintw(pikachu_screen,15+4,160,"/_____/\\____/\\__,_/\\__,_/_/_/ /_/\\__, /  (_|_|_)");
                mvwprintw(pikachu_screen,15+5,160,"                                /____/          ");
            }
            
            wrefresh(pikachu_screen);
            wclear(pikachu_screen);
            
            usleep(68000);
        }

        if (count_points==11)
        {
            count_points=0;
            sec+=6;
        }
        else
        {
            count_points++;
        }

        rewind(f);
    }
    
    fclose(f);

    if (delwin(pikachu_screen)==ERR)
    {
        exit(13);
    }
}


void print_house(WINDOW* house_map, int x, int y){
        
    mvwprintw(house_map,3,20," _______");
    mvwprintw(house_map,3+1,20,"|_______|");
    mvwprintw(house_map,3+2,20,"|       |");
    mvwprintw(house_map,3+3,20,"|]      |");
    mvwprintw(house_map,3+4,20,"|_______|");
    mvwprintw(house_map,3+5,20,"|]      |");
    mvwprintw(house_map,3+6,20,"|       |");
    mvwprintw(house_map,3+7,20,"|_______|");
        
    mvwprintw(house_map,6,3," __=||=________ ");   
    mvwprintw(house_map,6+1,3,"|,--''-- |     |");
    mvwprintw(house_map,6+2,3,"||______||     |");
    mvwprintw(house_map,6+3,3,"|________|_____|");
    mvwprintw(house_map,6+4,3," |____________|");

    mvwprintw(house_map,5,45," ________ "); 
    mvwprintw(house_map,5+1,45,"|(_)++(_)|");
    mvwprintw(house_map,5+2,45,"|________|");
    mvwprintw(house_map,5+3,45,"|.------.|");
    mvwprintw(house_map,5+4,45,"||     o||");
    mvwprintw(house_map,5+5,45,"|`------'|");

    mvwprintw(house_map,7,29," _ ");
    mvwprintw(house_map,7+1,29,"| |");
    mvwprintw(house_map,7+2,29,"|-|");
    mvwprintw(house_map,7+3,29,"|_|");
      
    mvwprintw(house_map,4,70,"     __________");
    mvwprintw(house_map,4+1,70,"   _/__________\\_");
    mvwprintw(house_map,4+2,70,"  | ,----------. |");
    mvwprintw(house_map,4+3,70,"  | |  ...     | |");
    mvwprintw(house_map,4+4,70," _| | :-o-:    | |_____");
    mvwprintw(house_map,4+5,70,"| | |  '''     | |   __|");
    mvwprintw(house_map,4+6,70,"| | `----------' |  /~/|");
    mvwprintw(house_map,4+7,70,"|  ~~~~~~~~~~~~~~  /_/ |");
    mvwprintw(house_map,4+8,70,"|______________________|");
    mvwprintw(house_map,4+9,70," |____________________|");
   
    mvwprintw(house_map,17,70,"   ___________________   ");
    mvwprintw(house_map,17+1,70," _|                   |_ ");
    mvwprintw(house_map,17+2,70,"||                     ||");
    mvwprintw(house_map,17+3,70,"||                     ||");
    mvwprintw(house_map,17+4,70,"||_____________________||");
    mvwprintw(house_map,17+5,70,"    o               o    ");
                                                                           
    mvwprintw(house_map,3,125,"                  .'");                                                                                  
    mvwprintw(house_map,3+1,125,"               .'   ____ ");
    mvwprintw(house_map,3+2,125,"            .'   _,|     ");                                       
    mvwprintw(house_map,3+3,125,"         .'   _,| ||     ");                                          
    mvwprintw(house_map,3+4,125,"      .'   _,| || ||____ ");
    mvwprintw(house_map,3+5,125,"   .'   _,| || ||_|'    ");
    mvwprintw(house_map,3+6,125,"     _,| || ||_|'       ");              
    mvwprintw(house_map,3+7,125,"  _,| || ||_|'          ");
    mvwprintw(house_map,3+8,125," | || ||_|'             ");
    mvwprintw(house_map,3+9,125," | ||_|'                ");
    mvwprintw(house_map,3+10,125," |_|'___________________");

    mvwprintw(house_map,29,10,"   ____________  "); 
    mvwprintw(house_map,29+1,10," /'            '\\"); 
    mvwprintw(house_map,29+2,10,"|                | "); 
    mvwprintw(house_map,29+3,10,"|                | "); 
    mvwprintw(house_map,29+4,10," \\,____________,/ "); 
    
    mvwprintw(house_map,34,13," ___ ");
    mvwprintw(house_map,34+1,13,"|___|");
    
    mvwprintw(house_map,34,20," ___ ");
    mvwprintw(house_map,34+1,20,"|___|");

    mvwprintw(house_map,27,13," ___ ");
    mvwprintw(house_map,27+1,13,"|___|");
    
    mvwprintw(house_map,27,20," ___ ");
    mvwprintw(house_map,27+1,20,"|___|");

    mvwprintw(house_map,35,120," _____________ ");
    mvwprintw(house_map,35+1,120,"|             |");
    mvwprintw(house_map,35+2,120,"|   WELCOME   |");
    mvwprintw(house_map,35+3,120,"|             |");
    mvwprintw(house_map,35+4,120,"               ");

    wattron(house_map,COLOR_PAIR(2));
    mvwprintw(house_map,18-1,3,"MOM");
    mvwprintw(house_map,18,3,".,_  ");
    mvwprintw(house_map,18+1,3,"/'_' ");
    mvwprintw(house_map,18+2,3," \\|\\");   
    mvwprintw(house_map,18+3,3,"  | ");
    mvwprintw(house_map,18+4,3,"  -' ");
    wattroff(house_map,COLOR_PAIR(2));                             

    wattron(house_map,COLOR_PAIR(1));
    mvwprintw(house_map,x,y+2,"_");  
    mvwprintw(house_map,x+1,y+1,"'_'");
    mvwprintw(house_map,x+2,y,"/| |\\");
    mvwprintw(house_map,x+3,y+1,"|-|");
    mvwprintw(house_map,x+4,y+1,"- -");       
    wattroff(house_map,COLOR_PAIR(1));
}   

void print_shop(WINDOW*shop_map,int x, int y){
   
    mvwprintw(shop_map,2,13,"   ___       __         ______           ");
    mvwprintw(shop_map,2+1,13,"  / _ \\___  / /_____   / __/ /  ___  ___ ");
    mvwprintw(shop_map,2+2,13," / ___/ _ \\/  '_/ -_) _\\ \\/ _ \\/ _ \\/ _ \\");
    mvwprintw(shop_map,2+3,13,"/_/   \\___/_/\\_\\\\__/ /___/_//_/\\___/ .__/");
    mvwprintw(shop_map,2+4,13,"                                  /_/    ");

    mvwprintw(shop_map,1,130," ____________ ");
    mvwprintw(shop_map,1+1,130,"|            |");
    mvwprintw(shop_map,1+2,130,"|     .-.    |");
    mvwprintw(shop_map,1+3,130,"|    |-o-|   |");
    mvwprintw(shop_map,1+4,130,"|     '-'    |");
    mvwprintw(shop_map,1+5,130,"|            |");   
    mvwprintw(shop_map,1+6,130,"|____________|");

    mvwprintw(shop_map,1,100," ____________ ");
    mvwprintw(shop_map,1+1,100,"|            |");
    mvwprintw(shop_map,1+2,100,"|     .-.    |");
    mvwprintw(shop_map,1+3,100,"|    |-o-|   |");
    mvwprintw(shop_map,1+4,100,"|     '-'    |");
    mvwprintw(shop_map,1+5,100,"|            |");   
    mvwprintw(shop_map,1+6,100,"|____________|");

    mvwprintw(shop_map,1,70," ____________ ");
    mvwprintw(shop_map,1+1,70,"|            |");
    mvwprintw(shop_map,1+2,70,"|     .-.    |");
    mvwprintw(shop_map,1+3,70,"|    |-o-|   |");
    mvwprintw(shop_map,1+4,70,"|     '-'    |");
    mvwprintw(shop_map,1+5,70,"|            |");   
    mvwprintw(shop_map,1+6,70,"|____________|");

    mvwprintw(shop_map,12,90," __-__ ");
    mvwprintw(shop_map,12+1,90,"[]| |[]");
    mvwprintw(shop_map,12+2,90,"[]| |[]");
    mvwprintw(shop_map,12+3,90,"[]| |[]");
    mvwprintw(shop_map,12+4,90,"[]| |[]");
    mvwprintw(shop_map,12+5,90,"[]| |[]");
    mvwprintw(shop_map,12+6,90,"[]|-|[]");
    mvwprintw(shop_map,12+7,90,"|_____|");

    mvwprintw(shop_map,23,90," __-__ ");
    mvwprintw(shop_map,23+1,90,"[]| |[]");
    mvwprintw(shop_map,23+2,90,"[]| |[]");
    mvwprintw(shop_map,23+3,90,"[]| |[]");
    mvwprintw(shop_map,23+4,90,"[]| |[]");
    mvwprintw(shop_map,23+5,90,"[]| |[]");
    mvwprintw(shop_map,23+6,90,"[]|-|[]");
    mvwprintw(shop_map,23+7,90,"|_____|");

    mvwprintw(shop_map,12,110," __-__ ");
    mvwprintw(shop_map,12+1,110,"[]| |[]");
    mvwprintw(shop_map,12+2,110,"[]| |[]");
    mvwprintw(shop_map,12+3,110,"[]| |[]");
    mvwprintw(shop_map,12+4,110,"[]| |[]");
    mvwprintw(shop_map,12+5,110,"[]| |[]");
    mvwprintw(shop_map,12+6,110,"[]|-|[]");
    mvwprintw(shop_map,12+7,110,"|_____|");

    mvwprintw(shop_map,23,110," __-__ ");
    mvwprintw(shop_map,23+1,110,"[]| |[]");
    mvwprintw(shop_map,23+2,110,"[]| |[]");
    mvwprintw(shop_map,23+3,110,"[]| |[]");
    mvwprintw(shop_map,23+4,110,"[]| |[]");
    mvwprintw(shop_map,23+5,110,"[]| |[]");
    mvwprintw(shop_map,23+6,110,"[]|-|[]");
    mvwprintw(shop_map,23+7,110,"|_____|");

    mvwprintw(shop_map,23,144," _-_");
    mvwprintw(shop_map,23+1,144,"[]| |");
    mvwprintw(shop_map,23+2,144,"[]| |");
    mvwprintw(shop_map,23+3,144,"[]| |");
    mvwprintw(shop_map,23+4,144,"[]| |");
    mvwprintw(shop_map,23+5,144,"[]| |");
    mvwprintw(shop_map,23+6,144,"[]|-|");
    mvwprintw(shop_map,23+7,144,"|____");

    mvwprintw(shop_map,12,144," _-_");
    mvwprintw(shop_map,12+1,144,"[]| |");
    mvwprintw(shop_map,12+2,144,"[]| |");
    mvwprintw(shop_map,12+3,144,"[]| |");
    mvwprintw(shop_map,12+4,144,"[]| |");
    mvwprintw(shop_map,12+5,144,"[]| |");
    mvwprintw(shop_map,12+6,144,"[]|-|");
    mvwprintw(shop_map,12+7,144,"|____");
    
    mvwprintw(shop_map,17-7,1,"                                                            |    |");        
    mvwprintw(shop_map,17-6,1,"                                                    |\\ ___  | _/||");        
    mvwprintw(shop_map,17-5,1,"                                                    | |   | ||_|/|");        
    mvwprintw(shop_map,17-4,1,"                                                     \\|___| |    |");                                                                       
    mvwprintw(shop_map,17-3,1,"                               [$]                     `  ` |    |");
    mvwprintw(shop_map,17-2,1,"                                                            |    |");   
    mvwprintw(shop_map,17-1,1,"                                                            |    |");   
    mvwprintw(shop_map,17,1,"____________________________________________________________|    |");
    mvwprintw(shop_map,17+1,1,"                                                                 |"); 
    mvwprintw(shop_map,17+2,1,"_________________________________________________________________|"); 
    mvwprintw(shop_map,17+3,1,"                                                                 |"); 
    mvwprintw(shop_map,17+4,1,"_________________________________________________________________|"); 

    wattron(shop_map,COLOR_PAIR(2));
    mvwprintw(shop_map,15,31,"  _");
    mvwprintw(shop_map,16,31," '_'");
    mvwprintw(shop_map,17,31,"/|_|\\");
    wattroff(shop_map,COLOR_PAIR(2));

    mvwprintw(shop_map,35,120," _____________ ");
    mvwprintw(shop_map,35+1,120,"|             |");
    mvwprintw(shop_map,35+2,120,"|   WELCOME   |");
    mvwprintw(shop_map,35+3,120,"|             |");
    mvwprintw(shop_map,35+4,120,"               ");

    wattron(shop_map,COLOR_PAIR(1));
    mvwprintw(shop_map,x,y+2,"_");  
    mvwprintw(shop_map,x+1,y+1,"'_'");
    mvwprintw(shop_map,x+2,y,"/| |\\");
    mvwprintw(shop_map,x+3,y+1,"|-|");
    mvwprintw(shop_map,x+4,y+1,"- -");       
    wattroff(shop_map,COLOR_PAIR(1));
}

void print_menu(WINDOW* win,int x,int y){

    mvwprintw(win,2,COLS/5,"88b           d88  88888888888  888b      88  88        88\n");
    mvwprintw(win,3,COLS/5,"888b         d888  88           8888b     88  88        88\n");
    mvwprintw(win,4,COLS/5,"88`8b       d8'88  88           88 `8b    88  88        88\n");
    mvwprintw(win,5,COLS/5,"88 `8b     d8' 88  88aaaaa      88  `8b   88  88        88\n");
    mvwprintw(win,6,COLS/5,"88  `8b   d8'  88  88           88   `8b  88  88        88\n");
    mvwprintw(win,7,COLS/5,"88   `8b d8'   88  88           88    `8b 88  88        88\n");
    mvwprintw(win,8,COLS/5,"88    `888'    88  88           88     `8888  88a.    .a8P\n"); 
    mvwprintw(win,9,COLS/5,"88     `8'     88  88888888888  88      `888   '88888888'\n");
        
    mvwprintw(win,13,COLS/15,"__   _____  _   _ ____    _____ _____    _    __  __ ");
    mvwprintw(win,13+1,COLS/15,"\\ \\ / / _ \\| | | |  _ \\  |_   _| ____|  / \\  |  \\/  |");
    mvwprintw(win,13+2,COLS/15," \\ V / | | | | | | |_) |   | | |  _|   / _ \\ | |\\/| |");
    mvwprintw(win,13+3,COLS/15,"  | || |_| | |_| |  _ /    | | | |___ / ___ \\| |  | |");
    mvwprintw(win,13+4,COLS/15,"  |_| '___/ '___/|_| '_\\   |_| |_____/_/   \\_\\_|  |_|");

    mvwprintw(win,22,COLS/15," ____    ___     _______ ");
    mvwprintw(win,22+1,COLS/15,"/ ___|  / \\ \\   / / ____|");
    mvwprintw(win,22+2,COLS/15,"'___ ' / _ \\ \\ / /|  _|  ");
    mvwprintw(win,22+3,COLS/15," ___) / ___ \\ V / | |___ ");
    mvwprintw(win,22+4,COLS/15,"|____/_/   '_\\_/  |_____|");

    mvwprintw(win,31,COLS/15,  "  ___  _   _ ___ _____   _____ _   _ _____    ____    _    __  __ _____ "); 
    mvwprintw(win,31+1,COLS/15,  " / _ \\| | | |_ _|_   _| |_   _| | | | ____|  / ___|  / \\  |  \\/  | ____|"); 
    mvwprintw(win,31+2,COLS/15,  "| | | | | | || |  | |     | | | |_| |  _|   | |  _  / _ \\ | |\\/| |  _|  "); 
    mvwprintw(win,31+3,COLS/15,  "| |_| | |_| || |  | |     | | |  _  | |___  | |_| |/ ___ \\| |  | | |___ "); 
    mvwprintw(win,31+4,COLS/15,  " \\__\\__\\___/|___| |_|     |_| |_| |_|_____|  \\____/_/   \\_\\_|  |_|_____|"); 

    mvwprintw(win,x,y,"    .");
    mvwprintw(win,x+1,y,"  .;;............");
    mvwprintw(win,x+2,y,".;;;;::::::::::::");
    mvwprintw(win,x+3,y," ':;;::::::::::::");
    mvwprintw(win,x+4,y,"   ':");    
}

void print_inventory(WINDOW* sac,int x,int y){
    int i;
    
    for ( i = 0; i < 40; i++)
    {
        mvwprintw(sac,1+i,(COLS/1.5)/2,"|");    //colonne du millieu
    }    

    for ( i = 0; i < 40; i++)
    {
        mvwprintw(sac,1+i,(COLS/1.5)/4,"|");    //colonne de gauche
    }  

    for ( i = 0; i < 40; i++)
    {
        mvwprintw(sac,1+i,(COLS/1.5)/1.33,"|");    //colonne de droite
    } 

    for ( i = 0; i < 155; i++)
    {
        mvwprintw(sac,(LINES/1.5)/3,1+i,"_");    //ligne du haut
    }

    for ( i = 0; i < 155; i++)
    {
        mvwprintw(sac,(LINES/1.5)/1.5,1+i,"_");    //ligne du bas
    }

    mvwprintw(sac,x,y,"  ,");      
    mvwprintw(sac,x+1,y,".:::.");
}

void print_main_menu(WINDOW* win,int x,int y){
mvwprintw(win,5,55," _       __________    __________  __  _________   __________     ______            ____  ____  __ __ ________  _______  _   __   __");
mvwprintw(win,5+1,55,"| |     / / ____/ /   / ____/ __ \\/  |/  / ____/  /_  __/ __ \\   / ____/           / __ \\/ __ \\/ //_// ____/  |/  / __ \\/ | / /  / /");
mvwprintw(win,5+2,55,"| | /| / / __/ / /   / /   / / / / /|_/ / __/      / / / / / /  / /      ______   / /_/ / / / / ,<  / __/ / /|_/ / / / /  |/ /  / / ");
mvwprintw(win,5+3,55,"| |/ |/ / /___/ /___/ /___/ /_/ / /  / / /___     / / / /_/ /  / /___   /_____/  / ____/ /_/ / /| |/ /___/ /  / / /_/ / /|  /  /_/  ");
mvwprintw(win,5+4,55,"|__/|__/_____/_____/\\____/\\____/_/  /_/_____/    /_/  \\____/   \\____/           /_/    \\____/_/ |_/_____/_/  /_/\\____/_/ |_/  (_)   ");


mvwprintw(win,20,130,"                         &&@&@#                                                                    "); 
mvwprintw(win,20+1,130,"                         &&&&@&..*.                                                                ");
mvwprintw(win,20+2,130,"                          .@&@/....,,&                                                           ,(");
mvwprintw(win,20+3,130,"                            #@*.........#                                               ,(.&@@&&@@ ");
mvwprintw(win,20+4,130,"                              #..........,,/                                       ./......,@&@&.  ");
mvwprintw(win,20+5,130,"                                ,,...........@                                 *,.........,(@&.    ");
mvwprintw(win,20+6,130,"                                   #,..........#    ,#@(((((##*.            #,,..........,,&       ");
mvwprintw(win,20+7,130,"           @..&                       &*.......,..,................,.@   @,,............(          ");
mvwprintw(win,20+8,130,"         #,......,.(*                    ./,*,..........................,,..........,(             ");
mvwprintw(win,20+9,130,"       #,...........,.../,                 ,,,............................,,..,,@                  ");
mvwprintw(win,20+10,130,"      .,.................,,,,@            *,..,.,..,......................,./                      ");
mvwprintw(win,20+11,130,"    #............................,/      #..,.(&@   #...............,........                      ");
mvwprintw(win,20+12,130,"   ..,................................@  *..,.&&@&@&&.,............&  ,@&...,                      ");
mvwprintw(win,20+13,130," /.,............................,.,...,.#.,.,,..*@*,,....,.,,,..../&&@&&&,..,                      ");
mvwprintw(win,20+14,130,"#,...........................#,,...,...(#(((((@.,..,,.,..,..........#&&(,...*                      ");
mvwprintw(win,20+15,130,"   #************************(........,@#(((((((#......@@@&&&@&&&,..........,,                      ");
mvwprintw(win,20+16,130,"            .#(**************#..........,(((((@.....,.########@#.....,#((((((*                     ");
mvwprintw(win,20+17,130,"                      .##*****/...........,(.,.......,#//////(/.....,,(((((((.                     ");
mvwprintw(win,20+18,130,"                               (,............*.........#*///(..........#(((@                       ");
mvwprintw(win,20+19,130,"                              @*(...........,.*........,.*.,,.........,./                          ");
mvwprintw(win,20+20,130,"                            *******,................................,/*                            ");
mvwprintw(win,20+21,130,"                           ********#.................******,,.....,,,.,(                           ");
mvwprintw(win,20+22,130,"                         @********(  .,...................,..,..,........                          ");
mvwprintw(win,20+23,130,"                         .@***********#*#,.,.................,,.........@                          ");
mvwprintw(win,20+24,130,"                               .#*****,.,....................,,.........*                          ");
mvwprintw(win,20+25,130,"                                 (***@,.....................,#,.........#                          ");
mvwprintw(win,20+26,130,"                               @###/&........................,........,,*                          ");
mvwprintw(win,20+27,130,"                             (@#####,.....(/#*,.............,.........,((*                         ");
mvwprintw(win,20+28,130,"                                 ,@#...,..,(#,,.,*...........,.....,.,/,..,@(,,@                   ");
mvwprintw(win,20+29,130,"                                   ......./,**.,,...........,#.,,.,..(..,,/.***                    ");
mvwprintw(win,20+30,130,"                                   .......******................,.*.,..../****/                    ");
mvwprintw(win,20+31,130,"                                   /.....**#****@**,.,**********,,......*****,                     ");
mvwprintw(win,20+32,130,"                                    #***************************************                       ");
mvwprintw(win,20+33,130,"                                       @**********************************/                        ");
mvwprintw(win,20+34,130,"                                              #*(                     *(                           ");

mvwprintw(win,28,30," ___           _                                         _             _                ");
mvwprintw(win,28+1,30,"| _ ) ___ __ _(_)_ _    __ _   _ _  _____ __ __  __ _ __| |_ _____ _ _| |_ _  _ _ _ ___ ");
mvwprintw(win,28+2,30,"| _ \\/ -_) _` | | ' \\  / _` | | ' \\/ -_) V  V / / _` / _` \\ V / -_) ' \\  _| || | '_/ -_)");
mvwprintw(win,28+3,30,"|___/\\___\\__, |_|_||_| \\__,_| |_||_\\___|\\_/\\_/  \\__,_\\__,_|\\_/\\___|_||_\\__|\\_,_|_| \\___|");
mvwprintw(win,28+4,30,"         |___/                                                                                         ");

mvwprintw(win,38,30," _                 _                                           _          ");
mvwprintw(win,38+1,30,"| |   ___  __ _ __| |  __ _   _ __ _ _ ___  __ _ _ _ ___ _____(_)___ _ _  ");
mvwprintw(win,38+2,30,"| |__/ _ \\/ _` / _` | / _` | | '_ \\ '_/ _ \\/ _` | '_/ -_|_-<_-< / _ \\ ' \\ ");
mvwprintw(win,38+3,30,"|____\\___/\\__,_\\__,_| \\__,_| | .__/_| \\___/\\__, |_| \\___/__/__/_\\___/_||_|");
mvwprintw(win,38+4,30,"                             |_|           |___/                          ");

mvwprintw(win,x,y,"        :'");   
mvwprintw(win,x+1,y,"::::::::;;:'"); 
mvwprintw(win,x+2,y,"::::::::;;;;.");
mvwprintw(win,x+3,y,"........;;.");  
mvwprintw(win,x+4,y,"        .");  

}

void create_map(WINDOW* map){

    //repérage : x_map = x_cadre + 29      y_map = y_cadre + 116

    mvwprintw(map,32,120,"        ________| |________"); 
    mvwprintw(map,32+1,120,"       /                  /\\");  
    mvwprintw(map,32+2,120,"      /       ______     /  \\");   
    mvwprintw(map,32+3,120,"     /       /\\    /    /    \\");  
    mvwprintw(map,32+4,120,"    /       /  /__/    /      \\");   
    mvwprintw(map,32+5,120,"   /        |[]| /    /        \\");       
    mvwprintw(map,32+6,120,"  /         |__|/    /==========\\");                
    mvwprintw(map,32+7,120," /__________________/   HOME   I_\\");            
    mvwprintw(map,32+8,120,"    I      _____         __    I");   
    mvwprintw(map,32+9,120,"    I     |__|__|  ___  |[]|   I");   
    mvwprintw(map,32+10,120,"    I     |__|__| |_1_| | -|   I");       //line = 9, col = 38  (+- 1)
    mvwprintw(map,32+11,120,"    I      XXXXX    |   |__|   I");
    mvwprintw(map,32+12,120,"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); 

    mvwprintw(map,34,343,"                     ____");
    mvwprintw(map,34+1,343,"  ___________________|  |______");
    mvwprintw(map,34+2,343," /      LAB                    \\ ");
    mvwprintw(map,34+3,343,"/_______________________________\\");
    mvwprintw(map,34+4,343,"  |||||||||||||||||||||||||||||"); 
    mvwprintw(map,34+5,343,"  ||___|___||||||||||||___|__||"); 
    mvwprintw(map,34+6,343,"  ||___|___||||||||||||___|__||"); 
    mvwprintw(map,34+7,343,"  |||||||||||||    ||||||||||||"); 
    mvwprintw(map,34+8,343,"  |||||||||||||   -||||||||||||");            //line = 9, col = 218  (+- 1)
    mvwprintw(map,34+9,343,"  |||||||||||||    ||||||||||||"); 
    mvwprintw(map,34+10,343," ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mvwprintw(map,74,121,"  _____________________________ ");                   
    mvwprintw(map,74+1,121," |                             |");                   
    mvwprintw(map,74+2,121," |     SHOP ________           |");                   
    mvwprintw(map,74+3,121," |         | .''''. |          |");                   
    mvwprintw(map,74+4,121," |_________| :-()-: |__________|");                   
    mvwprintw(map,74+5,121,"  | ______ | ',,,,' | _______ |");                   
    mvwprintw(map,74+6,121,"  ||  |   ||  ____  ||   |   ||");                   
    mvwprintw(map,74+7,121,"  ||--+---|| |    | ||---+---||");                   
    mvwprintw(map,74+8,121,"  ||__|___|| |   -| ||___|___||");        //line = 49, col = 38  (+- 1)                 
    mvwprintw(map,74+9,121,"  |________|_|____|_|_________|");                   
    mvwprintw(map,74+10,121," ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");   

    mvwprintw(map,54-3,369,"___________");
    mvwprintw(map,54-2,369,"|_OUTSIDE_|");
    mvwprintw(map,54-1,369,"     |  ");
    mvwprintw(map,54,380,"===");
    mvwprintw(map,54+1,381," ");
    mvwprintw(map,54+2,381," ");
    mvwprintw(map,54+3,381," ");
    mvwprintw(map,54+4,381,"  ->");     //line = 25, col = 256 (+- 1)
    mvwprintw(map,54+5,381," ");
    mvwprintw(map,54+6,381," ");
    mvwprintw(map,54+7,381," ");
    mvwprintw(map,54+8,380,"===");

    mvwprintw(map,122,120,"        ________| |________"); 
    mvwprintw(map,122+1,120,"       /                  /\\");  
    mvwprintw(map,122+2,120,"      /       ______     /  \\");   
    mvwprintw(map,122+3,120,"     /       /\\    /    /    \\");  
    mvwprintw(map,122+4,120,"    /       /  /__/    /      \\");   
    mvwprintw(map,122+5,120,"   /        |[]| /    /        \\");       
    mvwprintw(map,122+6,120,"  /         |__|/    /==========\\");                 
    mvwprintw(map,122+7,120," /__________________/          I_\\");            
    mvwprintw(map,122+8,120,"    I      _____         __    I");   
    mvwprintw(map,122+9,120,"    I     |__|__|  ___  |[]|   I");   
    mvwprintw(map,122+10,120,"    I     |__|__| |_2_| | -|   I");
    mvwprintw(map,122+11,120,"    I      XXXXX    |   |__|   I");
    mvwprintw(map,122+12,120,"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~"   "~~~"); 


    mvwprintw(map,122,343,"       ________| |________"); 
    mvwprintw(map,122+1,343,"      /\\                  \\");  
    mvwprintw(map,122+2,343,"     /  \\     ______       \\");   
    mvwprintw(map,122+3,343,"    /    \\    \\    /\\       \\");  
    mvwprintw(map,122+4,343,"   /      \\    \\__\\  \\       \\");   
    mvwprintw(map,122+5,343,"  /        \\    \\ |[]|        \\");       
    mvwprintw(map,122+6,343," /==========\\    \\|__|         \\");                 
    mvwprintw(map,122+7,343,"/_I          \\__________________\\");            
    mvwprintw(map,122+8,343,"  I    __         _____      I");   
    mvwprintw(map,122+9,343,"  I   |[]|  ___  |__|__|     I");   
    mvwprintw(map,122+10,343,"  I   |- | |_5_| |__|__|     I");
    mvwprintw(map,122+11,343,"  I   |__|   |    XXXXX      I");
    mvwprintw(map,122+12,343," ~~~"   "~~~~~~~~~~~~~~~~~~~~~~~~~~~"); 

    mvwprintw(map,72,343,"       ________| |________"); 
    mvwprintw(map,72+1,343,"      /\\                  \\");  
    mvwprintw(map,72+2,343,"     /  \\     ______       \\");   
    mvwprintw(map,72+3,343,"    /    \\    \\    /\\       \\");  
    mvwprintw(map,72+4,343,"   /      \\    \\__\\  \\       \\");   
    mvwprintw(map,72+5,343,"  /        \\    \\ |[]|        \\");       
    mvwprintw(map,72+6,343," /==========\\    \\|__|         \\");                 
    mvwprintw(map,72+7,343,"/_I          \\__________________\\");            
    mvwprintw(map,72+8,343,"  I    __         _____      I");   
    mvwprintw(map,72+9,343,"  I   |[]|  ___  |__|__|     I");   
    mvwprintw(map,72+10,343,"  I   |- | |_3_| |__|__|     I");
    mvwprintw(map,72+11,343,"  I   |__|   |    XXXXX      I");
    mvwprintw(map,72+12,343," ~~~"   "~~~~~~~~~~~~~~~~~~~~~~~~~~~"); 

    mvwprintw(map,97,343,"       ________| |________"); 
    mvwprintw(map,97+1,343,"      /\\                  \\");  
    mvwprintw(map,97+2,343,"     /  \\     ______       \\");   
    mvwprintw(map,97+3,343,"    /    \\    \\    /\\       \\");  
    mvwprintw(map,97+4,343,"   /      \\    \\__\\  \\       \\");   
    mvwprintw(map,97+5,343,"  /        \\    \\ |[]|        \\");       
    mvwprintw(map,97+6,343," /==========\\    \\|__|         \\");                 
    mvwprintw(map,97+7,343,"/_I          \\__________________\\");            
    mvwprintw(map,97+8,343,"  I    __         _____      I");   
    mvwprintw(map,97+9,343,"  I   |[]|  ___  |__|__|     I");   
    mvwprintw(map,97+10,343,"  I   |- | |_4_| |__|__|     I");
    mvwprintw(map,97+11,343,"  I   |__|   |    XXXXX      I");
    mvwprintw(map,97+12,343," ~~~"   "~~~~~~~~~~~~~~~~~~~~~~~~~~~"); 
}

void print_newtrainer(WINDOW* chat){

    mvwprintw(chat,2+1,150,"                     .@@&@ #.&@#/,,,*,./@&                        ");         
    mvwprintw(chat,2+2,150,"                #@@*&&&&&&&@@@@@@@@@@@@@&@,@@                     ");     
    mvwprintw(chat,2+3,150,"            #/&&&&&&@&&&&&&&&&&@@@@@@@@@@@&&&*@                   ");     
    mvwprintw(chat,2+4,150,"             (&@&&&&&&&&&&&&&&&&&@@@@@@@@@@@@&*                   ");     
    mvwprintw(chat,2+5,150,"              &@&&&&&,@@@@@@&*&&@@/&&&&&&&(@@&*@                  ");     
    mvwprintw(chat,2+6,150,"               @*&&&*@@@@@@@&&&&&&@&&&&&&&@@(/*@                  ");     
    mvwprintw(chat,2+7,150,"                @#((*&/***.#&&&&&&&&#.,,,(&,((&                   ");     
    mvwprintw(chat,2+8,150,"                @(&*/&&&*#,.,/&&&#*.*/&@@&&/*&(&                  ");     
    mvwprintw(chat,2+9,150,"                (#*/@&&*@@.(@&&&&&&@@.@@/&&#*,&.@                 ");     
    mvwprintw(chat,2+10,150,"                &,#*.&&&&@*#&&&&&&&&@/*&&&&./#*@                  ");     
    mvwprintw(chat,2+11,150,"                  @,*(&&&&&&&&&@#&&&&&&&&&(#*&@                   ");     
    mvwprintw(chat,2+12,150,"                     #&&&&@&&&&&&&&&&&(&&&*(                      ");     
    mvwprintw(chat,2+13,150,"                      @,&&&&&&&&&&&&&&&&/&@                       ");     
    mvwprintw(chat,2+14,150,"                        (&./&&&&&&&&&.(@                          ");     
    mvwprintw(chat,2+15,150,"                 /@&#(@@@(**////////*,,((,,/&@                    ");     
    mvwprintw(chat,2+16,150,"           .@&/#@@@#@@@@.((,,,,//,,,,,, //(.///#.@@               ");     
    mvwprintw(chat,2+17,150,"        .&@&@@@@@@#@@@@*&*((,,,,.,,,,,.@&&@@*@@@@@@&,@.           ");     
    mvwprintw(chat,2+18,150,"       @/&&&&&@@@@@@/&@*&&@(@#/*//(@(@@@.&,@@@&@@@(@@&.@          ");     
    mvwprintw(chat,2+19,150,"      (#&@@@@&@@@@*@@&@####@&&,*,*@@@@@@&@&#&@@@@@&@@@@ @         ");     
    mvwprintw(chat,2+20,150,"      @#@(@@####((((((((((((,&,##/@@@@@(@@@@**(/,@/@@@@@.@        ");     
    mvwprintw(chat,2+21,150,"     @*@@/( .*(############(#@&&@@@@@@@,@@@*/*@((//@@@@@@##/      ");     
    mvwprintw(chat,2+22,150,"     &@@@&,#################/.&&@@@@@@@*@@(@@@@,@#/@@@@@@@,@      ");     
    mvwprintw(chat,2+23,150,"    @#@@@@#######(*#/*#@@@#@((/@@@@@@@@(@@@@@@@@@#(@@@@@@@#&      ");     
    mvwprintw(chat,2+24,150,"  ,@/@&@@@@*,**###*//*#######(*@@@@@@@#&&@@@@@@&&//@@@@@@@@*@     ");     
    mvwprintw(chat,2+25,150," .#@@@@@@@@,##.###*,#@@#/,###((.@@@@@@/@((((//#&@@(@@@@@@&&&*@    ");     
    mvwprintw(chat,2+26,150," @(@@@@@@@,/(/&&&&&&&,*@###(##(,@@@@,@,*@@@@@@@@@@#@@@&&@&@@@@.   ");     
    mvwprintw(chat,2+27,150,"@#@@@@@@@*/*(#@&&#@@&&&&&#(##,*, @@@/#.@@@@@@@@@@@@@@@@@(@@@@,@   ");     
    mvwprintw(chat,2+28,150,"@*@@@@@@,/.###(#&&&&&&&&*/#(,//*,/@@@#.@@@@@@@@@@@&,@&&@@@@@@@@   ");     
    mvwprintw(chat,2+29,150,"*@(@@@@@*//######,#(##### /////*,.#.,,,@@@@@@@@@&&@@(@@@@@@@@(&@  ");     
    mvwprintw(chat,2+30,150,"  ##&@@@,///(###########....*////&(,**,@@@@@@@@@@@@@*@@@@@@,@*    ");     
    mvwprintw(chat,2+31,150,"    *@/@@*(///((/(*/####/,,,,.,,.,*(/*,@@@@@@@@@@@@@@,@@,@*       ");     
    mvwprintw(chat,2+32,150,"       &*#@@#.,#########.,,,,.,,.,/(,*.@@@@@@@@@@@@@@@@@          ");     
    mvwprintw(chat,2+33,150,"      @.@@&@###@.#######.,*//.,,.//*(/,@@@@@@@&&&@@@@@&/&         ");     
    mvwprintw(chat,2+34,150,"      @@@@@@@@@&*@#####@.*///,//*///// &@@@@@&#@@@@@@@@.@         ");     
    mvwprintw(chat,2+35,150,"      @@@@@@@@@@@@@@@@&@,/*///*/,///// &@@@@@&/@@@@@@@@(@         ");     
    mvwprintw(chat,2+36,150,"     @/@@@@@@@@#@@@@@@@@//////*/,///// &@@@@@@*@@@@@@@@@&         ");     
    mvwprintw(chat,2+37,150,"     @(@@@@@@@@,@@@@@@@(//,,,,,,.///// @@@@@@@,@@@@@@@@&#@        ");     
    mvwprintw(chat,2+38,150,"     @(@@@@@@@@@@@@@@@@,//*,,.,((.//// @@@@@@@*&@@@@@@@&*@        ");     
    mvwprintw(chat,2+39,150,"     @&@@@@@@@&@@@@@@@@.///*,,.(((*/// @@@@@@@(&@@@@@@@@.@        ");     
    mvwprintw(chat,2+40,150,"     @@@@@@&@(#@@@@@@@@,////,,*(((./// &@@@@@@@#@@##///#.@        ");     
    mvwprintw(chat,2+41,150,"    *(@@@@@@@@@@@@@@@@@/////*,((((/*/,.&@@@@@@@@@@@@@@@@ @        ");     
    mvwprintw(chat,2+42,150,"    #*@@@@@@@@@@@@@@@@#/////*.(((((,//,&@@@@@@@@@@@@@@@@ @        ");     
    mvwprintw(chat,2+43,150,"    #*@@@@@@@@@@@@@@@@*/////**,**,,.//,&@@@@@@@@@@@@@@@@.@        ");     
    mvwprintw(chat,2+44,150,"        @//**,...#@&@@./////*.@   *@*/*&@@@@&&@*...,,,,@          ");     
    mvwprintw(chat,2+45,150,"        ///////////////////**.@    @,///****/////////*,@          ");     
    mvwprintw(chat,2+46,150,"        /////.///////////***,.@    @*////////////////**&          ");     
    mvwprintw(chat,2+47,150,"        ////*///////////****,*@    ,&*//////////////**,(&         ");     
    mvwprintw(chat,2+48,150,"        @//,///////////*****,/@     @.///////////**,,,,,#@        ");     
    mvwprintw(chat,2+49,150,"        @.((//////////******.&.     @*//////////*,,,,,,,**@       ");     
    mvwprintw(chat,2+50,150,"       @*((//////////******,,/@      @,////////*,,,,,,,,,,@       ");     
    mvwprintw(chat,2+51,150,"       @.,//*/////,***,*****,@.      @ *//////*.,/////.,,,@       ");     
    mvwprintw(chat,2+52,150,"    /@.,#/////////*,**,.,,,.&,       @.,,/*,/,//////////, @       ");     
    mvwprintw(chat,2+53,150,"   @./(#**/////////*.**,.,.(@         @(,/(/,*//////////.,,&      ");     
    mvwprintw(chat,2+54,150,"   @.*/////((///////*,..@@              @,////((////////*,,,@     ");     
    mvwprintw(chat,2+55,150,"    @.****,,......,*,.@                 @**,*,.,**////*....#*     ");     
    mvwprintw(chat,2+56,150,"         @@&#/*..,@@                      /@&*.  ....  *@@        ");  

    mvwprintw(chat,15,18,"__      ___         _   _                                                                  _            _                ___            ");
    mvwprintw(chat,15+1,18,"\\ \\    / / |_  __ _| |_( )___  _  _ ___ _  _ _ _   _ _  __ _ _ __  ___   _ _  _____ __ __ | |_ _ _ __ _(_)_ _  ___ _ _  |__ \\           ");
    mvwprintw(chat,15+2,18," \\ \\/\\/ /| ' \\/ _` |  _|/(_-< | || / _ \\ || | '_| | ' \\/ _` | '  \\/ -_) | ' \\/ -_) V  V / |  _| '_/ _` | | ' \\/ -_) '_|   /_/  ");
    mvwprintw(chat,15+3,18,"  \\_/\\_/ |_||_\\__,_|\\__| /__/  \\_, \\___/\\_,_|_|   |_||_\\__,_|_|_|_\\___| |_||_\\___|\\_/\\_/   \\__|_| \\__,_|_|_||_\\___|_|    (_)            ");
    mvwprintw(chat,15+4,18,"                               |__/                                                                                                     ");    
}

void print_get_firstpoke(WINDOW* win,int x,int y){

    mvwprintw(win,15-1,95,"          .(*,@°@,*#.                                         ");
    mvwprintw(win,15,95,"           #,,,,,,,,,,(/                                                ");
    mvwprintw(win,15+1,95,"        &,   ,,,,,,,,,,*/&                                    ");
    mvwprintw(win,15+2,95,"      *,,...,,,,,,,,,,,,*//                                   ");
    mvwprintw(win,15+3,95,"     @,,,,,,,,,,,,,,,,*#@(//                                  ");
    mvwprintw(win,15+4,95,"     @.,*,,,,,,,,,,,,*(  @@/#                                 ");
    mvwprintw(win,15+5,95,"     & /,,,,,,,,,,,,,,&@*@@#/                                 ");
    mvwprintw(win,15+6,95,"     #@@,,,,,,,,,,,,,,#@@&@(/(                                ");
    mvwprintw(win,15+7,95,"    #*&&,,,,,,,,,,,,,,,&/*////                                ");
    mvwprintw(win,15+8,95,"    *,,,,,,.,,,,,,,,,,,,//////                         .      ");
    mvwprintw(win,15+9,95,"    ///@,,,,,,,,,,,,*@&& @///(                        (/#     ");
    mvwprintw(win,15+10,95,"      (//(##(#(#(((/**/#////*                       / ((/*   ");
    mvwprintw(win,15+11,95,"         #///&*,.,,,,@/////#                       #.*/(/(   ");
    mvwprintw(win,15+12,95,"             &///(/////////*,/(                   ./*///.*/, ");
    mvwprintw(win,15+13,95,"       .@,,,,**/#.. .&///*,,,,,,,,,/(             //((/((.,. ");
    mvwprintw(win,15+14,95," ,@,,,,,,,,,,@/        /,,,,,,,,,,,,,,,,/(&&     ../.*(/, ./ ");
    mvwprintw(win,15+15,95,"@,,,,,,,,,,,,@           &,,,,,,,,,,,,,(//*/    #... (.  ,/  ");
    mvwprintw(win,15+16,95,"  ,,,///////@              ,*(#///////&/          #.... .((  ");
    mvwprintw(win,15+17,95,"                            ,,,**/                 /..,,//(  ");
    mvwprintw(win,15+18,95,"                            .,,,,,*                   ,@     ");
    mvwprintw(win,15+19,95,"                             &,,,,,,@               ,*,@     ");
    mvwprintw(win,15+20,95,"           *                  (,,,,,,/             @//(      ");
    mvwprintw(win,15+21,95,"        #,,,,           .....,...,,,,,,/        @(///#,      ");
    mvwprintw(win,15+22,95,"      ,.  .,,*..      .   ..*...,,,,,,,/#((((((((((@.        ");
    mvwprintw(win,15+23,95,"      ...,,,////     .  .   *,,,,,,,,,*/((((((((((,          ");
    mvwprintw(win,15+24,95,"     .,**//////////#        ********/////((((&,,@            ");
    mvwprintw(win,15+25,95,"      &///////////@.       .(@@///////////*&.                ");
    mvwprintw(win,15+26,95,"    /,#/(///////*               #////////@                   ");
    mvwprintw(win,15+27,95,"  &(&  . .&                      &//////&@./                 ");
    mvwprintw(win,15+28,95,"                                  ,@  @&,.&                 ");

    mvwprintw(win,20,25,"                                          ,            ");   
    mvwprintw(win,20+1,25,"                                         (*(&*(        ");   
    mvwprintw(win,20+2,25,"                         ,#*****//***/////#**/@(@      ");   
    mvwprintw(win,20+3,25,"                     &******//**/@(**********/((       ");   
    mvwprintw(win,20+4,25,"       /#,         &((///***/#/********/*/**/(((#      ");   
    mvwprintw(win,20+5,25,"     (****#,,,,,,,******@/,,,***//*/////***//(@(((     ");   
    mvwprintw(win,20+6,25,"    /*(,,,,,,,,#####***********/(*///***//(((((((((    ");   
    mvwprintw(win,20+7,25,"    **,,,,,((#####*************/((((((((((((((((((((   ");   
    mvwprintw(win,20+8,25,"   (,,****@***(/****************//(((((((((((((((#(((( ");   
    mvwprintw(win,20+9,25,"  ##.#***(/****,****(,**,&##@**//////@#(((((((((((((((@");   
    mvwprintw(win,20+10,25," ,@.#///*****###****,*(.((/.#@/(///@//(@(((((((((((((((");   
    mvwprintw(win,20+11,25," *,.#,/********@*****@..@#(.##/////(/(#####@((##((((((@");   
    mvwprintw(win,20+12,25," ***&(*,,************...,(((((//(/((//(@#####(@((((((( ");   
    mvwprintw(win,20+13,25," @((***,,*******************//#/////////(@@@@((/&((#@  ");   
    mvwprintw(win,20+14,25,"   ,(/##@#/////////((#@@#*&//(///(//////////(////(     ");   
    mvwprintw(win,20+15,25,"       &//((//////////&(((////&/*******/#/#***/////    ");   
    mvwprintw(win,20+16,25,"       @***/(@(//(////(@#((((****@****//&*/((##//(((   ");   
    mvwprintw(win,20+17,25,"       .*(((#///(#((((((((((**#@*#****///*#(##@//(//   ");   
    mvwprintw(win,20+18,25,"        @(((@///////*##(((((//(******//@///((@(////#   ");   
    mvwprintw(win,20+19,25,"         (**//////(     #(@####****//# /((//////((/    ");   
    mvwprintw(win,20+20,25,"         .*.@/*//,        /*****///(     @(/#//(/#     ");   
    mvwprintw(win,20+21,25,"                            ,./.@                      ");   

    mvwprintw(win,21,160,"                         .(*,,*#.");
    mvwprintw(win,21+1,160,"                     *,,,,,,,,,,.. .&");
    mvwprintw(win,21+2,160,"                   .*///,*.*.,,,,,,,,(,");
    mvwprintw(win,21+3,160,"                  ////**#@@@@,,,,,,,,,@");
    mvwprintw(win,21+4,160,"                  (///// (&@&,,,,,,,,,##");
    mvwprintw(win,21+5,160,"                  (//////,,,,,,,,,,,(,,./");
    mvwprintw(win,21+6,160,"                   //(///((///////(//(/(");
    mvwprintw(win,21+7,160,"                    (///(/////////////");
    mvwprintw(win,21+8,160,"                .//@*@##//////////@#/(*");
    mvwprintw(win,21+9,160,"                (@/@//*,,.,********...,,,,..&");
    mvwprintw(win,21+10,160,"               &//(///,,,,.,@*,..   #  /,,,,,,,*.,");
    mvwprintw(win,21+11,160,"              .**/,@//*,,,(,,,....     .@,,,,&#(( ");
    mvwprintw(win,21+12,160,"              &**/@.**/#(,//,,.......  .. .,,.");
    mvwprintw(win,21+13,160,"              (///( ,@*#/(/((..../.....,.");
    mvwprintw(win,21+14,160,".. (*,,,,,,*   (((( ,#***,@,,.. .#...../*");
    mvwprintw(win,21+15,160,".@//((/**,,,*( #((,#,,,,@**,.....#.....,,,");
    mvwprintw(win,21+16,160," ///(/(//#/////(##*,,,,,,,@****,.(..,,(,...");
    mvwprintw(win,21+17,160," @/(//////////////,,,,,,,,,&*/@****,@/*,,,.(");
    mvwprintw(win,21+18,160,"  ,/////((////////*,,,,.,,*#(/((.  (/////**(");
    mvwprintw(win,21+19,160,"      /#(///#@.  ///***/*(          //////**@,");
    mvwprintw(win,21+20,160,"                 //////(/                ,");
    mvwprintw(win,21+21,160,"                   .#");

    mvwprintw(win,7,85,"  ___ _                                        _                        _ ");
    mvwprintw(win,7+1,85," / __| |_  ___  ___ ___ ___   __ _   _ __  ___| |_____ _ __  ___ _ _   | |");
    mvwprintw(win,7+2,85,"| (__| ' \\/ _ \\/ _ (_-</ -_) / _` | | '_ \\/ _ \\ / / -_) '  \\/ _ \\ ' \\  |_|");
    mvwprintw(win,7+3,85," \\___|_||_\\___/\\___/__/\\___| \\__,_| | .__/\\___/_\\_\\___|_|_|_\\___/_||_| (_)");
    mvwprintw(win,7+4,85,"                                    |_|                                   ");

    mvwprintw(win,x,y,"    .");
    mvwprintw(win,x+1,y,"  .:;:.");      
    mvwprintw(win,x+2,y,".:;;;;;:.");        
    mvwprintw(win,x+3,y,"  ;;;;;");    
}