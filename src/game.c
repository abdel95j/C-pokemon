#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../headers/game.h"
#include "../headers/structs.h"
#include "../headers/print.h"
#include "../headers/physic.h"
#include "../headers/talk.h"
#include "../headers/talkbis.h"

void init_poke(pokemon* pokenull, pokemon* charmander, pokemon* bulbasaur, pokemon* squirtle, pokemon* pikachu, pokemon* charizard,pokemon* blastoise,pokemon* venusaur,pokemon* raichu){

    // PROCÉDURE D'AJOUT D'UN NOUVEAU POKEMON :
    //
    //      1 : l'ajouter dans init poke (ici) et faire ses stats SOYEZ COHÉRENTS AVEC CE QUI EXISTE DÉJÀ
    //
    //          si le pokemon est un pokemon évolué ex : dracaufeu mettez son lvl à 25 (lvl d'évolution)
    //          et soyez logique sur les stats (aidez vous de la fonction pokelvlup et faites 25 fois ce qui
    //          augmente pour 1 lvl) + rajoutez sa sous évolution dans la fonction evolvepoke + silent_evolvepoke
    //          exemple : si j'ajoute dracaufeu alors je vais créer le système d'evolution de salamèche dans evolvepoke 
    //
    //          lvlup 1 fois :
    //          player_poke->lvl+=1;
    //          player_poke->atk+=1;
    //          player_poke->def=player_poke->def+0.002;
    //          player_poke->pv+=2;
    //          player_poke->pv_save+=2;
    //
    //      2 : créer un define dans structs.h catégorie pokearts avec le nom du pokemon en maj + le int suivant 
    //          exemple :   #define NOUVEAU-POKEMON 5
    //
    //      3 : créer son type dans la catégorie poketypes si il n'existe pas déjà (tjrs dans strcuts.h)
    //          exemple :   #define NOUVEAU-TYPE 7
    //
    //      4 : l'ajouter dans toutes les declarations de pokemons + init poke (suivez les erreurs sur vscode ça aide)
    //          exemple :    pokemon pokenull,charmander,bulbasaur,squirtle,pikachu, nouveau-pokemon;
    //                      init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu, &nouveau-pokemon);       
    //
    //      4.5 : l'ajouter dans le taux de drop de la fonction encounter poke SI C'EST UN POKEMON RENCONTRABLE DANS LA FORET
    //            -> monter le rand poke du taux de drop (10 par exemple) puis créer le if <= au nouveau rand poke
    //
    //      5 : créer ses sprites (images d'affichage) dans les fonctions print_poke et print_art_box 
    //          pour les sprites taper "<nom du pokemon> sprite front/back" sur google et chercher des images jolies et cohérentes puis
    //          crop et aller sur https://manytools.org/hacker-tools/convert-images-to-ascii-art/go/  :
    //          - Si l'art obtenu est tout noir inversez les couleurs pour les images sans fond ça arrive souvent
    //          - RESPECTEZ LES MESURES DEJA EXISTANTES en changeant le "width of output" jusqu'à obtenir 
    //            un sprite de 9 LIGNES (tentez entre 20 et 40 jusqu'à trouver le sprite parfait)
    //
    //      6 : POUR L'ÉTAPE 1 ET 4, vérifier que vous avez bien aussi changé dans les variables de fonctions et 
    //          fichiers .h    exemple:
    //          void init_poke(pokemon* pokenull, pokemon* charmander, pokemon* bulbasaur, pokemon* squirtle, pokemon* pikachu, pokemon* nouveau-pokemon);
    //
    //      7 : découvrez votre nouveau pokémon et testez tout pour etre sur que tout marche bien ^^


    //pokenull
    pokenull->atk=0;
    pokenull->def=0;
    pokenull->dodge=0;
    pokenull->pv=0;
    pokenull->pv_save=0;
    pokenull->lvl=0;
    pokenull->catchrate=0;
    pokenull->art_box=NOPOKEMON;
    pokenull->art_front=NOPOKEMON;
    pokenull->art_behind=NOPOKEMON;
    pokenull->type=NOPOKEMON;
    pokenull->CTstat->type=0; 
    pokenull->CTutil->type=0; 
    pokenull->CTstat->quant=0;
    pokenull->CTutil->quant=0;
    sprintf(pokenull->basicatk,"none");
    sprintf(pokenull->speatk,"none");
    sprintf(pokenull->CTutil->name,"none");
    sprintf(pokenull->CTstat->name,"none");
    sprintf(pokenull->name,"no-pokemon");

    //charmander -
    charmander->atk=10.0;
    charmander->def=30.0/100;
    charmander->dodge=15;
    charmander->pv=35.0;
    charmander->pv_save=35.0;
    charmander->lvl=1;
    charmander->catchrate=35;
    charmander->art_box=CHARMANDER;
    charmander->art_front=CHARMANDER;
    charmander->art_behind=CHARMANDER;
    charmander->type=FIRE;
    charmander->CTstat->type=0;     
    charmander->CTutil->type=0; 
    charmander->CTstat->quant=0;
    charmander->CTutil->quant=0;    
    sprintf(charmander->basicatk,"fire-punch");
    sprintf(charmander->speatk,"flamethrower");
    sprintf(charmander->CTutil->name,"none");
    sprintf(charmander->CTstat->name,"none");
    sprintf(charmander->name,"Charmander");
    
    //bulbasaur -
    bulbasaur->atk=8.0;
    bulbasaur->def=45.0/100;
    bulbasaur->dodge=12;
    bulbasaur->pv=40.0;
    bulbasaur->pv_save=40.0;
    bulbasaur->lvl=1;
    bulbasaur->catchrate=35;
    bulbasaur->art_box=BULBASAUR;
    bulbasaur->art_behind=BULBASAUR;
    bulbasaur->art_front=BULBASAUR;
    bulbasaur->type=GRASS;
    bulbasaur->CTstat->type=0; 
    bulbasaur->CTutil->type=0; 
    bulbasaur->CTstat->quant=0;
    bulbasaur->CTutil->quant=0;    
    sprintf(bulbasaur->basicatk,"bullet-seed");
    sprintf(bulbasaur->speatk,"solar-beam");
    sprintf(bulbasaur->CTutil->name,"none");
    sprintf(bulbasaur->CTstat->name,"none");
    sprintf(bulbasaur->name,"Bulbasaur");

    //squirtle -
    squirtle->atk=9.0;
    squirtle->def=35.0/100;
    squirtle->dodge=18;
    squirtle->pv=33.0;
    squirtle->pv_save=33.0;
    squirtle->lvl=1;
    squirtle->catchrate=35;
    squirtle->art_box=SQUIRTLE;
    squirtle->art_behind=SQUIRTLE;
    squirtle->art_front=SQUIRTLE;
    squirtle->type=WATER;
    squirtle->CTstat->type=0; 
    squirtle->CTutil->type=0; 
    squirtle->CTstat->quant=0;
    squirtle->CTutil->quant=0;    
    sprintf(squirtle->basicatk,"water-gun");
    sprintf(squirtle->speatk,"hydropump");
    sprintf(squirtle->CTutil->name,"none");
    sprintf(squirtle->CTstat->name,"none");
    sprintf(squirtle->name,"Squirtle");

    //pikachu -
    pikachu->atk=10.0;
    pikachu->def=35.0/100;
    pikachu->dodge=17;
    pikachu->pv=33.0;
    pikachu->pv_save=33.0;
    pikachu->lvl=1;
    pikachu->catchrate=15;
    pikachu->art_box=PIKACHU;
    pikachu->art_front=PIKACHU;
    pikachu->art_behind=PIKACHU;
    pikachu->type=ELECTRIC;
    pikachu->CTstat->type=0;     
    pikachu->CTutil->type=0; 
    pikachu->CTstat->quant=0;
    pikachu->CTutil->quant=0;    
    sprintf(pikachu->basicatk,"quick-attack");
    sprintf(pikachu->speatk,"thunderbolt");
    sprintf(pikachu->CTutil->name,"none");
    sprintf(pikachu->CTstat->name,"none");
    sprintf(pikachu->name,"Pikachu");  

    //charizard -
    charizard->atk=35.0;
    charizard->def=35.0/100;
    charizard->dodge=8;
    charizard->pv=83.0;
    charizard->pv_save=83.0;
    charizard->lvl=25;
    charizard->catchrate=10;
    charizard->art_box=CHARIZARD;
    charizard->art_front=CHARIZARD;
    charizard->art_behind=CHARIZARD;
    charizard->type=FIRE;
    charizard->CTstat->type=0;     
    charizard->CTutil->type=0; 
    charizard->CTstat->quant=0;
    charizard->CTutil->quant=0;    
    sprintf(charizard->basicatk,"slash");
    sprintf(charizard->speatk,"flare-blitz");
    sprintf(charizard->CTutil->name,"none");
    sprintf(charizard->CTstat->name,"none");
    sprintf(charizard->name,"Charizard"); 

    //blastoise -
    blastoise->atk=32.0;
    blastoise->def=40.0/100;
    blastoise->dodge=7;
    blastoise->pv=85.0;
    blastoise->pv_save=85.0;
    blastoise->lvl=25;
    blastoise->catchrate=10;
    blastoise->art_box=BLASTOISE;
    blastoise->art_front=BLASTOISE;
    blastoise->art_behind=BLASTOISE;
    blastoise->type=WATER;
    blastoise->CTstat->type=0;     
    blastoise->CTutil->type=0; 
    blastoise->CTstat->quant=0;
    blastoise->CTutil->quant=0;    
    sprintf(blastoise->basicatk,"water-gun");
    sprintf(blastoise->speatk,"hydro-blast");
    sprintf(blastoise->CTutil->name,"none");
    sprintf(blastoise->CTstat->name,"none");
    sprintf(blastoise->name,"Blastoise"); 

    //venusaur -
    venusaur->atk=30.0;
    venusaur->def=45.0/100;
    venusaur->dodge=5;
    venusaur->pv=90.0;
    venusaur->pv_save=90.0;
    venusaur->lvl=25;
    venusaur->catchrate=10;
    venusaur->art_box=VENUSAUR;
    venusaur->art_front=VENUSAUR;
    venusaur->art_behind=VENUSAUR;
    venusaur->type=GRASS;
    venusaur->CTstat->type=0;     
    venusaur->CTutil->type=0; 
    venusaur->CTstat->quant=0;
    venusaur->CTutil->quant=0;    
    sprintf(venusaur->basicatk,"leef-storm");
    sprintf(venusaur->speatk,"solar-beam");
    sprintf(venusaur->CTutil->name,"none");
    sprintf(venusaur->CTstat->name,"none");
    sprintf(venusaur->name,"Venusaur"); 

    //raichu -
    raichu->atk=33.0;
    raichu->def=38.0/100;
    raichu->dodge=20;
    raichu->pv=80.0;
    raichu->pv_save=80.0;
    raichu->lvl=25;
    raichu->catchrate=10;
    raichu->art_box=RAICHU;
    raichu->art_front=RAICHU;
    raichu->art_behind=RAICHU;
    raichu->type=ELECTRIC;
    raichu->CTstat->type=0;     
    raichu->CTutil->type=0; 
    raichu->CTstat->quant=0;
    raichu->CTutil->quant=0;    
    sprintf(raichu->basicatk,"iron-tail");
    sprintf(raichu->speatk,"thunder");
    sprintf(raichu->CTutil->name,"none");
    sprintf(raichu->CTstat->name,"none");
    sprintf(raichu->name,"Raichu"); 
}

