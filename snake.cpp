#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <time.h>
#include <stdbool.h>

int x = 16;
int y = 5;
int historyX[30];
int historyY[30];
int tailLength = 0;
int length = 1;
int niveau = 1;
int oldPosX;
int oldPosY;
int appleCount;
int randomX_1, randomY_1, randomX_2, randomY_2, randomX_3, randomY_3;




//ici y a le monde, le serpent et les fruits



int init(int xPos, int yPos, int randomX_1, int randomY_1, int randomX_2, int randomY_2, int randomX_3, int randomY_3, int length, int gameOver){

    int i, j, k;
    int xPosTail, yPosTail;
    char player, fruit;
    char world[5][16] = {
        {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}
    };

    //trois pommes mises au hasard
    
    
    
    for(i = 0; i < 1; i++){
        fruit = world[randomY_1][randomX_1] = '*';
        for(j = 0; j < 1; j++){
            fruit = world[randomY_2][randomX_2] = '*';
            for(k = 0; k < 1; k++){
                fruit = world[randomY_3][randomX_3] = '*';
            }
        }
    }
    
    
    //souvegarder



    //le serpent, sa position et son apparence DANS CETTE BOUCLE POUR AGRANDIR LE SERPENT
    
    
    
    historyX[tailLength] = xPos;
    historyY[tailLength] = yPos;

    tailLength++;

    if(tailLength == length){
        tailLength = 0;
    }

    for(i = 0; i < length; i++){
        xPosTail = historyX[i];
        yPosTail = historyY[i];
        player = world[yPosTail][xPosTail] = '#';
    }



    //
    for(i = 0; i < length; i++){
        for(j = i + 1; j < length; j++){
            if(historyX[i] == historyX[j] && historyY[i] == historyY[j]){
                gameOver = 1;
            }
        }
    }





    //l'init de la map[
    
    for(i = 0; i < y; i++){
            printf("\n\t\t\t\t");
        for(j = 0; j < x; j++){
            printf("%c  ", world[i][j]);
        }
    }

    //return world[y][x];
    return gameOver;
}

int fruits(int xPos, int yPos, int length){
	
	
	

    //si le serpent mange les 3 pommes
    
    
    
    
    if(randomX_1 == xPos && randomY_1 == yPos){
        randomX_1 = x + y;
        randomY_1 = x + y;
        appleCount++;
    }
    if(randomX_2 == xPos && randomY_2 == yPos){
        randomX_2 = x + y;
        randomY_2 = x + y;
        appleCount++;
    }
    if(randomX_3 == xPos && randomY_3 == yPos){
        randomX_3 = x + y;
        randomY_3 = x + y;
        appleCount++;
    }

    if(appleCount % 3 == 0 && appleCount != 0){
        do{
            randomX_1 = rand()% (x - 2) + 1;
            randomY_1 = rand()% (y - 2) + 1;
        } while(randomX_1 == xPos && randomY_1 == yPos);
        //
        do{
            randomX_2 = rand()% (x - 2) + 1;
            randomY_2 = rand()% (y - 2) + 1;
        } while(randomX_2 == xPos && randomY_2 == yPos);
        //
        do{
            randomX_3 = rand()% (x - 2) + 1;
            randomY_3 = rand()% (y - 2) + 1;
        } while(randomX_3 == xPos && randomY_3 == yPos);
        //

        appleCount = 0;
        length++;
    }


    printf("%i\n", length);
    return randomX_1, randomY_1, randomX_2, randomY_2, randomX_3, randomY_3, length, appleCount;

}
void createFile() {
    FILE *fp;
    fp = fopen("./save.txt", "w+");
    printf("Fichier crée");
    fprintf(fp, "%d", niveau);
    fclose(fp);
}




    //gameStart();




