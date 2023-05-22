#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

void unbox(WINDOW* win){
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
}
void cadremap(WINDOW* map){
  WINDOW* cadre = subwin(map,100-(LINES-2),400 -(COLS-2),(LINES-2)/2,(COLS-2)/2); // (F, lignes de F -(x(@) dans fa)*2, colonnes de F -(y(@) dans fa)*2, x(@) dans fa, y(@) dans fa)
  box(cadre,0,0);
  delwin(cadre);
}
void reset(){
    WINDOW* ecrannoir=newwin(LINES,COLS,0,0);
    wrefresh(ecrannoir);
    delwin(ecrannoir);
}
void sac(WINDOW* cam_state){
  int ch=ERR; int x=5;
    struct timespec trm, trq = { 0,10000000 };
    while(ch!='q'){
      ch=getch();
      WINDOW* sac=newwin(16,23,(LINES/8)+13,(COLS/8)-11);
      box(sac,0,0);
      switch (ch)
      {
      case KEY_UP:
      case 'z':
        if(x!=5){
            x-=3;
        }
        break;
      case KEY_DOWN:
      case 's':
        if(x!=14){
            x+=3;
        }
        break;
      case KEY_ENTER:
      case 'e':
      case '\r':
      case '\n':
        switch (x)
        {
        case 14:
          ch='q';
          break;
        default:
          break;
        }
        break;
      default:
        break;
      }
      mvwprintw(sac,1,10,"sac");
      mvwprintw(sac,5,1,"Pokeballs");
      mvwprintw(sac,8,1,"Potions");
      mvwprintw(sac,11,1,"CT");
      mvwprintw(sac,14,1,"Fermer le sac");
      mvwprintw(sac,x,17,"<-");
      wrefresh(sac);
      delwin(sac);
      nanosleep(&trq,&trm);
    }
    reset();
    wrefresh(cam_state);
}
void menu(int* pquit,WINDOW* cam_state){
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
        switch (x)
        {
        case 5:
          sac(cam_state);
          break;
        case 7:
          ch='m';
          break;
        case 8:
          *pquit=1;
         break;
        default:
          break;
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