void init_champions(trainer*player,trainer*blue, trainer*red, trainer*yellow){
    int sort1=rand()%3;    int lvlsort1=rand()%3;
    int sort2=rand()%2;    int lvlsort2=rand()%2;
    int moy_lvl=(player->poke1.lvl+player->poke2.lvl+player->poke3.lvl)/3;

    pokemon charmander,pokenull,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

    sprintf(blue->name,"Blue");
    blue->poke1=squirtle;
    blue->poke2=bulbasaur;
    blue->poke3=pikachu;
    blue->art=CHAMPIONBLUE;

    sprintf(red->name,"Red");
    red->poke1=charmander;
    red->poke2=bulbasaur;
    red->poke3=pikachu;
    red->art=CHAMPIONRED;

    sprintf(yellow->name,"Yellow");
    yellow->poke1=pikachu;
    yellow->poke2=charmander;
    yellow->poke3=squirtle;
    yellow->art=CHAMPIONYELLOW;

    switch (sort2)
    {
    case 0: // MINUS
        switch (sort1)
        {
        case 0:
            red->lvl=player->lvl;
            blue->lvl=player->lvl;
            yellow->lvl=player->lvl;
            switch (lvlsort2)
            {
            case 0: // MINUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl-1,&red->poke1);
                    silent_pokelvlup(moy_lvl-1,&red->poke2);
                    silent_pokelvlup(moy_lvl-1,&red->poke3);

                    silent_pokelvlup(moy_lvl-1,&blue->poke1);
                    silent_pokelvlup(moy_lvl-1,&blue->poke2);
                    silent_pokelvlup(moy_lvl-1,&blue->poke3);

                    silent_pokelvlup(moy_lvl-1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl-2,&red->poke1);
                    silent_pokelvlup(moy_lvl-2,&red->poke2);
                    silent_pokelvlup(moy_lvl-2,&red->poke3);

                    silent_pokelvlup(moy_lvl-2,&blue->poke1);
                    silent_pokelvlup(moy_lvl-2,&blue->poke2);
                    silent_pokelvlup(moy_lvl-2,&blue->poke3);

                    silent_pokelvlup(moy_lvl-2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;

            case 1: // PLUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl+1,&red->poke1);
                    silent_pokelvlup(moy_lvl+1,&red->poke2);
                    silent_pokelvlup(moy_lvl+1,&red->poke3);

                    silent_pokelvlup(moy_lvl+1,&blue->poke1);
                    silent_pokelvlup(moy_lvl+1,&blue->poke2);
                    silent_pokelvlup(moy_lvl+1,&blue->poke3);

                    silent_pokelvlup(moy_lvl+1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl+2,&red->poke1);
                    silent_pokelvlup(moy_lvl+2,&red->poke2);
                    silent_pokelvlup(moy_lvl+2,&red->poke3);

                    silent_pokelvlup(moy_lvl+2,&blue->poke1);
                    silent_pokelvlup(moy_lvl+2,&blue->poke2);
                    silent_pokelvlup(moy_lvl+2,&blue->poke3);

                    silent_pokelvlup(moy_lvl+2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;
            
            default:
                break;
            }
            break;
        
        case 1:
            red->lvl=player->lvl-1;
            blue->lvl=player->lvl-1;
            yellow->lvl=player->lvl-1;
            switch (lvlsort2)
            {
            case 0: // MINUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl-1,&red->poke1);
                    silent_pokelvlup(moy_lvl-1,&red->poke2);
                    silent_pokelvlup(moy_lvl-1,&red->poke3);

                    silent_pokelvlup(moy_lvl-1,&blue->poke1);
                    silent_pokelvlup(moy_lvl-1,&blue->poke2);
                    silent_pokelvlup(moy_lvl-1,&blue->poke3);

                    silent_pokelvlup(moy_lvl-1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl-2,&red->poke1);
                    silent_pokelvlup(moy_lvl-2,&red->poke2);
                    silent_pokelvlup(moy_lvl-2,&red->poke3);

                    silent_pokelvlup(moy_lvl-2,&blue->poke1);
                    silent_pokelvlup(moy_lvl-2,&blue->poke2);
                    silent_pokelvlup(moy_lvl-2,&blue->poke3);

                    silent_pokelvlup(moy_lvl-2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;

            case 1: // PLUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl+1,&red->poke1);
                    silent_pokelvlup(moy_lvl+1,&red->poke2);
                    silent_pokelvlup(moy_lvl+1,&red->poke3);

                    silent_pokelvlup(moy_lvl+1,&blue->poke1);
                    silent_pokelvlup(moy_lvl+1,&blue->poke2);
                    silent_pokelvlup(moy_lvl+1,&blue->poke3);

                    silent_pokelvlup(moy_lvl+1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl+2,&red->poke1);
                    silent_pokelvlup(moy_lvl+2,&red->poke2);
                    silent_pokelvlup(moy_lvl+2,&red->poke3);

                    silent_pokelvlup(moy_lvl+2,&blue->poke1);
                    silent_pokelvlup(moy_lvl+2,&blue->poke2);
                    silent_pokelvlup(moy_lvl+2,&blue->poke3);

                    silent_pokelvlup(moy_lvl+2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;
            
            default:
                break;
            }
            break;
        
        case 2:
            red->lvl=player->lvl-2;
            blue->lvl=player->lvl-2;
            yellow->lvl=player->lvl-2;
            switch (lvlsort2)
            {
            case 0: // MINUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl-1,&red->poke1);
                    silent_pokelvlup(moy_lvl-1,&red->poke2);
                    silent_pokelvlup(moy_lvl-1,&red->poke3);

                    silent_pokelvlup(moy_lvl-1,&blue->poke1);
                    silent_pokelvlup(moy_lvl-1,&blue->poke2);
                    silent_pokelvlup(moy_lvl-1,&blue->poke3);

                    silent_pokelvlup(moy_lvl-1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl-2,&red->poke1);
                    silent_pokelvlup(moy_lvl-2,&red->poke2);
                    silent_pokelvlup(moy_lvl-2,&red->poke3);

                    silent_pokelvlup(moy_lvl-2,&blue->poke1);
                    silent_pokelvlup(moy_lvl-2,&blue->poke2);
                    silent_pokelvlup(moy_lvl-2,&blue->poke3);

                    silent_pokelvlup(moy_lvl-2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;

            case 1: // PLUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl+1,&red->poke1);
                    silent_pokelvlup(moy_lvl+1,&red->poke2);
                    silent_pokelvlup(moy_lvl+1,&red->poke3);

                    silent_pokelvlup(moy_lvl+1,&blue->poke1);
                    silent_pokelvlup(moy_lvl+1,&blue->poke2);
                    silent_pokelvlup(moy_lvl+1,&blue->poke3);

                    silent_pokelvlup(moy_lvl+1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl+2,&red->poke1);
                    silent_pokelvlup(moy_lvl+2,&red->poke2);
                    silent_pokelvlup(moy_lvl+2,&red->poke3);

                    silent_pokelvlup(moy_lvl+2,&blue->poke1);
                    silent_pokelvlup(moy_lvl+2,&blue->poke2);
                    silent_pokelvlup(moy_lvl+2,&blue->poke3);

                    silent_pokelvlup(moy_lvl+2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }
        break;

    case 1: // PLUS
        switch (sort1)
        {
        case 0:
            red->lvl=player->lvl;
            blue->lvl=player->lvl;
            yellow->lvl=player->lvl;
            switch (lvlsort2)
            {
            case 0: // MINUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl-1,&red->poke1);
                    silent_pokelvlup(moy_lvl-1,&red->poke2);
                    silent_pokelvlup(moy_lvl-1,&red->poke3);

                    silent_pokelvlup(moy_lvl-1,&blue->poke1);
                    silent_pokelvlup(moy_lvl-1,&blue->poke2);
                    silent_pokelvlup(moy_lvl-1,&blue->poke3);

                    silent_pokelvlup(moy_lvl-1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl-2,&red->poke1);
                    silent_pokelvlup(moy_lvl-2,&red->poke2);
                    silent_pokelvlup(moy_lvl-2,&red->poke3);

                    silent_pokelvlup(moy_lvl-2,&blue->poke1);
                    silent_pokelvlup(moy_lvl-2,&blue->poke2);
                    silent_pokelvlup(moy_lvl-2,&blue->poke3);

                    silent_pokelvlup(moy_lvl-2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;

            case 1: // PLUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl+1,&red->poke1);
                    silent_pokelvlup(moy_lvl+1,&red->poke2);
                    silent_pokelvlup(moy_lvl+1,&red->poke3);

                    silent_pokelvlup(moy_lvl+1,&blue->poke1);
                    silent_pokelvlup(moy_lvl+1,&blue->poke2);
                    silent_pokelvlup(moy_lvl+1,&blue->poke3);

                    silent_pokelvlup(moy_lvl+1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl+2,&red->poke1);
                    silent_pokelvlup(moy_lvl+2,&red->poke2);
                    silent_pokelvlup(moy_lvl+2,&red->poke3);

                    silent_pokelvlup(moy_lvl+2,&blue->poke1);
                    silent_pokelvlup(moy_lvl+2,&blue->poke2);
                    silent_pokelvlup(moy_lvl+2,&blue->poke3);

                    silent_pokelvlup(moy_lvl+2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;
            
            default:
                break;
            }
            break;
        
        case 1:
            red->lvl=player->lvl+1;
            blue->lvl=player->lvl+1;
            yellow->lvl=player->lvl+1;
            switch (lvlsort2)
            {
            case 0: // MINUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl-1,&red->poke1);
                    silent_pokelvlup(moy_lvl-1,&red->poke2);
                    silent_pokelvlup(moy_lvl-1,&red->poke3);

                    silent_pokelvlup(moy_lvl-1,&blue->poke1);
                    silent_pokelvlup(moy_lvl-1,&blue->poke2);
                    silent_pokelvlup(moy_lvl-1,&blue->poke3);

                    silent_pokelvlup(moy_lvl-1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl-2,&red->poke1);
                    silent_pokelvlup(moy_lvl-2,&red->poke2);
                    silent_pokelvlup(moy_lvl-2,&red->poke3);

                    silent_pokelvlup(moy_lvl-2,&blue->poke1);
                    silent_pokelvlup(moy_lvl-2,&blue->poke2);
                    silent_pokelvlup(moy_lvl-2,&blue->poke3);

                    silent_pokelvlup(moy_lvl-2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;

            case 1: // PLUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl+1,&red->poke1);
                    silent_pokelvlup(moy_lvl+1,&red->poke2);
                    silent_pokelvlup(moy_lvl+1,&red->poke3);

                    silent_pokelvlup(moy_lvl+1,&blue->poke1);
                    silent_pokelvlup(moy_lvl+1,&blue->poke2);
                    silent_pokelvlup(moy_lvl+1,&blue->poke3);

                    silent_pokelvlup(moy_lvl+1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl+2,&red->poke1);
                    silent_pokelvlup(moy_lvl+2,&red->poke2);
                    silent_pokelvlup(moy_lvl+2,&red->poke3);

                    silent_pokelvlup(moy_lvl+2,&blue->poke1);
                    silent_pokelvlup(moy_lvl+2,&blue->poke2);
                    silent_pokelvlup(moy_lvl+2,&blue->poke3);

                    silent_pokelvlup(moy_lvl+2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;
            
            default:
                break;
            }
            break;
        
        case 2:
            red->lvl=player->lvl+2;
            blue->lvl=player->lvl+2;
            yellow->lvl=player->lvl+2;
            switch (lvlsort2)
            {
            case 0: // MINUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl-1,&red->poke1);
                    silent_pokelvlup(moy_lvl-1,&red->poke2);
                    silent_pokelvlup(moy_lvl-1,&red->poke3);

                    silent_pokelvlup(moy_lvl-1,&blue->poke1);
                    silent_pokelvlup(moy_lvl-1,&blue->poke2);
                    silent_pokelvlup(moy_lvl-1,&blue->poke3);

                    silent_pokelvlup(moy_lvl-1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl-2,&red->poke1);
                    silent_pokelvlup(moy_lvl-2,&red->poke2);
                    silent_pokelvlup(moy_lvl-2,&red->poke3);

                    silent_pokelvlup(moy_lvl-2,&blue->poke1);
                    silent_pokelvlup(moy_lvl-2,&blue->poke2);
                    silent_pokelvlup(moy_lvl-2,&blue->poke3);

                    silent_pokelvlup(moy_lvl-2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl-2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;

            case 1: // PLUS
                switch (lvlsort1)
                {
                case 0:
                    silent_pokelvlup(moy_lvl,&red->poke1);
                    silent_pokelvlup(moy_lvl,&red->poke2);
                    silent_pokelvlup(moy_lvl,&red->poke3);

                    silent_pokelvlup(moy_lvl,&blue->poke1);
                    silent_pokelvlup(moy_lvl,&blue->poke2);
                    silent_pokelvlup(moy_lvl,&blue->poke3);

                    silent_pokelvlup(moy_lvl,&yellow->poke1);
                    silent_pokelvlup(moy_lvl,&yellow->poke2);
                    silent_pokelvlup(moy_lvl,&yellow->poke3);
                    break;
                
                case 1:
                    silent_pokelvlup(moy_lvl+1,&red->poke1);
                    silent_pokelvlup(moy_lvl+1,&red->poke2);
                    silent_pokelvlup(moy_lvl+1,&red->poke3);

                    silent_pokelvlup(moy_lvl+1,&blue->poke1);
                    silent_pokelvlup(moy_lvl+1,&blue->poke2);
                    silent_pokelvlup(moy_lvl+1,&blue->poke3);

                    silent_pokelvlup(moy_lvl+1,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+1,&yellow->poke3);
                    break;
                
                case 2:
                    silent_pokelvlup(moy_lvl+2,&red->poke1);
                    silent_pokelvlup(moy_lvl+2,&red->poke2);
                    silent_pokelvlup(moy_lvl+2,&red->poke3);

                    silent_pokelvlup(moy_lvl+2,&blue->poke1);
                    silent_pokelvlup(moy_lvl+2,&blue->poke2);
                    silent_pokelvlup(moy_lvl+2,&blue->poke3);

                    silent_pokelvlup(moy_lvl+2,&yellow->poke1);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke2);
                    silent_pokelvlup(moy_lvl+2,&yellow->poke3);
                    break;
                
                default:
                    break;
                }
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }
        break;
    default:
        break;
    }
}

void create_newplayer(trainer* newplayer){
    WINDOW* chatwin=newwin(62,235,0,0);
    WINDOW* write=subwin(chatwin,5,50,30,55);
    nodelay(stdscr,FALSE);
    echo();
    curs_set(1);

    pokemon pokenull,charmander,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

    box(write,0,0);
    print_newtrainer(chatwin);
    wrefresh(chatwin);
    wmove(write,2,22);

    while (wscanw(write,"%s",newplayer->name)!=1)
    {
        mvwprintw(write,2,22,"                 ");
        wmove(write,2,22);
    }

    newplayer->lvl=1;
    newplayer->money=200;
    newplayer->xp=0;
    newplayer->is_on_water=0; // false
    newplayer->is_rock_there=1; // true

    newplayer->inventory[POKEBALLS].quant=10;
    newplayer->inventory[POKEBALLS].type=OTHER;
    sprintf(newplayer->inventory[POKEBALLS].name,"pokeballs"); 

    newplayer->inventory[POTIONS].quant=5;
    newplayer->inventory[POTIONS].type=OTHER;
    sprintf(newplayer->inventory[POTIONS].name,"potions"); 

    newplayer->inventory[CANDYS].quant=2;
    newplayer->inventory[CANDYS].type=OTHER;
    sprintf(newplayer->inventory[CANDYS].name,"candys"); 

    newplayer->inventory[SLOT4].quant=0;
    newplayer->inventory[SLOT4].type=EMPTY;
    sprintf(newplayer->inventory[SLOT4].name,"empty"); 

    newplayer->inventory[SLOT5].quant=0;
    newplayer->inventory[SLOT5].type=EMPTY;
    sprintf(newplayer->inventory[SLOT5].name,"empty"); 

    newplayer->inventory[SLOT6].quant=EMPTY;
    newplayer->inventory[SLOT6].type=0;
    sprintf(newplayer->inventory[SLOT6].name,"empty"); 

    for (int i = 0; i < 20; i++)
    {
        newplayer->pc[i]=pokenull;
    }

    newplayer->pokefight=pokenull;
    newplayer->poke1=pokenull;
    newplayer->poke2=pokenull;
    newplayer->poke3=pokenull;
    newplayer->poke4=pokenull;
    newplayer->poke5=pokenull;
    newplayer->poke6=pokenull;
    
    curs_set(0);
    nodelay(stdscr,TRUE);
    noecho();
    if(delwin(write)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(1);
    }
    if(delwin(chatwin)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(2);
    }
}

void get_firstpoke(trainer* player){
    int finish=0,ch=ERR;
    int x=50,y=50;

    pokemon pokenull, charmander, bulbasaur, squirtle, pikachu, charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

    while (finish==0)
    {
        WINDOW* pokewin=newwin(62,235,0,0);
        print_get_firstpoke(pokewin,x,y);   
        wrefresh(pokewin);
        ch=getch();

        physic_get_firstpoke(ch,&y); // colisions
        switch (ch) // actions
        {
        case 'e':
        case '\n':
        case '\r':
            switch (y)
            {
            case 50:
                player->poke1=bulbasaur;
                finish=1;
                break;

            case 115:
                player->poke1=charmander;
                finish=1;
                break;

            case 183:
                player->poke1=squirtle;
                finish=1;
                break;
            
            default:
                break;
            }
            break;
        
        default:
            break;
        }  

        usleep(16667);
        if(delwin(pokewin)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(3);
        }
    } 

}

void evolvepoke(pokemon* poke){
    pokemon pokenull,charmander,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

    WINDOW* evolve_win=newwin(62,235,0,0);

    pokemon temp;
    if (poke->type!=NOPOKEMON)
    {
        usleep(1000);
        system("cvlc ressources/evolve-theme.mp3 >/dev/null 2>&1 &"); // start evolve theme

        switch (poke->art_box)
        {
        case CHARMANDER:
            if (poke->lvl>=25)
            {
                sprintf(temp.CTstat->name,"%s",poke->CTstat->name);               
                sprintf(temp.CTutil->name,"%s",poke->CTutil->name);               
                temp.CTstat->type=poke->CTstat->type;
                temp.CTutil->type=poke->CTutil->type;

                *poke=charizard;
                
                sprintf(poke->CTstat->name,"%s",temp.CTstat->name);               
                sprintf(poke->CTutil->name,"%s",temp.CTutil->name);               
                poke->CTstat->type=temp.CTstat->type;
                poke->CTutil->type=temp.CTutil->type;

                print_evolution(evolve_win,charmander,charizard);
            }
            break;

        case BULBASAUR:
            if (poke->lvl>=25)
            {
                sprintf(temp.CTstat->name,"%s",poke->CTstat->name);               
                sprintf(temp.CTutil->name,"%s",poke->CTutil->name);               
                temp.CTstat->type=poke->CTstat->type;
                temp.CTutil->type=poke->CTutil->type;

                *poke=venusaur;
                
                sprintf (poke->CTstat->name,"%s",temp.CTstat->name);               
                sprintf (poke->CTutil->name,"%s",temp.CTutil->name);               
                poke->CTstat->type=temp.CTstat->type;
                poke->CTutil->type=temp.CTutil->type;

                print_evolution(evolve_win,bulbasaur,venusaur);
            }
            break;

        case SQUIRTLE:
            if (poke->lvl>=25)
            {
                sprintf(temp.CTstat->name,"%s",poke->CTstat->name);               
                sprintf(temp.CTutil->name,"%s",poke->CTutil->name);               
                temp.CTstat->type=poke->CTstat->type;
                temp.CTutil->type=poke->CTutil->type;

                *poke=blastoise;
                
                sprintf (poke->CTstat->name,"%s",temp.CTstat->name);               
                sprintf (poke->CTutil->name,"%s",temp.CTutil->name);               
                poke->CTstat->type=temp.CTstat->type;
                poke->CTutil->type=temp.CTutil->type;
            
                print_evolution(evolve_win,squirtle,blastoise);
            }
            break;

        case PIKACHU:
            if (poke->lvl>=25)
            {
                sprintf(temp.CTstat->name,"%s",poke->CTstat->name);               
                sprintf(temp.CTutil->name,"%s",poke->CTutil->name);               
                temp.CTstat->type=poke->CTstat->type;
                temp.CTutil->type=poke->CTutil->type;

                *poke=raichu;
                
                sprintf (poke->CTstat->name,"%s",temp.CTstat->name);               
                sprintf (poke->CTutil->name,"%s",temp.CTutil->name);               
                poke->CTstat->type=temp.CTstat->type;
                poke->CTutil->type=temp.CTutil->type;
            
                print_evolution(evolve_win,pikachu,raichu);
            }
            break;

        default:
            break;
        }
    }

    if (delwin(evolve_win)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(48);
    }  
    system("killall -9 vlc >/dev/null 2>&1 &"); // stop evolve theme
}

void silent_evolvepoke(pokemon* poke){
    pokemon pokenull,charmander,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

    pokemon temp;
    if (poke->type!=NOPOKEMON)
    {
        switch (poke->art_box)
        {
        case CHARMANDER:
            if (poke->lvl>=25)
            {
                int diff=poke->lvl-25;
                sprintf(temp.CTstat->name,"%s",poke->CTstat->name);               
                sprintf(temp.CTutil->name,"%s",poke->CTutil->name);               
                temp.CTstat->type=poke->CTstat->type;
                temp.CTutil->type=poke->CTutil->type;

                *poke=charizard;
                
                sprintf(poke->CTstat->name,"%s",temp.CTstat->name);               
                sprintf(poke->CTutil->name,"%s",temp.CTutil->name);               
                poke->CTstat->type=temp.CTstat->type;
                poke->CTutil->type=temp.CTutil->type;

                silent_pokelvlup(diff,poke);
            }
            break;

        case BULBASAUR:
            if (poke->lvl>=25)
            {
                int diff=poke->lvl-25;
                sprintf(temp.CTstat->name,"%s",poke->CTstat->name);               
                sprintf(temp.CTutil->name,"%s",poke->CTutil->name);               
                temp.CTstat->type=poke->CTstat->type;
                temp.CTutil->type=poke->CTutil->type;

                *poke=venusaur;
                
                sprintf (poke->CTstat->name,"%s",temp.CTstat->name);               
                sprintf (poke->CTutil->name,"%s",temp.CTutil->name);               
                poke->CTstat->type=temp.CTstat->type;
                poke->CTutil->type=temp.CTutil->type;

                silent_pokelvlup(diff,poke);
            }
            break;

        case SQUIRTLE:
            if (poke->lvl>=25)
            {
                int diff=poke->lvl-25;
                sprintf(temp.CTstat->name,"%s",poke->CTstat->name);               
                sprintf(temp.CTutil->name,"%s",poke->CTutil->name);               
                temp.CTstat->type=poke->CTstat->type;
                temp.CTutil->type=poke->CTutil->type;

                *poke=blastoise;
                
                sprintf (poke->CTstat->name,"%s",temp.CTstat->name);               
                sprintf (poke->CTutil->name,"%s",temp.CTutil->name);               
                poke->CTstat->type=temp.CTstat->type;
                poke->CTutil->type=temp.CTutil->type;
            
                silent_pokelvlup(diff,poke);
            }
            break;

        case PIKACHU:
            if (poke->lvl>=25)
            {
                int diff=poke->lvl-25;
                sprintf(temp.CTstat->name,"%s",poke->CTstat->name);               
                sprintf(temp.CTutil->name,"%s",poke->CTutil->name);               
                temp.CTstat->type=poke->CTstat->type;
                temp.CTutil->type=poke->CTutil->type;

                *poke=raichu;
                
                sprintf (poke->CTstat->name,"%s",temp.CTstat->name);               
                sprintf (poke->CTutil->name,"%s",temp.CTutil->name);               
                poke->CTstat->type=temp.CTstat->type;
                poke->CTutil->type=temp.CTutil->type;
            
                silent_pokelvlup(diff,poke);
            }
            break;

        default:
            break;
        }
    }
}

void silent_pokelvlup(int times, pokemon* player_poke){
    pokemon pokenull,charmander,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

    if (player_poke->type!=0)
    {
        for (int i = 0; i < times; i++)
        {
            player_poke->lvl+=1;
            player_poke->atk+=1;
            player_poke->def=player_poke->def+0.002;
            player_poke->pv+=2;
            player_poke->pv_save+=2;
        }
        silent_evolvepoke(player_poke);
    }
}

void pokelvlup(WINDOW* win,int x,int y,int times, pokemon* player_poke){
    pokemon pokenull,charmander,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

    if (player_poke->type!=NOPOKEMON)
    {
        for (int i = 0; i < times; i++)
        {
            system("killall -9 vlc >/dev/null 2>&1 &"); // stop main theme
            usleep(1000); // pour pas kill la prochaine commande
            system("cvlc ressources/lvlup-theme.mp3 >/dev/null 2>&1 &"); // start lvlup theme

            player_poke->lvl+=1;
            player_poke->atk+=1;
            player_poke->def=player_poke->def+0.002;
            player_poke->pv+=2;
            player_poke->pv_save+=2;

            mvwprintw(win,x,y,"%s has reached the lvl %d !",player_poke->name,player_poke->lvl);
            wrefresh(win);
            sleep(2);
        }
    }
    else
    {
        mvwprintw(win,x,y,"There is no pokemon in this emplacement");
        wrefresh(win);
        sleep(2);
    }

    mvwprintw(win,x,y,"                                       ");
    wrefresh(win);
    system("killall -9 vlc >/dev/null 2>&1 &"); // stop lvlup theme
    usleep(1000); // pour pas kill la prochaine commande

    evolvepoke(player_poke);
    usleep(1000); // pour pas kill la prochaine commande
    
    system("cvlc ressources/Main-Theme.mp3 >/dev/null 2>&1 &"); // restart main theme
}

void playerlvlup(trainer* player){
    if (player->xp>=player->lvl*100)
    {
        player->lvl+=1;
    }
}

// match returns 1 in case of victory and 0 in case of defeat
int match(trainer* player,pokemon* player_poke, pokemon* champion_poke, int League0_Catch1, int* count_atk){
    int finish=0, ch=ERR;   
    int x=32,y=88;

    pokemon charmander,pokenull,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

    while(finish==0)
    {
        WINDOW* match=newwin(63/1.5,236/1.5,63/6+1,236/6);
        WINDOW* text=subwin(match,13,80,40,39);
        WINDOW* actions=subwin(match,13,77,40,119);
        WINDOW *jauge_player = newwin(3, 21, 34, 155);
        WINDOW *jauge_champion = newwin(3, 21, 18, 66);
        box(match,0,0);
        box(text,0,0);
        box(actions,0,0);
        box(jauge_champion,0,0);
        box(jauge_player,0,0);

        pokemon charmander,pokenull,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
        init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

        pokemon wildpoke = *champion_poke;

        print_match(match,jauge_champion,jauge_player,*player_poke,*champion_poke,x,y);
        mvwprintw(text,5,25,"What do you want to do %s ?",player->name);

        wrefresh(match);
        wrefresh(text);
        wrefresh(jauge_champion);
        wrefresh(jauge_player);
        ch=getch();
        switch (ch)
        {
        case 'z':
        case KEY_UP:
            if (x!=32)
            {
                x=32;
                y=88;
            }
            break;
        
        case 's':
        case KEY_DOWN:
            if (x!=38)
            {
                x=38;
                y=111;
            }
            break;
        
        case 'd':
        case KEY_RIGHT:
            if (x!=38 && y!=128)
            {
                y=128;
            }
            break;
        
        case 'q':
        case KEY_LEFT:
            if (x!=38 && y!=88)
            {
                y=88;
            }
            break;

        case 'e':
        case '\r':
        case '\n':
            switch (x)
            {
            case 38: // RUN
                if (League0_Catch1==0) // trainer match
                {
                    mvwprintw(text,5,20,"                                                 ");
                    mvwprintw(text,5,25,"You can't run from a trainer challenge !");
                    wrefresh(text);
                    sleep(1);
                }
                else // pokecatch
                {
                    mvwprintw(text,5,20,"                                                 ");
                    mvwprintw(text,5,25,"You ran away");
                    wrefresh(text);
                    sleep(2);
                    wclear(match);
                    wrefresh(match);
                    finish=1;
                    return 1;
                    break;
                }

            case 32:
                if (y==88) // FIGHT
                {
                    wclear(actions);
                    wclear(text);
                    wrefresh(actions);
                    int finish_fight=0;
                    int x_fight=3;
                    int whatatk=0;
                    int dodgevar=0;
                    while (finish_fight==0)
                    {
                        WINDOW* fight=subwin(match,13,77,40,119);
                        box(fight,0,0);
                        box(text,0,0);

                        mvwprintw(text,5,15,"                                                         ");
                        mvwprintw(text,5,22,"What attack do you want %s to use ?",player_poke->name);
                        wrefresh(text);
                        mvwprintw(match,30,82," ___ ___ ___ _  _ _____");
                        mvwprintw(match,30+1,82,"| __|_ _/ __| || |_   _|");
                        mvwprintw(match,30+2,82,"| _| | | (_ | __ | | |");
                        mvwprintw(match,30+3,82,"|_| |___\\___|_||_| |_|");

                        if (*count_atk>=5)
                        {
                            *count_atk=4;
                        }

                        int dmg = player_poke->atk-(player_poke->atk * champion_poke->def);
                        int dmg_opponent = champion_poke->atk-(champion_poke->atk * player_poke->def);
                        if (dmg<=0)
                        {
                            dmg=1;
                        }   
                                             
                        mvwprintw(fight,3,38,"%s",player_poke->basicatk);
                        mvwprintw(fight,5,38,"%s",player_poke->speatk);
                        if (*count_atk!=4)
                        {
                            mvwprintw(fight,5,52,"%d turn left",4-(*count_atk));
                        }
                        else
                        {
                            mvwprintw(fight,5,52,"             ");
                            mvwprintw(fight,5,52,"USABLE");
                        }
                        
                        mvwprintw(fight,7,38,"%s",player_poke->CTstat->name);
                        mvwprintw(fight,x_fight,36,">");

                        int has_atk=0;

                        ch=getch();
                        switch (ch)
                        {
                        case ' ':
                            wclear(fight);
                            wrefresh(fight);
                            finish_fight=1;
                            break;

                        case 'z':
                        case KEY_UP:
                            if (x_fight!=3)
                            {
                                mvwprintw(fight,x_fight,36," ");
                                x_fight-=2;
                            }
                            break;

                        case 's':
                        case KEY_DOWN:
                            if (x_fight!=7)
                            {
                                mvwprintw(fight,x_fight,36," ");
                                x_fight+=2;
                            }
                            break;
                        
                        case 'e':
                        case '\n':
                        case '\r':
                            switch (x_fight)
                            {
                            case 3: // basicatk
                            //your turn
                                mvwprintw(text,5,15,"                                                         ");
                                mvwprintw(text,5,23,"%s uses %s !",player_poke->name,player_poke->basicatk);
                                has_atk=1;
                                dodgevar=rand()%101;
                                wrefresh(text);
                                wrefresh(fight);
                                sleep(2);
                                if (champion_poke->dodge>=dodgevar)
                                {
                                    mvwprintw(text,5,15,"                                                         ");
                                    mvwprintw(text,5,23,"%s dodges the attack !",champion_poke->name);
                                    wrefresh(fight);
                                }
                                else
                                {
                                    champion_poke->pv-=dmg;
                                    if (champion_poke->pv<=0)
                                    {
                                        champion_poke->pv=0;
                                        finish=1;
                                        finish_fight=1;
                                        has_atk=0;
                                        *count_atk+=1;
                                        mvwprintw(text,5,15,"                                                         ");
                                        mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",champion_poke->name);
                                        print_poke(match,pokenull,6,110,0);
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(fight);
                                        sleep(2);
                                        return 1;
                                    }
                                }
                                *count_atk+=1;
                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                wrefresh(fight);
                                sleep(2);
                            
                            //champ turn
                                if (has_atk==1)
                                {
                                    mvwprintw(text,5,15,"                                                         ");
                                    sleep(1);
                                    whatatk=rand()%101;
                                    if (whatatk<=10)
                                    {
                                        mvwprintw(text,5,15,"                                                         ");
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(1);
                                        mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->speatk,player_poke->name);
                                        dodgevar=rand()%101;
                                        wrefresh(fight);
                                        wrefresh(text);
                                        sleep(2);
                                        if (player_poke->dodge>=dodgevar)
                                        {
                                            mvwprintw(text,5,15,"                                                         ");
                                            mvwprintw(text,5,23,"Your %s dodges the attack !",player_poke->name);
                                            wrefresh(fight);
                                        }
                                        else 
                                        {
                                            player_poke->pv-=2*dmg;
                                            if (player_poke->pv<=0)
                                            {
                                                player_poke->pv=0;
                                                finish=1;
                                                finish_fight=1;
                                                has_atk=0;
                                                *count_atk=1;
                                                mvwprintw(text,5,15,"                                                         ");
                                                mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                print_poke(match,pokenull,17,10,1);
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(fight);
                                                sleep(2);
                                                return 0;
                                            }
                                        }
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(2);
                                    }
                                    else
                                    {
                                        mvwprintw(text,5,15,"                                                         ");
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(1);
                                        mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->basicatk,player_poke->name);
                                        dodgevar=rand()%101;
                                        wrefresh(fight);
                                        wrefresh(text);
                                        sleep(2);
                                        if (player_poke->dodge>=dodgevar)
                                        {
                                            mvwprintw(text,5,15,"                                                         ");
                                            mvwprintw(text,5,23,"Your %s dodges the attack !",player_poke->name);
                                            wrefresh(fight);
                                        }
                                        else 
                                        {
                                            player_poke->pv-=dmg;
                                            if (player_poke->pv<=0)
                                            {
                                                player_poke->pv=0;
                                                finish=1;
                                                finish_fight=1;
                                                has_atk=0;
                                                *count_atk=1;
                                                mvwprintw(text,5,15,"                                                         ");
                                                mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                print_poke(match,pokenull,17,10,1);
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(fight);
                                                sleep(2);
                                                return 0;
                                            }
                                        }
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(2);
                                    }
                                }
                                break;

                            case 5: // speatk
                            //your turn
                                if (*count_atk%4==0)
                                {
                                    mvwprintw(text,5,15,"                                                         ");
                                    mvwprintw(text,5,23,"%s uses his special move %s !",player_poke->name,player_poke->speatk);
                                    has_atk=1;
                                    dodgevar=rand()%101;
                                    wrefresh(text);
                                        wrefresh(fight);
                                sleep(2);
                                    if (champion_poke->dodge>=dodgevar)
                                    {
                                        mvwprintw(text,5,15,"                                                         ");
                                        mvwprintw(text,5,23,"%s dodges the attack !",champion_poke->name);
                                        wrefresh(fight);
                                    }
                                    else
                                    {
                                        champion_poke->pv=champion_poke->pv-(2*dmg);
                                        if (champion_poke->pv<=0)
                                        {
                                            champion_poke->pv=0;
                                            finish=1;
                                            finish_fight=1;
                                            has_atk=0;
                                            *count_atk+=1;
                                            mvwprintw(text,5,15,"                                                         ");
                                            mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",champion_poke->name);
                                            print_poke(match,pokenull,6,110,0);
                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                            wrefresh(fight);
                                            sleep(2);
                                            return 1;
                                        }
                                    }
                                    jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                    wrefresh(fight);
                                    sleep(2);
                                    *count_atk=1;
                                }
                                else
                                {
                                    mvwprintw(text,5,15,"                                                         ");
                                    mvwprintw(text,5,22,"%s can't use %s right now",player_poke->name,player_poke->speatk);
                                    jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                    wrefresh(fight);
                                    sleep(2);
                                }

                            //champ turn
                                if (has_atk==1)
                                {
                                    mvwprintw(text,5,15,"                                                         ");
                                    sleep(1);
                                    whatatk=rand()%101;
                                    if (whatatk<=10)
                                    {
                                        mvwprintw(text,5,15,"                                                         ");
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(1);
                                        mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->speatk,player_poke->name);
                                        dodgevar=rand()%101;
                                        wrefresh(fight);
                                        wrefresh(text);
                                        sleep(2);
                                        if (player_poke->dodge>=dodgevar)
                                        {
                                            mvwprintw(text,5,15,"                                                         ");
                                            mvwprintw(text,5,23,"Your %s dodges the attack !",player_poke->name);
                                            wrefresh(fight);
                                        }
                                        else 
                                        {
                                            player_poke->pv-=2*dmg;
                                            if (player_poke->pv<=0)
                                            {
                                                player_poke->pv=0;
                                                finish=1;
                                                finish_fight=1;
                                                has_atk=0;
                                                *count_atk=1;
                                                mvwprintw(text,5,15,"                                                         ");
                                                mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                print_poke(match,pokenull,17,10,1);
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(fight);
                                                sleep(2);
                                                return 0;
                                            }
                                        }
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(2);
                                    }
                                    else
                                    {
                                        mvwprintw(text,5,15,"                                                         ");
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(1);
                                        mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->basicatk,player_poke->name);
                                        dodgevar=rand()%101;
                                        wrefresh(fight);
                                        wrefresh(text);
                                        sleep(2);
                                        if (player_poke->dodge>=dodgevar)
                                        {
                                            mvwprintw(text,5,15,"                                                         ");
                                            mvwprintw(text,5,23,"Your %s dodges the attack !",player_poke->name);
                                            wrefresh(fight);
                                        }
                                        else 
                                        {
                                            player_poke->pv-=dmg;
                                            if (player_poke->pv<=0)
                                            {
                                                player_poke->pv=0;
                                                finish=1;
                                                finish_fight=1;
                                                has_atk=0;
                                                *count_atk=1;
                                                mvwprintw(text,5,15,"                                                         ");
                                                mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                print_poke(match,pokenull,17,10,1);
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(fight);
                                                sleep(2);
                                                return 0;
                                            }
                                        }
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(2);
                                    }
                                }
                                break;

                            case 7: // statatk
                            //your turn
                                switch (player_poke->CTstat->type)
                                {
                                case LEER:
                                    mvwprintw(text,5,15,"                                                         ");
                                    mvwprintw(text,5,23,"%s uses %s !",player_poke->name,player_poke->CTstat->name);
                                    dodgevar=rand()%101;
                                    has_atk=1;
                                    wrefresh(text);
                                        wrefresh(fight);
                                sleep(2);
                                    if (champion_poke->dodge>=dodgevar)
                                    {
                                        mvwprintw(text,5,15,"                                                         ");
                                        mvwprintw(text,5,23,"%s dodges the attack !",champion_poke->name);
                                        wrefresh(fight);
                                    }
                                    else
                                    {
                                        champion_poke->def-=0.1;
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(fight);
                                        sleep(2);
                                        mvwprintw(text,5,23,"                                        ");
                                        mvwprintw(text,5,23,"%s's defense has decreased",champion_poke->name);
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(fight);
                                        if(champion_poke->def<=0){
                                            champion_poke->def=0;
                                        }
                                    }
                                    sleep(1);
                                    *count_atk+=1;
                                    break;

                                case ROAR:
                                    mvwprintw(text,5,15,"                                                         ");
                                    mvwprintw(text,5,23,"%s uses %s !",player_poke->name,player_poke->CTstat->name);
                                    has_atk=1;
                                    wrefresh(text);
                                        wrefresh(fight);
                                sleep(2);
                                    if (champion_poke->dodge>=dodgevar)
                                    {
                                        mvwprintw(text,5,15,"                                                         ");
                                        mvwprintw(text,5,23,"%s dodges the attack !",champion_poke->name);
                                        wrefresh(fight);
                                    }
                                    else
                                    { 
                                        champion_poke->atk-=1.5;
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(fight);
                                        sleep(2);
                                        mvwprintw(text,5,15,"                                                         ");
                                        mvwprintw(text,5,23,"%s's attack has decreased",champion_poke->name);
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(fight);
                                        if(champion_poke->atk<=0){
                                            champion_poke->atk=0;
                                        }
                                    }
                                    sleep(1);   
                                    *count_atk+=1;
                                    break;
                                
                                default:
                                    break;
                                }
                                
                            //champ turn
                                if (has_atk==1)
                                {
                                    mvwprintw(text,5,15,"                                                         ");
                                    sleep(1);
                                    whatatk=rand()%101;
                                    if (whatatk<=10)
                                    {
                                        mvwprintw(text,5,15,"                                                         ");
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(1);
                                        mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->speatk,player_poke->name);
                                        dodgevar=rand()%101;
                                        wrefresh(fight);
                                        wrefresh(text);
                                        sleep(2);
                                        if (player_poke->dodge>=dodgevar)
                                        {
                                            mvwprintw(text,5,15,"                                                         ");
                                            mvwprintw(text,5,23,"Your %s dodges the attack !",player_poke->name);
                                            wrefresh(fight);
                                        }
                                        else 
                                        {
                                            player_poke->pv-=2*dmg;
                                            if (player_poke->pv<=0)
                                            {
                                                player_poke->pv=0;
                                                finish=1;
                                                finish_fight=1;
                                                has_atk=0;
                                                *count_atk=1;
                                                mvwprintw(text,5,15,"                                                         ");
                                                mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                print_poke(match,pokenull,17,10,1);
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(fight);
                                                sleep(2);
                                                return 0;
                                            }
                                        }
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(2);
                                    }
                                    else
                                    {
                                        mvwprintw(text,5,15,"                                                         ");
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(1);
                                        mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->basicatk,player_poke->name);
                                        dodgevar=rand()%101;
                                        wrefresh(fight);
                                        wrefresh(text);
                                        sleep(2);
                                        if (player_poke->dodge>=dodgevar)
                                        {
                                            mvwprintw(text,5,15,"                                                         ");
                                            mvwprintw(text,5,23,"Your %s dodges the attack !",player_poke->name);
                                            wrefresh(fight);
                                        }
                                        else 
                                        {
                                            player_poke->pv-=dmg;
                                            if (player_poke->pv<=0)
                                            {
                                                player_poke->pv=0;
                                                finish=1;
                                                finish_fight=1;
                                                has_atk=0;
                                                *count_atk=1;
                                                mvwprintw(text,5,15,"                                                         ");
                                                mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                print_poke(match,pokenull,17,10,1);
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(fight);
                                                sleep(2);
                                                return 0;
                                            }
                                        }
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(text);
                                        wrefresh(fight);
                                        sleep(2);
                                    }
                                }
                                break;
                            
                            default:
                                break;
                            }
                            break;

                        default:
                            break;
                        }

                        wrefresh(fight);
                        usleep(16667);
                        if (delwin(fight)==ERR)
                        {
                            system("killall -9 vlc >/dev/null 2>&1 &");
                            exit(47);
                        } 
                    }
                }

                else if (y==128) // BAG
                {
                    wclear(actions);
                    wclear(text);
                    wrefresh(actions);
                    int finish_bag=0;
                    int x_bag=3;
                    while (finish_bag==0)
                    {
                        WINDOW* bag=subwin(match,13,77,40,119);
                        box(bag,0,0);
                        box(text,0,0);

                        mvwprintw(text,5,25,"What object do you want to use ?");
                        wrefresh(text);
                        mvwprintw(match,30,82," ___   _   ___ ");
                        mvwprintw(match,30+1,82,"| _ ) /_\\ / __|");
                        mvwprintw(match,30+2,82,"| _ \\/ _ \\ (_ |");
                        mvwprintw(match,30+3,82,"|___/_/ \\_\\___|");

                        mvwprintw(bag,3,46,"    ");
                        mvwprintw(bag,5,48,"    "); // clear x number zone 
                        
                        mvwprintw(bag,3,38,"%s",player->inventory[POTIONS].name);
                        mvwprintw(bag,3,46,"x%d",player->inventory[POTIONS].quant);
                        mvwprintw(bag,5,38,"%s",player->inventory[POKEBALLS].name);
                        mvwprintw(bag,5,48,"x%d",player->inventory[POKEBALLS].quant);
                        mvwprintw(bag,x_bag,36,">");

                        ch=getch();
                        switch (ch)
                        {
                        case 'z':
                        case KEY_UP:
                            if (x_bag!=3)
                            {
                                mvwprintw(bag,x_bag,36," ");
                                x_bag-=2;
                            }
                            break;

                        case 's':
                        case KEY_DOWN:
                            if (x_bag!=5)
                            {
                                mvwprintw(bag,x_bag,36," ");
                                x_bag+=2;
                            }
                            break;

                        case ' ':
                            wclear(bag);
                            wrefresh(bag);
                            finish_bag=1;
                            break;

                        case 'e':
                        case '\n':
                        case '\r':
                            if (x_bag==3)
                            {   
                                if (player->inventory[POTIONS].quant>0)
                                {
                                    if (player_poke->pv>0 && player_poke->pv<player_poke->pv_save)
                                    {
                                        player->inventory[POTIONS].quant-=1;
                                        player_poke->pv+=player_poke->pv_save/2;
                                        if (player_poke->pv>player_poke->pv_save)
                                        {
                                            player_poke->pv=player_poke->pv_save;
                                        }
                                        mvwprintw(text,5,20,"                                                 ");
                                        mvwprintw(text,5,25,"%s healed successfully",player_poke->name);
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        sleep(2);
                                        *count_atk+=1;
                                        int has_atk=1;
                                        int dmg = player_poke->atk-(player_poke->atk * champion_poke->def);
                                        int dmg_opponent = champion_poke->atk-(champion_poke->atk * player_poke->def);
                                        if (dmg<=0)
                                        {
                                            dmg=1;
                                        }  
                                    //champ turn
                                        if (has_atk==1)
                                        {
                                            mvwprintw(text,5,15,"                                                         ");
                                            sleep(1);
                                            int whatatk=rand()%101;
                                            if (whatatk<=10)
                                            {
                                                mvwprintw(text,5,15,"                                                         ");
                                                wrefresh(text);
                                                wrefresh(bag);
                                                sleep(1);
                                                mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->speatk,player_poke->name);
                                                player_poke->pv-=2*dmg;
                                                if (player_poke->pv<=0)
                                                {
                                                    player_poke->pv=0;
                                                    finish=1;
                                                    finish_bag=1;
                                                    has_atk=0;
                                                    *count_atk=1;
                                                    mvwprintw(text,5,15,"                                                         ");
                                                    mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                    print_poke(match,pokenull,17,10,1);
                                                    jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                    wrefresh(bag);
                                                    sleep(2);
                                                    return 0;
                                                }
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(text);
                                                wrefresh(bag);
                                                sleep(2);
                                            }
                                            else
                                            {
                                                mvwprintw(text,5,15,"                                                         ");
                                                wrefresh(text);
                                                wrefresh(bag);
                                                sleep(1);
                                                mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->basicatk,player_poke->name);
                                                player_poke->pv-=dmg;
                                                if (player_poke->pv<=0)
                                                {
                                                    player_poke->pv=0;
                                                    finish=1;
                                                    finish_bag=1;
                                                    has_atk=0;
                                                    *count_atk=1;
                                                    mvwprintw(text,5,15,"                                                         ");
                                                    mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                    print_poke(match,pokenull,17,10,1);
                                                    jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                    wrefresh(bag);
                                                    sleep(2);
                                                    return 0;
                                                }
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(text);
                                                wrefresh(bag);
                                                sleep(2);
                                            }
                                        }
                                    }
                                    else if(player_poke->pv<=0)
                                    {
                                        mvwprintw(text,5,20,"                                                 ");
                                        mvwprintw(text,5,25,"%s needs to be revived",player_poke->name);
                                    }
                                    else if (player_poke->pv==player_poke->pv_save)
                                    {
                                        mvwprintw(text,5,20,"                                                 ");
                                        mvwprintw(text,5,25,"%s already has maximum HP",player_poke->name);
                                    }
                                }
                                else
                                {
                                    mvwprintw(text,5,20,"                                                 ");
                                    mvwprintw(text,5,25,"You need more potions to do this");
                                }
                                wrefresh(text);
                                sleep(1);
                                mvwprintw(text,5,20,"                                                 ");
                                mvwprintw(text,5,25,"What object do you want to use ?");
                                wrefresh(text);
                            }
                            else if (x_bag==5)
                            {
                                if (League0_Catch1==0) // trainer match
                                {
                                    mvwprintw(text,5,20,"                                                 ");
                                    mvwprintw(text,5,25,"You can't use that on the champion !");
                                    wrefresh(text);
                                    sleep(1);
                                    mvwprintw(text,5,20,"                                                 ");
                                    wrefresh(text);
                                }
                                else // catch
                                {
                                    if (player->inventory[POKEBALLS].quant!=0)
                                    {    
                                        int sort;
                                        mvwprintw(text,5,20,"                                                 ");
                                        mvwprintw(text,5,25,"You launch a pokeball on %s !",champion_poke->name);
                                        wrefresh(text);
                                        sleep(2);

                                        player->inventory[POKEBALLS].quant-=1;

                                        mvwprintw(text,5,20,"                                                 ");
                                        mvwprintw(text,5,25,"It shakes one time ...");

                                        print_poke(match,pokenull,6,110,0);
                                        mvwprintw(match,13,112,"(-o-)");

                                        usleep(400000);
                                        mvwprintw(match,13,112,"     ");
                                        mvwprintw(match,13,112,"(o-)");
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(match);
                                        usleep(400000);
                                        mvwprintw(match,13,112,"     ");
                                        mvwprintw(match,13,112,"(-o-)");
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(match);
                                        usleep(400000);
                                        mvwprintw(match,13,112,"     ");
                                        mvwprintw(match,13,112,"(-o)");
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(match);
                                        usleep(400000);
                                        mvwprintw(match,13,112,"     ");
                                        mvwprintw(match,13,112,"(-o-)");
                                        jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                        wrefresh(match);
                                        sleep(2);

                                        sort=rand()%201;

                                        if ((champion_poke->catchrate/100,0)+((champion_poke->pv_save/champion_poke->pv)/20)*100>=sort) // catched
                                        {
                                            mvwprintw(match,13,112,"*(-o-)*");
                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                            wrefresh(match);

                                            mvwprintw(text,5,20,"                                                 ");
                                            mvwprintw(text,5,25,"You got %s !",champion_poke->name);
                                            wrefresh(text);
                                            sleep(1);

                                            if (player->poke1.type==NOPOKEMON)
                                            {
                                                player->poke1=wildpoke;
                                            }
                                            else if (player->poke2.type==NOPOKEMON)
                                            {
                                                player->poke2=wildpoke;
                                            }
                                            else if (player->poke3.type==NOPOKEMON)
                                            {
                                                player->poke3=wildpoke;
                                            }
                                            else if (player->poke4.type==NOPOKEMON)
                                            {
                                                player->poke4=wildpoke;
                                            }
                                            else if (player->poke5.type==NOPOKEMON)
                                            {
                                                player->poke5=wildpoke;
                                            }
                                            else if (player->poke6.type==NOPOKEMON)
                                            {
                                                player->poke6=wildpoke;
                                            }
                                            else
                                            {
                                                mvwprintw(text,5,25,"                                       ");
                                                mvwprintw(text,5,25,"Your pocket is full of pokemons !");
                                                wrefresh(text);
                                                sleep(1);
                                                mvwprintw(text,5,25,"                                       ");
                                                mvwprintw(text,5,25,"Go put a pokemon on the pc or free it");
                                                wrefresh(text);
                                                sleep(1);
                                            }

                                            mvwprintw(text,5,25,"                                       ");
                                            mvwprintw(text,5,25,"*You earned 50$*");
                                            wrefresh(text);
                                            sleep(1);
                                            mvwprintw(text,5,20,"                                                 ");
                                            mvwprintw(text,5,25,"*You earned %d xp*",player->lvl*10);
                                            wrefresh(text);
                                            sleep(1);
                                            mvwprintw(text,5,20,"                                                 ");
                                            mvwprintw(text,5,25,"*You earned %d xp*",player->lvl*10);
                                            wrefresh(text);
                                            sleep(3);

                                            pokelvlup(text,5,25,1,player_poke);

                                            player->money+=70;
                                            player->xp+=player->lvl*10;

                                            wclear(bag);
                                            wrefresh(bag);
                                            finish_bag=1;
                                            mvwprintw(text,5,20,"                                                 ");
                                            wrefresh(text);
                                            wclear(match);
                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                            wrefresh(match);
                                            finish=1;
                                            return 1;
                                        }

                                        else
                                        {
                                            mvwprintw(text,5,20,"                                                 ");
                                            mvwprintw(text,5,25,"It shakes two times ...");
                                            wrefresh(text);
                                            sleep(1);

                                            mvwprintw(match,13,112,"     ");
                                            mvwprintw(match,13,112,"(-o-)");
                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                            wrefresh(match);
                                            usleep(400000);
                                            mvwprintw(match,13,112,"     ");
                                            mvwprintw(match,13,112,"(o-)");
                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                            wrefresh(match);
                                            usleep(400000);
                                            mvwprintw(match,13,112,"     ");
                                            mvwprintw(match,13,112,"(-o-)");
                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                            wrefresh(match);
                                            usleep(400000);
                                            mvwprintw(match,13,112,"     ");
                                            mvwprintw(match,13,112,"(-o)");
                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                            wrefresh(match);
                                            usleep(400000);
                                            mvwprintw(match,13,112,"     ");
                                            mvwprintw(match,13,112,"(-o-)");
                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                            wrefresh(match);
                                            sleep(2);

                                            sort=rand()%201;

                                            if (champion_poke->catchrate/(champion_poke->pv/champion_poke->pv_save)*1.8>=sort) // catched
                                            {
                                                mvwprintw(match,13,112,"*(-o-)*");
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(match);

                                                mvwprintw(text,5,20,"                                                 ");
                                                mvwprintw(text,5,25,"You got %s !",champion_poke->name);
                                                wrefresh(text);
                                                sleep(1);

                                                if (player->poke1.type==NOPOKEMON)
                                                {
                                                    player->poke1=wildpoke;
                                                }
                                                else if (player->poke2.type==NOPOKEMON)
                                                {
                                                    player->poke2=wildpoke;
                                                }
                                                else if (player->poke3.type==NOPOKEMON)
                                                {
                                                    player->poke3=wildpoke;
                                                }
                                                else if (player->poke4.type==NOPOKEMON)
                                                {
                                                    player->poke4=wildpoke;
                                                }
                                                else if (player->poke5.type==NOPOKEMON)
                                                {
                                                    player->poke5=wildpoke;
                                                }
                                                else if (player->poke6.type==NOPOKEMON)
                                                {
                                                    player->poke6=wildpoke;
                                                }
                                                else
                                                {
                                                    mvwprintw(text,5,25,"                                       ");
                                                    mvwprintw(text,5,25,"Your pocket is full of pokemons !");
                                                    wrefresh(text);
                                                    sleep(1);
                                                    mvwprintw(text,5,25,"                                       ");
                                                    mvwprintw(text,5,25,"Go put a pokemon on the pc or free it");
                                                    wrefresh(text);
                                                    sleep(1);
                                                }

                                                mvwprintw(text,5,25,"                                       ");
                                                mvwprintw(text,5,25,"*You earned 50$*");
                                                wrefresh(text);
                                                sleep(1);
                                                mvwprintw(text,5,20,"                                                 ");
                                                mvwprintw(text,5,25,"*You earned %d xp*",player->lvl*10);
                                                wrefresh(text);
                                                sleep(1);
                                                mvwprintw(text,5,20,"                                                 ");
                                                mvwprintw(text,5,25,"*You earned %d xp*",player->lvl*10);
                                                wrefresh(text);
                                                sleep(3);

                                                pokelvlup(text,5,25,1,player_poke);

                                                player->money+=70;
                                                player->xp+=player->lvl*10;

                                                wclear(bag);
                                                wrefresh(bag);
                                                finish_bag=1;
                                                mvwprintw(text,5,20,"                                                 ");
                                                wrefresh(text);
                                                wclear(match);
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(match);
                                                finish=1;
                                                return 1;
                                            }

                                            else
                                            {
                                                mvwprintw(text,5,20,"                                                 ");
                                                mvwprintw(text,5,25,"It shakes three times ...");
                                                wrefresh(text);
                                                sleep(1);

                                                mvwprintw(match,13,112,"     ");
                                                mvwprintw(match,13,112,"(-o-)");
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(match);
                                                usleep(400000);
                                                mvwprintw(match,13,112,"     ");
                                                mvwprintw(match,13,112,"(o-)");
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(match);
                                                usleep(400000);
                                                mvwprintw(match,13,112,"     ");
                                                mvwprintw(match,13,112,"(-o-)");
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(match);
                                                usleep(400000);
                                                mvwprintw(match,13,112,"     ");
                                                mvwprintw(match,13,112,"(-o)");
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(match);
                                                usleep(400000);
                                                mvwprintw(match,13,112,"     ");
                                                mvwprintw(match,13,112,"(-o-)");
                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                wrefresh(match);
                                                sleep(2);

                                                sort=rand()%201;

                                                if (champion_poke->catchrate/(champion_poke->pv/champion_poke->pv_save)*1.8>=sort) // catched
                                                {
                                                    mvwprintw(match,13,112,"*(-o-)*");
                                                    jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                    wrefresh(match);

                                                    mvwprintw(text,5,20,"                                                 ");
                                                    mvwprintw(text,5,25,"You got %s !",champion_poke->name);
                                                    wrefresh(text);
                                                    sleep(1);

                                                    if (player->poke1.type==NOPOKEMON)
                                                    {
                                                        player->poke1=wildpoke;
                                                    }
                                                    else if (player->poke2.type==NOPOKEMON)
                                                    {
                                                        player->poke2=wildpoke;
                                                    }
                                                    else if (player->poke3.type==NOPOKEMON)
                                                    {
                                                        player->poke3=wildpoke;
                                                    }
                                                    else if (player->poke4.type==NOPOKEMON)
                                                    {
                                                        player->poke4=wildpoke;
                                                    }
                                                    else if (player->poke5.type==NOPOKEMON)
                                                    {
                                                        player->poke5=wildpoke;
                                                    }
                                                    else if (player->poke6.type==NOPOKEMON)
                                                    {
                                                        player->poke6=wildpoke;
                                                    }
                                                    else
                                                    {
                                                        mvwprintw(text,5,25,"                                       ");
                                                        mvwprintw(text,5,25,"Your pocket is full of pokemons !");
                                                        wrefresh(text);
                                                        sleep(1);
                                                        mvwprintw(text,5,25,"                                       ");
                                                        mvwprintw(text,5,25,"Go put a pokemon on the pc or free it");
                                                        wrefresh(text);
                                                        sleep(1);
                                                    }

                                                    mvwprintw(text,5,25,"                                       ");
                                                    mvwprintw(text,5,25,"*You earned 50$*");
                                                    wrefresh(text);
                                                    sleep(1);
                                                    mvwprintw(text,5,20,"                                                 ");
                                                    mvwprintw(text,5,25,"*You earned %d xp*",player->lvl*10);
                                                    wrefresh(text);
                                                    sleep(1);
                                                    mvwprintw(text,5,20,"                                                 ");
                                                    mvwprintw(text,5,25,"*You earned %d xp*",player->lvl*10);
                                                    wrefresh(text);
                                                    sleep(3);

                                                    pokelvlup(text,5,25,1,player_poke);

                                                    player->money+=70;
                                                    player->xp+=player->lvl*10;

                                                    wclear(bag);
                                                    wrefresh(bag);
                                                    finish_bag=1;
                                                    mvwprintw(text,5,20,"                                                 ");
                                                    wrefresh(text);
                                                    wclear(match);
                                                    jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                    wrefresh(match);
                                                    finish=1;
                                                    return 1;
                                                }

                                                else
                                                {
                                                    print_poke(match,*champion_poke,6,110,0);
                                                    mvwprintw(text,5,20,"                                                 ");
                                                    mvwprintw(text,5,25,"No ! He escaped !");
                                                    wrefresh(text);
                                                    sleep(1);
                                                    mvwprintw(match,13,112,"     ");
                                                    print_poke(match,*champion_poke,6,110,0);
                                                    wrefresh(match);
                                                    *count_atk+=1;
                                                    int has_atk=1;
                                                    int dmg = player_poke->atk-(player_poke->atk * champion_poke->def);
                                                    int dmg_opponent = champion_poke->atk-(champion_poke->atk * player_poke->def);
                                                    if (dmg<=0)
                                                    {
                                                        dmg=1;
                                                    } 
                                                    //champ turn
                                                    if (has_atk==1)
                                                    {
                                                        mvwprintw(text,5,15,"                                                         ");
                                                        sleep(1);
                                                        int whatatk=rand()%101;
                                                        if (whatatk<=10)
                                                        {
                                                            mvwprintw(text,5,15,"                                                         ");
                                                            wrefresh(text);
                                                            wrefresh(bag);
                                                            sleep(1);
                                                            mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->speatk,player_poke->name);
                                                            player_poke->pv-=2*dmg;
                                                            if (player_poke->pv<=0)
                                                            {
                                                                player_poke->pv=0;
                                                                finish=1;
                                                                finish_bag=1;
                                                                has_atk=0;
                                                                *count_atk=1;
                                                                mvwprintw(text,5,15,"                                                         ");
                                                                mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                                print_poke(match,pokenull,17,10,1);
                                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                                wrefresh(bag);
                                                                sleep(2);
                                                                return 0;
                                                            }
                                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                            wrefresh(text);
                                                            wrefresh(bag);
                                                            sleep(2);
                                                        }
                                                        else
                                                        {
                                                            mvwprintw(text,5,15,"                                                         ");
                                                            wrefresh(text);
                                                            wrefresh(bag);
                                                            sleep(1);
                                                            mvwprintw(text,5,23,"%s uses %s on your %s !",champion_poke->name,champion_poke->basicatk,player_poke->name);
                                                            player_poke->pv-=dmg;
                                                            if (player_poke->pv<=0)
                                                            {
                                                                player_poke->pv=0;
                                                                finish=1;
                                                                finish_bag=1;
                                                                has_atk=0;
                                                                *count_atk=1;
                                                                mvwprintw(text,5,15,"                                                         ");
                                                                mvwprintw(text,5,23,"%s has 0 hp ! He leaves the stage",player_poke->name);
                                                                print_poke(match,pokenull,17,10,1);
                                                                jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                                wrefresh(bag);
                                                                sleep(2);
                                                                return 0;
                                                            }
                                                            jauges_refresh(match,jauge_player,jauge_champion,*player_poke,*champion_poke);
                                                            wrefresh(text);
                                                            wrefresh(bag);
                                                            sleep(2);
                                                            mvwprintw(text,5,20,"                                                 ");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        mvwprintw(text,5,20,"                                                 ");
                                        mvwprintw(text,5,25,"You don't have enough pokeballs");
                                        wrefresh(text);
                                        sleep(2);
                                        mvwprintw(text,5,20,"                                                 ");
                                    }
                                }
                            }
                            break;
                        
                        default:
                            break;
                        }

                        wrefresh(bag);
                        usleep(16667);
                        if (delwin(bag)==ERR)
                        {
                            system("killall -9 vlc >/dev/null 2>&1 &");
                            exit(47);
                        } 
                    }  
                }
                
                
                break;            
            default:
                break;
            }
            break;
        
        
        default:
            break;
        }

        usleep(16667);
        if (delwin(jauge_champion)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(45);
        }
        if (delwin(jauge_player)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(46);
        }
        if (delwin(actions)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(44);
        } 
        if (delwin(text)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(43);
        }  
        if (delwin(match)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(42);
        }  
    }
}

//returns 1 if you won the 3 matches and 0 if you dont
int duel(WINDOW* league_map,trainer* player, trainer champion){
    WINDOW* blackscreen = newwin(62,235,0,0);
    int count_atk=1;

    if (player->poke1.pv>0 && player->poke2.pv>0 && player->poke3.pv>0)
    {
        system("killall -9 vlc >/dev/null 2>&1 &"); // stop main theme
        usleep(1000);
        system("cvlc ressources/Battle-Theme.mp3 >/dev/null 2>&1 &"); // start battle theme
        if(match(player,&player->poke1,&champion.poke1,0,&count_atk)==1)
        {
            if (match(player,&player->poke1,&champion.poke2,0,&count_atk)==1)
            {
                if (match(player,&player->poke1,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke1);
                    return 1; // victory
                }
                else if (match(player,&player->poke2,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke2);
                    return 1; // victory
                }
                else if (match(player,&player->poke3,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke3);
                    return 1; // victory
                }
                else 
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    return 0; // defeat
                }
            }
            else if (match(player,&player->poke2,&champion.poke2,0,&count_atk)==1)
            {
                if (match(player,&player->poke2,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke2);
                    return 1; // victory
                }
                else if (match(player,&player->poke3,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke3);
                    return 1; // victory
                }
                else 
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    return 0; // defeat
                }
            }
            else if (match(player,&player->poke3,&champion.poke2,0,&count_atk)==1)
            {
                if (match(player,&player->poke3,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke3);
                    return 1; // victory
                }
                else
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    return 0; // defeat     
                }
            }
            else
            {
                wclear(blackscreen);
                wrefresh(blackscreen);
                return 0; // defeat
            }   
        }

        else if (match(player,&player->poke2,&champion.poke1,0,&count_atk)==1)
        {
            if (match(player,&player->poke2,&champion.poke2,0,&count_atk)==1)
            {
                if (match(player,&player->poke2,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke2);
                    return 1; // victory
                }
                else if (match(player,&player->poke3,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke3);
                    return 1; // victory
                }
                else
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    return 0; // defeat
                }
            }
            else if (match(player,&player->poke3,&champion.poke2,0,&count_atk)==1)
            {
                if (match(player,&player->poke3,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke3);
                    return 1; // victory
                }
                else
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    return 0; // defeat
                }
            }
            else
            {
                wclear(blackscreen);
                wrefresh(blackscreen);
                return 0; // defeat
            }
        }

        else if (match(player,&player->poke3,&champion.poke1,0,&count_atk)==1)
        {
            if (match(player,&player->poke3,&champion.poke2,0,&count_atk)==1)
            {
                if (match(player,&player->poke3,&champion.poke3,0,&count_atk)==1)
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    box(league_map,0,0);
                    print_league(league_map,14,65,champion);
                    wrefresh(league_map);
                    mvwprintw(league_map,13,72,"                 ");
                    mvwprintw(league_map,14,72,"                 ");
                    wrefresh(league_map);
                    pokelvlup(league_map,13,72,1,&player->poke3);
                    return 1; // victory
                }
                else
                {
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    return 0; // defeat
                }
            }
            else
            {
                wclear(blackscreen);
                wrefresh(blackscreen);
                return 0; // defeat
            }
        }

        else 
        {
            wclear(blackscreen);
            wrefresh(blackscreen);
            return 0; // defeat
        }
            if (delwin(blackscreen)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(47);
        }  
        system("killall -9 vlc >/dev/null 2>&1 &"); // stop battle theme
        usleep(1000);
        system("cvlc ressources/Main-Theme.mp3 >/dev/null 2>&1 &"); // restart main theme
    }
    else
    {
        mvwprintw(league_map,13,72,"                 ");
        mvwprintw(league_map,14,72,"                 ");
        write_flush(league_map,13,72,"You have a 0 HP pokemon");
        write_flush(league_map,14,72,"in your duel team");
        sleep(1);
        mvwprintw(league_map,13,72,"                          ");
        mvwprintw(league_map,14,72,"                     ");
        mvwprintw(league_map,15,72,"                    ");
        if (delwin(blackscreen)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(47);
        }  
        system("killall -9 vlc >/dev/null 2>&1 &"); // stop battle theme
        usleep(1000);
        system("cvlc ressources/Main-Theme.mp3 >/dev/null 2>&1 &"); // restart main theme
        return 2;
    }

    if (delwin(blackscreen)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(47);
        }  
    system("killall -9 vlc >/dev/null 2>&1 &"); // stop battle theme
        usleep(1000);
    system("cvlc ressources/Main-Theme.mp3 >/dev/null 2>&1 &"); // restart main theme
}

void house(trainer* player){
    int quit=0,finish=0,ch=ERR;
    int x=34,y=125;

    while (finish==0)
    {
        WINDOW* house_map=newwin(40,150,13,43);
        WINDOW* line_wall=subwin(house_map,1,148,22,44);
        box(house_map,0,0);
        box(line_wall,0,0);

        print_house(house_map,x,y);
        wrefresh(house_map);

        ch=getch();

        physic_house(ch,&x,&y); // colisions

        switch (ch) // actions
        {
            case 'e':
            case '\r':
            case '\n':
                if (x<=19 && x>=18 && y<=9) // mom area
                {
                    talkto_mom(house_map,player);
                }

                if (x==34 && y>=121 && y<=129) // exit area
                {
                    chargement();
                    finish=1;
                }  
                break;

            case 'm':
                menu(&quit,player);
                break;

            case 'i':
                inventory(player);
                break;

            default:
                break;
        }

        usleep(16667);
        if (delwin(line_wall)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(12);
        }
        if (delwin(house_map)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(11);
        }
    }
}

void league(trainer* player){
    int finish=0,ch=ERR,quit=0,has_fought=0;
    int x=34,y=71;

    trainer red,blue,yellow,champion;
    init_champions(player,&blue,&red,&yellow);

    int sort=rand()%3+1;

    if (sort==1)
    {
        champion=red;
    }
    else if (sort==2)
    {
        champion=blue;
    }
    else if (sort==3)
    {
        champion=yellow;
    }
    
    while (finish==0)
    {
        WINDOW* league_map=newwin(40,150,13,43);
        WINDOW* line_wall_league=subwin(league_map,1,148,22,44);
        WINDOW* arena_zone=subwin(league_map, 25, 50, 25, 92);
        box(line_wall_league,0,0);
        box(arena_zone, 0, 0);
        box(league_map,0,0);
        
        print_league(league_map,x,y,champion);
        wrefresh(league_map);
        physic_league(ch,&x,&y);
        ch=getch();
        switch (ch)
        {
        case 'e':
        case '\r':
        case '\n':
            if (x==34 && y>68 && y<79) // exit area
            {
                chargement(); 
                finish=1;   
            }

            if (x==14 && y>61 && y<69) // champion of the ligue area
            {
                if (has_fought==0)
                {
                    talkto_champion(league_map,player,champion,&has_fought);
                }  
                else
                {
                    write_flush(league_map,13,72,"You already had a match with me");
                    write_flush(league_map,14,72,"I need to heal my pokemons");
                    sleep(1);
                    mvwprintw(league_map,13,72,"                          ");
                    mvwprintw(league_map,14,72,"                     ");
                }
            }
            break;

        case 'm':
            menu(&quit,player);
            break;

        case 'i':
            inventory(player);
            break;
        default:
            break;
        }

        usleep(16667);
        if (delwin(line_wall_league)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(37);
        }
        if (delwin(arena_zone)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(38);
        }
        if (delwin(league_map)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(36);
        }
    }
}

void lab(trainer* player){
    int quit=0,ch=ERR, finish=0;
    int x=34,y=73;

    while(finish==0)
    {
        WINDOW* lab_map=newwin(40,150,13,43);
        WINDOW* line_wall_lab=subwin(lab_map,1,148,22,44);
        
        box(lab_map,0,0);
        box(line_wall_lab,0,0);

        print_lab(lab_map,x,y);
        physic_lab(ch,&x,&y);
        wrefresh(lab_map);

        ch=getch();

        switch (ch)
        {
        case 'e':
        case '\n':
        case '\r':
            if (x==34 && y>=69 && y<=77)
            {
                chargement();
                finish=1;
            }

            if (x<=7 && y>=95 && y<=105)
            {
                talkto_prof(lab_map,player);                
            }

            if (x==7 && y>=35 && y<=41)
            {
                computer(player);                
            }
            break;

        case 'm':
            menu(&quit,player);
            break;
        
        case 'i':
            inventory(player);
            break;
        
        default:
            break;
        }

        usleep(16667);
        if(delwin(line_wall_lab)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(19);
        }
        if(delwin(lab_map)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(20);
        }
    }
}

void encouter_poke(WINDOW* forest_map, trainer* player){
    pokemon charmander,pokenull,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);

    WINDOW* blackscreen = newwin(62,235,0,0);

    pokemon wildpoke;

    int rand_encounter;// random number to determine if the player encounters a pokemon
    int rand_wildpoke;// random number to determine the wild pokemon
    rand_wildpoke=rand()%110 +1;// rand from 1 to 100
    rand_encounter=rand()%100 +1;// same

    int sortsign = rand()%1; // 0 = + et 1 = -
    int sortlvl = rand()%2; // 0, 1 et 2

    int moypoke = (player->poke1.lvl + player->poke2.lvl + player->poke3.lvl) / 3 ;

    if(player->poke1.pv==0 && player->poke2.pv==0 && player->poke3.pv==0){
        rand_encounter=100; // cannot meet a wild pokemon without an alive pokemon
    }

    if(rand_encounter<=10){
        clignotement(forest_map);
        wclear(blackscreen);
        wrefresh(blackscreen);

        // case of charmander (33 %)
        if(rand_wildpoke<=33){
            wildpoke=charmander;
        }

        // case of squirtle (33 %)
        else if(rand_wildpoke<=66){
            wildpoke=squirtle;
        }

        // case of bulbasaur (34 %)
        else if(rand_wildpoke<=100){
            wildpoke=bulbasaur;
        }

        // case of pikachu (10 %)
        else if(rand_wildpoke<=110){
            wildpoke=pikachu;
        }

        switch (sortsign)
        {
        case 0: // +
            switch (sortlvl)
            {
            case 0:
                silent_pokelvlup(moypoke,&wildpoke);
                break;
            
            case 1:
                silent_pokelvlup(moypoke+1,&wildpoke);
                break;
            
            case 2:
                silent_pokelvlup(moypoke+2,&wildpoke);
                break;

            default:
                break;
            }
            break;

        case 1: // -
            switch (sortlvl)
            {
            case 0:
                silent_pokelvlup(moypoke,&wildpoke);
                break;
            
            case 1:
                silent_pokelvlup(moypoke-1,&wildpoke);
                break;
            
            case 2:
                silent_pokelvlup(moypoke-2,&wildpoke);
                break;

            default:
                break;
            }
            break;
        
        default:
            break;
        }

        if (wildpoke.lvl<=0)
        {
            // case of charmander (33 %)
            if(rand_wildpoke<=33){
                wildpoke=charmander;
            }

            // case of squirtle (33 %)
            else if(rand_wildpoke<=66){
                wildpoke=squirtle;
            }

            // case of bulbasaur (34 %)
            else if(rand_wildpoke<=100){
                wildpoke=bulbasaur;
            }

            // case of pikachu (10 %)
            else if(rand_wildpoke<=110){
                wildpoke=pikachu;
            }
        }
        duel_forest(player,wildpoke);
    }

    if (delwin(blackscreen)==ERR)
    {
        system("killall -9 vlc");
        exit(51);
    }
}

void forest(trainer* player){
    int finish=0,ch=ERR,quit=0;
    int x=17,y=3;
    WINDOW* blackscreen=newwin(62,235,0,0);
    wrefresh(blackscreen);
    while(finish==0){
        WINDOW* forest_map=newwin(63,211,0,12);
        print_forest(forest_map,x,y);
        wrefresh(forest_map);

        ch=getch();
        physic_forest(forest_map,ch,player,&x,&y);

        if (delwin(forest_map)==ERR)
            {
                system("killall -9 vlc");
                exit(100);
            }
        usleep(16667);
        switch (ch) // actions
            {
                case 'e':
                case '\r':
                case '\n':
                    if (y==3)
                    {
                        finish=1;
                        chargement();
                    }
                    break;
                case 'm':
                    menu(&quit,player);
                    break;

                case 'i':
                    inventory(player);
                    break;

                default:
                    break;
            }
    }
    if (delwin(blackscreen)==ERR)
        {
            system("killall -9 vlc");
            exit(101);
        }
}
void shop(trainer* player){
    int quit=0,finish=0,ch=ERR;
    int x=34,y=125;

    while (finish==0)
    {
        WINDOW* shop_map=newwin(40,150,13,43);
        WINDOW* line_wall=subwin(shop_map,1,148,22,44);
        box(shop_map,0,0);
        box(line_wall,0,0);
        print_shop(shop_map,x,y);
        wrefresh(shop_map);

        ch=getch();

        physic_shop(ch,&x,&y); // colisions

        switch (ch) // actions
        {
            case 'e':
            case '\r':
            case '\n':
                if (x==18 && y>=29 && y<=33) // cashier area
                {
                    talkto_cashier(shop_map,player);
                }

                if (x==34 && y>=121 && y<=129) // exit area
                {
                    chargement();
                    finish=1;
                }  
                break;

            case 'm':
                menu(&quit,player);
                break;

            case 'i':
                inventory(player);
                break;

            default:
                break;
        }

        usleep(16667);
        if (delwin(line_wall)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(12);
        }
        if (delwin(shop_map)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(11);
        }
    }
}

void your_team(trainer* player){
    WINDOW* blackscreen=newwin(62,235,0,0);
    int finish=0,ch=ERR;
    int x=1,y=1;

    pokemon charmander,pokenull,bulbasaur,squirtle,pikachu,charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);
    
     while (finish==0)
    {
        WINDOW* yourteam = newwin(40,155,14,40);
        WINDOW* yourteam_array=newwin(4,50,10,50);
        WINDOW* box1=subwin(yourteam,20,50,14,41);
        WINDOW* box2=subwin(yourteam,20,51,14,92);
        WINDOW* box3=subwin(yourteam,20,50,14,144);
        WINDOW* box4=subwin(yourteam,20,50,34,41);
        WINDOW* box5=subwin(yourteam,20,51,34,92);
        WINDOW* box6=subwin(yourteam,20,50,34,144);
        box(yourteam,0,0);
        box(box1,0,0);
        box(box2,0,0);
        box(box3,0,0);
        box(box4,0,0);
        box(box5,0,0);
        box(box6,0,0);

        mvwprintw(yourteam_array,0,0,"__  ______  __  _____    _____________   __  ___");
        mvwprintw(yourteam_array,0+1,0,"\\ \\/ / __ \\/ / / / _ \\  /_  __/ __/ _ | /  |/  /");
        mvwprintw(yourteam_array,0+2,0," \\  / /_/ / /_/ / , _/   / / / _// __ |/ /|_/ / ");
        mvwprintw(yourteam_array,0+3,0," /_/\\____/\\____/_/|_|   /_/ /___/_/ |_/_/  /_/  ");
                                  
        ch=getch();
        print_yourteam(box1,box2,box3,box4,box5,box6,player,x,y);        
        wrefresh(yourteam);
        wrefresh(yourteam_array);

        physic_yourteam(ch,&x,&y); // colisions

        switch (ch) // actions
        {
        case ' ':
            wclear(blackscreen);
            wrefresh(blackscreen);
            finish=1;
            break;
        case 'e':
        case '\n':
        case '\r':
            int finishact=0;
            int xact=5;
            int ok=0; // to not let click on pokenull
            pokemon tmp;

            switch (x)
            {
            case 1:
                switch (y){
                case 1:
                    if (player->poke1.type!=NOPOKEMON)
                    {
                        ok=1;
                    } 
                    break;

                case 2:
                    if (player->poke2.type!=NOPOKEMON)
                    {
                        ok=1;
                    } 
                    break;

                case 3:
                    if (player->poke3.type!=NOPOKEMON)
                    {
                        ok=1;
                    }  
                    break;
                }
                break;

            case 2:
                switch (y){
                case 1:
                    if (player->poke4.type!=NOPOKEMON)
                    {
                        ok=1;
                    } 
                    break;

                case 2:
                    if (player->poke5.type!=NOPOKEMON)
                    {
                        ok=1;
                    } 
                    break;

                case 3:
                    if (player->poke6.type!=NOPOKEMON)
                    {
                        ok=1;
                    } 
                    break;
                }
                break;
            
            default:
                break;
            }

            if (ok==1)
            {
                while(finishact==0)
                {
                    WINDOW* actions=newwin(10,20,20,10);
                    box(actions,0,0);

                    mvwprintw(actions,1,2,"What do you want");
                    mvwprintw(actions,2,2,"to do ?");
                    mvwprintw(actions,5,6,"Move");
                    mvwprintw(actions,7,6,"Free");
                    mvwprintw(actions,xact,4,">");
                    wrefresh(actions);

                    print_yourteam(box1,box2,box3,box4,box5,box6,player,x,y);

                    ch=getch();

                    switch (ch)
                    {
                    case 'z':
                    case KEY_UP:
                        if (xact!=5)
                        {
                            mvwprintw(actions,xact,4," ");
                            xact-=2;
                        }
                        break;

                    case 's':
                    case KEY_DOWN:
                        if (xact!=7)
                        {
                            mvwprintw(actions,xact,4," ");
                            xact+=2;
                        }
                        break;

                    case ' ':
                        wclear(actions);
                        wrefresh(actions);
                        finishact=1;
                        break;

                    case 'e':
                    case '\r':
                    case '\n':
                        if (xact==7)
                        {
                            int whatpoke=0;
                            if (x==1)
                            {
                                switch (y)
                                {
                                case 1:
                                    tmp=player->poke1; 
                                    whatpoke=1;
                                    break;

                                case 2:
                                    tmp=player->poke2; 
                                    whatpoke=2;
                                    break;

                                case 3:
                                    tmp=player->poke3; 
                                    whatpoke=3;
                                    break;

                                default:
                                    break;
                                }
                            }

                            if (x==2)
                            {
                                switch (y)
                                {
                                case 1:
                                    tmp=player->poke4; 
                                    whatpoke=4;
                                    break;

                                case 2:
                                    tmp=player->poke5; 
                                    whatpoke=5;
                                    break;

                                case 3:
                                    tmp=player->poke6; 
                                    whatpoke=6;
                                    break;

                                default:
                                    break;
                                }
                            }

                            int done=0,xsure=5;
                            while (done==0)
                            {
                                mvwprintw(actions,1,2,"                ");
                                mvwprintw(actions,2,2,"       ");
                                mvwprintw(actions,5,6,"    ");
                                mvwprintw(actions,7,6,"    ");
                                mvwprintw(actions,xact,4," ");

                                mvwprintw(actions,1,2," Are you sure ?");
                                mvwprintw(actions,5,6,"Yes");
                                mvwprintw(actions,7,6,"No");
                                mvwprintw(actions,xsure,4,">");
                                wrefresh(actions);

                                ch=getch();

                                switch (ch)
                                {
                                case ' ':
                                    wclear(actions);
                                    done=1;
                                    break;

                                case 'z':
                                case KEY_UP:
                                    if (xsure!=5)
                                    {
                                        mvwprintw(actions,xsure,4," ");
                                        xsure-=2;
                                    }
                                    break;

                                case 's':
                                case KEY_DOWN:
                                    if (xsure!=7)
                                    {
                                        mvwprintw(actions,xsure,4," ");
                                        xsure+=2;
                                    }
                                    break;

                                case 'e':
                                case '\r':
                                case '\n':
                                    if (xsure==5) // yes
                                    {
                                        mvwprintw(actions,1,2,"                ");
                                        mvwprintw(actions,2,2,"       ");
                                        mvwprintw(actions,5,6,"    ");
                                        mvwprintw(actions,7,6,"    ");
                                        mvwprintw(actions,xsure,4," ");
                                        switch (whatpoke)
                                        {
                                        case 1:
                                            if (player->poke2.type==NOPOKEMON && player->poke3.type==NOPOKEMON && player->poke4.type==NOPOKEMON && player->poke5.type==NOPOKEMON && player->poke6.type==NOPOKEMON)
                                            {
                                                mvwprintw(actions,3,4,"You can't free");
                                                mvwprintw(actions,4,2,"your last pokemon");
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            else
                                            {
                                                mvwprintw(actions,3,5,"%s",player->poke1.name);
                                                mvwprintw(actions,4,5,"released");
                                                player->poke1=pokenull;
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            break;

                                        case 2:
                                            if (player->poke1.type==NOPOKEMON && player->poke3.type==NOPOKEMON && player->poke4.type==NOPOKEMON && player->poke5.type==NOPOKEMON && player->poke6.type==NOPOKEMON)
                                            {
                                                mvwprintw(actions,3,4,"You can't free");
                                                mvwprintw(actions,4,2,"your last pokemon");
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            else
                                            {
                                                mvwprintw(actions,3,5,"%s",player->poke2.name);
                                                mvwprintw(actions,4,5,"released");
                                                player->poke2=pokenull;
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            break;

                                        case 3:
                                            if (player->poke1.type==NOPOKEMON && player->poke2.type==NOPOKEMON && player->poke4.type==NOPOKEMON && player->poke5.type==NOPOKEMON && player->poke6.type==NOPOKEMON)
                                            {
                                                mvwprintw(actions,3,4,"You can't free");
                                                mvwprintw(actions,4,2,"your last pokemon");
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            else
                                            {
                                                mvwprintw(actions,3,5,"%s",player->poke3.name);
                                                mvwprintw(actions,4,5,"released");
                                                player->poke3=pokenull;
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            break;

                                        case 4:
                                            if (player->poke1.type==NOPOKEMON && player->poke3.type==NOPOKEMON && player->poke2.type==NOPOKEMON && player->poke5.type==NOPOKEMON && player->poke6.type==NOPOKEMON)
                                            {
                                                mvwprintw(actions,3,4,"You can't free");
                                                mvwprintw(actions,4,2,"your last pokemon");
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            else
                                            {
                                                mvwprintw(actions,3,5,"%s",player->poke4.name);
                                                mvwprintw(actions,4,5,"released");
                                                player->poke4=pokenull;
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            break;

                                        case 5:
                                            if (player->poke1.type==NOPOKEMON && player->poke3.type==NOPOKEMON && player->poke4.type==NOPOKEMON && player->poke2.type==NOPOKEMON && player->poke6.type==NOPOKEMON)
                                            {
                                                mvwprintw(actions,3,4,"You can't free");
                                                mvwprintw(actions,4,2,"your last pokemon");
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            else
                                            {
                                                mvwprintw(actions,3,5,"%s",player->poke5.name);
                                                mvwprintw(actions,4,5,"released");
                                                player->poke5=pokenull;
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            break;

                                        case 6:
                                            if (player->poke1.type==NOPOKEMON && player->poke3.type==NOPOKEMON && player->poke4.type==NOPOKEMON && player->poke5.type==NOPOKEMON && player->poke2.type==NOPOKEMON)
                                            {
                                                mvwprintw(actions,3,4,"You can't free");
                                                mvwprintw(actions,4,2,"your last pokemon");
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            else
                                            {
                                                mvwprintw(actions,3,5,"%s",player->poke6.name);
                                                mvwprintw(actions,4,5,"released");
                                                player->poke6=pokenull;
                                                wrefresh(actions);
                                                sleep(2);
                                            }
                                            break;    
                                        default:
                                            break;
                                        }
                                        done=1;
                                    }
                                    else if (xsure==7) // no
                                    {
                                        wclear(actions);
                                        done=1;
                                        break;
                                    }
                                    break;

                                default:
                                    break;
                                }

                            }
                        }

                        else if (xact==5)
                        {
                            int whatpoke=0;
                            if (x==1)
                            {
                                switch (y)
                                {
                                case 1:
                                    tmp=player->poke1; 
                                    whatpoke=1;
                                    break;

                                case 2:
                                    tmp=player->poke2; 
                                    whatpoke=2;
                                    break;

                                case 3:
                                    tmp=player->poke3; 
                                    whatpoke=3;
                                    break;

                                default:
                                    break;
                                }
                            }

                            if (x==2)
                            {
                                switch (y)
                                {
                                case 1:
                                    tmp=player->poke4; 
                                    whatpoke=4;
                                    break;

                                case 2:
                                    tmp=player->poke5; 
                                    whatpoke=5;
                                    break;

                                case 3:
                                    tmp=player->poke6; 
                                    whatpoke=6;
                                    break;

                                default:
                                    break;
                                }
                            }

                            int xmove=1,ymove=1,moved=0;
                            while (moved==0)
                            {
                                box(yourteam,0,0);
                                box(box1,0,0);
                                box(box2,0,0);
                                box(box3,0,0);
                                box(box4,0,0);
                                box(box5,0,0);
                                box(box6,0,0);
                                print_yourteam(box1,box2,box3,box4,box5,box6,player,xmove,ymove);
                                physic_yourteam(ch,&xmove,&ymove);
                                wrefresh(yourteam);

                                ch=getch();
                                switch (ch)
                                {
                                
                                case ' ':
                                    moved=1;
                                    finishact=1;
                                    wclear(actions);
                                    wrefresh(actions);
                                    break;

                                case 'e':
                                case '\n':
                                case '\r':

                                    if (whatpoke==1)
                                    {
                                        if (xmove==1)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke1=player->poke1;
                                                player->poke1=tmp;
                                                break;

                                            case 2:
                                                player->poke1=player->poke2;
                                                player->poke2=tmp;
                                                break;

                                            case 3:
                                                player->poke1=player->poke3;
                                                player->poke3=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }

                                        if (xmove==2)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke1=player->poke4;
                                                player->poke4=tmp;
                                                break;

                                            case 2:
                                                player->poke1=player->poke5;
                                                player->poke5=tmp;
                                                break;

                                            case 3:
                                                player->poke1=player->poke6;
                                                player->poke6=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }
                                    }

                                    else if (whatpoke==2)
                                    {
                                        if (xmove==1)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke2=player->poke1;
                                                player->poke1=tmp;
                                                break;

                                            case 2:
                                                player->poke2=player->poke2;
                                                player->poke2=tmp;
                                                break;

                                            case 3:
                                                player->poke2=player->poke3;
                                                player->poke3=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }

                                        if (xmove==2)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke2=player->poke4;
                                                player->poke4=tmp;
                                                break;

                                            case 2:
                                                player->poke2=player->poke5;
                                                player->poke5=tmp;
                                                break;

                                            case 3:
                                                player->poke2=player->poke6;
                                                player->poke6=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }
                                    }

                                    else if (whatpoke==3)
                                    {
                                        if (xmove==1)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke3=player->poke1;
                                                player->poke1=tmp;
                                                break;

                                            case 2:
                                                player->poke3=player->poke2;
                                                player->poke2=tmp;
                                                break;

                                            case 3:
                                                player->poke3=player->poke3;
                                                player->poke3=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }

                                        if (xmove==2)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke3=player->poke4;
                                                player->poke4=tmp;
                                                break;

                                            case 2:
                                                player->poke3=player->poke5;
                                                player->poke5=tmp;
                                                break;

                                            case 3:
                                                player->poke3=player->poke6;
                                                player->poke6=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }
                                    }

                                    else if (whatpoke==4)
                                    {
                                        if (xmove==1)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke4=player->poke1;
                                                player->poke1=tmp;
                                                break;

                                            case 2:
                                                player->poke4=player->poke2;
                                                player->poke2=tmp;
                                                break;

                                            case 3:
                                                player->poke4=player->poke3;
                                                player->poke3=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }

                                        if (xmove==2)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke4=player->poke4;
                                                player->poke4=tmp;
                                                break;

                                            case 2:
                                                player->poke4=player->poke5;
                                                player->poke5=tmp;
                                                break;

                                            case 3:
                                                player->poke4=player->poke6;
                                                player->poke6=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }
                                    }

                                    else if (whatpoke==5)
                                    {
                                        if (xmove==1)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke5=player->poke1;
                                                player->poke1=tmp;
                                                break;

                                            case 2:
                                                player->poke5=player->poke2;
                                                player->poke2=tmp;
                                                break;

                                            case 3:
                                                player->poke5=player->poke3;
                                                player->poke3=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }

                                        if (xmove==2)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke5=player->poke4;
                                                player->poke4=tmp;
                                                break;

                                            case 2:
                                                player->poke5=player->poke5;
                                                player->poke5=tmp;
                                                break;

                                            case 3:
                                                player->poke5=player->poke6;
                                                player->poke6=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }
                                    }

                                    else if (whatpoke==6)
                                    {
                                        if (xmove==1)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke6=player->poke1;
                                                player->poke1=tmp;
                                                break;

                                            case 2:
                                                player->poke6=player->poke2;
                                                player->poke2=tmp;
                                                break;

                                            case 3:
                                                player->poke6=player->poke3;
                                                player->poke3=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }

                                        if (xmove==2)
                                        {
                                            switch (ymove)
                                            {
                                            case 1:
                                                player->poke6=player->poke4;
                                                player->poke4=tmp;
                                                break;

                                            case 2:
                                                player->poke6=player->poke5;
                                                player->poke5=tmp;
                                                break;

                                            case 3:
                                                player->poke6=player->poke6;
                                                player->poke6=tmp;
                                                break;

                                            default:
                                                break;
                                            }
                                        }
                                    }

                                    moved=1;
                                    finishact=1;
                                    wclear(actions);
                                    wrefresh(actions);
                                    break;

                                default:
                                    break;
                                }

                                usleep(16667);
                                wclear(yourteam);
                            }
                        }

                        break;
                    default:
                        break;
                    }

                    usleep(16667);
                    if(delwin(actions)==ERR)
                    {
                        system("killall -9 vlc >/dev/null 2>&1 &");
                        exit(45);
                    } 
                }
                break;
            default:
                break;
            }
        }

        usleep(16667);
        if(delwin(box1)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(36);
        }
        if(delwin(box2)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(37);
        }
        if(delwin(box3)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(38);
        }
        if(delwin(box4)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(39);
        }
        if(delwin(box5)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(40);
        }
        if(delwin(box6)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(41);
        }
        if(delwin(yourteam)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(34);
        }
        if(delwin(yourteam_array)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(33);
        }   
    }
    wclear(blackscreen);
    wrefresh(blackscreen);
        if (delwin(blackscreen)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(32);
        }
}

