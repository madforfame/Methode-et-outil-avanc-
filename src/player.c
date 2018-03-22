/**
* \file
* \brief Méthodes permettant à l'utilisateur de jouer ???
*/

#include "player.h"

/**
 * \fn void player(char **board, int num, char character)
 * \brief ???
 *
 * \param board le plateau de jeu
 * \param num  A CONFIRMER
 * \param character A CONFIRMER
 */
void player(char **board, int num, char character){
    int i;
    for(i=(height-1); i>=0 && board[i][num-1]!=VIDE;i--){}// supprimer le break 
    if(board[i][num-1]==VIDE){
        board[i][num-1] = character;
    }
    print(board);
}

/**
 * \fn int checknum(int num, char **board ,int width)
 * \brief Récupère l'entrée de l'utilisateur jusqu'à ce qu'elle soit valide
 *
 * \param num première entrée utilisateur
 * \param board le plateau de jeu
 * \param width la largeur du plateau de jeu
 * 
 * \return l'entrée utilisateur valide
 */
int checknum(int num, char **board ,int width){
    while((num<-3) || (num>width))
    {
        print(board);
    
            printf("\nPlease enter a number between 1 and %d :", width);
            scanf("%d", &num);
       
    }
    return num;
}
