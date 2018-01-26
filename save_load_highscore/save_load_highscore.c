#include "save_load_highscore.h"

void highscore(int high)
{
    int i=0, n=0, temp;
    int highs[highscores];
    FILE *highsc = fopen("highscores.text", "w");
    if (highsc == NULL){
        perror("Le fichier de highscore highscores.text ne peut être ouvert ou n'existe pas \n");
    }
    else{
        fscanf(highsc, "%d", &highs[i]);
        do
        {
           i++;
            if(fscanf(highsc, "%d", &n)!=EOF){
                highs[i]=n;
            }
            else {
        	   break;
            }
        }while(i<highscores);

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