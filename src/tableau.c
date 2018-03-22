/**
* \file
* \brief De gestion du tableau de jeu: affichage et modifications du contenu
*/

#include "tableau.h"

/**
 * \fn int numX(char **board)
 * \brief Compte le nombre de "X" dans le tableau de jeu
 *
 * \param board le plateau de jeu
 * 
 * \return le nombre de "X" dans board
 */
int numX(char **board){
    int i, j, counter=0;
    for(i=height-1;i>=0;i--){
        for(j=width-1;j>=0;j--){
            if(board[i][j] == 'X'){;
            	counter+=1;
            }
        }
    }
    return counter;
}

/**
 * \fn int numO(char **board)
 * \brief Compte le nombre de "O" dans le tableau de jeu
 *
 * \param board le plateau de jeu
 * 
 * \return le nombre de "O" dans board
 */
int numO(char **board){
    int i, j, counter=0;
    for(i=height-1;i>=0;i--){
        for(j=width-1;j>=0;j--){
            if(board[i][j] == 'O'){;
            	counter+=1;
            }
        }
    }
    return counter;
}

/**
 * \fn int checkEmpty1(char **board,int num,int numOfrow)
 * \brief ???
 */
int checkEmpty1(char **board,int num,int numOfrow){
    if(numOfrow==(height-1) && board[numOfrow][num]==VIDE){
        return 1;
    }
    else if(numOfrow+1==height){
        if(board[numOfrow][num]==VIDE){
            return 1;
        }
    }
    else if(board[numOfrow+1][num]!=VIDE && board[numOfrow][num]==VIDE){
        return 1;
    }
    return 0;
}

/**
 * \fn int checkEmpty(char **board)
 * \brief Vérifie si le tableau de jeu est vide
 *
 * \param board le plateau de jeu
 * 
 * \return 1 si board est vide, 0 sinon
 */
int checkEmpty(char **board){
    int n, m;
    for(n=0;n<height;n++){
        for(m=0;m<width;m++){
            if(board[n][m] !=VIDE){
                return 0;
            }
        }
    }
    return 1;
}

/**
 * \fn int checkCol(int num, char **board)
 * \brief Vérifie si une colonne est pleine
 *
 * \param num numéro de la colonne
 * \param board le plateau de jeu
 * 
 * \return 1 si la colonne est vide, 0 sinon
 */
int checkCol(int num, char **board){
    int i, counter=0;
    for(i=height-1;i>=0;i--){

        if(num >0 && board[i][num-1] == VIDE){
            counter = 0;
            break;
        }
        else{
            counter = 1;
        }
    }
    return counter;
}

/**
 * \fn int checkfull(char **board)
 * \brief Vérifie si une le tableau de jeu est plein
 *
 * \param board le plateau de jeu
 * 
 * \return 1 si board est plein, 0 sinon
 */
int checkfull(char **board){
    int i, j;
    for(i=0; i<height; i++)
    {
        for(j=0; j<width; j++)
        {
            if(board[i][j] == VIDE)
            {
                return 1;
            }
        }

    }
    return 0;
}

/**
 * \fn int rowNum(int num, char **board)
 * \brief Compte le nombre de cases vides d'une colonne ???
 *
 * \param num le numéro de la colonne
 * \param board le plateau de jeu
 * 
 * \return le nombre de cases vides de la colonne num dans board
 */
int rowNum(int num, char **board){
    int i=0;
    for(i=0;i<height;i++){
        if(num == 0){
        	return 0;
        }
        if(board[i][num-1]!=VIDE){
        	break;
        }
    }
    return i-1;
}

/**
 * \fn void print(char **board)
 * \brief Affiche le tableau de jeu
 *
 * \param board le plateau de jeu
 */
void print(char **board){
    int i, j;
    for(i=0; i<height; i++){
        printf("\n+");

        for(j=0; j<width; j++){
            printf("---+");
        }
        
        printf("\n|");
   
        for(j=0; j<width; j++){
            printf(" %c |", board[i][j]);
        }
    }
    printf("\n+");

    for(i=0; i<width; i++){
        printf("---+");
    }

    printf("\n");
 
    for(i=1;i<=width;i++){
        printf("  %d ",i);
    }
   
    printf("\n\n\n");
}

/**
 * \fn int diagonal(char **board, char character)
 * \brief Compte le nombre de points en diagonale pour le caractère donné (diagonale de gauche à droite ?)
 *
 * \param board le plateau de jeu
 * \param character le caractère à vérifier
 * 
 * \return nombre de fois ou 4 symboles character sont alignés en diagonale
 */
int diagonal(char **board, char character){
    int u, v;
    int score1=0;
    for(u=(height-1);u>=3;u--)
    {
        for(v=0;v<(width-3);v++)
        {
            if(board[u][v] == character && board[u-1][v+1] == character && board[u-2][v+2] == character && board[u-3][v+3] == character){
                score1++;
            }
        }
    }
    return score1;
}

/**
 * \fn int diagonal1(char **board, char character)
 * \brief Compte le nombre de points en diagonale pour le caractère donné (diagonale de droite à gauche ?)
 *
 * \param board le plateau de jeu
 * \param character le caractère à vérifier
 * 
 * \return nombre de fois ou 4 symboles character sont alignés en diagonale
 */
int diagonal1(char **board, char character){
    int u, v;
    int score1=0;
    for(u=(height-1);u>=3;u--)
    {
        for(v=(width-1);v>=3;v--)
        {
            if(board[u][v] == character && board[u-1][v-1] == character && board[u-2][v-2] == character && board[u-3][v-3] == character){
                score1++;
            }
        }
    }
    return score1;
}

/**
 * \fn int horizontalScore(char **board, char character)
 * \brief Compte le nombre de points en horizontal pour le caractère donné
 *
 * \param board le plateau de jeu
 * \param character le caractère à vérifier
 * 
 * \return nombre de fois ou 4 symboles character sont alignés en horizontal
 */
int horizontalScore(char **board, char character){
    int u, v;
    int score1=0;
    for(u=0;u<height;u++)
    {
        for(v=0;v<(width-3);v++)
        {
            if(board[u][v] == character && board[u][v+1] == character && board[u][v+2] == character && board[u][v+3] == character){
                score1++;
            }
        }
    }
    return score1;
}

/**
 * \fn int verticalScore(char **board, char character)
 * \brief Compte le nombre de points en vertical pour le caractère donné
 *
 * \param board le plateau de jeu
 * \param character le caractère à vérifier
 * 
 * \return nombre de fois ou 4 symboles character sont alignés en vertical
 */
int verticalScore(char **board, char character){
    int u, v;
    int score1=0;
    for(v=0;v<width;v++)
    {
        for(u=0;u<(height-3);u++)
        {
            if(board[u][v] == character && board[u+1][v] == character && board[u+2][v] == character && board[u+3][v] == character){
                score1++;
            }
        }
    }
    return score1;
}
