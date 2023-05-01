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

void chargement(int time){
    WINDOW* pikachu_screen=newwin(LINES-1,COLS-1,0,0);
    WINDOW* pikachu_screen_void=newwin(LINES-1,COLS-1,0,0);
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
            sec+=3;
        }
        else
        {
            count_points++;
        }

        rewind(f);
    }
    
    fclose(f);
    delwin(pikachu_screen);
    wrefresh(pikachu_screen_void);
    endwin();
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
    mvwprintw(map,32+10,120,"    I     |__|__| |_1_| | -|   I<-");       //line = 9, col = 38  (+- 1)
    mvwprintw(map,32+11,120,"    I      XXXXX    |   |__|   I  ");
    mvwprintw(map,32+12,120,"   ~~~~~~~~~~~~~~~~~~~~~~~~~~~"   "~~~"); 

    mvwprintw(map,34,343,"                     ____");
    mvwprintw(map,34+1,343,"  ___________________|  |______");
    mvwprintw(map,34+2,343," /      LAB                    \\ ");
    mvwprintw(map,34+3,343,"/_______________________________\\");
    mvwprintw(map,34+4,343,"  |||||||||||||||||||||||||||||"); 
    mvwprintw(map,34+5,343,"  ||___|___||||||||||||___|__||"); 
    mvwprintw(map,34+6,343,"  ||___|___||||||||||||___|__||"); 
    mvwprintw(map,34+7,343,"  |||||||||||||    ||||||||||||"); 
    mvwprintw(map,34+8,343,"->|||||||||||||   -||||||||||||");            //line = 9, col = 218  (+- 1)
    mvwprintw(map,34+9,343,"  |||||||||||||    ||||||||||||"); 
    mvwprintw(map,34+10,343," ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

    mvwprintw(map,74,121,"  _____________________________ ");                   
    mvwprintw(map,74+1,121," |                             |");                   
    mvwprintw(map,74+2,121," |     SHOP ________           |");                   
    mvwprintw(map,74+3,121," |         | .''''. |          |");                   
    mvwprintw(map,74+4,121," |_________| :-()-: |__________|");                   
    mvwprintw(map,74+5,121,"  | ______ | ',,,,' | _______ | ");                   
    mvwprintw(map,74+6,121,"  ||  |   ||  ____  ||   |   || ");                   
    mvwprintw(map,74+7,121,"  ||--+---|| |    | ||---+---|| ");                   
    mvwprintw(map,74+8,121,"  ||__|___|| |   -| ||___|___||<-");        //line = 49, col = 38  (+- 1)                 
    mvwprintw(map,74+9,121,"  |________|_|____|_|_________| ");                   
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