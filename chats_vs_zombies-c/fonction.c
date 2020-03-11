#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "personnages.h"
#include "inventaire.h"
#include "zombie.h"
#include "etapeJeu.h"
#include "carte.h"
#include "combat.h"

#define FILE_SIZE 10;

extern const char numInventaire[5][5];
extern const char inventaireNom[5][15];

//finction pour charger une partie
int load(struct personnage*joueur, struct chat*pantoufle, struct chat*poil, int *carte, int *posTestx, int *posTesty, int *compteurTour, int *inventaire)
{
    FILE* inFile;
    inFile = fopen("data.txt", "r");
    if(inFile == NULL)
    {
        printf("Erreur de chargement.\n");
        return 0;
    }
    fscanf(inFile, "%d\n", &joueur->pv);
    fscanf(inFile, "%d\n", &joueur->pv);
    fscanf(inFile, "%d\n", &joueur->defense);
    fscanf(inFile, "%s\n", &joueur->name);
    fscanf(inFile, "%d\n", &pantoufle->defense);
    fscanf(inFile, "%d\n", &pantoufle->force);
    fscanf(inFile, "%d\n", &pantoufle->rapidite);
    fscanf(inFile, "%s\n", &pantoufle->name);
    fscanf(inFile, "%s\n", &poil->name);
    fscanf(inFile, "%d\n", &poil->defense);
    fscanf(inFile, "%d\n", &poil->force);
    fscanf(inFile, "%d\n", carte);
    fscanf(inFile, "%d\n", posTestx);
    fscanf(inFile, "%d\n", posTesty);
    fscanf(inFile, "%d\n", compteurTour);
    fscanf(inFile, "%d\n", &inventaire[0]);
    fscanf(inFile, "%d\n", &inventaire[1]);
    fscanf(inFile, "%d\n", &inventaire[2]);
    fscanf(inFile, "%d\n", &inventaire[3]);
    fscanf(inFile, "%d\n", &inventaire[4]);
    fscanf(inFile, "%d\n", &inventaire[5]);
    fscanf(inFile, "%d\n", &inventaire[6]);
    fclose(inFile);
    return 1;
}


//fonction de sauvegarde
void save(struct personnage*joueur, struct chat*pantoufle, struct chat*poil, int *carte, int *posTestx, int *posTesty, int *compteurTour, int *inventaire)
{
    FILE* savefile;

    savefile = fopen("data.txt","w");

    fprintf(savefile, "%d\n", joueur->pv);
    fprintf(savefile, "%d\n", joueur->defense);
    fprintf(savefile, "%s\n", joueur->name);
    fprintf(savefile, "%d\n", pantoufle->defense);
    fprintf(savefile, "%d\n", pantoufle->force);
    fprintf(savefile, "%d\n", pantoufle->rapidite);
    fprintf(savefile, "%s\n", pantoufle->name);
    fprintf(savefile, "%s\n", poil->name);
    fprintf(savefile, "%d\n", poil->defense);
    fprintf(savefile, "%d\n", poil->force);
    fprintf(savefile, "%d\n", carte);
    fprintf(savefile, "%d\n", posTestx);
    fprintf(savefile, "%d\n", posTesty);
    fprintf(savefile, "%d\n", compteurTour);
    fprintf(savefile, "%d\n", inventaire[0]);
    fprintf(savefile, "%d\n", inventaire[1]);
    fprintf(savefile, "%d\n", inventaire[2]);
    fprintf(savefile, "%d\n", inventaire[3]);
    fprintf(savefile, "%d\n", inventaire[4]);
    fprintf(savefile, "%d\n", inventaire[5]);
    fprintf(savefile, "%d\n", inventaire[6]);


    fclose(savefile);
    printf("ta partie est sauvegardee\n");
}

