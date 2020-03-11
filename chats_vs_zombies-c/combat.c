#include "zombie.h"
#include "personnages.h"
//definit quel zombie on croise
int aleaZombie()
{
    int al = rand()%2;
    int num = al + 1;
    return num;
}
//fonction combat, beaucoup trop longe, pas eu le temps de nettoyer ça... desole si c'est illisible ;)
void combat(struct personnage* j,struct chat* p, int carte, int  *inventaire, int numzomb, struct chat* po)
{
    int a = numzomb;
    struct zombie z = GetZombie(a);
    char choix[10];
    int vieZombie = z.pv;
    int forZombie = z.force;
    int forceZomb = forceZombie(forZombie, carte);
    int defZombie = z.defense;
    int defenseZomb = defenseZombie(defZombie, carte);
    int forceChat = (*p).force;

    int shampoing = 0;
    int dArme = (*po).force;



    if (a != 3)
    {
        printf("Tu viens de croiser un zombie %s! \n", z.name);
        printf("Son niveau de force est de %d \n",forceZomb);
        printf("Son niveau de defense est de %d \n",defenseZomb);
        printf("Veux tu combattre?\n");
        printf("o/n");
        scanf("%s",&choix);
    }
    if ( a == 3)
    {
        printf("Tu viens de croiser le chef-Zombie !! \n");
        printf("Tu n'as encore jamais croiser de zombie aussi fort! \n");
        printf("J espere que tu es pret car tu ne peux plus reculer\n");
        choix[0]= 'o';
        char commencer[10];
        printf("appuies sur n importe quelle touche pour commencer\n");
        scanf("%s",&commencer);
    }



    if(choix[0] == 'o')
    {
        //int joueur = (*j).pv;
        //int z = (*b).pv;
        while((*j).pv > 0 && vieZombie > 0)
        {
            if (dArme != 0)
            {
                char chat[10];

                printf("Quel chat veux tu utiliser?\n");
                printf("1- %s \n", (*p).name);
                printf("2- Poilu\n");
                scanf("%s", &chat);


                if (chat[0] == '1')
                {
                    forceChat = (*p).force;
                }
                if (chat[0] == '2')
                {
                    forceChat = (*po).force;
                }

            }
            char attaque[10];
            char attzombie[10];
            printf("c'est a toi d'attaquer\n");
            printf("Que veux tu faire?\n");
            printf("- attaquer? a\n");
            printf("- inventaire? i\n");
            scanf("%s",&attaque);
            while(attaque[0] == 'i')
            {
                printInventaire(inventaire);
                printf("Que veux tu utiliser?");
                char choixPotion[10];
                scanf("%s", &choixPotion);
                if(choixPotion[0] == '1')
                {
                    if(inventaire[0]<1)
                    {
                        printf("Tu n as pas cet objet\n");
                        printf("Consulte l inventaire pour voir tes objets\n");
                    }
                    if(inventaire[0]>=1)
                    {
                        if(carte <= 2)
                        {
                            printf("Tu ne sais pas encore utiliser cet objet");
                            scanf("%s", &choixPotion);
                        }
                        if (carte > 2)
                        {
                            shampoing = 1;
                            printf("Les poils de ton chat sont enduit de shampoing, tu es pret a lancer l attaque allergene\n");
                            inventaire[0] -= 1;
                        }
                    }


                }
                if(choixPotion[0] == '2')
                {
                     if(inventaire[1]<1)
                    {
                        printf("Tu n as pas cet objet\n");
                        printf("Consulte l inventaire pour voir tes objets\n");
                    }
                    if (inventaire[1]>= 1)
                    {
                         (*j).pv += 5;
                        printf("Tes points de vie ont augmenté de 5");
                        inventaire[1] -= 1;
                    }


                }
                if(choixPotion[0] == '3') //3 correspond a une bouteille de lait. ses effets : donne 5 pt de force supplémentaire pour la durée du combat
                {
                     if(inventaire[2]<1)
                    {
                        printf("Tu n as pas cet objet\n");
                        printf("Consulte l inventaire pour voir tes objets\n");
                    }
                    if(inventaire[2]>=1)
                    {
                        forceChat += 5;
                        printf("tes point de force sont maintenant de : %d \n",forceChat);
                        inventaire[2] -= 1;
                    }

                    //printf("force de base = %d \n",(*p).force);
                }

                printf("c'est a toi d'attaquer\n");
                printf("Que veux tu faire?\n");
                printf("- attaquer? a\n");
                printf("- inventaire? i\n");
                scanf("%s",&attaque);

            }


            if(attaque[0] == 'a')
            {
                if(shampoing == 1)
                {
                    int allergene;
                    printf("Quelle attaque veux tu utiliser?\n");
                    printf("-allergene press s\n");
                    printf("-classique autre lettre\n");
                    scanf("%s", &allergene);

                    if(allergene == 's')
                    {
                        printf("Tu viens d utiliser allergene...\n");
                        int forceAttaque = aleatoireAttaque(forceChat);
                        if ((forceAttaque*2) > (defenseZomb/2))
                            {
                                vieZombie -= ((forceAttaque*2) -(defenseZomb/2));
                                printf("Cette attaque est deux fois plus puissante que celle que tu utilise habituellement\n");

                            }
                            if ((forceAttaque*2) <= (defenseZomb/2))
                            {
                                printf("Ton attaque est trop faible par rapport a sa defense\n");
                            }
                        //int vz = vieZombie;
                        printf("Les PV du zombie : ");
                        vie(vieZombie);

                    }

                    if(allergene != 's')
                    {
                        int forceAttaque = aleatoireAttaque(forceChat);
                        int forceAttaqueFinale = attaqueDouble(forceAttaque);
                        if (attaqueDouble != 0)
                        {
                            if (forceAttaqueFinale > (defenseZomb/2))
                            {
                                vieZombie -= (forceAttaqueFinale -(defenseZomb/2));
                                printf("la force de l'attaque est de %d\n", forceAttaqueFinale);
                            }
                            if (forceAttaqueFinale <= (defenseZomb/2))
                            {
                                printf("Ton attaque est trop faible par rapport a sa defense\n");
                            }

                            //int vz = vieZombie;
                            printf("Les PV du zombie : ");
                            vie(vieZombie);

                        }
                    }

                }
                if (shampoing == 0)
                {
                    int forceAttaque = aleatoireAttaque(forceChat);
                    int forceAttaqueFinale = attaqueDouble(forceAttaque);
                    if (attaqueDouble != 0)
                    {
                        if (forceAttaqueFinale > (defenseZomb/2))
                            {
                                vieZombie -= (forceAttaqueFinale -(defenseZomb/2));
                                printf("la force de l'attaque est de %d\n", forceAttaqueFinale);
                            }
                            if (forceAttaqueFinale <= (defenseZomb/2))
                            {
                                printf("Ton attaque est trop faible par rapport a sa defense\n");
                            }

                            printf("Les PV du zombie : ");
                            vie(vieZombie);

                    }
                }
                shampoing = 0;



            }

            if(vieZombie > 0)
            {
                printf("Le zombie va attaquer \n");
                printf("es tu pret? y\n");
                scanf("%s", &attzombie);
                while(attzombie[0] != 'y')
                {
                    printf("Le zombie va attaquer \n");
                    printf("es tu pret? y\n");
                    scanf("%s", &attzombie);
                }
                if(attzombie[0] == 'y')
                {
                    int forceAttaque = aleatoireAttaque(forceZomb);
                    (*j).pv -= (forceAttaque -((*p).defense/2));
                    int v = (*j).pv;
                    printf("Le zombie a attaque \n");
                    printf("Tes PV restant : ");
                    vie(v);
                }
            }

        if ((*j).pv <= 0)
        {
            printf("Tu as perdu\n");
            menu();

        }

        if (vieZombie <= 0)
        {

            char continuer;
            int ajoutForce = forceZomb/10;
            int ajoutDefense = defenseZomb/10;
            printf("test : ajoutForce = %d , ajoutDefense = %d \n", ajoutForce, ajoutDefense);
            (*p).force += ajoutForce;
            (*p).defense += ajoutDefense;
            if( dArme != 0)
            {
                (*po).force += ajoutForce;
                (*po).defense += ajoutDefense;
            }

            printf("Tu as gagne!\n");
            inventaire[3] += ajoutForce;
            printf("Tu as gagné %d pieces\n", ajoutForce);

            printf("Continuer?\n");
            scanf("%s",&continuer);


        }

        }

    }


}


//defini si l'attaque est double ou rate ou normal
int attaqueDouble(force)
{
    int result;
    int aleaAttaque = rand()%8;
    if(aleaAttaque == 2)
    {
        printf("L'attaque a echoue...\n");
        result = 0;
        return result;
    }
    if(aleaAttaque == 4 || aleaAttaque == 5)
    {
        printf("Bien joue! Cette attaque est doublee!\n");
        result = (force * 2);
        return result;
    }
    if(aleaAttaque != 2 && aleaAttaque != 4 && aleaAttaque != 5)
    {
        result = force;
        return result;
    }

}



int aleatoireAttaque(force) // l'attaque peut varier de 60 à 90% de la force de l'attaquant
{
    float result;
    int aleaForce = rand()%4;
    if (aleaForce == 0)
    {
        result = (force * 60)/100;
        int r = (int)result;
        return r;
    }
    if (aleaForce == 1)
    {
        result = (force * 70)/100;
        int r = (int)result;
        return r;

    }
    if (aleaForce == 2)
    {
        result = (force * 80)/100;
        int r = (int)result;
        return r;
    }
    if(aleaForce == 3)
    {
        result = (force * 90/100);
        int r = (int)result;
        return r;
    }

}
