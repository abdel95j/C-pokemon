#include <curses.h>
#include<unistd.h>

int main() {
<<<<<<< HEAD
    initscr();
    int l=5;int c=1;int ch=ERR;
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
        case 'd':
        c++;
            break;
        case 'q':
        c--;
            break;
        default:
            break;
        }
        WINDOW* fenetre_affichage=subwin(fenetre,10,20,l,c);
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
=======
  initscr();
  int l=1;int c=1;int ch=ERR;
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
                 if(l!=1)
                 {l--;}
                    break;
                case 's':
                if(l!=24){
                l++;}
                    break;
                case 'd':
                if(c!=19){
                  c++;}
                    break;
                case 'q':
                if(c!=1){
                  c--;}
                    break;
                default:
                    break;
                }
  WINDOW* fenetre_affichage=subwin(fenetre,10,20,l,c);
  WINDOW* cadre= newwin(12,22,LINES/2,COLS/2);
  box(cadre,0,0);
  mvwin(cadre,LINES/2-1,COLS/2-1);
  mvwin(fenetre_affichage,LINES/2,COLS/2);
  wrefresh(cadre);
  wrefresh(fenetre_affichage);
  usleep(80000);
  delwin(cadre);
  delwin(fenetre_affichage);
  }
  wrefresh(fenetre);
  sleep(5);
  delwin(fenetre);
  endwin();
  return 0;
>>>>>>> 831b9ca6d9af9db005b936f0bb9aeb51011024c2
}