//fonction qui affiche le logo au debut du jeu
void debut()
{
    printf("                  hhhhhhh                                     tttt                          \n");
    printf("                  h:::::h                                  ttt:::t                          \n");
    printf("                  h:::::h                                  t:::::t                          \n");
    printf("                  h:::::h                                  t:::::t                          \n");
    printf("    ccccccccccccccch::::h hhhhh        aaaaaaaaaaaaa ttttttt:::::ttttttt       ssssssssss   \n");
    printf("  cc:::::::::::::::h::::hh:::::hhh     a::::::::::::at:::::::::::::::::t     ss::::::::::s  \n");
    printf(" c:::::::::::::::::h::::::::::::::hh   aaaaaaaaa:::::t:::::::::::::::::t   ss:::::::::::::s \n");
    printf("c:::::::cccccc:::::h:::::::hhh::::::h           a::::tttttt:::::::tttttt   s::::::ssss:::::s\n");
    printf("c::::::c     cccccch::::::h   h::::::h   aaaaaaa:::::a     t:::::t          s:::::s  ssssss \n");
    printf("c:::::c            h:::::h     h:::::h aa::::::::::::a     t:::::t            s::::::s      \n");
    printf("c:::::c            h:::::h     h:::::ha::::aaaa::::::a     t:::::t               s::::::s   \n");
    printf("c::::::c     cccccch:::::h     h:::::a::::a    a:::::a     t:::::t    tttttssssss   s:::::s \n");
    printf("c:::::::cccccc:::::h:::::h     h:::::a::::a    a:::::a     t::::::tttt:::::s:::::ssss::::::s\n");
    printf(" c:::::::::::::::::h:::::h     h:::::a:::::aaaa::::::a     tt::::::::::::::s::::::::::::::s \n");
    printf("  cc:::::::::::::::h:::::h     h:::::ha::::::::::aa:::a      tt:::::::::::tts:::::::::::ss  \n");
    printf("    ccccccccccccccchhhhhhh     hhhhhhh aaaaaaaaaa  aaaa        ttttttttttt   sssssssssss    \n");
    printf("               vvvvvvv           vvvvvvv ssssssssss                                         \n");
    printf("                v:::::v         v:::::vss::::::::::s                                        \n");
    printf("                 v:::::v       v:::::ss:::::::::::::s                                      \n");
    printf("                  v:::::v     v:::::vs::::::ssss:::::s                         \n");
    printf("                   v:::::v   v:::::v  s:::::s  ssssss               \n");
    printf("                    v:::::v v:::::v     s::::::s                                            \n");
    printf("                     v:::::v:::::v         s::::::s                                                 \n");
    printf("                      v:::::::::v    ssssss   s:::::s bbbbbbbb                                  \n");
    printf("                       v:::::::v     s:::::ssss::::::sb::::::b             iiii             \n");
    printf("                        v:::::v      s::::::::::::::s b::::::b            i::::i                      \n");
    printf("                         v:::v        s:::::::::::ss  b::::::b             iiii                    \n");
    printf("                          vvv          sssssssssss     b:::::b                                             \n");
    printf("zzzzzzzzzzzzzzzzz  ooooooooooo     mmmmmmm    mmmmmmm  b:::::bbbbbbbbb   iiiiiii    eeeeeeeeeeee       ssssssssss   \n");
    printf("z:::::::::::::::zoo:::::::::::oo mm:::::::m  m:::::::mmb::::::::::::::bb i:::::i  ee::::::::::::ee   ss::::::::::s  \n");
    printf("z::::::::::::::zo:::::::::::::::m::::::::::mm::::::::::b::::::::::::::::b i::::i e::::::eeeee:::::ess:::::::::::::s \n");
    printf("zzzzzzzz::::::z o:::::ooooo:::::m::::::::::::::::::::::b:::::bbbbb:::::::bi::::ie::::::e     e:::::s::::::ssss:::::s\n");
    printf("      z::::::z  o::::o     o::::m:::::mmm::::::mmm:::::b:::::b    b::::::bi::::ie:::::::eeeee::::::es:::::s  ssssss \n");
    printf("     z::::::z   o::::o     o::::m::::m   m::::m   m::::b:::::b     b:::::bi::::ie:::::::::::::::::e   s::::::s      \n");
    printf("    z::::::z    o::::o     o::::m::::m   m::::m   m::::b:::::b     b:::::bi::::ie::::::eeeeeeeeeee       s::::::s   \n");
    printf("   z::::::z     o::::o     o::::m::::m   m::::m   m::::b:::::b     b:::::bi::::ie:::::::e          ssssss   s:::::s \n");
    printf("  z::::::zzzzzzzo:::::ooooo:::::m::::m   m::::m   m::::b:::::bbbbbb::::::i::::::e::::::::e         s:::::ssss::::::s      Veux tu jouer?\n");
    printf(" z::::::::::::::o:::::::::::::::m::::m   m::::m   m::::b::::::::::::::::bi::::::ie::::::::eeeeeeee s::::::::::::::s         y/n ? \n");
    printf("z:::::::::::::::zoo:::::::::::oom::::m   m::::m   m::::b:::::::::::::::b i::::::i ee:::::::::::::e  s:::::::::::ss  \n");
    printf("zzzzzzzzzzzzzzzzz  ooooooooooo  mmmmmm   mmmmmm   mmmmmbbbbbbbbbbbbbbbb  iiiiiiii   eeeeeeeeeeeeee   sssssssssss    \n");
    char choix;
    scanf("%c", &choix);
    if(choix == 'y')
    {
        menu();
    }
    if(choix != 'y' && choix != 'n')
    {
        debut();
    }
}

