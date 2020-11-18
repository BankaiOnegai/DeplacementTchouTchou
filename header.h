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
#define Long_train 131

#define Haut_trainGare 5
#define Long_trainGare 130

#define Haut_metro 42
#define Long_metro 156

#define vitesse_Train 40000

#define trainSuivant 20


// Fonction qui met un fichier texte dans une matrice
void remplissage_mat(char **mat, char chemin[]);

// Fonctions d'initialisation des matrices
char **initialisation_train();
char **initialisation_metro();
char **initialisation_trainEnGare();
char **initialisation_trainGare();

// Fonction d'affichage des matrices
void affichage(char **mat, char sentence[],int x,int y, int cache);
void convertion(char **matrix , int i , int j, int y, int x );
void affichageTemps(int x , int y , int temp);

void deplacementTrain(char **train,int x, int y, int stop,int verif);
void trainEnGare(char c);
void departTrainHaut(char **train, char **metro, char sentence[]);  
void departTrainBas(char **train,char **metro, char sentence[]);  




#endif 