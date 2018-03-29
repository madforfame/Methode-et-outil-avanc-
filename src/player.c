/**
* \file
* \brief Méthodes permettant à l'utilisateur d'inserer un jeton 
*/

#include "player.h"

/**
 * \fn void player(char **board, int num, char character)
 * \insere un jeton dans le tableau à la colonne choisie 
 *
 * \param board le plateau de jeu
 * \param num : numero de colonne
 * \param character : le jeton a inserer 
 */
void player(char **board, int num, char character){
    int i;
    for(i=(height-1); i>=0 && board[i][num-1]!=VIDE;i--){}// supprimer le break 
    if(board[i][num-1]==VIDE){
        board[i][num-1] = character;
    }
    print(board);
}


