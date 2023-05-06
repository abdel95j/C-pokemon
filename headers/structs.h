#ifndef STRUCTS_H
#define STRUCTS_H

#define WATER 1
#define FIRE 2
#define GRASS 3
#define ELECTRIC 4

typedef struct
{
    char name[30];
    float pv;
    float atk;
    float def;
    float dodge;
    float spetaux;
    int lvl;
    int type;
    int art;
    int catchrate;
    char basicatk[30];
    char speatk[30];
    char statatk[30];
    char utilitary[30];
}pokemon;


typedef struct
{
    char name[25];
    int type;   //type of the object to know what the player wants to use in his inventory
}object;

/*
types: 

no obj=0
pokeballs = 1
potions=2
bonbons=3
*/


typedef struct 
{
    char name[30];
    int lvl;
    int xp;
    int money;
    int art;
    pokemon pokefight;
    pokemon poke1;
    pokemon poke2;
    pokemon poke3;
    pokemon poke4;
    pokemon poke5;
    pokemon poke6;
    pokemon pc[20];
    object inventory[12];
}trainer;

#endif