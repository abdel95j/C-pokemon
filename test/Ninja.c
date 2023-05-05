#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>

int main()
{
    
    initscr();
    WINDOW *house = newwin(LINES, COLS, 0, 0);
    box(house, 0, 0);

    // Coordonnées et dimensions du mur
    int x_r = 1;
    int y_r = 1;
    int l_r = COLS - 2;
    int h_r = 10;

    
    mvwprintw(house, y_r, x_r, "+");    // Dessin des coins supérieurs mur
    mvwprintw(house, y_r, x_r+l_r, "+");
    

    for (int i = x_r + 1; i < x_r + l_r; i++) {   // Dessin des côtés horizontaux mur
        mvwprintw(house, y_r, i, "-");
        mvwprintw(house, y_r + h_r, i, "-");
    }

    for (int i = y_r + 1; i < y_r + h_r; i++) {    // Dessin des côtés verticaux mur
        mvwprintw(house, i, x_r, "|");
        mvwprintw(house, i, x_r + l_r, "|");
    }

    // TAPIS
    mvwprintw(house, LINES/2,     COLS/2 - 15, "+----------------------------------+");
    mvwprintw(house, LINES/2 + 1, COLS/2 - 15, "| *   *   *   *   *   *   *  *   * |");
    mvwprintw(house, LINES/2 + 2, COLS/2 - 15, "| *   _    _                     * |");
    mvwprintw(house, LINES/2 + 3, COLS/2 - 15, "| *  | |  | |                    * |");
    mvwprintw(house, LINES/2 + 4, COLS/2 - 15, "| *  | |__| | ___  _   _ ____    * |");
    mvwprintw(house, LINES/2 + 5, COLS/2 - 15, "| *  |  _ | |/ _ \\| |_| |  _ \\   * |");
    mvwprintw(house, LINES/2 + 6, COLS/2 - 15, "| *  | |  | | (_) | |-| |  __/   * |");
    mvwprintw(house, LINES/2 + 7, COLS/2 - 15, "| *  |_|  |_|\\___/|_| |_|\\___|   * |");
    mvwprintw(house, LINES/2 + 8, COLS/2 - 15, "| *                              * |");
    mvwprintw(house, LINES/2 + 9, COLS/2 - 15, "| *   *   *   *   *   *   *  *   * |");
    mvwprintw(house, LINES/2 + 10, COLS/2 - 15, "+----------------------------------+");


    // Dessin four
    int x_four = x_r + 5;
    int y_four = y_r + h_r - 7;
    mvwprintw(house, y_four, x_four,   "    ())");
    mvwprintw(house, y_four+1, x_four, "    (()");
    mvwprintw(house, y_four+2, x_four, "  \\__~__/");
    mvwprintw(house, y_four+3, x_four, " _(_)(_)_");
    mvwprintw(house, y_four+4, x_four, "|.------.|");
    mvwprintw(house, y_four+5, x_four, "||     o||");
    mvwprintw(house, y_four+6, x_four, "|`------'|");

      
    // Dessin freg
    int x_freg = x_r + 20;
    int y_freg = y_r + h_r - 7;
    mvwprintw(house, y_freg, x_freg,   " _______");
    mvwprintw(house, y_freg+1, x_freg, "|       |");
    mvwprintw(house, y_freg+2, x_freg, "|]      |");
    mvwprintw(house, y_freg+3, x_freg, "|_______|");
    mvwprintw(house, y_freg+4, x_freg, "|]      |");
    mvwprintw(house, y_freg+5, x_freg, "|       |");
    mvwprintw(house, y_freg+6, x_freg, "|_______|");


    // Stairs
    int x_pot_droit = x_r + l_r - 16;
    mvwprintw(house, y_four-2, x_pot_droit+14, "__");
    mvwprintw(house, y_four-1, x_pot_droit+11, "__|");
    mvwprintw(house, y_four,   x_pot_droit+8, "__|");
    mvwprintw(house, y_four+1, x_pot_droit+5, "__|");
    mvwprintw(house, y_four+2, x_pot_droit+2, "__|");
    mvwprintw(house, y_four+3, x_pot_droit-1, "__|");
    mvwprintw(house, y_four+4, x_pot_droit-4, "__|");
    mvwprintw(house, y_four+5, x_pot_droit-7, "__|");
    mvwprintw(house, y_four+6, x_pot_droit-10, "__|");
    mvwprintw(house, y_four+7, x_pot_droit-11, "'");


    // Dessin cab
    int x_cab = x_r + 155;
    int y_cab = y_r + h_r - 7;
    mvwprintw(house, y_cab, x_cab,   " _______");
    mvwprintw(house, y_cab+1, x_cab, "||__°__||");
    mvwprintw(house, y_cab+2, x_cab, "| _____ |");
    mvwprintw(house, y_cab+3, x_cab, "||__°__||");
    mvwprintw(house, y_cab+4, x_cab, "| _____ |");
    mvwprintw(house, y_cab+5, x_cab, "||__°__||");
    mvwprintw(house, y_cab+6, x_cab, "|_______|");


    // Dessin win1
    int x_win1 = x_r + 100;
    int y_win1 = y_r + h_r - 7;
    mvwprintw(house, y_win1, x_win1,   "+_______+");
    mvwprintw(house, y_win1+1, x_win1, "| ~ | ~ |");
    mvwprintw(house, y_win1+2, x_win1, "|___0___|");
    mvwprintw(house, y_win1+3, x_win1, "| ~ | ~ |");
    mvwprintw(house, y_win1+4, x_win1, "|___|___|");
    

    // Dessin win2
    int x_win2 = x_r + 90;
    int y_win2 = y_r + h_r - 7;
    mvwprintw(house, y_win2, x_win2,   "+_______+");
    mvwprintw(house, y_win2+1, x_win2, "| ~ | ~ |");
    mvwprintw(house, y_win2+2, x_win2, "|___0___|");
    mvwprintw(house, y_win2+3, x_win2, "| ~ | ~ |");
    mvwprintw(house, y_win2+4, x_win2, "|___|___|");


    // Dessin flower pot1
    int x_flo = x_r + 60;
    int y_flo = y_r + h_r - 7;

    mvwprintw(house, y_flo+2, x_flo, "  @ @ @ ");
    mvwprintw(house, y_flo+3, x_flo, "  _\\|/_");
    mvwprintw(house, y_flo+4, x_flo, " |_____|");
    mvwprintw(house, y_flo+5, x_flo, "  |   | ");
    mvwprintw(house, y_flo+6, x_flo, "  |___| ");


    // Dessin flower pot2
    int x_flo2 = x_r + 140;
    int y_flo2 = y_r + h_r - 7;

    mvwprintw(house, y_flo2+2, x_flo2, "  @ @ @ ");
    mvwprintw(house, y_flo2+3, x_flo2, "  _\\|/_");
    mvwprintw(house, y_flo2+4, x_flo2, " |_____|");
    mvwprintw(house, y_flo2+5, x_flo2, "  |   | ");
    mvwprintw(house, y_flo2+6, x_flo2, "  |___| ");


    // Dessin cab2
    int x_cab2 = x_r + 40;
    int y_cab2 = y_r + h_r - 7;
    mvwprintw(house, y_cab2+2, x_cab2, " _______ ");
    mvwprintw(house, y_cab2+3, x_cab2, "|_o_|_o_|");
    mvwprintw(house, y_cab2+4, x_cab2, "|___o___|");
    mvwprintw(house, y_cab2+5, x_cab2, "|___o___|");
    mvwprintw(house, y_cab2+6, x_cab2, " ||   || ");


    // Sofa
    mvwprintw(house, LINES/2 - 7,     COLS/2 - 7, ".-=-------------=-.");
    mvwprintw(house, LINES/2 - 6,     COLS/2 - 7, "| . . . . . . .'. |");
    mvwprintw(house, LINES/2 - 5,     COLS/2 - 7, "| .'.'.'.'.'.'.'. |");
    mvwprintw(house, LINES/2 - 4,     COLS/2 - 7, "()_______________()");
    mvwprintw(house, LINES/2 - 3,     COLS/2 - 7, "||_______________||");
    mvwprintw(house, LINES/2 - 2,     COLS/2 - 7, " W               W");


    // Chair1
    mvwprintw(house, LINES/2 + 2, COLS/2 - 30, ".____.");
    mvwprintw(house, LINES/2 + 3, COLS/2 - 30, "||o o|");
    mvwprintw(house, LINES/2 + 4, COLS/2 - 30, "||o o|");
    mvwprintw(house, LINES/2 + 5, COLS/2 - 30, "()___|_()");
    mvwprintw(house, LINES/2 + 6, COLS/2 - 30, "||     ||");
    mvwprintw(house, LINES/2 + 7, COLS/2 - 30, "||_____||");
    mvwprintw(house, LINES/2 + 8, COLS/2 - 30, " W     W");


    // Chair2
    mvwprintw(house, LINES/2 + 2, COLS/2 + 27, "   .____.");
    mvwprintw(house, LINES/2 + 3, COLS/2 + 27, "   |o o||");
    mvwprintw(house, LINES/2 + 4, COLS/2 + 27, "   |o o||");
    mvwprintw(house, LINES/2 + 5, COLS/2 + 27, "()_|___()");
    mvwprintw(house, LINES/2 + 6, COLS/2 + 27, "||     ||");
    mvwprintw(house, LINES/2 + 7, COLS/2 + 27, "||_____||");
    mvwprintw(house, LINES/2 + 8, COLS/2 + 27, " W     W");



    // Porte de sortie
    int x_d = COLS - 10;
    int y_d = LINES - 10;

    mvwprintw(house, y_d, x_d,   "       /|");
    mvwprintw(house, y_d+1, x_d, "      / |");
    mvwprintw(house, y_d+2, x_d, " ____/__|");
    mvwprintw(house, y_d+3, x_d, "|       |");
    mvwprintw(house, y_d+4, x_d, "|       |");
    mvwprintw(house, y_d+5, x_d, "|       |");
    mvwprintw(house, y_d+6, x_d, "+       |");
    mvwprintw(house, y_d+7, x_d, "|       |");
    mvwprintw(house, y_d+8, x_d, "|_______|"); 
    


    // TABLE 
    mvwprintw(house, LINES/2 + 2, COLS/2 - 70, "  .___________. ");
    mvwprintw(house, LINES/2 + 3, COLS/2 - 70, " /             \\");
    mvwprintw(house, LINES/2 + 4, COLS/2 - 70, "|              |");
    mvwprintw(house, LINES/2 + 5, COLS/2 - 70, "\\.___________./");
    mvwprintw(house, LINES/2 + 6, COLS/2 - 70, "  || ||  || ||  ");


    

    wrefresh(house);
    getch();
    delwin(house);
    endwin();

    return 0;
}