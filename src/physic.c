#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/talk.h"
#include "../headers/talkbis.h"

void physic_get_firstpoke(int ch, int* y){
    switch (ch)
        {
            
        case 'd':
        case KEY_RIGHT:
            if (*y==50)
            {
                *y=115;
            }

            else if (*y==115)
            {
                *y=183;
            }
            break;

        case 'q':
        case KEY_LEFT :
            if (*y==115)
            {
                *y=50;
            }

            else if (*y==183)
            {
                *y=115;
            }
            break;
        }
}

void physic_menu(int chmenu, int* x){
    switch (chmenu)
    {
        case KEY_UP:
        case 'z':
            if (*x==13)
            {
                //nothing happens
            }
            else if (*x==22)
            {
                *x=13;
            }
            else if (*x==31)
            {
                *x=22;
            }
            break;

        case KEY_DOWN:
        case 's':
            if (*x==31)
            {
                //nothing happens
            }
            else if (*x==22)
            {
                *x=31;
            }
            else if (*x==13)
            {
                *x=22;
            }
            break;
    }
}

void physic_house(int ch, int* x, int* y){
    switch (ch)
    {
        case 'z':
        case KEY_UP:
            if (*x!=6)
            {
                *x-=1;
            }

            if (*x==6 && *y<=31)  // lavabo + frigo + poubelle
            {
                *x+=1;
            }

            if (*x==6 && *y>=41 && *y<=53)  // four
            {
                *x+=1;
            }

            if (*x==9 && *y>=67 && *y<=93)  // télé
            {
                *x+=1;
            }

            if (*x==18 && *y>=67 && *y<=93)  // sofa
            {
                *x+=1;
            }

            if (*x==9 && *y>=125)  // stairs
            {
                *x+=1;
            }

            if (*x==31 && *y>=7 && *y<=27)
            {
                *x+=1;
            }
            
            if (*y<=7 && *x==18) // mom
            {
                *x+=1;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (*x!=34)
            {
                *x+=1;
            }

            if (*x==13 && *y>=67 && *y<=93)  // sofa
            {
                *x-=1;
            }

            if (*x==23 && *y>=7 && *y<=27) // table
            {
                *x-=1;
            }

            if (*y<=7 && *x==14) // mom
            {
                *x-=1;
            }
            break;

        case 'q':
        case KEY_LEFT:
            if (*y!=1)
            {
                *y-=2;
            }

            if (*x==6 && *y==31)  // lavabo + frigo + poubelle
            {
                *y+=2;
            }

            if (*x==6 && *y==53)  // four
            {
                *y+=2;
            }

            if (*x>=6 && *x<=9 && *y==93)  // télé
            {
                *y+=2;
            }

            if (*x>=13 && *x<=18 && *y==93)  // sofa
            {
                *y+=2;
            }

            if (*y==27 && *x>=23 && *x<=31) // table
            {
                *y+=2;
            }

            if (*y==7 && *x<=18 && *x>=14) // mom
            {
                *y+=2;
            }    
            break;
        
        case 'd':
        case KEY_RIGHT:
            if (*y!=143)
            {
                *y+=2;
            }

            if (*x==6 && *y==41)  // four
            {
                *y-=2;
            }

            if (*x>=6 && *x<=9 && *y==67)  // télé
            {
                *y-=2;
            }

            if (*x>=13 && *x<=18 && *y==67)  // télé
            {
                *y-=2;
            }

            if (*x>=6 && *x<=9 && *y==125)  // stairs
            {
                *y-=2; 
            }

            if (*y==7 && *x<=31 && *x>=23) // table
            {
                *y-=2;
            }
            break;

        default:
            break;
    }
}

void physic_league(int ch, int* x, int* y){
    switch (ch)
    {
        case 'z':
        case KEY_UP:
            if (*x!=6)
            {
                *x-=1;
            }

            if (*x==6 && *y>=63 && *y<=81) // door
            {
                *x+=1;
            }

            if (*x==13 && *y>=61 && *y<=69) // Champion of the league
            {
                *x+=1;
            }

            //droite

            if (*x==14 && *y>=107 && *y<=121) // poteau haut droite
            {
                *x+=1;
            }

            if (*x==31 && *y>=107 && *y<=121) // poteau bas droite
            {
                *x+=1;
            }

            if (*x==20 && *y>=107 && *y<=119) // flamme droite
            {
                *x+=1;
            }

            //gauche

            if (*x==14 && *y>=19 && *y<=33) // poteau haut gauche
            {
                *x+=1;
            }

            if (*x==31 && *y>=19 && *y<=33) // poteau bas gauche
            {
                *x+=1;
            }

            if (*x==20 && *y>=19 && *y<=31) // flamme gauche
            {
                *x+=1;
            }        
            break;

        case 's':
        case KEY_DOWN:
            if (*x!=34)
            {
                *x+=1;
            }

            if (*x==9 && *y>=61 && *y<=69) // Champion of the league
            {
                *x-=1;
            }

            //droite

            if (*x==7 && *y>=107 && *y<=121) // poteau haut droite
            {
                *x-=1;
            }

            if (*x==24 && *y>=107 && *y<=121) // poteau bas droite
            {
                *x-=1;
            }

            if (*x==16 && *y>=107 && *y<=119) // flamme droite
            {
                *x-=1;
            }

            //gauche

            if (*x==7 && *y>=19 && *y<=33) // poteau haut gauche
            {
                *x-=1;
            }

            if (*x==24 && *y>=19 && *y<=33) // poteau bas gauche
            {
                *x-=1;
            }

            if (*x==16 && *y>=19 && *y<=31) // flamme gauche
            {
                *x-=1;
            }

            break;

        case 'q':
        case KEY_LEFT:
            if (*y!=1)
            {
                *y-=2;
            }

            if (*x==6 && *y==81) // door
            {
                *y+=2;
            }

            if (*y==69 && *x>=9 && *x<=13) // Champion of the league
            {
                *y+=2;
            }
            
            //droite

            if (*y==121 && *x>=7 && *x<=14) // poteau haut droite
            {
                *y+=2;
            }

            if (*y==121 && *x>=24 && *x<=31) // poteau bas droite
            {
                *y+=2;
            }

            if (*y==119 && *x>=16 && *x<=20) // flamme droite
            {
                *y+=2;
            }

            //gauche

            if (*y==33 && *x>=7 && *x<=14) // poteau haut gauche
            {
                *y+=2;
            }

            if (*y==33 && *x>=24 && *x<=31) // poteau bas gauche
            {
                *y+=2;
            }

            if (*y==31 && *x>=16 && *x<=20) // flamme gauche
            {
                *y+=2;
            }

            break;
        
        case 'd':
        case KEY_RIGHT:
            if (*y!=143)
            {
                *y+=2;
            }

            if (*x==6 && *y==63) // door
            {
                *y-=2;
            }

            if (*y==61 && *x>=9 && *x<=13) // Champion of the league
            {
                *y-=2;
            }

            //droite

            if (*y==107 && *x>=7 && *x<=14) // poteau haut droite
            {
                *y-=2;
            }

            if (*y==107 && *x>=24 && *x<=31) // poteau bas droite
            {
                *y-=2;
            }

            if (*y==107 && *x>=16 && *x<=20) // flamme droite
            {
                *y-=2;
            }

            //gauche

            if (*y==19 && *x>=7 && *x<=14) // poteau haut gauche
            {
                *y-=2;
            }

            if (*y==19 && *x>=24 && *x<=31) // poteau bas gauche
            {
                *y-=2;
            }

            if (*y==19 && *x>=16 && *x<=20) // flamme gauche
            {
                *y-=2;
            }
            break;

        default:
            break;
    }

}

void physic_lab(int ch, int* x, int* y){
    switch (ch)
    {
        case 'z':
        case KEY_UP:
            if (*x!=6)
            {
                *x-=1;
            }

            if (*x==20 && *y>=103 && *y<=127) // table
            {
                *x+=1;
            }

            if (*y>=116 && *x==6) // grande armoire en haut à droite 
            {
                *x+=1;
            }   

            if (*x==6 && *y<=51 && *y>=33) // pc
            {
                *x+=1;
            }

            if (*y<=25 && *x==6) // tiroirs en haut a gauche 
            {
                *x+=1;
            }

            if (*x==18 && *y<=23 && *y>=9) // truc à gauche
            {
                *x+=1;
            }

            if (*x==6 && *y>=97 && *y<=103) // prof
            {
                *x+=1;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (*x!=34)
            {
                *x+=1;
            }

            if (*x==28 && *y>=91 && *y<=113) // petite armoire en bas à droite
            {
                *x-=1;
            }

            if (*x==28 && *y>=117) // grande armoire en bas à droite
            {
                *x-=1;
            }

            if (*x==28 && *y>=31 && *y<=53) // petite armoire en bas à gauche
            {
                *x-=1;
            }
            
            if (*x==28 && *y<=28) // grande armoire en bas à gauche
            {
                *x-=1;
            }

            if (*x==15 && *y>=103 && *y<=127) // table
            {
                *x-=1;
            }

            if (*x==13 && *y<=23 && *y>=9) // truc a gauche 
            {
                *x-=1;
            }
            break;

        case 'q':
        case KEY_LEFT:
            if (*y!=1)
            {
                *y-=2;
            }   

            if (*x>=28 && *y==113) // petite armoire en bas à droite
            {
                *y+=2;
            }

            if (*x>=28 && *y==53) // petite armoire en bas à gauche
            {
                *y+=2;
            }

            if (*x>=28 && *y==27) // grande armoire en bas à gauche
            {
                *y+=2;
            }

            if (*y==127 && *x>=15 && *x<=20) // table
            {
                *y+=2;
            }
            
            if (*x==6 && *y==51) // pc
            {
                *y+=2;
            }

            if (*x==6 && *y==25) // tiroirs en haut a gauche
            {
                *y+=2;
            }

            if (*y==23 && *x>=13 && *x<=18) // truc a gauche 
            {
                *y+=2;
            }

            if (*x==6 && *y==103) // prof
            {
                *y+=2;
            } 
            break;
        
        case 'd':
        case KEY_RIGHT:
            if (*y!=143)
            {
                *y+=2;
            }

            if (*x>=28 && *y==91) // petite armoire en bas à droite
            {
                *y-=2;
            }
            
            if (*x>=28 && *y==117) // grande armoire en bas à droite
            {
                *y-=2;
            }

            if (*x>=28 && *y==31) // petite armoire en bas a gauche
            {
                *y-=2;
            }

            if (*y==103 && *x>=15 && *x<=20) // table
            {
                *y-=2;
            }

            if (*x==6 && *y>=116) // armoire haut à droite
            {
                *y-=2;
            }

            if (*x==6 && *y==33) // pc
            {
                *y-=2;
            }
            
            if (*y==9 && *x>=13 && *x<=18) // truc a gauche 
            {
                *y-=2;
            }
            
            if (*x==6 && *y==97) // prof
            {
                *y-=2;
            } 
            break;

        default:
            break;
    }
}


void physic_shop(int ch, int* x, int* y){
    switch (ch)
    {
        case 'z':
        case KEY_UP:
            if (*x!=6)
            {
                *x-=1;
            }

            if (*x==26 && *y<=115 && *y>=107) // rayon millieu bas
            {
                *x+=1;
            }

            if (*x==26 && *y<=95 && *y>=87) // rayon gauche bas
            {
                *x+=1;
            }

            if (*x==26 && *y>=140) // rayon droite bas
            {
                *x+=1;
            }

            if (*x==15 && *y<=115 && *y>=107) // rayon millieu haut
            {
                *x+=1;
            }

            if (*x==15 && *y<=95 && *y>=87) // rayon gauche haut
            {
                *x+=1;
            }

            if (*x==15 && *y>=140) // rayon droite bas
            {
                *x+=1;
            }

            if (*x==17 && *y<=65) // comptoir
            {
                *x+=1;
            }
            
            break;

        case 's':
        case KEY_DOWN:
            if (*x!=34)
            {
                *x+=1;
            }

            if (*x==19 && *y<=115 && *y>=107) // rayon millieu bas
            {
                *x-=1;
            }

            if (*x==8 && *y<=95 && *y>=87) // rayon gauche bas
            {
                *x-=1;
            }

            if (*x==8 && *y>=140) // rayon droite bas
            {
                *x-=1;
            }

            if (*x==8 && *y<=115 && *y>=107) // rayon millieu haut
            {
                *x-=1;
            }

            if (*x==19 && *y<=95 && *y>=87) // rayon gauche haut
            {
                *x-=1;
            }

            if (*x==19 && *y>=140) // rayon droite bas
            {
                *x-=1;
            }
            
            break;

        case 'q':
        case KEY_LEFT:
            if (*y!=1)
            {
                *y-=2;
            }  

            if (*y==115 && *x<=26 && *x>=19) // rayon millieu bas
            {
                *y+=2;
            }

            if (*y==95 && *x<=26 && *x>=19) // rayon gauche bas
            {
                *y+=2;
            }

            if (*y==115 && *x<=15 && *x>=8) // rayon millieu haut
            {
                *y+=2;
            }

            if (*y==95 && *x<=15 && *x>=8) // rayon gauche haut
            {
                *y+=2;
            }

            if (*x<=17 && *x>=1  && *y==65) // comptoir
            {
                *y+=2;
            }

            break;
        
        case 'd':
        case KEY_RIGHT:
            if (*y!=143)
            {
                *y+=2;
            }

            if (*y==107 && *x<=26 && *x>=19) // rayon millieu bas
            {
                *y-=2;
            }

            if (*y==87 && *x<=26 && *x>=19) // rayon gauche bas
            {
                *y-=2;
            }

            if (*y==141 && *x<=26 && *x>=19) // rayon droite bas
            {
                *y-=2;
            }

            if (*y==107 && *x<=15 && *x>=8) // rayon millieu haut
            {
                *y-=2;
            }

            if (*y==87 && *x<=15 && *x>=8) // rayon gauche haut
            {
                *y-=2;
            }

            if (*y==141 && *x<=15 && *x>=8) // rayon droite haut
            {
                *y-=2;
            }
            break;

        default:
            break;
    }
}

void physic_map(int ch, int* l, int* c){

    switch (ch)
    {
        case KEY_UP:
        case 'z':
            if (*l!=0)  //physic bordermap
            {
                *l=*l-1;
            }

            if (*c<=36 && *l==49)   //physic pokeshop
            {
                *l=*l+1;
            }

            if (*c<=36 && *l==9)   //physic home
            {
                *l=*l+1;
            }

            if (*c>=220 && *l==9)   //physic lab
            {
                *l=*l+1;
            }

            if (*c<=36 && *l==99)   //physic house 3
            {
                *l=*l+1;
            }

            if (*c>=220 && *l==49)   //physic house 3
            {
                *l=*l+1;
            }

            if (*c>=220 && *l==74)   //physic house 4
            {
                *l=*l+1;
            }

            if (*c>=220 && *l==99)   //physic house 5
            {
                *l=*l+1;
            }

            if (*c>=242 && *l==18)   //physic "THE FOREST"
            {
                *l=*l+1;
            }

            if (*c<=14 && *l==68)   //physic "THE LEAGUE"
            {
                *l=*l+1;
            }

            break;

        case KEY_DOWN:
        case 's':
            if (*l!=103)    //physic bordermap
            {
                *l=*l+1;
            }

            if (*c<=36 && *l==39)   //physic pokeshop
            {
                *l=*l-1;
            }

            if (*c<=36 && *l==87)   //physic house 2
            {
                *l=*l-1;
            }

            if (*c>=220 && *l==37)   //physic house 3
            {
                *l=*l-1;
            }

            if (*c>=220 && *l==62)   //physic house 4
            {
                *l=*l-1;
            }

            if (*c>=220 && *l==87)   //physic house 5
            {
                *l=*l-1;
            }

            if (*c>=242 && *l==16)   //physic "THE FOREST"
            {
                *l=*l-1;
            }

            if (*c<=14 && *l==66)   //physic "THE LEAGUE"
            {
                *l=*l-1;
            }
            
            
            break;
        case KEY_RIGHT:
        case 'd':
            if (*c!=256)    //physic bordermap
            {
                *c=*c+2;
            }

            if (*c==220 && *l<=9)  //physic lab
            {
                *c=*c-2;
            }

            if (*c==220 && *l>=37 && *l<=49)  //physic house 3
            {
                *c=*c-2;
            }

            if (*c==220 && *l>=62 && *l<=74)  //physic house 4
            {
                *c=*c-2;
            }

            if (*c==220 && *l>=87 && *l<=99)  //physic house 5
            {
                *c=*c-2;
            }

            if (*c==242 && *l>=16 && *l<=18)  //physic "THE FOREST"
            {
                *c=*c-2;
            }
            
            
            break;
        case KEY_LEFT:
        case 'q':
            if (*c!=0)  //physic bordermap
            {
                *c=*c-2;
            }
            
            if (*c==36 && *l>=39 && *l<=49) //physic pokeshop
            {
                *c=*c+2;
            }

            if (*c==36 && *l<=9) //physic home
            {
                *c=*c+2;
            }
            
            if (*c==36 && *l>=87 && *l<=99) //physic house 2
            {
                *c=*c+2;
            }

            if (*c==14 && *l>=66 && *l<=68)  //physic "THE LEAGUE"
            {
                *c=*c+2;
            }
            
            break;
    }
}

void physic_roadto_league(int ch, int* l, int* c){

    switch (ch)
    {
        case KEY_UP:
        case 'z':
            if (*l!=13)  //physic bordermap + bat and trees
            {
                *l=*l-1;
            }

            if (*l==75)  //  border water down
            {
                *l=*l+1;
            }

            if (*l==49)  //  border water up (surf)
            {
                *l=*l+1;
            }
            break;

        case KEY_DOWN:
        case 's':
            if (*l!=103)    //physic bordermap
            {
                *l=*l+1;
            }  

            if (*l==49)  // border water up
            {
                *l-=1;
            }

            if (*l==75)  // border water up
            {
                *l-=1;
            }
                      
            break;
        case KEY_RIGHT:
        case 'd':
            if (*c!=140)    //physic bordermap
            {
                *c=*c+2;
            }    
            break;
        case KEY_LEFT:
        case 'q':
            if (*c!=0)  //physic bordermap
            {
                *c=*c-2;
            }     
            break;
    }
}

void physic_inventory(int ch, int* x, int* y){

    switch (ch)
        {
        case 'q' :
        case KEY_LEFT :
            if (*y!=17)
            {
                *y-=40;
            }
            break;

        case 'd' :
        case KEY_RIGHT :
            if (*y!=97)
            {
                *y+=40;
            }
            break;

        case 'z' :
        case KEY_UP :
            if (*x==26)
            {
                *x=12;
            }
            break;

        case 's' :
        case KEY_DOWN :
            if (*x==12)
            {
                *x=26;
            }
            break;
        
        default:
            break;
        }
}

void physic_yourteam(int ch,int* x,int* y){

    switch (ch)
        {
        case 'q' :
        case KEY_LEFT :
            if (*y!=1)
            {
                *y-=1;
            }
            break;

        case 'd' :
        case KEY_RIGHT :
            if (*y!=3)
            {
                *y+=1;
            }
            break;

        case 'z' :
        case KEY_UP :
            if (*x==2)
            {
                *x=1;
            }
            break;

        case 's' :
        case KEY_DOWN :
            if (*x==1)
            {
                *x=2;
            }
            break;
        
        default:
            break;
        }
}