void menu(int* quit,trainer* player){
    WINDOW* blackscreen=newwin(62,235,0,0);
    int chmenu=ERR,menuexit=0;
    int x=13,y=95;
    
    while(chmenu!='m' && menuexit==0)
        {            
            WINDOW* winmenu=newwin(63/1.5,236/1.5,63/6+1,236/6);
            WINDOW* jaugelvl=newwin(3,51,16,135);

            box(jaugelvl,0,0);
            int array_lvl=(player->xp/player->lvl)*0.5;
            if (array_lvl>0)
            {
                for (int i =1 ; i < array_lvl ; i++)
                {
                    mvwprintw(jaugelvl,1,i,"#");
                }
            }
            mvwprintw(winmenu,3,96,"You have %d $                       You are lvl %d",player->money,player->lvl);
            mvwprintw(winmenu,8,97,"%d/%d xp",player->xp,player->lvl*100);
            
            print_menu(winmenu,x,y);

            box(winmenu,0,0);
            wrefresh(winmenu);  
            wrefresh(jaugelvl);  
            
            chmenu=getch();        

            physic_menu(chmenu,&x); // colisions
            switch (chmenu) // actions
            {
                case KEY_ENTER:
                case 'e':
                case '\r':
                case '\n':
                    switch (x)
                    {
                    case 31:
                        menuexit=1;
                        *quit=1;
                        //end music
                        system("killall -9 vlc >/dev/null 2>&1 &");
                        endwin();
                        exit(0);
                        break;

                    case 22:
                        save(player);
                        break;

                    case 13:
                        wclear(blackscreen);
                        wrefresh(blackscreen);
                        your_team(player);
                        break;
                    }
                    break;

                case ' ':
                    wclear(blackscreen);
                    wrefresh(blackscreen);
                    menuexit=1;
                    break;

                default:
                    break;
            } 
            usleep(16667);
            if(delwin(winmenu)==ERR)
            {
                system("killall -9 vlc >/dev/null 2>&1 &");
                exit(4);
            }
            if(delwin(jaugelvl)==ERR)
            {
                system("killall -9 vlc >/dev/null 2>&1 &");
                exit(47);
            }
        }
        wclear(blackscreen);
        wrefresh(blackscreen);
        if (delwin(blackscreen)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(24);
        }      
}

