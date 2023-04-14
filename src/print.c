#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"


void print_player(WINDOW* win,double x,double y){
    init_pair(1,COLOR_RED,COLOR_BLACK);
    wattron(win,COLOR_PAIR(1));
    mvwprintw(win,x,y,"   _");                
    mvwprintw(win,x+1,y,"  '_'");                
    mvwprintw(win,x+2,y," /| |\\");
    mvwprintw(win,x+3,y,"* |_| *");
    mvwprintw(win,x+4,y,"  | |");
    mvwprintw(win,x+5,y,"  - -");
    wattroff(win,COLOR_PAIR(1));
}

void print_menu(WINDOW* win,double x,double y){

    mvwprintw(win,2,COLS/5,"88b           d88  88888888888  888b      88  88        88\n");
    mvwprintw(win,3,COLS/5,"888b         d888  88           8888b     88  88        88\n");
    mvwprintw(win,4,COLS/5,"88`8b       d8'88  88           88 `8b    88  88        88\n");
    mvwprintw(win,5,COLS/5,"88 `8b     d8' 88  88aaaaa      88  `8b   88  88        88\n");
    mvwprintw(win,6,COLS/5,"88  `8b   d8'  88  88           88   `8b  88  88        88\n");
    mvwprintw(win,7,COLS/5,"88   `8b d8'   88  88           88    `8b 88  88        88\n");
    mvwprintw(win,8,COLS/5,"88    `888'    88  88           88     `8888  Y8a.    .a8P\n"); 
    mvwprintw(win,9,COLS/5,"88     `8'     88  88888888888  88      `888    `Y8888Y  '\n");
        
    mvwprintw(win,13,COLS/15,"__   _____  _   _ ____    _____ _____    _    __  __ ");
    mvwprintw(win,13+1,COLS/15,"\\ \\ / / _ \\| | | |  _ \\  |_   _| ____|  / \\  |  \\/  |");
    mvwprintw(win,13+2,COLS/15," \\ V / | | | | | | |_) |   | | |  _|   / _ \\ | |\\/| |");
    mvwprintw(win,13+3,COLS/15,"  | || |_| | |_| |  _ <    | | | |___ / ___ \\| |  | |");
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

void print_map(WINDOW* map){
//position tete xy devant maison : (45;191)
//position tete xy devant lab : (25;191)
//position tete xy devant shop : (12;191)

mvwprintw(map,LINES/1.5,COLS/1.2,"       ________| |________");             
mvwprintw(map,LINES/1.5+1,COLS/1.2,"      /\\                  \\");         
mvwprintw(map,LINES/1.5+2,COLS/1.2,"     // \\   HOME  ______   \\");         
mvwprintw(map,LINES/1.5+3,COLS/1.2,"    //   \\        \\    /\\   \\");     
mvwprintw(map,LINES/1.5+4,COLS/1.2,"   //     \\        \\__/  \\   \\");     
mvwprintw(map,LINES/1.5+5,COLS/1.2,"  //       \\        \\ |[]|    \\");         
mvwprintw(map,LINES/1.5+6,COLS/1.2," /==========\\        \\|__|     \\");                 
mvwprintw(map,LINES/1.5+7,COLS/1.2,"/_I    __    \\__________________\\");             
mvwprintw(map,LINES/1.5+8,COLS/1.2,"  I   |[]|       |__|__|     I");         
mvwprintw(map,LINES/1.5+9,COLS/1.2,"  I   | -|       |__|__|     I");         
mvwprintw(map,LINES/1.5+10,COLS/1.2,"  I   |__|        XXXXX      I ");     
mvwprintw(map,LINES/1.5+11,COLS/1.2," ~~~"   "~~~~~~~~~~~~~~~~~~~~~~~~~~~"); 

mvwprintw(map,LINES/2.4,COLS/1.2,"                     ____");
mvwprintw(map,LINES/2.4+1,COLS/1.2,"  ___________________|  |______");
mvwprintw(map,LINES/2.4+2,COLS/1.2," /         LAB                 \\ ");
mvwprintw(map,LINES/2.4+3,COLS/1.2,"/_______________________________\\");
mvwprintw(map,LINES/2.4+4,COLS/1.2,"  ||___|___||||||||||||___|__||"); 
mvwprintw(map,LINES/2.4+5,COLS/1.2,"  ||___|___|||||  |||||___|__||"); 
mvwprintw(map,LINES/2.4+6,COLS/1.2,"  |||||||||||||| -|||||||||||||"); 
mvwprintw(map,LINES/2.4+7,COLS/1.2," ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); 

mvwprintw(map,LINES/8.4,COLS/1.2,"  _____________________________ ");                   
mvwprintw(map,LINES/8.4+1,COLS/1.2," |                             |");                   
mvwprintw(map,LINES/8.4+2,COLS/1.2," |   SHOP   ________           |");                   
mvwprintw(map,LINES/8.4+3,COLS/1.2," |         | .''''. |          |");                   
mvwprintw(map,LINES/8.4+4,COLS/1.2," |_________| :-()-: |__________|");                   
mvwprintw(map,LINES/8.4+5,COLS/1.2,"  | ______ | ',,,,' | _______ | ");                   
mvwprintw(map,LINES/8.4+6,COLS/1.2,"  ||  |   ||  ____  ||   |   || ");                   
mvwprintw(map,LINES/8.4+7,COLS/1.2,"  ||--+---|| |    | ||---+---|| ");                   
mvwprintw(map,LINES/8.4+8,COLS/1.2,"  ||__|___|| |   -| ||___|___|| ");                   
mvwprintw(map,LINES/8.4+9,COLS/1.2,"  |________|_|____|_|_________| ");                   
mvwprintw(map,LINES/8.4+10,COLS/1.2," ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");                   
}