#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<curses.h>
void frame(FILE* f,int frame_number){
    WINDOW* pikachu_screen=newwin(LINES-1,COLS-1,0,0);
    char ligne[101];int ligne_limite;
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
    delwin(pikachu_screen);
}
int main(){
    initscr();
    FILE* f= NULL;
    int frame_number; int ch=ERR;
    noecho();
    nodelay(stdscr,TRUE);
    curs_set(0);
    f=fopen("pikachus.txt","r");
    if(f==NULL){
        printw("ouverture du fichier ratée");
        exit(1);
    }
    while(ch!='q'){
        ch=getch();
        if(ch=='q'){break;}
    for(frame_number=1;frame_number<=4;frame_number++)
    {
        frame(f,frame_number);
        usleep(60000);
    }
        rewind(f);
        }
    fclose(f);
    endwin();
    return 0;
}