void inventory(trainer* player){
    WINDOW* blackscreen=newwin(62,235,0,0);
    int finish=0,ch=ERR;
    int x=12,y=17;

    while (finish==0)
    {
        WINDOW* sac = newwin(29,118,20,60);
        WINDOW* bag_array=newwin(5,50,15,60);
        box(sac,0,0);

        mvwprintw(bag_array,1,12," ___   _   ___ ");
        mvwprintw(bag_array,1+1,12,"| _ ) /_\\ / __|");
        mvwprintw(bag_array,1+2,12,"| _ \\/ _ \\ (_ |");
        mvwprintw(bag_array,1+3,12,"|___/_/ \\_\\___|");

        ch=getch();
        print_inventory(sac,player,x,y);        
        wrefresh(sac);
        wrefresh(bag_array);

        physic_inventory(ch,&x,&y); // colisions

        switch (ch) // actions
        {
        case 'i':
        case ' ':
            finish=1;
            break;
            
        case 'e':
        case '\n':
        case '\r':
            
            if (x==12)
            {
                switch (y)
                {
                case 17: // pokeballs
                    //inutile
                    break;

                case 57: // potions
                    int finishpotion=0;
                    int xpotion=4;

                    while (finishpotion==0)
                    {
                        WINDOW* actions = newwin(10,20,20,10);
                        box(actions,0,0);

                        mvwprintw(actions,1,2,"What do you want");
                        mvwprintw(actions,2,2,"to do ?");
                        mvwprintw(actions,4,6,"Use");
                        mvwprintw(actions,6,6,"Nothing");
                        mvwprintw(actions,xpotion,4,">");
                        wrefresh(actions);

                        ch=getch();
                        switch (ch)
                        {
                        case ' ':
                            wclear(actions);
                            wrefresh(actions);
                            finishpotion=1;
                            break;

                        case 'z':
                        case KEY_UP:
                            if (xpotion!=4)
                            {
                                xpotion-=2;
                            }
                            break;

                        case 's':
                        case KEY_DOWN:
                            if (xpotion!=6)
                            {
                                xpotion+=2;
                            }
                            break;

                        case 'e':
                        case '\r':
                        case '\n':
                            if (xpotion==6)
                            {
                                wclear(actions);
                                wrefresh(actions);
                                finishpotion=1;
                            }
                            else if (xpotion==4)
                            {
                                int finishchoice=0;
                                int xchoice=3;
                                while (finishchoice==0)
                                {
                                    wclear(actions);
                                    box(actions,0,0);
                                    mvwprintw(actions,1,2,"On which poke ?");
                                    mvwprintw(actions,3,3,"%s %.0f/%.0f",player->poke1.name,player->poke1.pv,player->poke1.pv_save);
                                    mvwprintw(actions,4,3,"%s %.0f/%.0f",player->poke2.name,player->poke2.pv,player->poke2.pv_save);
                                    mvwprintw(actions,5,3,"%s %.0f/%.0f",player->poke3.name,player->poke3.pv,player->poke3.pv_save);
                                    mvwprintw(actions,6,3,"%s %.0f/%.0f",player->poke4.name,player->poke4.pv,player->poke4.pv_save);
                                    mvwprintw(actions,7,3,"%s %.0f/%.0f",player->poke5.name,player->poke5.pv,player->poke5.pv_save);
                                    mvwprintw(actions,8,3,"%s %.0f/%.0f",player->poke6.name,player->poke6.pv,player->poke6.pv_save);
                                    mvwprintw(actions,xchoice,1,">");
                                    wrefresh(actions);

                                    ch=getch();
                                    switch (ch)
                                    {
                                    case ' ':
                                        wclear(actions);
                                        box(actions,0,0);
                                        finishchoice=1;
                                        break;

                                    case 'z':
                                    case KEY_UP:
                                        if (xchoice!=3)
                                        {
                                            xchoice-=1;
                                        }
                                        break;

                                    case 's':
                                    case KEY_DOWN:
                                        if (xchoice!=8)
                                        {
                                            xchoice+=1;
                                        }
                                        break;

                                    case 'e':
                                    case '\r':
                                    case '\n':
                                        switch (xchoice)
                                        {
                                        case 3: // poke1
                                            if (player->poke1.type!=NOPOKEMON && player->inventory[POTIONS].quant>0 && player->poke1.pv<player->poke1.pv_save)
                                            {
                                                player->inventory[POTIONS].quant-=1;
                                                player->poke1.pv+=player->poke1.pv_save/2;
                                                if (player->poke1.pv>player->poke1.pv_save)
                                                {
                                                    player->poke1.pv=player->poke1.pv_save;
                                                }
                                                wclear(actions);
                                                box(actions,0,0);
                                                mvwprintw(actions,1,2,"%s",player->poke1.name);
                                                mvwprintw(actions,2,2,"healed");
                                                wrefresh(actions);
                                                sleep(1);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                            }
                                            break;
                                        
                                        case 4: // poke2
                                            if (player->poke2.type!=NOPOKEMON && player->inventory[POTIONS].quant>0 && player->poke2.pv<player->poke2.pv_save)
                                            {
                                                player->inventory[POTIONS].quant-=1;
                                                player->poke2.pv+=player->poke2.pv_save/2;
                                                if (player->poke2.pv>player->poke2.pv_save)
                                                {
                                                    player->poke2.pv=player->poke2.pv_save;
                                                }
                                                wclear(actions);
                                                box(actions,0,0);
                                                mvwprintw(actions,1,2,"%s",player->poke2.name);
                                                mvwprintw(actions,2,2,"healed");
                                                wrefresh(actions);
                                                sleep(1);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                            }
                                            break;

                                        case 5: // poke3
                                            if (player->poke3.type!=NOPOKEMON && player->inventory[POTIONS].quant>0 && player->poke3.pv<player->poke3.pv_save)
                                            {
                                                player->inventory[POTIONS].quant-=1;
                                                player->poke3.pv+=player->poke3.pv_save/2;
                                                if (player->poke3.pv>player->poke3.pv_save)
                                                {
                                                    player->poke3.pv=player->poke3.pv_save;
                                                }
                                                wclear(actions);
                                                box(actions,0,0);
                                                mvwprintw(actions,1,2,"%s",player->poke3.name);
                                                mvwprintw(actions,2,2,"healed");
                                                wrefresh(actions);
                                                sleep(1);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                            }
                                            break;

                                        case 6: // poke4
                                            if (player->poke4.type!=NOPOKEMON && player->inventory[POTIONS].quant>0 && player->poke4.pv<player->poke4.pv_save)
                                            {
                                                player->inventory[POTIONS].quant-=1;
                                                player->poke4.pv+=player->poke4.pv_save/2;
                                                if (player->poke4.pv>player->poke4.pv_save)
                                                {
                                                    player->poke4.pv=player->poke4.pv_save;
                                                }
                                                wclear(actions);
                                                box(actions,0,0);
                                                mvwprintw(actions,1,2,"%s",player->poke4.name);
                                                mvwprintw(actions,2,2,"healed");
                                                wrefresh(actions);
                                                sleep(1);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                            }
                                            break;

                                        case 7: // poke5
                                            if (player->poke5.type!=NOPOKEMON && player->inventory[POTIONS].quant>0 && player->poke5.pv<player->poke5.pv_save)
                                            {
                                                player->inventory[POTIONS].quant-=1;
                                                player->poke5.pv+=player->poke5.pv_save/2;
                                                if (player->poke5.pv>player->poke5.pv_save)
                                                {
                                                    player->poke5.pv=player->poke5.pv_save;
                                                }
                                                wclear(actions);
                                                box(actions,0,0);
                                                mvwprintw(actions,1,2,"%s",player->poke5.name);
                                                mvwprintw(actions,2,2,"healed");
                                                wrefresh(actions);
                                                sleep(1);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                            }
                                            break;

                                        case 8: // poke6
                                            if (player->poke6.type!=NOPOKEMON && player->inventory[POTIONS].quant>0 && player->poke6.pv<player->poke6.pv_save)
                                            {
                                                player->inventory[POTIONS].quant-=1;
                                                player->poke6.pv+=player->poke6.pv_save/2;
                                                if (player->poke6.pv>player->poke6.pv_save)
                                                {
                                                    player->poke6.pv=player->poke6.pv_save;
                                                }
                                                wclear(actions);
                                                box(actions,0,0);
                                                mvwprintw(actions,1,2,"%s",player->poke6.name);
                                                mvwprintw(actions,2,2,"healed");
                                                wrefresh(actions);
                                                sleep(1);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                            }
                                            break;
                                        
                                        default:
                                            break;
                                        }

                                        break;

                                    default:
                                        break;
                                    }
                                    usleep(16667);
                                } 
                            }
                            break;
                        default:
                            break;
                        }

                        usleep(16667);
                        if (delwin(actions)==ERR)
                        {
                            system("killall -9 vlc >/dev/null 2>&1 &");
                            exit(53);
                        }
                    }
                    break;

                case 97: // candys
                    int finishcandy=0;
                    int xcandy=4;

                    while (finishcandy==0)
                    {
                        WINDOW* actions = newwin(10,20,20,10);
                        box(actions,0,0);

                        mvwprintw(actions,1,2,"What do you want");
                        mvwprintw(actions,2,2,"to do ?");
                        mvwprintw(actions,4,6,"Use");
                        mvwprintw(actions,6,6,"Nothing");
                        mvwprintw(actions,xcandy,4,">");
                        wrefresh(actions);

                        ch=getch();
                        switch (ch)
                        {
                        case ' ':
                            wclear(actions);
                            wrefresh(actions);
                            finishcandy=1;
                            break;

                        case 'z':
                        case KEY_UP:
                            if (xcandy!=4)
                            {
                                xcandy-=2;
                            }
                            break;

                        case 's':
                        case KEY_DOWN:
                            if (xcandy!=6)
                            {
                                xcandy+=2;
                            }
                            break;

                        case 'e':
                        case '\r':
                        case '\n':
                            if (xcandy==6)
                            {
                                wclear(actions);
                                wrefresh(actions);
                                finishcandy=1;
                            }
                            else if (xcandy==4)
                            {
                                int finishchoice=0;
                                int xchoice=3;
                                while (finishchoice==0)
                                {
                                    wclear(actions);
                                    box(actions,0,0);
                                    mvwprintw(actions,1,2,"On which poke ?");
                                    mvwprintw(actions,3,3,"%s lv %d",player->poke1.name,player->poke1.lvl);
                                    mvwprintw(actions,4,3,"%s lv %d",player->poke2.name,player->poke2.lvl);
                                    mvwprintw(actions,5,3,"%s lv %d",player->poke3.name,player->poke3.lvl);
                                    mvwprintw(actions,6,3,"%s lv %d",player->poke4.name,player->poke4.lvl);
                                    mvwprintw(actions,7,3,"%s lv %d",player->poke5.name,player->poke5.lvl);
                                    mvwprintw(actions,8,3,"%s lv %d",player->poke6.name,player->poke6.lvl);
                                    mvwprintw(actions,xchoice,1,">");
                                    wrefresh(actions);

                                    ch=getch();
                                    switch (ch)
                                    {
                                    case ' ':
                                        wclear(actions);
                                        box(actions,0,0);
                                        finishchoice=1;
                                        break;

                                    case 'z':
                                    case KEY_UP:
                                        if (xchoice!=3)
                                        {
                                            xchoice-=1;
                                        }
                                        break;

                                    case 's':
                                    case KEY_DOWN:
                                        if (xchoice!=8)
                                        {
                                            xchoice+=1;
                                        }
                                        break;

                                    case 'e':
                                    case '\r':
                                    case '\n':
                                        switch (xchoice)
                                        {
                                        case 3: // poke1
                                            if (player->poke1.type!=NOPOKEMON && player->inventory[CANDYS].quant>0)
                                            {
                                                player->inventory[CANDYS].quant-=1;
                                                pokelvlup(bag_array,5,0,1,&player->poke1);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                                finishcandy=1;
                                                finish=1;
                                            }
                                            break;
                                        
                                        case 4: // poke2
                                            if (player->poke2.type!=NOPOKEMON && player->inventory[CANDYS].quant>0)
                                            {
                                                player->inventory[CANDYS].quant-=1;
                                                pokelvlup(bag_array,5,0,1,&player->poke2);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                                finishcandy=1;
                                                finish=1;
                                            }
                                            break;

                                        case 5: // poke3
                                            if (player->poke3.type!=NOPOKEMON && player->inventory[CANDYS].quant>0)
                                            {
                                                player->inventory[CANDYS].quant-=1;
                                                pokelvlup(bag_array,5,0,1,&player->poke3);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                                finishcandy=1;
                                                finish=1;
                                            }
                                            break;

                                        case 6: // poke4
                                            if (player->poke4.type!=NOPOKEMON && player->inventory[CANDYS].quant>0)
                                            {
                                                player->inventory[CANDYS].quant-=1;
                                                pokelvlup(bag_array,5,0,1,&player->poke4);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                                finishcandy=1;
                                                finish=1;
                                            }
                                            break;

                                        case 7: // poke5
                                            if (player->poke5.type!=NOPOKEMON && player->inventory[CANDYS].quant>0)
                                            {
                                                player->inventory[CANDYS].quant-=1;
                                                pokelvlup(bag_array,5,0,1,&player->poke5);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                                finishcandy=1;
                                                finish=1;
                                            }
                                            break;

                                        case 8: // poke6
                                            if (player->poke6.type!=NOPOKEMON && player->inventory[CANDYS].quant>0)
                                            {
                                                player->inventory[CANDYS].quant-=1;
                                                pokelvlup(bag_array,5,0,1,&player->poke6);
                                                wclear(actions);
                                                box(actions,0,0);
                                                finishchoice=1;
                                                finishcandy=1;
                                                finish=1;
                                            }
                                            break;
                                        
                                        default:
                                            break;
                                        }

                                        break;

                                    default:
                                        break;
                                    }
                                    usleep(16667);
                                } 
                            }
                            break;
                        default:
                            break;
                        }

                        usleep(16667);
                        if (delwin(actions)==ERR)
                        {
                            system("killall -9 vlc >/dev/null 2>&1 &");
                            exit(53);
                        }
                    }
                    break;
                default:
                    break;
            }
            }

            else if (x==26)
            {
                switch (x)
                {
                case 17: // SLOT4
                    //inutile
                    break;

                case 57: // SLOT5
                    //inutile
                    break;

                case 97: // SLOT6
                    //inutile
                    break;
                default:
                    break;
                }
                break;
            }
            
            break;
        default:
            break;
        }

        usleep(16667);
        if(delwin(sac)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(5);
        }
        if(delwin(bag_array)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(6);
        }   
    }
    wclear(blackscreen);
    wrefresh(blackscreen);
        if (delwin(blackscreen)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(25);
        } 
}