void StarGame() {

    time_t t;
    srand((unsigned) time(&t));

    int gameOver = 0;



    //pos au hasard des pommes pour chaque fois qu'on les mange
    
    
    int xPos, yPos, deltaX, deltaY, direction;

    //direction -> 1 = up, 2 = down, 3 = left, 4 = right    
    char player;
    xPos = yPos = 2;
    deltaX = deltaY = appleCount = 0;

    do{
        randomX_1 = rand()% (x - 2) + 1;
        randomY_1 = rand()% (y - 2) + 1;
    } while(randomX_1 == xPos && randomY_1 == yPos);
    //
    do{
        randomX_2 = rand()% (x - 2) + 1;
        randomY_2 = rand()% (y - 2) + 1;
    } while(randomX_2 == xPos && randomY_2 == yPos);
    //
    do{
        randomX_3 = rand()% (x - 2) + 1;
        randomY_3 = rand()% (y - 2) + 1;
    } while(randomX_3 == xPos && randomY_3 == yPos);
    //

    while(gameOver == 0){

        int i, j;

        //fruits(xPos, yPos, length);

        if(randomX_1 == xPos && randomY_1 == yPos){
        randomX_1 = x + y;
        randomY_1 = x + y;
        appleCount++;
    }
    if(randomX_2 == xPos && randomY_2 == yPos){
        randomX_2 = x + y;
        randomY_2 = x + y;
        appleCount++;
    }
    if(randomX_3 == xPos && randomY_3 == yPos){
        randomX_3 = x + y;
        randomY_3 = x + y;
        appleCount++;
    }

    if(appleCount % 3 == 0 && appleCount != 0){
        do{
            randomX_1 = rand()% (x - 2) + 1;
            randomY_1 = rand()% (y - 2) + 1;
        } while(randomX_1 == xPos && randomY_1 == yPos);
        //
        do{
            randomX_2 = rand()% (x - 2) + 1;
            randomY_2 = rand()% (y - 2) + 1;
        } while(randomX_2 == xPos && randomY_2 == yPos);
        //
        do{
            randomX_3 = rand()% (x - 2) + 1;
            randomY_3 = rand()% (y - 2) + 1;
        } while(randomX_3 == xPos && randomY_3 == yPos);
        //

        appleCount = 0;
        length++;
        if ((length - 1) % 5 == 0 && length - 1 != 0){
                    niveau++;
                }

         }



        //l? il print la map avec la fonction init
        
        
        printf("\n\n\t\t\t                         SNAKE GAME Maamar & Cedric                   \n");
        printf("\t\t\t__________________________________________________________________________\n");
        if (length - 1 < 2){
            printf("\n\t\t                                        NIVEAU: %i   POINT: %i                                      \n",  niveau ,length - 1);
        } else if(length - 1 > 1 && length < 10){
            printf("\n\t\t                                         NIVEAU: %i   POINTS: %i                                      \n",  niveau ,length - 1);
        } else {
            printf("\n\t\t                                        NIVEAU: %i     POINTS: %i                                      \n",  niveau ,length - 1);
        }
        printf("\t\t\t                            _______________                                     \n");
        gameOver = init(xPos += deltaX, yPos += deltaY, randomX_1, randomY_1, randomX_2, randomY_2, randomX_3, randomY_3, length, gameOver);
        printf("\n\n\n\t\t\t     UP : Z  \tLEFT : Q  \tDOWN : S  \tRIGHT : D\n");

        usleep(100000);

        //l? il d?tecte les touches claviers
        
        
        player = getchar();
        switch(player){
            case 's' : deltaY = 1; direction = 2; deltaX = 0; break;
            //go down
            case 'z' : deltaY = -1; direction = 1; deltaX = 0; break;
            //go up
            case 'q' : deltaX = -1; direction = 3; deltaY = 0; break;
            //go left
            case 'd' : deltaX = 1; direction = 4; deltaY = 0; break;
            //go right
        }

        //avance seul

        system("clear");

        //si le serpent arrive aux limites de la map, il r?apparait de l'autre c?t?
        
        
        if (xPos == x - 1 && direction == 4){
            xPos = -1;
        } else if (xPos == 0 && direction == 3){
            xPos = x;
        }
        if (yPos == y - 1 && direction == 2){
            yPos = -1;
        } else if (yPos == 0 && direction == 1){
            yPos = y;
        }

    }

    printf("\n\n\t\t\t                   SNAKE GAME by Maamar & Cedric                   \n");
    printf("\t\t\t__________________________________________________________________________\n");
    if (length - 1 < 2){
        printf("\n\t\t                                       NIVEAU: %i  POINT: %i                                      \n", niveau , length - 1);
    } else if(length - 1 > 1 && length < 10){
        printf("\n\t\t                                        NIVEAU: %i  POINTS: %i                                      \n",  niveau ,length - 1);
    } else {
        printf("\n\t\t                                        NIVEAU: %i   POINTS: %i                                      \n", niveau , length - 1);
    } niveau ,
    printf("\t\t\t                            _______________                                     \n");
    gameOver = init(xPos += deltaX, yPos += deltaY, randomX_1, randomY_1, randomX_2, randomY_2, randomX_3, randomY_3, length, gameOver);
    printf("\n\n\n\t\t\t                       GAME OVER !!!                        \n");
    system("Pause");
   createFile();
    exit(0);
}


int main(){
      int choix = 0;
    printf("Veuillez selectionner une commande :");
    printf("\n\t1 - Lancez le jeu");
    printf("\n\t2 - Reprendre la partie");
    printf("\n\t0 - Quitter");
    do {
        scanf("%d", &choix);
        switch (choix) {
            case 1 : StarGame(); break;
            case 2 : StarGame(); break;
        }
    }
    while (choix != 0);
    printf("%d", choix);
       return 0;
}


