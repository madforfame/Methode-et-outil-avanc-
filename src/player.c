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
 * \param num variable de stockage de l'entier lu
 * \param board le plateau de jeu
 * \param width la largeur du plateau de jeu
 * 
 * \return l'entrée utilisateur valide
 */
int checknum(int num, char **board ,int width){
    while((num<-3) || (num>width))
    {
        print(board);
    
            printf("\nPlease enter a number between 1 and %d to play\n", width);
            printf("if you want to undo, press 0\n");
	        printf("if you want to redo, press -3, to load, press -1, to save, press -2\n");
            num = checkentier(num);
       
    }
    return num;
}

/**
 * \fn int checkentier(int num)
 * \brief Récupère l'entrée de l'utilisateur jusqu'à ce qu'elle soit valide soit un entier
 *
 * \param num variable de stockage de l'entier lu
 * 
 * \return l'entrée utilisateur valide
 */
int checkentier(int num){
	int err =0;
	
	while(err<1){
		err=scanf("%d", &num);
		getchar();
		if(err<1){
			printf("\nPlease enter a number: ");
		}
	}
    return num;
}
