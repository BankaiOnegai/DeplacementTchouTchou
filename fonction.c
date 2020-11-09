#include "header.h"



void remplissage_mat(char **mat, char chemin[])
{

    printw("Test 1 fichier\n");

    FILE *fichier = NULL;

    char caractere_actuel = 0;
    int i = 0, j = 0;

    char path[20];

    if (sprintf(path, "%s.txt", chemin) == 0)
    {
        printw("Erreur du sprintf\n");
    }

    fichier = fopen(path, "r+");

    if (fichier != NULL)
    {
        caractere_actuel = fgetc(fichier);
        while (caractere_actuel != EOF)
        {
            if (caractere_actuel == '\n')
            {
                i++;
                j = 0;
            }
            else
            {
                mat[i][j] = caractere_actuel;
                //printw("%c",mat[i][j]);
                j++;
            }
            caractere_actuel = fgetc(fichier);
        }
    }
    fclose(fichier);
    printw("\n");
    printw("%s\n", chemin);
    //affichage(mat, chemin);
}

char **initialisation_train()
{
    char **mat = NULL;
    mat = (char **)malloc(Haut_train * sizeof(char *));
    for (int i = 0; i < Haut_train; i++)
    {
        mat[i] = (char *)malloc(Long_train * sizeof(char));
    }
    return mat;
}

char **initialisation_metro()
{
    char **mat = NULL;
    mat = (char **)malloc(Haut_metro * sizeof(char *));
    for (int i = 0; i < Haut_metro; i++)
    {
        mat[i] = (char *)malloc(Long_metro * sizeof(char));
    }
    return mat;
}


void toTheRight(char **mat,  char sentence[])
{
    int x, y;

    x = 0;
    y = 14;
    mouvement(mat, sentence, x, y);
}
void toTheLeft(char **mat,  char sentence[])
{
    int x, y;

    x = Long_metro;
    y = 22;
    mouvement2(mat, sentence, x, y);
}