//pour changer la couleur du texte
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


void menu()
{
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("         /|__/|                 /|__/|                 /|__/|       \n");
    printf("        / o o |                / o o |                / o o |       \n");
    printf("       (== ^ ==)              (== ^ ==)              (== ^ ==)      \n");
    printf("        )     (                )     (                )     (       \n");
    printf("        (     )                (     )                (     )       \n");
    printf("       (()   ())              (()   ())              (()   ())      \n");
    printf("      (_(_)_(_)_)            (_(_)_(_)_)            (_(_)_(_)_)     \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("         /|__/|                  Menu                  /|__/|       \n");
    printf("        / o o |                 ~~~~~~                / o o |       \n");
    printf("       (== ^ ==)         1) Nouvelle partie          (== ^ ==)      \n");
    printf("        )     (          2) Charger une partie        )     (       \n");
    printf("        (     )          3) Credits                   (     )       \n");
    printf("       (()   ())         4) Quitter                  (()   ())      \n");
    printf("      (_(_)_(_)_)                                   (_(_)_(_)_)     \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("         /|__/|                 /|__/|                 /|__/|       \n");
    printf("        / o o |                / o o |                / o o |       \n");
    printf("       (== ^ ==)              (== ^ ==)              (== ^ ==)      \n");
    printf("        )     (                )     (                )     (       \n");
    printf("        (     )                (     )                (     )       \n");
    printf("       (()   ())              (()   ())              (()   ())      \n");
    printf("      (_(_)_(_)_)            (_(_)_(_)_)            (_(_)_(_)_)     \n");
    printf("                                                                    \n");


    char choix[10];
    scanf("%s",&choix);

    while (choix[0] != '1' && choix[0] != '2' && choix[0] != '3' && choix[0] != '4')
    {
        printf("Ce choix n'est pas valide!!\n");
        printf("1) Nouvelle partie\n");
        printf("2) Charger une partie\n");
        printf("3) Credit\n");
        printf("4) Quitter\n");

        scanf("%s",&choix);
    }

    if (choix[0] == '1')
    {
        start(0);
    }
    if (choix[0] == '3')
    {
        credits();
    }
    if (choix[0] == '4')
    {
        quitter();
    }
    if (choix[0] == '2')
    {
        start(1);

    }
    else
    {

    }
}

void credits()
{
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("         /|__/|                 /|__/|                 /|__/|       \n");
    printf("        / o o |                / o o |                / o o |       \n");
    printf("       (== ^ ==)              (== ^ ==)              (== ^ ==)      \n");
    printf("        )     (                )     (                )     (       \n");
    printf("        (     )                (     )                (     )       \n");
    printf("       (()   ())              (()   ())              (()   ())      \n");
    printf("      (_(_)_(_)_)            (_(_)_(_)_)            (_(_)_(_)_)     \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("         /|__/|                 Credits                /|__/|       \n");
    printf("        / o o |                 ~~~~~~                / o o |       \n");
    printf("       (== ^ ==)           Chats VS Zombies          (== ^ ==)      \n");
    printf("        )     (                                       )     (       \n");
    printf("        (     )              Anais Riviere            (     )       \n");
    printf("       (()   ())              Sarah Zouari           (()   ())      \n");
    printf("      (_(_)_(_)_)                                   (_(_)_(_)_)     \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("                                                                    \n");
    printf("         /|__/|                 /|__/|                 /|__/|       \n");
    printf("        / o o |                / o o |                / o o |       \n");
    printf("       (== ^ ==)              (== ^ ==)              (== ^ ==)      \n");
    printf("        )     (                )     (                )     (       \n");
    printf("        (     )                (     )                (     )       \n");
    printf("       (()   ())              (()   ())              (()   ())      \n");
    printf("      (_(_)_(_)_)            (_(_)_(_)_)            (_(_)_(_)_)     \n");
    printf("                                                                    \n");
    printf("r pour retour");

    char retour[10];
    scanf("%s",&retour[0]);
    if(retour[0] == 'r')
    {
        menu();
    }
    else
    {
        credits();
    }
}



int placeInventaireN = 20;
int posPerso[2] = {3,26};



void start(int sauv)
{
    char nomDuJoueur[100];

    int posTestx = 3;
    int posTesty = 26;
    int carte = 0;
    int vehicule = 1;
    int inventairev[7] = {0,6,2,120,0,0,0};
    int m[26][80];
    map(m,80,26,carte,posTestx,posTesty);
    struct personnage joueur;

    struct chat pantoufle;
    struct chat poil;

    joueur.pv = 10;
    joueur.defense = 10;
    strcpy(joueur.name, nomDuJoueur);
    pantoufle.force = 10;
    pantoufle.defense = 10;
    pantoufle.rapidite = 3;
    poil.force = 0;
    poil.defense = 10;
    poil.rapidite = 3;
    strcpy(poil.name, "Poilu");
    int compteurTour = 0;
    if (sauv == 1)
    {
        load(&joueur, &pantoufle, &poil, &carte, &posTestx, &posTesty ,&compteurTour, &inventairev);
    }

    if (sauv == 0)
    {
        printf("Quel est ton nom? \n");
        scanf("%s", nomDuJoueur);
        strcpy(joueur.name, nomDuJoueur);
        tour1(joueur.name);
        Color(9,0);
        printf("Comment veux tu appeler ton nouveau compagnon?\n");
        Color(15,0);
        char nomChat[100];
        scanf("%s", nomChat);
        strcpy(pantoufle.name, nomChat);

        explicationJeu(joueur.name, pantoufle.name);


    }


    while (Fin() == 0)
    {
        if (inventairev[6] == 1)
        {
            poil.force = 10;
        }
        if (compteurTour == 5)
        {
            tour5();
            carte = 1;
        }
        if (carte == 2)
        {
            rencontreSage(joueur.name);
            carte += 1;
        }


        map(m,80,26,carte, posTestx, posTesty);
        posPerso[0] = posTestx;
        posPerso[1] = posTesty;
        //printMap(m,80,26,carte);

        //positionJoueur(m);

        //avancementJeu(carte);
        int choix = choixDuJoueur(carte, &inventairev, &vehicule, &joueur, &pantoufle, &poil, posTestx, posTesty, compteurTour);
        deplacementJoueur(m , choix, &posTestx, &posTesty, &carte, &inventairev, &joueur, &pantoufle, &vehicule, &poil);
        caseAleatoire(&joueur,&pantoufle,carte, &inventairev, &poil);

        compteurTour += 1;

    }


}

int choixDuJoueur(int carte, int *inventaire, int *vehicule, struct personnage*joueur, struct chat*pantoufle, struct chat*poil, int posTestx, int posTesty, int compteurTour)
{

    printf("Dans quelle direction veux tu avancer?\n");
    printf("n pour le nord, o pour l'ouest, s pour le sud ou e pour l'est. \n");
    printf(" i pour voir l'inventaire, m pour afficher la carte\n");
    printf(" v pour changer de vehicule, q pour quitter, p pour sauvegarder\n");
    char choixDirection[10];
    scanf("%s", &choixDirection[0]);
    if(choixDirection[0] == 'm')
    {
        avancementJeu(carte);
        choixDuJoueur(carte, inventaire,vehicule,joueur,pantoufle, poil,posTestx,posTesty, compteurTour);

    }
    if(choixDirection[0] == 'i')
    {
        printInventaire(inventaire);
        choixDuJoueur(carte, inventaire,vehicule,joueur, pantoufle, poil, posTestx, posTesty, compteurTour);
    }
    if(choixDirection[0] == 'p')
    {
        printf("%d",joueur->pv);
        save(joueur, pantoufle, poil, carte, posTestx, posTesty, compteurTour, inventaire);
    }
    if(choixDirection[0] == 'v')
    {
        changeVehicule(inventaire, vehicule);
        choixDuJoueur(carte, inventaire,vehicule,joueur,pantoufle, poil,posTestx,posTesty, compteurTour);

    }
    if (choixDirection[0] == 'q')
    {
        printf("Tu es sur le point de quitter la partie\n");
        printf("Es tu sur? y/n \n");
        char ch[10];
        scanf("%s", &ch);
        if(ch[0] == 'y')
        {
            quitter();
        }
        if (ch[0] != 'y')
        {
             choixDuJoueur(carte, inventaire,vehicule,joueur,pantoufle, poil,posTestx,posTesty, compteurTour);
        }

    }
    if(choixDirection[0] != 'n' && choixDirection[0] != 'o' && choixDirection[0] != 's' && choixDirection[0] != 'e')
    {
        printf("Cette direction n'est pas valide!\n");
        choixDuJoueur(carte, inventaire,vehicule,joueur,pantoufle, poil,posTestx,posTesty, compteurTour);
       /*
        printf("n pour le nord, o pour l'ouest, s pour le sud ou e pour l'est. \n");
        //choixDuJoueur(carte, inventaire);
        scanf("%s", &choixDirection[0]);*/
    }
    return choixDirection[0];


}

//fonction qui decide aleatoirement si le joueur va combattre ou trouver un objet
int caseAleatoire(struct personnage*joueur,struct chat*pantoufle, int carte,int  *inventaire, struct chat*poil)
{
    int alea = rand()%2;
    printf("%d \n",alea);

    if(alea == 0)
    {
        items(inventaire);
    }
    if(alea == 1)
    {
        int alea = aleaZombie();
        combat(joueur,pantoufle,carte,inventaire,alea, poil);
    }

}


//fonction qui affiche la barre de vie (vert si beaucoup de PV rouge si tu vas bientot mourir)
void vie(int a)
{
    int n = a;

    if (n < 9 && n > 5)
    {
        for(int i=0 ; i<n ; i++)
        {
            Color(0,12);
            printf(".");
            Color(15,0);
        }
    }

    else if ( n <= 5 )
    {
        for(int i = 0 ; i < n ; i++)
        {
            Color(0,4);
            printf(".");
            Color(15,0);
        }
    }
    else
    {
        for(int i = 0 ; i < n ; i++)
        {
            Color(0,10);
            printf(".");
            Color(15,0);
        }

    }

    printf("\n");
}


//aleatoiremnt, quel objet on trouve sur la case
void items(int *inventaire)
{

    int placeRestanteN = placeInventaireN - (inventaire[0] + inventaire[1]  + inventaire[2]);
    int choix ;
    int it = rand()%4;
    if (placeRestanteN > 0)
    {
        printf("Tu as trouve un objet %s , veux tu le ramasser? 1 = oui / 2 = non \n", inventaireNom[it]);
        scanf("%d", &choix);
        if (choix == 1)
        {
            inventaire[it] += 1;
        }
    }
    if (placeRestanteN <= 0)
    {
        Color(4,0);
        printf("Tu as trouve un objet %s , mais tu n'as plus de place pour le stocker\n", inventaireNom[it]);
        Color(15,0);
    }

}

//recupere la valeur de choixDuJoueur pour deplacer le perso dans la bonne direction
void deplacementJoueur(int P[26][80], int choixDuJoueur, int *posx, int *posy, int *carte, int  *inventaire, struct personnage*joueur, struct chat*pantoufle,int *vehicule , struct chat*poil)
{

    int n = *vehicule;
    int limit1 = n-1;
    int limit2 = 80 - n;
    int x = *posx;
    int y = *posy;
    if (choixDuJoueur == 'n')
    {
        if(x>limit1)
        {
            if(P[x-n][y] == 2 && *carte < 2)
            {

                *carte = 2;
            }
            if(P[x-n][y] == 3)
            {
                combat(joueur,pantoufle,carte,inventaire,3,poil);
                gagner();

            }
            if(P[x-n][y] == 4)
            {
                boutiques(inventaire,poil);
            }
            //P[x][y] = 0;
            *posx -= n;
        }
        else
        {
            printf("Tu es bloque par une chaine de montagne!\n");


        }
    }
    if (choixDuJoueur == 'o')
    {
        if(y>limit1)
        {
            if(P[x][y-n]== 2 && *carte < 2)
            {
                 *carte = 2;
            }
             if(P[x][y-n]== 3)
            {
                 combat(joueur,pantoufle,carte,inventaire,3, poil);
                 gagner();
            }
            if(P[x][y-n] == 4)
            {
                boutiques(inventaire, poil);

            }

            //P[x][y]=0;
            *posy -= n;
        }
        else
        {
            printf("Tu es bloque par une chaine de montagne!\n");


        }
    }
    if (choixDuJoueur == 's')
    {
        if(x<limit2)
        {
            if (P[x+n][y] == 2 && *carte < 2)
            {
                *carte = 2;
            }
            if (P[x+n][y] == 3)
            {
                combat(joueur,pantoufle,carte,inventaire,3,poil);
                gagner();
            }
            if(P[x+n][y] == 4)
            {
                boutiques(inventaire, poil);

            }
            //P[x][y]=0;
            *posx += n;
        }
        else
        {
            printf("Tu es bloque par une chaine de montagne!\n");


        }

    }
    if (choixDuJoueur == 'e')
    {
        if(y<limit2)
        {
            if(P[x][y+n] == 2 && *carte < 2)
            {
                *carte = 2;
            }
            if(P[x][y+n] == 3)
            {
                combat(joueur,pantoufle,carte,inventaire,3,poil);
                gagner();
            }
            if(P[x][y+n] == 4)
            {
                boutiques(inventaire, poil);

            }
            //P[x][y]=0;
            *posy += n;
        }
        else
        {
            printf("Tu es bloque par une chaine de montagne!\n");


        }
    }

    posPerso[0] = *posx;
    posPerso[1] = *posy;



}


//imprime la carte que le joueur voit
void mappJoueur(int *m, int *n, int *o, int *p)
{
    char mapJoueur[26][81] =
    {"ffffffffffffffffffffffffffffffff..............................................." ,
     "::::::::::::::::::::::::::::::fff............................mmmmmmmmmmmmmmmmmm" ,
     ":::::FORET::::::::::::::::::ffff...........................mm::::::::::::::::::" ,
     ":::::::::::::::::::::::::fff......vvvvvvvvvvvvvvvv........m::::::::::::::::::::" ,
     ":::::::NORD::::::::::fffff......vv::B::::::::::::vvv......mm:::::::::::::::::::" ,
     "::::::::::::::::ffffff..........vvv:::::::::::::::vv.....mm:::::MONTAGNE:::::::" ,
     "ffffffffffffffff.................vv:::::::::::::::vv......mm:::::::::::::::::::" ,
     "...................................v:::VILLAGE:::::v.....mm::::::::::::::::::::" ,
     "....................................vv::::::::::::vv......mmm::::::::::::::::::" ,
     "....................................vvv::::::::::vv..........mmmmm:::::::::::::" ,
     "rrrrrrrrr.............................vv::::::::vvv..............mmmm::::::::::" ,
     "******rrrrrrrrrrrrrr...................vvvvvvvvvvv..................mmmmmmmmmmm" ,
     "****************rrrrrrrrrrrrrrr................................................" ,
     "******RIVIERE************* ***rrrp............................................." ,
     "rrrrrrr***************************rp......prrrrrr........rrrrrrrrrrrrrrrrrrrrrr" ,
     ".....rrrrrrrrrrrrrrrrrr*************rp......prrrrrrrrrrrrrrr*******************" ,
     "......................rrrrrr**********rp......prr*************RIVIERE**********" ,
     "..........................rrrrrrrrrrrrrrp......prr*****************************" ,
     "fffffffffffffff..................................rrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" ,
     ":::::::::::::ffffff............................................................" ,
     "::::::::::::::::::fffff................cccccccccccccccccccccccccccccccccccccccc" ,
     "::::::FORET:::::::::::ffffff..........ccccc::::::::::::::::::::::::::::::::::::" ,
     ":::::::::::::::::::::::::ffff........cccc::::::::::::::::COLLINES::::::::::::::" ,
     "::::SUD-OUEST::::::::fffffff..........cccc:::::::::::::::::::::::::::::::::::::" ,
     "::::::::::::::::ffffff..................ccccc::::::::::::::::::::::::::::::::::" ,
     "fffffffffffffffffff.........................ccccccccccccccccccccccccccccccccccc" };


     int x = posPerso[0];
     int y = posPerso[1];



     Color(12, 0);
     mapJoueur[x][y] = 'X';
     Color(15, 0);

   // for(int i=0;i<27;i++)
   // {
    //    printf("%s\n",mapJoueur[i]);
    //}



    for(int i=0; i<26; i++)
    {
        for(int j=0; j<81; j++)
        {

            if (mapJoueur[i][j] ==  mapJoueur[x][y])
            {
                Color(12,0);
                printf("%c",mapJoueur[i][j]);
            }

            else if(i > *o && i < *p && j > *m && j < *n )

            {
                Color(10,0);
                printf("%c",mapJoueur[i][j]);
            }
            else if (mapJoueur[i][j] == 'B')
            {
                Color(9,5);
                printf("%c",mapJoueur[i][j]);
            }

            else
            {
                Color(15, 0);
                printf("%c",mapJoueur[i][j]);
            }

        }
        printf("\n");
    }




}

//quitter le jeu
void quitter()
{
    printf("Tu vas me manquer, a bientot mon lapin\n");
    exit(0);

}
 int Fin()
 {
     return 0;
 }



