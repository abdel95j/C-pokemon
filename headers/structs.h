#ifndef STRUCTS_H
#define STRUCTS_H

#define NOPOKEMON 0
#define WATER 1
#define FIRE 2
#define GRASS 3
#define ELECTRIC 4

#define POKEBALLS 0
#define POTIONS 1
#define CANDYS 2
#define CT 3

#define RED 1
#define MAGENTA 2
#define YELLOW 3
#define BLUE 4
#define GREEN 5

typedef struct
{
    char name[25];
    int quant;
    int type;
}object;
typedef struct
{
    char name[30];
    float pv;
    float pv_save;
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
    object CTstat[30];
    object CTutil[30];
}pokemon;

typedef struct 
{
    char name[30];
    int lvl;
    int xp;
    int money;
    int art;
    int is_on_water;
    pokemon pokefight;
    pokemon poke1;
    pokemon poke2;
    pokemon poke3;
    pokemon poke4;
    pokemon poke5;
    pokemon poke6;
    pokemon pc[20];
    object inventory[6];
}trainer;

#endif