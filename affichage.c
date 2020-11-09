#include "header.h"


void mouvement(char **mat, char sentence[],int x, int y)
{
    printw("Coordonne du train \n");

    int xCache = x;
    int yCache = y;
    int vitesse = 1;

    int xbleue = 33;
    int compt = 0;

    erase();

    for (int k = 0; xCache < Long_metro; k++)
    {
        xCache = xCache + vitesse; // vitesse du train
        usleep(35000);
        erase();
        refresh();

        if (xCache > xbleue){
            compt ++;
        }
        
        for (int i = 0; i < Haut_train; i++)
        {
            x = 0;
            for (int j = 0; j < Long_train - compt; j++)
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
void mouvement2(char **mat, char sentence[],int x, int y)
{
    printw("Coordonne du train \n");

    int xCache = x;
    int yCache = y;
    int vitesse = 1;
    erase();

    for (int k = Long_metro - 1; xCache > 0; k--)
    {
        xCache = xCache - vitesse; // vitesse du train
        //usleep(35000);
        sleep(1);
        //erase();
        refresh();

        for (int i = Haut_train - 1; i > 0; i--)
        {
            x = xCache;
            for (int j = Long_train - 1; j > 0; j--)
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
                x--;
                refresh();
            }
            y--;
            printw("\n");
        }
        y = yCache;
    }
    printw("\nEND");
}


void affichage(char **mat, char sentence[]){
    
    int Haut = 0, Long = 0; 
    //printf("%s\n", sentence );
    char train_txt[] = "train";
    char metro_txt[] = "metro";

   // printw("result = %d\n");

    if (strcmp(sentence,train_txt) == 0){
        Haut = Haut_train;
        Long = Long_train;
    }
    else if(strcmp(sentence,metro_txt) == 0){
        Haut = Haut_metro;
        Long = Long_metro;
    }

    printw("haut = %d long = %d\n",Haut, Long);

    erase();
    for(int i = 0 ; i < Haut; i ++){
        for(int j = 0; j < Long ; j++){
        
            switch (mat[i][j]){
                case ' ':
                    printw(" ");
                    break;
                case 'a':
                    printw("═");
                    break;
                case 'b':
                    printw("║");
                    break;
                case 'c':
                    printw("╦");
                    break;
                case 'd':
                    printw("╩");
                    break;
                case 'e':
                    printw("╔");
                    break;
                case 'f':
                    printw("╗");
                    break;
                case 'g':
                    printw("╚");
                    break;

                case 'h':
                    printw("╝");
                    break;
                
                case 'i':
                    printw("╠");
                    break;
                
                case 'j':
                    printw("╣");
                    break;

                case 'k':
                    printw("╬");
                    break;
                
                case 'l':
                    printw("┌");
                    break;

                case 'm':
                    printw("┐");
                    break;

                case 'n':
                    printw("└");
                    break;

                case 'o':
                    printw("┘");
                    break;

                case 'p':
                    printw("│");
                    break;

                case 'q':
                    printw("█");
                    break;

                case 'r':
                    printw("■");
                    break;

                case 's':
                    printw("▒");
                    break;

                case 't':
                    printw("▓");
                    break;
                
                case 'u':
                    printw("░");
                    break;
                
                default:
                    break;
                }
        }
        printw("\n");
    }
    printw("\n");
}


void mouvementTotal(char **train,char **metro, char sentence[],int x, int y, int verif)
{
    int xCache = x;
    int yCache = y;
    int vitesse = 1;

    int xbleue = 33;
    int compt = 0;

    erase();

    if(verif == 1){
        vitesse *= -1;
    }
    else
    {
        vitesse = 1;
    }
    
    for (int k = 0; xCache < Long_metro; k++)
    {
        affichage(metro, "metro");
        xCache = xCache + vitesse; // vitesse du train
        usleep(100000);
        //erase();
        refresh();

        if (xCache > xbleue){
            compt ++;
        }
        for (int i = 0; i < Haut_train; i++)
        {
            x = 0;
            for (int j = 0; j < Long_train - compt; j++)
            {
                switch (train[i][j])
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