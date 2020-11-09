#ifndef HEADER
#define HEADER


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <locale.h>
#include <time.h>

#define Haut_train 5
#define Long_train 123

#define Haut_metro 44
#define Long_metro 156

void remplissage_mat(char **mat, char chemin[]);
char **initialisation_train();
char **initialisation_metro();
void affichage(char **mat, char chemin[]);

void keypressed(char sentence[], char key);
void viderBuffer();

void mouvement(char **mat, char sentence[], int x, int y);
void toTheRight(char **mat,  char sentence[]);
void toTheLeft(char **mat,  char sentence[]);
void mouvement2(char **mat, char sentence[],int x, int y);
void affichage(char **mat, char sentence[]);

void mouvementTotal(char **train,char **metro, char sentence[],int x, int y, int verif);     


#endif 