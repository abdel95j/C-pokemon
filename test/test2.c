#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

int main() {
  initscr();
  int l=1;int c=1;int ch=ERR;int i;int j;int quit=0;int ind_cadre=0;
  struct timespec trm, trq = { 0,10000000 };
  WINDOW* fenetre = newwin(100, 400, 0, 0);
  WINDOW* fenetre_backup= newwin(100, 400, 0, 0);
  nodelay(stdscr,TRUE);
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);
  box(fenetre,0,0);
  box(fenetre_backup,0,0); 
  mvwprintw(fenetre,1,1,"*");          /*reperage des coins par des étoiles*/
  mvwprintw(fenetre,1,398,"*");
  mvwprintw(fenetre,98,1,"*");
  mvwprintw(fenetre,98,398,"*");                                             /*abscisse=ligne, ordonnée=colonne*/
  for(i=((LINES-2)/2)+1;i<99-((LINES-2)/2);i++){ /*i=abscisse de @ dans fenetre d'affichage +1; i< nombre lignes fenetre - abscisse de @ dans fenêtre d'affichage -1*/
    mvwprintw(fenetre,i,1,"                                                                      ligne a  ");/*"ordonnée de @ dans fenetre d'affichage" d'espaces*/
    for(j=80;j<399-((COLS-2)/2);j++){/*j= ordonnée qui suit;j< nombre colonnes fenêtre - ordonnée de @ dans fenêtre d'affichage -1 */
      mvwprintw(fenetre,i,j,"a");
    }
  }
  fenetre_backup=dupwin(fenetre);
  while(quit==0){
     WINDOW* fenetre_affichage=subwin(fenetre,LINES-1,COLS-1,l,c); //21,81
     mvwin(fenetre_affichage,0,0); //LINES/4,COLS/4
     mvwprintw(fenetre_affichage,(LINES-2)/2,(COLS-2)/2,"@"); //10,40
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
                if(l!=62){  /*l!= nombre lignes de fenêtre -1 - nombre lignes de fenetre affcihage*/
                l++;}
                    break;
                case KEY_RIGHT:
                case 'd':
                if(c!=258){ /*c!= nombre colonnes de fenêtre -1 - nombre colonnes de fenetre affcihage*/
                  c++;}
                    break;
                case KEY_LEFT:
                case 'q':
                if(c!=1){
                  c--;}
                    break;
                case 'm':
                menu(&quit,fenetre_affichage);
                cadre_cam();
                default:
                    break;
                }
   if(ind_cadre==0){cadre_cam();
                  ind_cadre++;}      /*pour cadrer la camera la première fois sans cadrer à chaque fois dans la boucle*/
  wrefresh(fenetre_affichage);       //affichage camera
  fenetre=dupwin(fenetre_backup); // remise à neuf de la fenêtre avec la fenêtre backup
  nanosleep(&trq,&trm);
  delwin(fenetre_affichage);
  }
  delwin(fenetre);
  delwin(fenetre_backup);
  endwin();
  return 0;
}
