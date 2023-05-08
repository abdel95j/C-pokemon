#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>

int main()
{
    
    initscr();
    WINDOW* lab_map=newwin(40,150,13,43);
    WINDOW* line_wall_lab=subwin(lab_map,1,148,22,44);
    WINDOW* arena_zone=subwin(lab_map, 25, 50, 25, 92);
    box(lab_map,0,0);
    box(line_wall_lab,0,0);
    box(arena_zone, 0, 0);
    refresh();

    mvwprintw(lab_map,3,1,  "       _________       ");
    mvwprintw(lab_map,3+1,1,"------|   .-.   |------");
    mvwprintw(lab_map,3+2,1,"______|  ( o )  |______");
    mvwprintw(lab_map,3+3,1,"      |___'-'___|      ");
    

    mvwprintw(lab_map,3,24,  "       _________    ");
    mvwprintw(lab_map,3+1,24,"------|   .-.   |---");
    mvwprintw(lab_map,3+2,24,"______|  ( o )  |___");
    mvwprintw(lab_map,3+3,24,"      |___'-'___|   ");

    mvwprintw(lab_map,3,44,  "       _________       ");
    mvwprintw(lab_map,3+1,44,"------|   .-.   |------");
    mvwprintw(lab_map,3+2,44,"______|  ( o )  |______");
    mvwprintw(lab_map,3+3,44,"      |___'-'___|      ");

    mvwprintw(lab_map,1,67,  "     ______         ");
    mvwprintw(lab_map,1+1,67,"  ,-' |__| `-.      ");
    mvwprintw(lab_map,1+2,67," / __________ \\    ");
    mvwprintw(lab_map,1+3,67,"| |    ||    | |");
    mvwprintw(lab_map,1+4,67,") |   =||=   | (");
    mvwprintw(lab_map,1+5,67,"| | =  ||  = | |");
    mvwprintw(lab_map,1+6,67,"| | =  ||  = | |");
    mvwprintw(lab_map,1+7,67,"| |   =||=   | |");
    mvwprintw(lab_map,1+8,67,") |    ||    | (");
    mvwprintw(lab_map,1+9,67,"|_|_;-------;|_|");
  

    mvwprintw(lab_map,3,83,  "       _________     ");
    mvwprintw(lab_map,3+1,83,"------|   .-.   |----");
    mvwprintw(lab_map,3+2,83,"______|  ( o )  |____");
    mvwprintw(lab_map,3+3,83,"      |___'-'___|    ");

    mvwprintw(lab_map,3,104,  "       _________       ");
    mvwprintw(lab_map,3+1,104,"------|   .-.   |------");
    mvwprintw(lab_map,3+2,104,"______|  ( o )  |______");
    mvwprintw(lab_map,3+3,104,"      |___'-'___|      ");

    mvwprintw(lab_map,3,127,  "       _________     ");
    mvwprintw(lab_map,3+1,127,"------|   .-.   |-----");
    mvwprintw(lab_map,3+2,127,"______|  ( o )  |_____");
    mvwprintw(lab_map,3+3,127,"      |___'-'___|     ");

    //

    mvwprintw(lab_map,20,66,  "     .-'""'-.");
    mvwprintw(lab_map,20+1,66,"  .'        '.");
    mvwprintw(lab_map,20+2,66," /    .--.    \\");
    mvwprintw(lab_map,20+3,66,";____/    \\____;");
    mvwprintw(lab_map,20+4,66,";----\\    /----;");
    mvwprintw(lab_map,20+5,66," \\    '--'    /");
    mvwprintw(lab_map,20+6,66,"  '.        .'");
    mvwprintw(lab_map,20+7,66,"    '-....-'");
   
    mvwprintw(lab_map,23,50,  "________________;");
    mvwprintw(lab_map,24,50,  "----------------;");
    mvwprintw(lab_map,23,81,  ";________________");
    mvwprintw(lab_map,24,81,  ";----------------");

    mvwprintw(lab_map,11,22,  " __________ ");
    mvwprintw(lab_map,11+1,22,"|__________|");
    mvwprintw(lab_map,11+2,22,"  ||||||||  ");
    mvwprintw(lab_map,11+3,22,"  ||||||||  ");
    mvwprintw(lab_map,11+4,22,"  ||||||||  ");
    mvwprintw(lab_map,11+5,22,"  ||||||||  ");
    mvwprintw(lab_map,11+6,22," -||||||||-  ");
    mvwprintw(lab_map,11+7,22,"|__________|");  

    mvwprintw(lab_map,23,50,    "________________;");
    mvwprintw(lab_map,23+1,50,  "----------------;");
    mvwprintw(lab_map,23,50,    "________________;");
    mvwprintw(lab_map,23+1,50,  "----------------;");
    mvwprintw(lab_map,23,50,    "________________;");
    mvwprintw(lab_map,23+1,50,  "----------------;");

    mvwprintw(lab_map,28,22,  " __________ ");
    mvwprintw(lab_map,28+1,22,"|__________|");
    mvwprintw(lab_map,28+2,22,"  ||||||||  ");
    mvwprintw(lab_map,28+3,22,"  ||||||||  ");
    mvwprintw(lab_map,28+4,22,"  ||||||||  ");
    mvwprintw(lab_map,28+5,22,"  ||||||||  ");
    mvwprintw(lab_map,28+6,22," -||||||||-  ");
    mvwprintw(lab_map,28+7,22,"|__________|");

    mvwprintw(lab_map,20,22,"     )    ");
    mvwprintw(lab_map,20+1,22,"    ) \\  ");
    mvwprintw(lab_map,20+2,22,"   / ) (  ");
    mvwprintw(lab_map,20+3,22," --\\(_)/--");
    mvwprintw(lab_map,20+4,22,"|_________|");

    mvwprintw(lab_map,11,110,  " __________ ");
    mvwprintw(lab_map,11+1,110,"|__________|");
    mvwprintw(lab_map,11+2,110,"  ||||||||  ");
    mvwprintw(lab_map,11+3,110,"  ||||||||  ");
    mvwprintw(lab_map,11+4,110,"  ||||||||  ");
    mvwprintw(lab_map,11+5,110,"  ||||||||  ");
    mvwprintw(lab_map,11+6,110," -||||||||-  ");
    mvwprintw(lab_map,11+7,110,"|__________|");  

    mvwprintw(lab_map,20,110,"     )    ");
    mvwprintw(lab_map,20+1,110,"    ) \\  ");
    mvwprintw(lab_map,20+2,110,"   / ) (  ");
    mvwprintw(lab_map,20+3,110," --\\(_)/--");
    mvwprintw(lab_map,20+4,110,"|_________|");

    mvwprintw(lab_map,28,110,  " __________ ");
    mvwprintw(lab_map,28+1,110,"|__________|");
    mvwprintw(lab_map,28+2,110,"  ||||||||  ");
    mvwprintw(lab_map,28+3,110,"  ||||||||  ");
    mvwprintw(lab_map,28+4,110,"  ||||||||  ");
    mvwprintw(lab_map,28+5,110,"  ||||||||  ");
    mvwprintw(lab_map,28+6,110," -||||||||-  ");
    mvwprintw(lab_map,28+7,110,"|__________|");

    wrefresh(lab_map);
    getch();
    delwin(lab_map);
    endwin();

    return 0;
}



