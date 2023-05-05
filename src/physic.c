#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"

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
            if (*x!=6 || *y>=127)
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

void physic_shop(int ch, int* x, int* y){
    switch (ch)
    {
        case 'z':
        case KEY_UP:
            if (*x!=6 || *y>=127)
            {
                *x-=1;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (*x!=34)
            {
                *x+=1;
            }
            break;

        case 'q':
        case KEY_LEFT:
            if (*y!=1)
            {
                *y-=2;
            }  
            break;
        
        case 'd':
        case KEY_RIGHT:
            if (*y!=143)
            {
                *y+=2;
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

            if (*c>=246 && *l==18)   //physic "OUTDSIDE"
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

            if (*c>=246 && *l==16)   //physic "OUTDSIDE"
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

            if (*c==246 && *l>=16 && *l<=18)  //physic "OUTSIDE"
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
            if (*y!=137)
            {
                *y+=40;
            }
            break;

        case 'z' :
        case KEY_UP :
            if (*x==39)
            {
                *x=26;
            }

            else if (*x==26)
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

            else if (*x==26)
            {
                *x=39;
            }
            break;
        
        default:
            break;
        }
}