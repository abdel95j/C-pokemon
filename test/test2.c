#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

int main() {
  initscr();
  int l=1;int c=1;int ch=ERR;int i;int j;int quit=0;
  struct timespec trm, trq = { 0,10000000 };
  WINDOW* fenetre = newwin(60, 200, 0, 0);
  WINDOW* fenetre_backup= newwin(60, 200, 0, 0);
  nodelay(stdscr,TRUE);
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  box(fenetre,0,0);
  box(fenetre_backup,0,0);                /*abscisse=ligne, ordonnée=colonne*/
  for(i=11;i<49;i++){ /*i=abscisse de @ dans fenetre d'affichage +1; i< nombre lignes fenetre - abscisse de @ dans fenêtre d'affichage -1*/
    mvwprintw(fenetre,i,1,"                                        ligne a  ");/*"ordonnée de @ dans fenetre d'affichage" d'espaces*/
    for(j=50;j<159;j++){/*j= ordonnée qui suit;j< nombre colonnes fenêtre - ordonnée de @ dans fenêtre d'affichage -1 */
      mvwprintw(fenetre,i,j,"a");
    }
  }
  copywin(fenetre,fenetre_backup,0,0,0,0,59,199,FALSE);
  while(quit==0){  
                ch=getch();
                switch (ch)
                {
                case KEY_UP:
                case 'z':
                 if(l!=1)
                 {l--;}
                    break;
                case KEY_DOWN:
                case 's':
                if(l!=38){  /*l!= nombre lignes de fenêtre -1 - nombre lignes de fenetre affcihage*/
                l++;}
                    break;
                case KEY_RIGHT:
                case 'd':
                if(c!=118){ /*c!= nombre colonnes de fenêtre -1 - nombre colonnes de fenetre affcihage*/
                  c++;}
                    break;
                case KEY_LEFT:
                case 'q':
                if(c!=1){
                  c--;}
                    break;
                case 'm':
                menu(&quit);
                default:
                    break;
                }
  WINDOW* fenetre_affichage=subwin(fenetre,21,81,l,c);
  mvwin(fenetre_affichage,LINES/4,COLS/4);
  mvwprintw(fenetre_affichage,10,40,"@");
  cadre();
  wrefresh(fenetre_affichage);
  copywin(fenetre_backup,fenetre,0,0,0,0,59,199,FALSE);
  nanosleep(&trq,&trm);
  delwin(fenetre_affichage);
  }
  delwin(fenetre);
  delwin(fenetre_backup);
  endwin();
  return 0;
}
