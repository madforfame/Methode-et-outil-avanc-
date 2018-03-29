/**
* \file
* \brief Méthodes permettant les sauvegardes et chargements de l'état du jeu ainsi que le traitement des highscores
*/

#include "save_load_highscore.h"

/**
 * \fn void highscore(int high)
 * \brief Ecris le highscore dans le fichier de highscore si supérieur
 *
 * \param high valeur du score
 */
void highscore(int high){
    int i=0, n=0, temp, ret;
    int highs[highscores];
    FILE *highsc = fopen("highscores.text", "r+");
    if (highsc == NULL){
        perror("Le fichier de highscore highscores.text ne peut être ouvert ou n'existe pas \n");
    }
    else{
        while(i<highscores){
            if((ret = fscanf(highsc, "%d", &n))!=EOF && ret!=0 ){
                highs[i]=n;
                i++;
            }
            else {
        	   break;
            }
        }

        while(highscores>i){
    	   highs[i]=0;
    	   i++;
        }
        
        i--;
        
        if(high>highs[i])
        {
            highs[i] = high;
        }
        while(highs[i]>highs[i-1] && i>0)
        {
            temp = highs[i-1];
            highs[i-1] = highs[i];
            highs[i] = temp;
            i--;
        }
        highsc = fopen("highscores.text", "w");
        printf("\n\t      High Scores\n\t\t*****");
        for(i=0; i<highscores; i++)
        {
            fprintf(highsc,"%d ", highs[i]);
            printf("\n\t\t* %d *", highs[i]);
        }
        printf("\n\t\t*****");
        fclose(highsc);
    }
}

/**
 * \fn void saveLoad(int *num, char **board)
 * \brief Sauvegarde ou charge un état de jeu selon l'entrée
 *
 * \param num entrée utilisateur, définis si on fait un save ou un load
 * \param board le plateau de jeu
 */
void saveLoad(int *num, char **board){
    FILE *pfile;
    int r, t;
    if(*num == -2){
    
            printf("Game Saved Successfully");
     
        pfile = fopen("save.txt", "w");
        for(r=height-1;r>=0;r--){
            for(t=width-1;t>=0;t--){
                fprintf(pfile, "%c", board[r][t]);
            }
        }
        fclose(pfile);
    }
    if(*num == -1){
        pfile = fopen("save.txt", "r");
        if (pfile == NULL){
		perror("Le fichier de sauvegarde save.txt ne peut être ouvert ou n'existe pas \n");
		}
		else{
			for(r=height-1;r>=0;r--){
				for(t=width-1;t>=0;t--){
					fscanf(pfile, "%c", &board[r][t]);
				}
			}
			fclose(pfile);
		}
    }
}
