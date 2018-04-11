/**
* \file
* \brief Méthodes concernant le niveau de difficulté de l'ordinateur
*/

#include "niveau.h"

int width=0, height=0, highscores=0;

/**
 * \fn void Easy(char **board, int *num)
 * \brief Effectue un coup dans le jeu en difficulté Easy: coup aléatoire
 *
 * \param board le plateau de jeu
 * \param num : colonne choisie pour jouer 
 * \param pcharacter : caractère que doit jouer l'ordinateur 
 */
void Easy(char **board, int *num, char pcharacter){
    int i, j, flag, l;
    l = rand() % width;
    for(i=(height-1); i>=0; i--)
    {
        if(board[i][l]==VIDE)
        {
            board[i][l] = pcharacter;
            break;
        }
        flag = 0;
        while(i==0 && board[i][l]!=VIDE)
        {
            l = rand() % width;
            flag = 1;
        }
        for(j=(height-1); flag==1; j--)
        {
            if(board[j][l]==VIDE)
            {
                board[j][l] = pcharacter;
                break;
            }
        }
    }
    *num = l+1;
}

/**
 * \fn int Medium(char **board, char character, int *num)
 * \brief Joue un coup dans le jeu en difficulté Medium si possible
 *
 * \param board le plateau de jeu
 * \param character caractère avec lequel il cherche à aligner un 4eme pion
 * \param num : colonne choisie pour jouer 
 * \param pcharacter : caractère que doit jouer l'ordinateur 
 * 
 * \return 1 si coup joué, 0 sinon
 * 
 * Si peut aligner jouer à un endroit où 3 pions de même couleur sont alignés,
 * le fait et renvoie 1, renvoie 0 sinon
 */
int Medium(char **board, char character, int *num, char pcharacter){
    int i, j;
    for(i=height-1; i>=3; i--)
    {
        for(j=0; j<width; j++)
        {
            if(board[i][j] == character && board[i-1][j] == character && board[i-2][j] == character && board[i-3][j]==VIDE){
                board[i-3][j] = pcharacter;
                *num = j+1;
                return 1;
            }
        }
    }
    for(i=0;i<height;i++)
    {
        for(j=0;j<(width-3);j++)
        {
            if(board[i][j] == character && board[i][j+1] == character && board[i][j+2] == character && checkEmpty1(board,j+3,i)){
                board[i][j+3] = pcharacter;
                *num = j+3+1;
                return 1;
            }
            if(board[i][j+1] == character && board[i][j+2] == character && board[i][j+3] == character && checkEmpty1(board,j,i)){
                board[i][j] = pcharacter;
                *num = j+1;
                return 1;
            }
            if(board[i][j] == character && board[i][j+2] == character && board[i][j+3] == character && checkEmpty1(board,j+1,i)){
                board[i][j+1] = pcharacter;
                *num = j+1+1;
                return 1;
            }
            if(board[i][j] == character && board[i][j+1] == character && board[i][j+3] == character && checkEmpty1(board,j+2,i)){
                board[i][j+2] = pcharacter;
                *num = j+2+1;
                return 1;
            }
        }
    }
    for(i=height-1; i>=3; i--)
    {
        for(j=0;j<(width-3);j++)
        {
            if(board[i][j] == character && board[i-1][j+1] == character && board[i-2][j+2] == character && checkEmpty1(board,j+3,i-3)){
                board[i-3][j+3] = pcharacter;
                *num = j+3+1;
                return 1;
            }
            if(board[i-1][j+1] == character && board[i-2][j+2] == character && board[i-3][j+3] == character && checkEmpty1(board,j,i)){
                board[i][j] = pcharacter;
                *num = j+1;
                return 1;
            }
            if(board[i][j] == character && board[i-2][j+2] == character && board[i-3][j+3] == character && checkEmpty1(board,j+1,i-1)){
                board[i-1][j+1] = pcharacter;
                *num = j+1+1;
                return 1;
            }
            if(board[i][j] == character && board[i-1][j+1] == character && board[i-3][j+3] == character && checkEmpty1(board,j+2,i-2)){
                board[i-2][j+2] = pcharacter;
                *num = j+2+1;
                return 1;
            }
        }
    }
    for(i=height-1; i>=3; i--)
    {
        for(j=width-1; j>=3; j--)
        {
            if(board[i][j] == character && board[i-1][j-1] == character && board[i-2][j-2] == character && checkEmpty1(board,j-3,i-3)){
                board[i-3][j-3] = pcharacter;
                *num = j-3+1;
                return 1;
            }
            if(board[i-1][j-1] == character && board[i-2][j-2] == character && board[i-3][j-3] == character && checkEmpty1(board,j,i)){
                board[i][j] = pcharacter;
                *num = j+1;
                return 1;
            }
            if(board[i][j] == character && board[i-2][j-2] == character && board[i-3][j-3] == character && checkEmpty1(board,j-1,i-1)){
                board[i-1][j-1] = pcharacter;
                *num = j-1+1;
                return 1;
            }
            if(board[i][j] == character && board[i-1][j-1] == character && board[i-3][j-3] == character && checkEmpty1(board,j-2,i-2)){
                board[i-2][j-2] = pcharacter;
                *num = j-2+1;
                return 1;
            }
        }
    }
    return 0;
}


