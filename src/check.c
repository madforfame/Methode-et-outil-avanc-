
/**
 * \file 
 * \brief methodes de vérification d'entrées 
 */

#include "check.h"

#ifdef KLEE
#include <klee/klee.h>
#endif



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
    #ifndef KLEE
            printf("\nPlease enter a number between 1 and %d to play\n", width);
            printf("if you want to undo, press 0\n");
	        printf("if you want to redo, press -3, to load, press -1, to save, press -2\n");
	        #endif
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
	#ifndef KLEE
	int err =0;
	#else
	int err=1;
	#endif
	
	do{

		#ifdef KLEE
		klee_make_symbolic(&num, sizeof(int), "err check.c");
		#else
		err=scanf("%i", &num);
		#endif
		
		#ifndef KLEE
		getchar();
		#endif
		if(err<1){
			#ifndef KLEE
			printf("\nPlease enter a number: ");
			#endif
		}
	}while(err<1);
    return num;
}