void roadto_league(trainer* player){
    int quit=0,finish=0, ch=ERR;
    int l=103,c=70;

    int flowerx1  = 50 + rand()%((50+31+1)-50);
    int flowerx2  = 50 + rand()%((50+31+1)-50);
    int flowerx3  = 50 + rand()%((50+31+1)-50);
    int flowerx4  = 50 + rand()%((50+31+1)-50);
    int flowerx5  = 50 + rand()%((50+31+1)-50);
    int flowerx6  = 50 + rand()%((50+31+1)-50);
    int flowerx7  = 50 + rand()%((50+31+1)-50);
    int flowerx8  = 50 + rand()%((50+31+1)-50);
    int flowerx9  = 50 + rand()%((50+31+1)-50);
    int flowerx10 = 50 + rand()%((50+31+1)-50);

    int flowery1  = 118 + rand()%((118+142+1)-118);
    int flowery2  = 118 + rand()%((118+142+1)-118);
    int flowery3  = 118 + rand()%((118+142+1)-118);
    int flowery4  = 118 + rand()%((118+142+1)-118);
    int flowery5  = 118 + rand()%((118+142+1)-118);
    int flowery6  = 118 + rand()%((118+142+1)-118);
    int flowery7  = 118 + rand()%((118+142+1)-118);
    int flowery8  = 118 + rand()%((118+142+1)-118);
    int flowery9  = 118 + rand()%((118+142+1)-118);
    int flowery10 = 118 + rand()%((118+142+1)-118);

    while(finish==0)
    {
        WINDOW* road = newwin(200,400, 0, 0);
        WINDOW* cam= subwin(road,62,235,l,c);
        WINDOW* cadre= subwin(road,111,150,29,116);
        WINDOW* chute= subwin(road,10,150,139,116);
        WINDOW* limite_bas= subwin(road,1,150,110,116);
        WINDOW* limite_haut= subwin(road,1,150,84,116);
        WINDOW* blackscreen= newwin(62,235,0,0);

        box(cadre,0,0);
        box(chute,0,0);
        box(limite_bas,0,0);
        box(limite_haut,0,0);
        mvwin(cam,0,0);
        print_roadto_league(road);
        print_flowers(road,flowerx1,flowerx2,flowerx3,flowerx4,flowerx5,flowerx6,flowerx7,flowerx8,flowerx9,flowerx10,flowery1,flowery2,flowery3,flowery4,flowery5,flowery6,flowery7,flowery8,flowery9,flowery10);
        print_player(cam,player);
        physic_roadto_league(ch,&l,&c);

        //mvwprintw(road,flowerx1-34,flowery1-119,"@"); // position exacte pour la fleur 1 pour la cam (joueur dessus)

        ch=getch();

        switch (ch)
        {
        case 'e':
        case '\n':
        case '\r':
            if (l==103 && c<=74 && c>=68)  //  exit zone
            {
                finish=1;
                chargement();
            }

            if (l==13 && c>=66 && c<=74) // league door
            {
                chargement();
                league(player);
                flowerx1  = 50 + rand()%((50+31+1)-50);
                flowerx2  = 50 + rand()%((50+31+1)-50);
                flowerx3  = 50 + rand()%((50+31+1)-50);
                flowerx4  = 50 + rand()%((50+31+1)-50);
                flowerx5  = 50 + rand()%((50+31+1)-50);
                flowerx6  = 50 + rand()%((50+31+1)-50);
                flowerx7  = 50 + rand()%((50+31+1)-50);
                flowerx8  = 50 + rand()%((50+31+1)-50);
                flowerx9  = 50 + rand()%((50+31+1)-50);
                flowerx10 = 50 + rand()%((50+31+1)-50);
            
                flowery1  = 118 + rand()%((118+142+1)-118);
                flowery2  = 118 + rand()%((118+142+1)-118);
                flowery3  = 118 + rand()%((118+142+1)-118);
                flowery4  = 118 + rand()%((118+142+1)-118);
                flowery5  = 118 + rand()%((118+142+1)-118);
                flowery6  = 118 + rand()%((118+142+1)-118);
                flowery7  = 118 + rand()%((118+142+1)-118);
                flowery8  = 118 + rand()%((118+142+1)-118);
                flowery9  = 118 + rand()%((118+142+1)-118);
                flowery10 = 118 + rand()%((118+142+1)-118);
            }

            if (l==flowerx1-34 && c==flowery1-119 || c==flowery1-118 || c==flowery1-120) // grab flower1
            {
                flowerx1=0;
                flowery1=0; // make it disapear
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            else if (l==flowerx2-34 && c==flowery2-119 || c==flowery2-118 || c==flowery2-120) // grab flower2
            {
                flowerx2=0;
                flowery2=0; // make it disapear
            
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            else if (l==flowerx3-34 && c==flowery3-119 || c==flowery3-118 || c==flowery3-120) // grab flower3
            {
                flowerx3=0;
                flowery3=0; // make it disapear
            
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            else if (l==flowerx4-34 && c==flowery4-119 || c==flowery4-118 || c==flowery4-120) // grab flower4
            {
                flowerx4=0;
                flowery4=0; // make it disapear
            
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            else if (l==flowerx5-34 && c==flowery5-119 || c==flowery5-118 || c==flowery5-120) // grab flower5
            {
                flowerx5=0;
                flowery5=0; // make it disapear
            
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            else if (l==flowerx6-34 && c==flowery6-119 || c==flowery6-118 || c==flowery6-120) // grab flower6
            {
                flowerx6=0;
                flowery6=0; // make it disapear
            
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            else if (l==flowerx7-34 && c==flowery7-119 || c==flowery7-118 || c==flowery7-120) // grab flower7
            {
                flowerx7=0;
                flowery7=0; // make it disapear
            
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            else if (l==flowerx8-34 && c==flowery8-119 || c==flowery8-118 || c==flowery8-120) // grab flower8
            {
                flowerx8=0;
                flowery8=0; // make it disapear
            
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            else if (l==flowerx9-34 && c==flowery9-119 || c==flowery9-118 || c==flowery9-120) // grab flower9
            {
                flowerx9=0;
                flowery9=0; // make it disapear
            
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            else if (l==flowerx10-34 && c==flowery10-119 || c==flowery10-187 || c==flowery10-021) // grab flower10
            {
                flowerx10=0;
                flowery10=0; // make it disapear
            
                if (player->inventory[SLOT4].type==EMPTY)
                {
                    player->inventory[SLOT4].type=FLOWER;
                    sprintf(player->inventory[SLOT4].name,"flowers");
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT4].type==FLOWER)
                {
                    player->inventory[SLOT4].quant+=1;
                }
                else if (player->inventory[SLOT5].type==EMPTY)
                {
                    player->inventory[SLOT5].type=FLOWER;
                    sprintf(player->inventory[SLOT5].name,"flowers");
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT5].type==FLOWER)
                {
                    player->inventory[SLOT5].quant+=1;
                }
                else if (player->inventory[SLOT6].type==EMPTY)
                {
                    player->inventory[SLOT6].type=FLOWER;
                    sprintf(player->inventory[SLOT6].name,"flowers");
                    player->inventory[SLOT6].quant+=1;
                }
                else if (player->inventory[SLOT6].type==FLOWER)
                {
                    player->inventory[SLOT6].quant+=1;
                }
                else 
                {
                    write_flush(cam,((63-2)/2)+1,((236-2)/2)+6,"You don't have enough space in your inventory");   
                    sleep(1);             
                }
            }

            if (l==76)  // border water down 
            {
                if (player->poke1.CTutil->type==SURF && player->poke1.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke1.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke2.CTutil->type==SURF && player->poke2.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke2.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke3.CTutil->type==SURF && player->poke3.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke3.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke4.CTutil->type==SURF && player->poke4.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke4.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke5.CTutil->type==SURF && player->poke5.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke5.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else if (player->poke6.CTutil->type==SURF && player->poke6.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke6.name);
                    wrefresh(cam);
                    sleep(1);
                    l-=2;
                    player->is_on_water=1;
                }

                else
                {
                    write_flush(cam,((63-2)/2)-1,((236-2)/2)+5,"None of your pokemon have surf !");
                    sleep(1);
                }
            }

            else if (l==74)  // border water down 
            {
                l+=2;
                player->is_on_water=0;
            }

            if (l==50) // border water up
            {
                l-=2;
                player->is_on_water=0;
            }
            
            else if (l==48) // border water up
            {
                if (player->poke1.CTutil->type=SURF && player->poke1.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke1.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke2.CTutil->type=SURF && player->poke2.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke2.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke3.CTutil->type=SURF && player->poke3.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke3.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke4.CTutil->type=SURF && player->poke4.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke4.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke5.CTutil->type=SURF && player->poke5.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke5.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else if (player->poke6.CTutil->type=SURF && player->poke6.type==WATER)
                {
                    mvwprintw(cam,((63-2)/2)-1,((236-2)/2)+5,"%s uses surf !",player->poke6.name);
                    wrefresh(cam);
                    sleep(1);
                    l+=2;
                    player->is_on_water=1;
                }

                else
                {
                    write_flush(cam,((63-2)/2)-1,((236-2)/2)+5,"None of your pokemon have surf !");
                    sleep(1);
                }
            }
            break;
        
        case 'm':
            menu(&quit,player);
            break;

        case 'i':
            inventory(player);
            break;

        default:
            break;
        }

        wrefresh(cam);

        usleep(16667);
        if(delwin(cam)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(15);
        }
        if(delwin(cadre)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(16);
        }
        if(delwin(chute)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(21);
        }
        if(delwin(limite_bas)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(22);
        }
        if(delwin(limite_haut)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(23);
        }
        if(delwin(road)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(17);
        }
        if(delwin(blackscreen)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(18);
        }
    }
}

void main_menu(trainer* player,int* quit,int* x, int* y){
    WINDOW* win=newwin(62,235,0,0);
    WINDOW* blackscreen=newwin(62,235,0,0);
    int ch=ERR;

    pokemon pokenull, charmander, bulbasaur, squirtle, pikachu, charizard,blastoise,venusaur,raichu;
    init_poke(&pokenull,&charmander,&bulbasaur,&squirtle,&pikachu,&charizard,&blastoise,&venusaur,&raichu);
    
    ch=getch();
    print_main_menu(win,*x,*y);

    wclear(blackscreen);
    wrefresh(blackscreen);
    wrefresh(win);
    switch (ch)
    {
        // colisions
    case 'z':
    case KEY_UP:
        if (*x==38)
        {
            *x=28;
        }
        
        break;

    case 's':
    case KEY_DOWN:
        if (*x==28)
        {
            *x=38;
        }
        break; 

        // actions
    case 'e' :
    case '\n' :
    case '\r' :
        switch (*x)
        {
        case 28:
            create_newplayer(player);
            get_firstpoke(player);
            *quit=1;
            chargement();
            break;

        case 38:
            if (load(player)==1)
            {
                *quit=1;
                chargement();
            }
            break;
        
        default:
            break;
        }
        break;  
    
    default:
        break;
    }
    usleep(16667);
    if(delwin(win)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(7);
    }
    if(delwin(blackscreen)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(7);
    }
}

void game(trainer* player, int* quit,int* l,int* c){
    int ch=ERR;int i;int j;
    WINDOW* map = newwin(170,500, 0, 0);
    WINDOW* cadre= subwin(map,111, 266, 29,116);      //cadre = map réelle : origine sur map (29;116), dimensions (111;268)
    WINDOW* cam=subwin(map,62,235,*l,*c);
    box(cadre,0,0);                                   //repérage : x_map = x_cadre + 29      y_map = y_cadre + 116

    mvwin(cam,0,0);
    create_map(map,player);
    print_player(cam,player); 
    wrefresh(cam); 

    ch=getch();

    physic_map(ch,l,c,player); // colisions
    switch (ch) // actions
    {
        case 'e':
        case '\r':
        case '\n':
            if (*l==10 && *c<=28 && *c>=24) // house area
            {
                chargement();
                house(player);
            }  

            if (*l==50 && *c>=14 && *c<=18) // shop area
            {
                chargement();
                shop(player);
            } 

            if (*l==10 && *c>=238 && *c<=242) // lab area
            {
                chargement();
                lab(player);
            }

            if (*c==0 && *l>=70 && *l<=76) // road to league area
            {
                chargement();
                roadto_league(player);
            }

            if (player->is_rock_there==1) // TRUE
            {
                if (*c>=248 && *l>=23 && *l<=26) // rock area
                {
                    cinematique_rock(map,cam,player);
                }
            }
            else
            {
                if (*c==256 && *l>=20 && *l<=26) // forest area
                {
                    chargement();
                    forest(player); 
                }
            }

            break;

        case 'm':
            menu(quit,player);
            break;

        case 'i':
            inventory(player);
            break;  

        default:
            break;
    }                       
    usleep(16667);

    if(delwin(cam)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(8);
    }
    if(delwin(cadre)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(9);
    }
    if(delwin(map)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(10);
    }
}
void clignotement(WINDOW* fenetre){
    int count=0;

    WINDOW* fenetre_backup = newwin(63,211,0,12);
    for(count=0;count<3;count++){
        copywin(fenetre,fenetre_backup,0,0,0,0,62,210,FALSE);
        wrefresh(fenetre_backup);
        usleep(300000);
        wclear(fenetre_backup);
        wrefresh(fenetre_backup);
        usleep(300000);
    }
     if(delwin(fenetre_backup)==ERR)
    {
        system("killall -9 vlc >/dev/null 2>&1 &");
        exit(103);
    }
}
void duel_forest(trainer * player,pokemon wild_poke){
    
    int count_atk=1;

    system("killall -9 vlc >/dev/null 2>&1 &"); // stop main theme
    usleep(1000);
    system("cvlc ressources/Battle-Theme.mp3 >/dev/null 2>&1 &"); // start battle theme

    if(player->poke1.pv>0 && player->poke2.pv>0 && player->poke3.pv>0){
        if(match(player,&player->poke1,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else if(match(player,&player->poke2,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else if(match(player,&player->poke3,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else{
            //defeat
        }
    }
    else if(player->poke1.pv==0 && player->poke2.pv>0 && player->poke3.pv>0){
        if(match(player,&player->poke2,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else if(match(player,&player->poke3,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else{
            //defeat
        }
    }
    else if(player->poke1.pv>0 && player->poke2.pv==0 && player->poke3.pv>0){
        if(match(player,&player->poke1,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else if(match(player,&player->poke3,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else{
            //defeat
        }
    }
    else if(player->poke1.pv>0 && player->poke2.pv>0 && player->poke3.pv==0){
        if(match(player,&player->poke1,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else if(match(player,&player->poke2,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else{
            //defeat
        }
    }
    else if(player->poke1.pv==0 && player->poke2.pv==0 && player->poke3.pv>0)
    {
        if(match(player,&player->poke3,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else{
            //defeat
        }
    }
    else if(player->poke1.pv>0 && player->poke2.pv==0 && player->poke3.pv==0)
    {
        if(match(player,&player->poke1,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else{
            //defeat
        }
    }
    else if(player->poke1.pv==0 && player->poke2.pv>0 && player->poke3.pv==0)
    {
        if(match(player,&player->poke2,&wild_poke,1,&count_atk)==1){
            //victory
        }
        else{
            //defeat
        }
    }

    system("killall -9 vlc >/dev/null 2>&1 &"); // stop battle theme
    usleep(1000);
    system("cvlc ressources/Main-Theme.mp3 >/dev/null 2>&1 &"); // restart main theme
}

// V1.0
void save(trainer* player){

    FILE* save1 = NULL;
    FILE* save2 = NULL;
    FILE* save3 = NULL;
    FILE* save4 = NULL;
    FILE* save5 = NULL;

    FILE* save1r = NULL;
    FILE* save2r = NULL;
    FILE* save3r = NULL;
    FILE* save4r = NULL;
    FILE* save5r = NULL;

    save1r=fopen("saves/save1","rb");
    save2r=fopen("saves/save2","rb");
    save3r=fopen("saves/save3","rb");
    save4r=fopen("saves/save4","rb");
    save5r=fopen("saves/save5","rb");

    if (save1r == NULL)
    {
        exit(100);
    }
    if (save2r == NULL)
    {
        exit(101);
    }
    if (save3r == NULL)
    {
        exit(102);
    }
    if (save4r == NULL)
    {
        exit(103);
    }
    if (save5r == NULL)
    {
        exit(104);
    }

    int ch=ERR,finish=0;
    int x=29;

    while (finish==0)
    {
        WINDOW* save_win=newwin(62,235,0,0);
        print_save(save_win,save1r,save2r,save3r,save4r,save5r,x);
        wrefresh(save_win);

        ch=getch();
        switch (ch)
        {
        case ' ':
            wclear(save_win);
            wrefresh(save_win);
            finish=1;
            break;

        case 'z':
        case KEY_UP:
            if (x!=29)
            {
                x-=2;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (x!=37)
            {
                x+=2;
            }  
            break;

        case 'e': // save
        case '\r':
        case '\n':
            switch (x)
            {
            case 29: // save 1
                fclose(save1r);
                save1=fopen("saves/save1","wb+"); // delete content 
                if (save1 == NULL)
                {
                    exit(105);
                }
                if(fwrite(player,sizeof(trainer),1,save1)!=1)
                {
                    exit(150);
                }
                mvwprintw(save_win,29,100,"Saved successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                finish=1;
                fclose(save1);
                fclose(save2r);
                fclose(save3r);
                fclose(save4r);
                fclose(save5r);
                break;
            
            case 31: // save 2
                fclose(save2r);
                save2=fopen("saves/save2","wb+");  // delete content 
                if (save2 == NULL)
                {
                    exit(106);
                }
                if(fwrite(player,sizeof(trainer),1,save2)!=1)
                {
                    exit(150);
                }
                mvwprintw(save_win,31,100,"Saved successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                finish=1;
                fclose(save2);
                fclose(save1r);
                fclose(save3r);
                fclose(save4r);
                fclose(save5r);
                break;
            
            case 33: // save 3
                fclose(save3r);
                save3=fopen("saves/save3","wb+");  // delete content 
                if (save3 == NULL)
                {
                    exit(107);
                }
                if(fwrite(player,sizeof(trainer),1,save3)!=1)
                {
                    exit(150);
                }
                mvwprintw(save_win,33,100,"Saved successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                finish=1;
                fclose(save3);
                fclose(save1r);
                fclose(save2r);
                fclose(save4r);
                fclose(save5r);
                break;
            
            case 35: // save 4
                fclose(save4r);
                save4=fopen("saves/save4","wb+");  // delete content 
                if (save4 == NULL)
                {
                    exit(108);
                }
                if(fwrite(player,sizeof(trainer),1,save4)!=1)
                {
                    exit(150);
                }
                mvwprintw(save_win,35,100,"Saved successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                finish=1;
                fclose(save4);
                fclose(save1r);
                fclose(save2r);
                fclose(save3r);
                fclose(save5r);
                break;
            
            case 37: // save 5
                fclose(save5r);
                save5=fopen("saves/save5","wb+");  // delete content 
                if (save5 == NULL)
                {
                    exit(109);
                }
                if(fwrite(player,sizeof(trainer),1,save5)!=1)
                {
                    exit(150);
                }
                mvwprintw(save_win,37,100,"Saved successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                fclose(save5);
                finish=1;
                fclose(save1r);
                fclose(save2r);
                fclose(save3r);
                fclose(save4r);
                break;
            
            default:
                break;
            }
            break;

        case 'x': // delete a save
            switch (x)
            {
            case 29: // save 1
                fclose(save1r);
                save1=fopen("saves/save1","wb+"); // delete content 
                if (save1 == NULL)
                {
                    exit(105);
                }
                mvwprintw(save_win,29,100,"Removed successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                finish=1;
                fclose(save1);
                fclose(save2r);
                fclose(save3r);
                fclose(save4r);
                fclose(save5r);
                break;
            
            case 31: // save 2
                fclose(save2r);
                save2=fopen("saves/save2","wb+");  // delete content 
                if (save2 == NULL)
                {
                    exit(106);
                }
                mvwprintw(save_win,31,100,"Removed successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                finish=1;
                fclose(save2);
                fclose(save1r);
                fclose(save3r);
                fclose(save4r);
                fclose(save5r);
                break;
            
            case 33: // save 3
                fclose(save3r);
                save3=fopen("saves/save3","wb+");  // delete content 
                if (save3 == NULL)
                {
                    exit(107);
                }
                mvwprintw(save_win,33,100,"Removed successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                finish=1;
                fclose(save3);
                fclose(save1r);
                fclose(save2r);
                fclose(save4r);
                fclose(save5r);
                break;
            
            case 35: // save 4
                fclose(save4r);
                save4=fopen("saves/save4","wb+");  // delete content 
                if (save4 == NULL)
                {
                    exit(108);
                }
                mvwprintw(save_win,35,100,"Removed successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                finish=1;
                fclose(save4);
                fclose(save1r);
                fclose(save2r);
                fclose(save3r);
                fclose(save5r);
                break;
            
            case 37: // save 5
                fclose(save5r);
                save5=fopen("saves/save5","wb+");  // delete content 
                if (save5 == NULL)
                {
                    exit(109);
                }
                mvwprintw(save_win,37,100,"Removed successfully !");
                wrefresh(save_win);
                sleep(2);
                wclear(save_win);
                wrefresh(save_win);
                fclose(save5);
                finish=1;
                fclose(save1r);
                fclose(save2r);
                fclose(save3r);
                fclose(save4r);
                break;
            
            default:
                break;
            }
        
        default:
            break;
        }

        usleep(16667);
        if (delwin(save_win)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(50);
        }
    }
}

// V1.0
int load(trainer* player){

    FILE* save1r = NULL;
    FILE* save2r = NULL;
    FILE* save3r = NULL;
    FILE* save4r = NULL;
    FILE* save5r = NULL;

    save1r=fopen("saves/save1","rb");
    save2r=fopen("saves/save2","rb");
    save3r=fopen("saves/save3","rb");
    save4r=fopen("saves/save4","rb");
    save5r=fopen("saves/save5","rb");

    if (save1r == NULL)
    {
        exit(100);
    }
    if (save2r == NULL)
    {
        exit(101);
    }
    if (save3r == NULL)
    {
        exit(102);
    }
    if (save4r == NULL)
    {
        exit(103);
    }
    if (save5r == NULL)
    {
        exit(104);
    }

    int ch=ERR,finish=0;
    int x=29;

    while (finish==0)
    {
        WINDOW* load_win=newwin(62,235,0,0);
        print_load(load_win,save1r,save2r,save3r,save4r,save5r,x);
        wrefresh(load_win);

        ch=getch();
        switch (ch)
        {
        case ' ':
            wclear(load_win);
            wrefresh(load_win);
            finish=1; 
            return 0;  
            break;

        case 'z':
        case KEY_UP:
            if (x!=29)
            {
                x-=2;
            }
            break;

        case 's':
        case KEY_DOWN:
            if (x!=37)
            {
                x+=2;
            }  
            break;

        case 'e': // save
        case '\r':
        case '\n':
            switch (x)
            {
            case 29: // save 1
                fseek(save1r,0,SEEK_END);
                if(ftell(save1r)==0)
                {
                    mvwprintw(load_win,29,100,"No save data found in this file");
                    wrefresh(load_win);
                    sleep(2);
                }
                else
                {
                    rewind(save1r);
                    fread(player,sizeof(trainer),1,save1r);
                    mvwprintw(load_win,29,100,"Loaded successfully !");
                    wrefresh(load_win);
                    sleep(2);
                    wclear(load_win);
                    wrefresh(load_win);
                    finish=1;
                    fclose(save1r);
                    fclose(save2r);
                    fclose(save3r);
                    fclose(save4r);
                    fclose(save5r);
                    return 1;
                }
                break;
            
            case 31: // save 2
                fseek(save2r,0,SEEK_END);
                if(ftell(save2r)==0)
                {
                    mvwprintw(load_win,29,100,"No save data found in this file");
                    wrefresh(load_win);
                    sleep(2);
                }
                else
                {
                    rewind(save2r);
                    fread(player,sizeof(trainer),1,save2r);
                    mvwprintw(load_win,29,100,"Loaded successfully !");
                    wrefresh(load_win);
                    sleep(2);
                    wclear(load_win);
                    wrefresh(load_win);
                    finish=1;
                    fclose(save1r);
                    fclose(save2r);
                    fclose(save3r);
                    fclose(save4r);
                    fclose(save5r);
                    return 1;
                }
                break;
            
            case 33: // save 3
                fseek(save3r,0,SEEK_END);
                if(ftell(save3r)==0)
                {
                    mvwprintw(load_win,29,100,"No save data found in this file");
                    wrefresh(load_win);
                    sleep(2);
                }
                else
                {
                    rewind(save3r);
                    fread(player,sizeof(trainer),1,save3r);
                    mvwprintw(load_win,29,100,"Loaded successfully !");
                    wrefresh(load_win);
                    sleep(2);
                    wclear(load_win);
                    wrefresh(load_win);
                    finish=1;
                    fclose(save1r);
                    fclose(save2r);
                    fclose(save3r);
                    fclose(save4r);
                    fclose(save5r);
                    return 1;
                }
                break;
            
            case 35: // save 4
                fseek(save4r,0,SEEK_END);
                if(ftell(save4r)==0)
                {
                    mvwprintw(load_win,29,100,"No save data found in this file");
                    wrefresh(load_win);
                    sleep(2);
                }
                else
                {
                    rewind(save4r);
                    fread(player,sizeof(trainer),1,save4r);
                    mvwprintw(load_win,29,100,"Loaded successfully !");
                    wrefresh(load_win);
                    sleep(2);
                    wclear(load_win);
                    wrefresh(load_win);
                    finish=1;
                    fclose(save1r);
                    fclose(save2r);
                    fclose(save3r);
                    fclose(save4r);
                    fclose(save5r);
                    return 1;
                }
                break;
            
            case 37: // save 5
                fseek(save5r,0,SEEK_END);
                if(ftell(save5r)==0)
                {
                    mvwprintw(load_win,29,100,"No save data found in this file");
                    wrefresh(load_win);
                    sleep(2);
                }
                else
                {
                    rewind(save5r);
                    fread(player,sizeof(trainer),1,save5r);
                    mvwprintw(load_win,29,100,"Loaded successfully !");
                    wrefresh(load_win);
                    sleep(2);
                    wclear(load_win);
                    wrefresh(load_win);
                    finish=1;
                    fclose(save1r);
                    fclose(save2r);
                    fclose(save3r);
                    fclose(save4r);
                    fclose(save5r);
                    return 1;
                }
                break;
            
            default:
                break;
            }
            break;

        case 'x': // delete a save
            switch (x)
            {
            case 29: // save 1
                save1r=fopen("saves/save1","wb+"); // delete content 
                if (save1r == NULL)
                {
                    exit(105);
                }
                mvwprintw(load_win,29,100,"Removed successfully !");
                wrefresh(load_win);
                sleep(2);
                print_load(load_win,save1r,save2r,save3r,save4r,save5r,x);
                wrefresh(load_win);
                break;
            
            case 31: // save 2
                save2r=fopen("saves/save2","wb+");  // delete content 
                if (save2r == NULL)
                {
                    exit(106);
                }
                mvwprintw(load_win,31,100,"Removed successfully !");
                wrefresh(load_win);
                sleep(2);
                print_load(load_win,save1r,save2r,save3r,save4r,save5r,x);
                wrefresh(load_win);
                break;
            
            case 33: // save 3
                save3r=fopen("saves/save3","wb+");  // delete content 
                if (save3r == NULL)
                {
                    exit(107);
                }
                mvwprintw(load_win,33,100,"Removed successfully !");
                wrefresh(load_win);
                sleep(2);
                print_load(load_win,save1r,save2r,save3r,save4r,save5r,x);
                wrefresh(load_win);
                break;
            
            case 35: // save 4
                save4r=fopen("saves/save4","wb+");  // delete content 
                if (save4r == NULL)
                {
                    exit(108);
                }
                mvwprintw(load_win,35,100,"Removed successfully !");
                wrefresh(load_win);
                sleep(2);
                print_load(load_win,save1r,save2r,save3r,save4r,save5r,x);
                wrefresh(load_win);
                break;
            
            case 37: // save 5
                save5r=fopen("saves/save5","wb+");  // delete content 
                if (save5r == NULL)
                {
                    exit(109);
                }
                mvwprintw(load_win,37,100,"Removed successfully !");
                wrefresh(load_win);
                sleep(2);
                print_load(load_win,save1r,save2r,save3r,save4r,save5r,x);
                wrefresh(load_win);
                break;
            
            default:
                break;
            }
        
        default:
            break;
        }

        usleep(16667);
        if (delwin(load_win)==ERR)
        {
            system("killall -9 vlc >/dev/null 2>&1 &");
            exit(50);
        }
    }    
}