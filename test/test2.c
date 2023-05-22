#include <curses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

int main() {                   // fa= fenetre affichage, F= fenetre , x= abscisse, y= ordonnée ,abscisse=ligne, ordonnée=colonne
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
  mvwprintw(fenetre,1,1,"*");          //reperage des coins par des étoiles
  mvwprintw(fenetre,1,398,"*");
  mvwprintw(fenetre,98,1,"*");
  mvwprintw(fenetre,98,398,"*");                                             
  /*for(i=((LINES-2)/2)+1;i<99-((LINES-2)/2);i++){ //i= x(@) dans fa +1; i< lignes de F - x(@) dans fa -1
    mvwprintw(fenetre,i,1,"                                                                      ligne a  ");//" y(@) dans fa " d'espaces
    for(j=80;j<399-((COLS-2)/2);j++){ // j= ordonnée qui suit;j< colonnes de F - y(@) dans fa -1 
      mvwprintw(fenetre,i,j,"a");
    }
  }*/
  cadremap(fenetre);
  fenetre_backup=dupwin(fenetre);
  while(quit==0){
     WINDOW* fenetre_affichage=subwin(fenetre,LINES-1,COLS-1,l,c); 
     mvwin(fenetre_affichage,0,0); 
     mvwprintw(fenetre_affichage,(LINES-2)/2,(COLS-2)/2,"@");
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
                if(l!=62){  // l!= lignes de F -1 - lignes de fa 
                l++;}
                    break;
                case KEY_RIGHT:
                case 'd':
                if(c < 258){ // c < colonnes de F -1 - colonnes de fa
                  c=c+2;}
                    break;
                case KEY_LEFT:
                case 'q':
                if(c < 1){
                  c=c-2;}
                    break;
                case 'm':
                menu(&quit,fenetre_affichage);
                default:
                    break;
                }
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
