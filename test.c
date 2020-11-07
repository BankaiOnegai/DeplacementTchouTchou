#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <locale.h>
#include <time.h>

#define Haut_train 5
#define Long_train 123

#define Haut_metro 43
#define Long_metro 156

void remplissage_mat(char **mat, char chemin[]);
char **initialisation_train();
char **initialisation_metro();
void affichage(char **mat, char chemin[]);

void keypressed(char sentence[], char key);
void viderBuffer();

void mouvement(char **mat, char sentence[]);

int main()
{
    setlocale(LC_ALL, "");
    initscr();
    printw("1\n");

    char **train = initialisation_train();
    char **metro = initialisation_metro();

    char train_txt[] = "train";
    char metro_txt[] = "metro";

    int clavier;

    int choix;
    int continuer = 1;

    remplissage_mat(train, train_txt);
    mouvement(train, train_txt);
    refresh();
    clavier = getch();
    printw(" clavier = %d\n", clavier);
    refresh();
    getch();
    endwin();

    return 0;

    /*
    while(continuer){
        
        mvprintw(0,0,"\t\t----------------- Menu ----------------\n\n");
        mvprintw(1,0,"1/Affiche gare\n");
        mvprintw(2,0,"2/Affiche metro\n");
        mvprintw(5,0,"3/ Quitter\n");
        scanw("%d",&choix);

        switch(choix){

            case 1:
                remplissage_mat(metro, metro_txt);
                refresh();
                //keypressed("Appuyez sur Y pour continuer\n",'y');
                clavier = getch();
                printw(" clavier = %d\n",clavier);
                refresh();
                getch();
                break;
            
            case 2: 
                remplissage_mat(train, train_txt);
                refresh();
                clavier = getch();
                printw(" clavier = %d\n",clavier);
                refresh();
                getch();
                break;

            case 3:
                remplissage_mat(train, train_txt);
                mouvement(train,train_txt);
                refresh();
                clavier = getch();
                printw(" clavier = %d\n",clavier);
                refresh();
                getch();
                break;

            case 4:
                continuer = 0;
                break;
            
            default:
                printw("Rentrer une commande valide SVP\n");
                clavier = getch();
                printw(" clavier = %d\n",clavier);
                refresh();
                getch();
                break;
        }
        
        erase();
     }
    */
    refresh();
    getch();
    endwin();

    return 0;
}

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

void mouvement(char **mat, char sentence[])
{
    int x, y;
    printw("Coordonne du train \n");
    //scanw("%d %d", &x, &y);

    // x => droite gauche
    // y => haut bas
    y = 0;
    x = 0;

    int xCache = x;
    int yCache = y;

    erase();

    for (int k = 0; xCache < 200; k++)
    {
        xCache = xCache + 10; // 10 = vitesse du train
        usleep(424242);
        erase();
        refresh();

        for (int i = 0; i < Haut_train; i++)
        {
            x = 0;
            for (int j = 0; j < Long_train; j++)
            {
                switch (mat[i][j])
                {
                case ' ':
                    mvprintw(y, x + xCache, " ");
                    break;
                case 'a':
                    mvprintw(y, x + xCache, "═");
                    break;
                case 'b':
                    mvprintw(y, x + xCache, "║");
                    break;
                case 'c':
                    mvprintw(y, x + xCache, "╦");
                    break;
                case 'd':
                    mvprintw(y, x + xCache, "╩");
                    break;
                case 'e':
                    mvprintw(y, x + xCache, "╔");
                    break;
                case 'f':
                    mvprintw(y, x + xCache, "╗");
                    break;
                case 'g':
                    mvprintw(y, x + xCache, "╚");
                    break;
                case 'h':
                    mvprintw(y, x + xCache, "╝");
                    break;
                case 'i':
                    mvprintw(y, x + xCache, "╠");
                    break;
                case 'j':
                    mvprintw(y, x + xCache, "╣");
                    break;
                case 'k':
                    mvprintw(y, x + xCache, "╬");
                    break;
                case 'l':
                    mvprintw(y, x + xCache, "┌");
                    break;
                case 'm':
                    mvprintw(y, x + xCache, "┐");
                    break;
                case 'n':
                    mvprintw(y, x + xCache, "└");
                    break;
                case 'o':
                    mvprintw(y, x + xCache, "┘");
                    break;
                case 'p':
                    mvprintw(y, x + xCache, "│");
                    break;
                case 'q':
                    mvprintw(y, x + xCache, "█");
                    break;
                case 'r':
                    mvprintw(y, x + xCache, "■");
                    break;
                case 's':
                    mvprintw(y, x + xCache, "▒");
                    break;
                case 't':
                    mvprintw(y, x + xCache, "▓");
                    break;
                case 'u':
                    mvprintw(y, x + xCache, "░");
                    break;
                default:
                    break;
                }
                x++;
                refresh();
            }
            y++;
            printw("\n");
        }
        y = yCache;
    }
    printw("\nEND");
}
/*
void efface_train()
// Supprime le train et affiche le train a coté 
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
*/