/**
 * \fn void Hard(char **board, int *num)
 * \brief Joue un coup dans le jeu en difficulté Hard.
 *
 * \param board le plateau de jeu
 * \param num :colonne choisie pour jouer 
 * \param pcharacter : caractère que doit jouer l'ordinateur 
 * 
 * Si possible joue un coup Medium, sinon Essaie d'aligner un pion avec deux autres pions de type O,
 * et si impossible joue un coup en Easy.
 */
void Hard(char **board, int *num, char pcharacter){
    int i, j;
    char x='X',o='O';
    if(Medium(board,x,num,pcharacter)==1){
    	return;
    }
    if(Medium(board,o,num,pcharacter)==1){
    	return;
    }
    for(i=height-1; i>=2; i--)
    {
        for(j=0; j<width; j++)
        {
            if(board[i][j] == pcharacter && board[i-1][j] == pcharacter && board[i-2][j]==VIDE)
            {
                board[i-2][j] = pcharacter;
                *num = j+1;
                return;
            }
        }
    }
    for(i=0;i<height;i++)
    {
        for(j=0;j<(width-2);j++)
        {
            if(board[i][j] == pcharacter && board[i][j+1] == pcharacter && checkEmpty1(board,j+2,i)){
                board[i][j+2] = pcharacter;
                *num = j+2+1;
                return;
            }
            if(board[i][j+1] == pcharacter && board[i][j+2] == pcharacter && checkEmpty1(board,j,i)){
                board[i][j] = pcharacter;
                *num = j+1;
                return;
            }
        }
    }
    for(i=height-1; i>=2; i--)
    {
        for(j=0;j<(width-2);j++)
        {
            if(board[i][j] == pcharacter && board[i-1][j+1] == pcharacter && checkEmpty1(board,j+2,i-2)){
                board[i-2][j+2] = pcharacter;
                *num = j+2+1;
                return;
            }
            if(board[i-1][j+1] == pcharacter && board[i-2][j+2] == pcharacter && checkEmpty1(board,j,i)){
                board[i][j] = pcharacter;
                *num = j+1;
                return;
            }
        }
    }
    for(i=height-1; i>=2; i--)
    {
        for(j=width-1; j>=2; j--)
        {
            if(board[i][j] == pcharacter && board[i-1][j-1] == pcharacter && checkEmpty1(board,j-2,i-2)){
                board[i-2][j-2] = pcharacter;
                *num = j-2+1;
                return;
            }
            if(board[i-1][j-1] == pcharacter && board[i-2][j-2] == pcharacter && checkEmpty1(board,j,i)){
                board[i][j] = pcharacter;
                *num = j+1;
                return;
            }
        }
    }
    Easy(board,num,pcharacter);
}
