#include <curses.h>
#include<unistd.h>

int main() {
  initscr();
  int l=5;int ch=ERR;
  WINDOW* fenetre = newwin(35, 40, 0, 0);
  nodelay(stdscr,TRUE);
  noecho();
  box(fenetre,0,0);
  for(int i=1;i<34;i++){
    mvwprintw(fenetre,i,1,"ligne %d",i);
  }
  box(fenetre,0,0);
  while(ch!='k'){  
                ch=getch();
                switch (ch)
                {
                case 'z':
                 l--;
                    break;
                case 's':
                l++;
                    break;
                default:
                    break;
                }
  WINDOW* fenetre_affichage=subwin(fenetre,10,20,l,1);
  mvwin(fenetre_affichage,LINES/2,COLS/2);
  wrefresh(fenetre_affichage);
  usleep(80000);
  delwin(fenetre_affichage);
  }
  wrefresh(fenetre);
  sleep(5);
  delwin(fenetre);
  endwin();
  return 0;
}
