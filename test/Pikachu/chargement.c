#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<curses.h>

void chargement(){
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr,TRUE);

    WINDOW* pikachu_screen=newwin(LINES-1,COLS-1,0,0);
    FILE* f = NULL;
    int frame_number, ch=ERR;

    f=fopen("pikachus.txt","r");
    if(f==NULL){
        printw("ouverture du fichier ratée");
        exit(1);
    }
    while(ch!='q'){
        ch=getch();
        if(ch=='q'){break;}
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
            for(int i=0;i<ligne_limite;i++){
                fgets(ligne,100,f);
                mvwprintw(pikachu_screen,i+2,15,"%s",ligne);
                mvwprintw(pikachu_screen,5,120,"CHARGEMENT .....");
            }
            wrefresh(pikachu_screen);
            wclear(pikachu_screen);
            usleep(60000);
        }
        rewind(f);
    }
    fclose(f);
    delwin(pikachu_screen);
    endwin();
}

int main(){

    chargement();

    return 0;
}