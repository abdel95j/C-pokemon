#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"


void print_player(WINDOW* cam){
    init_pair(1,COLOR_RED,COLOR_BLACK);
    wattron(cam,COLOR_PAIR(1));
    mvwprintw(cam,((LINES-2)/2),(COLS-2)/2,"   _");                
    mvwprintw(cam,((LINES-2)/2)+1,(COLS-2)/2,"  '_'");                
    mvwprintw(cam,((LINES-2)/2)+2,(COLS-2)/2," /| |\\");
    mvwprintw(cam,((LINES-2)/2)+3,(COLS-2)/2,"* |_| *");
    mvwprintw(cam,((LINES-2)/2)+4,(COLS-2)/2,"  | |");
    mvwprintw(cam,((LINES-2)/2)+5,(COLS-2)/2,"  - -");
    wattroff(cam,COLOR_PAIR(1));
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

void create_map(WINDOW* map){

    //repérage : x_map = x_cadre + 29      y_map = y_cadre + 116

    mvwprintw(map,32,118,"        ________| |________"); 
    mvwprintw(map,32+1,118,"       /                  /\\      ");  
    mvwprintw(map,32+2,118,"      /       ______     /  \\     ");   
    mvwprintw(map,32+3,118,"     /       /\\    /    /    \\    ");  
    mvwprintw(map,32+4,118,"    /       /  /__/    /      \\   ");   
    mvwprintw(map,32+5,118,"   /        |[]| /    /        \\  ");       
    mvwprintw(map,32+6,118,"  /         |__|/    /==========\\ ");                
    mvwprintw(map,32+7,118," /__________________/   HOME   I_\\");            
    mvwprintw(map,32+8,118,"    I      _____         __    I  ");   
    mvwprintw(map,32+9,118,"    I     |__|__|       |[]|   I");   
    mvwprintw(map,32+10,118,"    I     |__|__|       | -|   I<-");
    mvwprintw(map,32+11,118,"    I      XXXXX        |__|   I  ");
    mvwprintw(map,32+12,118,"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~"   "~~~ "); 

/*    mvwprintw(map,5,COLS-38,"                     ____");
    mvwprintw(map,5+1,COLS-38,"  ___________________|  |______");
    mvwprintw(map,5+2,COLS-38," /      LAB                    \\ ");
    mvwprintw(map,5+3,COLS-38,"/_______________________________\\");
    mvwprintw(map,5+4,COLS-38,"  |||||||||||||||||||||||||||||"); 
    mvwprintw(map,5+5,COLS-38,"  ||___|___||||||||||||___|__||"); 
    mvwprintw(map,5+6,COLS-38,"  ||___|___||||||||||||___|__||"); 
    mvwprintw(map,5+7,COLS-38,"  |||||||||||||    ||||||||||||"); 
    mvwprintw(map,5+8,COLS-38,"->|||||||||||||   -||||||||||||"); 
    mvwprintw(map,5+9,COLS-38,"  |||||||||||||    ||||||||||||"); 
    mvwprintw(map,5+10,COLS-38," ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mvwprintw(map,5,2,"  _____________________________ ");                   
    mvwprintw(map,5+1,2," |                             |");                   
    mvwprintw(map,5+2,2," |     SHOP ________           |");                   
    mvwprintw(map,5+3,2," |         | .''''. |          |");                   
    mvwprintw(map,5+4,2," |_________| :-()-: |__________|");                   
    mvwprintw(map,5+5,2,"  | ______ | ',,,,' | _______ | ");                   
    mvwprintw(map,5+6,2,"  ||  |   ||  ____  ||   |   || ");                   
    mvwprintw(map,5+7,2,"  ||--+---|| |    | ||---+---|| ");                   
    mvwprintw(map,5+8,2,"  ||__|___|| |   -| ||___|___||<-");                   
    mvwprintw(map,5+9,2,"  |________|_|____|_|_________| ");                   
    mvwprintw(map,5+10,2," ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");   

    mvwprintw(map,50,233,"==");
    mvwprintw(map,50+1,234," ");
    mvwprintw(map,50+2,234," ");
    mvwprintw(map,50+3,234," ");
    mvwprintw(map,50+4,234," ");
    mvwprintw(map,50+5,234," ");
    mvwprintw(map,50+6,234," ");
    mvwprintw(map,50+7,234," ");
    mvwprintw(map,50+8,233,"==");*/

}