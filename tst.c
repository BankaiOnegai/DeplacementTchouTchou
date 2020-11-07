#include <stdio.h>
#include <unistd.h> // for usleep function
 
const char rocket[] =
"          _\n\
          /^\\\n\
          |-|\n\
          | |\n\
          |N|\n\
          |A|\n\
          |S|\n\
          |A|\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";
 
int main()
{
    for (int i = 0; i < 50; i ++) printf("\n"); // jump to bottom of console
    printf("%s", rocket);
    int j = 300000;
    for (int i = 0; i < 50; i ++) {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        printf("\n"); // move rocket a line upward
    }
    system("clear");
    return 0;
}

#include "AllIncludes.h"
void AffichageGare(char *sentence){
  usleep(150000);
  FILE *file = NULL;
  int Lecture=0;
  int x=0,y=0; 
  Gare = fopen(sentence,"r");

  if (Gare==NULL) {
    printf("Erreur ouverture Gare.txt")
  }
  else{
  while(!feof(file)){
        Lecture=fgetc(file);
        switch (Lecture){
          case 48:
            mvprintw(y,x," ");
            break;
          case 49:
            mvprintw(y,x,"═");
            break;
          case 50:
            mvprintw(y,x,"║");
            break;
          case 51:
            mvprintw(y,x,"╔");
            break;
          case 52:
            mvprintw(y,x,"╗");
            break;
          case 53:
            mvprintw(y,x,"╝");
            break;
          case 54:
            mvprintw(y,x,"╚");
            break;
          case 10:
            x=-1;y++;
            break;
          default:
            break;
        }
        x++;
    }
    fclose(Gare);
    refresh();
  }
}


void getMatrix(int mat[Haut_train][Long_train]){

    FILE *file;
    char *line, *number;
    int i = 0;

    file = fopen("train.txt", "r");
    while(!feof(file)){
        j = 0;
        fscanf(file, "%s" , line);
        //number = strtok(line; ",");
        while( number != NULL ){
            mat[i][j] = atoi(number);
            j++;
            //number = strtok(NULL, ",");
        }
        printf("\n");
        i++;
    }
}

void printMatrix(int mat[Haut_train][Long_train]){

    for(int i = 0; i < Haut_train ; i++){
        for(int j = 0; j < Long_train  j++){
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }
}


















void affichage(char **mat, char sentence[]){
    
    int Haut = 0, Long = 0; 

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


