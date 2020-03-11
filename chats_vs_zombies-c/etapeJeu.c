#include "personnages.h"
#include <stdio.h>

//premiere présentation du jeu
void tour1(joueur)
{
    char avance[10];
    printf("\n");
    printf("\n");
    printf("___________________________________________________________________________________________________________________\n");
    printf("___________________________________________________________________________________________________________________\n");
    printf("\n");
    Color(5,0);
    printf("Il est 5h, tu te trouve en plein miliu de la foret du nord...\n");
    printf("Tu te reveille, perdu.. \n");
    Color(15,0);
    printf("\n");
    printf(" %s : ''Mes yeux s ouvrent, je regarde autour de moi sans reconnaitre, mes oreilles sifflent, ma tete tourne.''\n", joueur);
    printf(" %s : ''Soudain, des bribes de souvenirs me reviennent et j’ai un flashback de la veille.''\n", joueur);
    scanf("%s",&avance);
    printf(" %s : ''Les zombies...''\n",joueur);
    printf(" %s : ''Ils nous ont attaques pendant la nuit, nous n avions aucune chance,''\n", joueur);
    printf(" %s : ''ma soeur dormait deja lorsqu ils sont entres, la porte a fini par ceder sous leur poids...''\n",joueur);
    scanf("%s",&avance);
    printf(" %s : ''Et elle aussi.''\n",joueur);
    scanf("%s",&avance);
    printf(" %s : ''J ai bien essaye de les attaquer a l aide d un couteau mais il a fini par ceder, et je n ai pu que fuir...''\n",joueur);
    printf(" %s : ''La honte me submerge et me ramene a la realite.''\n",joueur);
    printf(" %s : ''Ou ai-je fini par atterrir ? Il fait sombre, je suis entoure d’arbres, seul.''\n",joueur);
    printf(" %s : ''Chaque bruit me fait sursauter, ''crac'' , c’est seulement mon imagination.''\n",joueur);
    scanf("%s",&avance);
    printf("Chat: '' miaou '' \n");
    printf(" %s : ''C est encore mon imagina... attends, miaou ???'' \n",joueur);



}

void explicationJeu(joueur, pantoufle)
{
    printf(" %s : Allons y %s , nous allons nous venger de ces zombies...\n",joueur, pantoufle);
    printf("\n");
    Color(5,0);
    printf("Te voila determine a te debarasser des zombies. \n");
    printf("Si tu veux les faire disparaitre definitivement tu dois detruire leur chef \n");
    printf("c est grace a lui qu'ils finissent toujours par revenir a la vie.\n");
    printf("Es tu pret?\n");
    char choix[10];
    scanf("%s", choix);
    printf("De toute facon tu n as pas vraiment le choix\n");
    printf("voici mes derniers conseils:\n");
    printf("En tapant i a tout moment tu peux consulter ton inventaire,\n");
    printf("tu as peut etre deja quelque objets utiles...\n");
    printf("En appuyant sur m tu peux consulter ta carte, n hesite pas a t en servir si tu ne veux pas te perdre encore plus\n");
    printf("\n");
    printf("Bonne chance\n");
    scanf("%s", choix);
    Color(15,0);
    printf("\n");
    printf("\n");
}

// au cinquieme tour , on rencontre un randonneur
void tour5()
{

    char reponse[10];
    char reponse2[10];

    printf("\n");
    printf("\n");
    printf("\n");

    printf("Tu viens de croiser un randonneur \n");
    Color(11,0);
    printf("Randonneur : 'Arriere Zombie!' \n");
    Color(15,0);
    printf("Que veux tu répondre? \n");
    printf(" 1 - 'Ta gueule' \n");
    printf(" 2- 'Il y a meprise tres cher, je ne suis pas un zombie mais un chasseur de zombie \n");

    scanf("%s", &reponse);
    Color(11,0);
    printf("Randonneur : 'Tu sais parler, tu n es donc pas un zombie' \n");
    printf("Es tu ici pour tuer le roi-zombie? \n");
    Color(15,0);
    printf("o = oui \n");

    scanf("%s", &reponse);
    Color(11,0);
    printf(" Randonneur : Je peux t aider. Il y a un sage qui vit dans la montagne qui sais ou es cache le roi-zombie\n");
    printf("Voici som emplacement! Bonne chance \n");
    Color(15,0);
    printf("Tu as obtenu l emplacement du sage, l indice est sur ta carte appuie sur m quand tu cherche ta route pour l afficher");

    printf("continuer?");

    scanf("%s", &reponse);



}


void rencontreSage(joueur)
{
    char choix[10];
    Color(5,0);
    printf("Tu viens de trouver le sage...\n");
    Color(15,0);
    printf("%s :'' Bonjour, je suis %s , je suis à la recherche d'un moyen de detruire le chef des zombies\n",joueur,joueur);
    printf("J ai ete envoye ici par un gars bizarre rencontre dans la foret''\n");
    printf("Le sage : ''Si tu veux vaincre le chef-zombie tu dois utiliser l'attaque allergene!''\n");
    printf("Pour cela tu auras besoin de shampoing, que les zombies detestent, associé a une attque de poils de chat''\n");
    scanf("%s", &choix);
    Color(5,0);
    printf("Es tu heureux d'avoir fait tout ce chemin pour cette information?\n");
    printf(" 1- oui c est tres utile! \n");
    printf("2- J ai perdu mon temps, depuis tout ce temps je me demandais a quoi servait ce stupide shampoing dans mon inventaire. Ce jeu est de plus en plus nul.");
    scanf("%s", &choix);
    printf("J ai menti, je m en fout de ton avis.");
    Color(15,0);
    scanf("%s", &choix);
    printf("Le sage : Ca m arrange que tu tue le chef-zombie a ma place\n");
    printf("Laisse moi t aider en te donnant sa position\n");
    Color(5,0);
    printf("La position du chef zombie est maintenant sur ta carte, Bonne chance\n");
    Color(15,0);

}

void gagner()
{
    printf(" __   __  ___   _______  _______  _______  ___   ______    _______  __   __  \n");
    printf("|  | |  ||   | |       ||       ||       ||   | |    _ |  |       ||  | |  | \n");
    printf("|  |_|  ||   | |       ||_     _||   _   ||   | |   | ||  |    ___||  | |  | \n");
    printf("|       ||   | |       |  |   |  |  | |  ||   | |   |_||_ |   |___ |  | |  | \n");
    printf("|       ||   | |      _|  |   |  |  |_|  ||   | |    __  ||    ___||__| |__| \n");
    printf(" |     | |   | |     |_   |   |  |       ||   | |   |  | ||   |___  __   __  \n");
    printf("  |___|  |___| |_______|  |___|  |_______||___| |___|  |_||_______||__| |__| \n");
    printf("\n");
    printf("Bravo!! Tu viens de vaincre le chef-zombie!!\n");
    printf("Tu peux aller faire quelque chose de plus interressant de ta vie en quittant ce jeu idiot,\n");
    printf("ou si tu es vraiment stupide tu peux recommencer.\n");
    printf("q pour quitter  r pour recommencer(mais c est idiot)\n");
    char choix[10];
    scanf("%s", &choix);
    if (choix[0] == 'q')
    {
        quitter();
    }
    if (choix[0] == 'r')
    {
        menu();
    }
}
