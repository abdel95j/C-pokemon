#ifndef STRUCTS_H
#define STRUCTS_H

//inventoryplaces
#define POKEBALLS 0
#define POTIONS 1
#define CANDYS 2
#define SLOT4 3
#define SLOT5 4
#define SLOT6 5

//poketypes
#define NOPOKEMON 0
#define WATER 1
#define FIRE 2
#define GRASS 3
#define ELECTRIC 4

//init_pairs
#define RED 1
#define MAGENTA 2
#define YELLOW 3
#define BLUE 4
#define GREEN 5

//object types
#define OTHER -1
#define EMPTY 0
#define SURF 1
#define LEER 2
#define ROAR 3
#define FLOWER 4

//champions_art
#define CHAMPIONBLUE 1
#define CHAMPIONRED 2
#define CHAMPIONYELLOW 3

//pokearts
#define NOPOKEMON 0
#define CHARMANDER 1
#define SQUIRTLE 2 
#define BULBASAUR 3
#define PIKACHU 4
#define CHARIZARD 5

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
    int art_box;
    int art_front;
    int art_behind;
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
    int is_rock_there;
    pokemon pokefight;
    pokemon poke1;
    pokemon poke2;
    pokemon poke3;
    pokemon poke4;
    pokemon poke5;
    pokemon poke6;
    pokemon pc[20];
    object inventory[6];
}trainer; // V1.0

#endif