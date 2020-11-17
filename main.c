#include "header.h"

int main()
{
    setlocale(LC_ALL, "");
    initscr();
   // printw("1\n");

    char **train = initialisation_train();
    char **metro = initialisation_metro();
   

    char train_txt[] = "train";
    char metro_txt[] = "metro";

    int clavier;

    int choix;
    int continuer = 1;


    remplissage_mat(metro, metro_txt);
    remplissage_mat(train, train_txt);
    erase();
    
    affichage(metro ,metro_txt, 0, 0, 0);
    mouvementTotal(train, train_txt, 13,13,1);
    /*trainEnGare('h');
    sleep(1);
    deplacementTrain(train, metro, train_txt,13,13,1);
    trainEnGare('b');
    sleep(1);
    deplacementTrain(train, metro, train_txt,13,23,-1);
    
        
        if(suivant = 0){
            suivant = 15;
        }
            
        if(actuel < suivant ){
            
            usleep(100000);
            actuel ++ ;
            
        }
        else if ( actuel != 0 && suivant < 10 ){
            deplacementTrain(train, metro, train_txt, 10, 14, 1 );
            suivant -- ;
        }
        */ 

    refresh();
    //clavier = getch();
    //printw(" clavier = %d\n", clavier);
    refresh();
    getch();
    endwin();

    return 0;
}





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
