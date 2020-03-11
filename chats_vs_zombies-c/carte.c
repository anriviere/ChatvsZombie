//map non affichée sur laquelle est stockée l'emplacement des perso/boss/indices
void map(int t[26][80], int colonne, int ligne, int carte, int Posx, int Posy)
{
    int n = carte;
    for(int i=0; i<ligne; i++)
    {
        for(int y=0; y<colonne; y++)
        {

            t[i][y] = 0;

        }

    }
    t[4][36] = 4;
    if(n == 1)
    {
        t[6][74] = 2;
    }

    if(n == 3)
    {
        t[15][54] = 3;
    }

    int x = Posx;
    int y = Posy;

    t[x][y] = 1;

}

//Cette fonction sert uniquement pour des tests
void printMap(int t[26][80],int colonne, int ligne, int carte)
{

    for(int i=0; i<ligne; i++)
    {
        for(int y=0; y<colonne; y++)
        {


            printf("%d",t[i][y]);
        }

        printf("\n");
    }
}

//renvoie a la map les zones a colorer en fonction des indices
void avancementJeu(carte)
{
    if (carte == 0)
    {
        int m = 0;
        int n = 0;
        int o = 0;
        int p = 0;
        mappJoueur(&m, &n, &o, &p);
    }
    if (carte == 1)
    {
        int m = 63;
        int n = 78;
        int o = 4;
        int p = 8;
        mappJoueur(&m, &n, &o, &p);
    }
    if (carte == 3)
    {
        int m = 51;
        int n = 57;
        int o = 11;
        int p = 16;
        mappJoueur(&m, &n, &o, &p);
    }

}
