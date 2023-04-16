#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

void unbox(WINDOW* win){
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
}
void reset(){
    WINDOW* ecrannoir=newwin(LINES,COLS,0,0);
    wrefresh(ecrannoir);
    delwin(ecrannoir);
}
void menu(int* pquit){
    int ch=ERR; int x=4;
    struct timespec trm, trq = { 0,10000000 };
    while(ch!='m' && *pquit==0){
      ch=getch();
      WINDOW* menu=newwin(11,21,LINES/8,COLS/8-10);
      box(menu,0,0);
      switch (ch)
      {
      case KEY_UP:
      case 'z':
        if(x!=4){
            x--;
        }
        break;
      case KEY_DOWN:
      case 's':
        if(x!=8){
            x++;
        }
        break;
      case KEY_ENTER:
      case 'e':
      case '\r':
      case '\n':
        if(x==7){
            ch='m';
        }
        if(x==8){
            *pquit=1;
        }
        break;
      default:
        break;
      }
      mvwprintw(menu,1,4,"menu");
      mvwprintw(menu,4,1,"Equipe");
      mvwprintw(menu,5,1,"Sac");
      mvwprintw(menu,6,1,"Sauvegarder");
      mvwprintw(menu,7,1,"Quitter le menu");
      mvwprintw(menu,8,1,"Quitter le jeu");
      mvwprintw(menu,x,17,"<-");
      wrefresh(menu);
      delwin(menu);
      nanosleep(&trq,&trm);
    }
    reset();
}
void cadre(){
    WINDOW* cadre= newwin(23,83,LINES/4-1,COLS/4-1);
    box(cadre,0,0);
    wrefresh(cadre);
    delwin(cadre);
}
