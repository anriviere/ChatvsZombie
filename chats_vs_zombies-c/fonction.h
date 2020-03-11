void menu();
void start();
int choixDuJoueur(int carte, int *inventaire, int *vehicule, struct personnage*joueur, struct chat*pantoufle, struct chat*poil, int *carte2, int *posTestx, int *posTesty);
void deplacementJoueur(int P[26][80], int choixDuJoueur, int *posx, int *posy, int *carte, int  *inventaire, struct personnage*joueur, struct chat*pantoufle, struct chat*poil);
void combat();
void quitter();
int Fin();
void inventaire();
