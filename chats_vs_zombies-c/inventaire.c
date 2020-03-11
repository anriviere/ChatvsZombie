#include "personnages.h"
#include "fonction.h"

const char numInventaire[5][5] = {"1-", "2-", "3-" ,"4-"};
const char inventaireNom[5][15] = {"shampoing", "cidre" , "lait" , "monnaie" , "velo", "voiture"};
//pour afficher l'inventaire
void printInventaire(int *inventaire)
{
    printf("-----------------------------------------------------------------------------------\n");
    printf("                                    INVENTAIRE                                     \n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("\n");
    for(int i=0; i<4; i++)
    {
        if( inventaire[i] != 0)
        {
           printf("%s %s : %d\n",numInventaire[i], inventaireNom[i], inventaire[i]);
        }

    }
    printf("\n");
    printf("Tes vehicules disponibles: \n");

    for(int i=4; i<6; i++)
    {
        if( inventaire[i] != 0)
        {
           printf("%s : %d\n",inventaireNom[i], inventaire[i]);
        }

    }
    printf("\n");
    printf("\n");
    printf("Appuie sur h pour l aide, n importe quelle autre lettre pour sortir de l inventaire\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------\n");

    char aide[10];
    scanf("%s",aide);
    if(aide[0] == 'h')
    {
        aideInventaire(inventaire);
    }


}


//affiche les explications des objets
void aideInventaire(inventaire)
{
    printf("-----------------------------------------------------------------------------------\n");
    printf("                                   AIDE INVENTAIRE                                 \n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("\n");
    printf("cidre : te redonne 5 PV,  prix : 3 pieces\n");
    printf("lait : augmente l'attaque de ton chat\n");
    printf("shampoing : Tu n es pas pret petit\n");
    printf("monnaie : Au village tu trouveras differentes boutiques\n");
    printf("\n");
    printf("\n");
    printf("velo : te permet de te deplacer 3 fois plus vite\n");
    printf("voiture : te permet de te deplacer 5 fois plus vite\n");
    printf("tape sur n importe quelle lettre pour revenir en arrière\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("-----------------------------------------------------------------------------------\n");

    char retour[10];
    scanf("%s",retour);
    printInventaire(inventaire);
}

//dans village, choix de la boutique ou on veut aller
void boutiques(int *inventaire)
{
    printf("\n");
    printf("_________________________________________________________________________________\n");
    printf("                       Bienvenue aux boutiques du village!!                      \n");
    printf("_________________________________________________________________________________\n");
    printf("\n");
    printf("Ou veux tu te rendre?\n");
    printf("1- A TATI\n");
    printf("2- Au magasin de vehicule\n");
    printf("3- A l animalerie\n");
    printf("\n");
    printf("4-Retour\n");
    printf("\n");
    printf("\n");
    printf("_________________________________________________________________________________\n");

    char choix[10];
    scanf("%s", &choix);

    if(choix[0] == '1')
    {
        tati(inventaire);

    }
    if (choix[0] == '2')
    {
        vehicules(inventaire);
    }
    if(choix[0] == '3')
    {

        animalerie(inventaire);

    }
    if(choix[0] != '1' && choix[0] != '2' && choix[0] != '3' && choix[0] != '4')
    {
        boutiques(inventaire);
    }

}

//boutique de vehicule
void vehicules(int *inventaire)
{
    printf("_________________________________________________________________________________\n");
    printf("                       Bienvenue au magasin de vehicules                         \n");
    printf("_________________________________________________________________________________\n");
    printf("\n");
    printf("Quel type de vehicule desirez vous?\n");
    printf("1-Velo     -100 pieces\n");
    printf("2-Voiture  -1000 pieces\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("_________________________________________________________________________________\n");
    printf("_________________________________________________________________________________\n");
    char choix[10];
    scanf("%s", &choix);
    if (choix[0] == '1')
    {
        if(inventaire[3] >= 100)
        {
            inventaire[4]+=1;
            inventaire[3]-=100;
            printf("Tu viens d aquerir un velo\n");
        }
        else if(inventaire[3] < 100)
        {
            printf("Tu n'as pas assez de monnaie pour acheter cet objet\n");
        }
    }
    if (choix[0] == '2')
    {
        if(inventaire[3] >= 1000)
        {
            inventaire[5]+=1;
            inventaire[3]-=1000;
            printf("Tu viens d aquerir une voiture\n");
        }
        else if(inventaire[3] < 1000)
        {
            printf("Tu n'as pas assez de monnaie pour acheter cet objet\n");
        }
    }
    char continuer[10];
    scanf("%s", &continuer);
    if(continuer[0] == 'c')
    {
        vehicules(inventaire);
    }
    if(continuer[0] != 'c')
    {
        boutiques(inventaire);
    }

}

void tati(int *inventaire)
{
    printf("\n");
    printf("_________________________________________________________________________________\n");
    printf("                                Bienvenue chez TATI!!                            \n");
    printf("_________________________________________________________________________________\n");
    printf("\n");
    printf("Que veux tu acheter?\n");
    printf("1-Du shampoing  -6 pieces\n");
    printf("2-Du cidre      -3 pieces\n");
    printf("3-Du lait       -7 pieces\n");
    printf("\n");
    printf("_________________________________________________________________________________\n");

    char choix[10];
    scanf("%s", &choix);
    if (choix[0] == '1')
    {
        if (inventaire[3] >= 6)
        {
            inventaire[3] -= 6;
            inventaire[0] += 1;
        }
        if (inventaire[3] < 6)
        {
            printf("Tu n'as pas assez de monnaie pour acheter cet objet\n");
        }

    }
    if (choix[0] == '2')
    {
        if (inventaire[3] >= 3)
        {
            inventaire[3] -= 3;
            inventaire[1] += 1;
        }
        if (inventaire[3] < 3)
        {
            printf("Tu n'as pas assez de monnaie pour acheter cet objet\n");
        }
    }
    if (choix[0] == '3')
    {
        if (inventaire[3] >= 7)
        {
            inventaire[3] -= 7;
            inventaire[2] += 1;
        }
        if (inventaire[3] < 7)
        {
            printf("Tu n'as pas assez de monnaie pour acheter cet objet\n");
        }
    }

    printf("Veux tu continuer tes achats?\n");
    printf("c pour continuer\n");
    char continuer[10];
    scanf("%s", &continuer);
    if(continuer[0] == 'c')
    {
        tati(inventaire);
    }
    if(continuer[0] != 'c')
    {
        boutiques(inventaire);
    }

}

//a chaque tour on peut décider de changer de véhicule
void changeVehicule(int *inventaire, int *vehicule )
{

    printf("Comment veux tu te deplacer?\n");
    printf("1- a pied\n");
    printf("2- a velo\n");
    printf("3- en voiture\n");
    char choix[10];
    scanf("%s", &choix);
    if (choix[0]== '1')
    {
        *vehicule = 1;
    }
    if (choix[0]== '2')
    {
        if (inventaire[4] >= 1)
        {
            *vehicule = 3;
        }
        if (inventaire[4] < 1)
        {
            printf("Tu n as pas acces a ce vehicule, regarde dans l inventaire tes modes de transports disponibles\n");
        }
    }
    if (choix[0]== '3')
    {
        if (inventaire[5] >= 1)
        {
            *vehicule = 5;
        }
        if (inventaire[5] < 1)
        {
            printf("Tu n as pas acces a ce vehicule, regarde dans l inventaire tes modes de transports disponibles\n");
        }

    }
}

void animalerie(int *inventaire)
{
    printf("Veux tu adopter un nouveau chat?\n");
    printf("y/n \n");
    char choix[10];
    scanf("%s", &choix);
    //int f = (*p).force;

    if (choix[0] == 'y')
    {
       inventaire[6] = 1;
    }

    printf("r pour retour\n");
    char continuer[10];
    scanf("%s", &continuer);
    if(continuer[0] != 'r')
    {
        animalerie(inventaire);
    }
    if(continuer[0] == 'r')
    {
        boutiques(inventaire);
    }
}
