#include "personnages.h"


struct zombie GetZombie(int id)
{
    if (id == 1)
    {
        struct zombie bucheron;
        strcpy(bucheron.name, "bucheron");
        bucheron.pv = 10 ;
        bucheron.force = 12;
        bucheron.defense = 10;
        bucheron.rapidite = 2;
        return bucheron;

    }
    else if (id == 2)
    {
        struct zombie enfant;
        strcpy(enfant.name, "enfant");
        enfant.pv = 7;
        enfant.force = 10;
        enfant.defense = 10;
        enfant.rapidite = 4;
        return enfant;
    }


    else if (id == 3)
    {
        struct zombie boss;
        strcpy(boss.name, "chef-zombie");
        boss.pv = 50;
        boss.force = 50;
        boss.defense = 50;
        return boss;
    }
}

//en fonction de l'avancé du jeu, augmente la force des zombies
int forceZombie (fZombie, carte)
{
    int result;
    if (carte == 0)
    {
        result = fZombie;
        return result;
    }
    if (carte == 1)
    {
        result = fZombie + 3;
        return result;
    }
    if (carte == 3)
    {
        result = fZombie + 12;
        return result;
    }
}

//en fonction de l'avancé du jeu, augmente la defense des zombies
 int defenseZombie (dZombie, carte)
 {
     int result;
     if (carte == 0)
     {
         result = dZombie;
         return result;
     }
     if (carte == 1)
     {
         result = dZombie + 3;
         return result;
     }
     if (carte == 3)
     {
         result = dZombie + 12;
         return result;
     }
 }
