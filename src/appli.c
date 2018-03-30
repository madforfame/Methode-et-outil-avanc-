/**
* \file
* \brief Fichier principal du puissance4, contient le main
*/

#include "tableau.h"
#include "niveau.h"
#include "redo.h"
#include "save_load_highscore.h"
#include "player.h"
#include "check.c"

void XMLformating();


/**
 * \fn int main(int argc, char *argv[])
 * \brief main: utilise toutes les méthodes d'affichage, de score et d'IA
 * 
 * \return EXIT_SUCCESS - Arrêt normal du programme.
 */
int main(int argc, char *argv[]){
    int high=0;
    XMLformating(argv[1]);
    char playAgain;
    do{
        int flag, score1=0, score2=0, *compUndoCol, undoCounter=0,
            redoCounter=0, compUndoCounter =0, choose;
        int i, j, num=0, *undoCol, k, *undoRow,
            *redoCol, *redoRow, l, *compUndoRow;
        static int q=0, z=0, d=0, c=0;
        char **board, x='X', o='O';
		undoCol = (int *)malloc(height*width*sizeof(int));
		redoCol = (int *)malloc(height*width*sizeof(int));
		undoRow = (int *)malloc(height*width*sizeof(int));
		redoRow = (int *)malloc(height*width*sizeof(int));
		compUndoCol = (int *)malloc(height*width*sizeof(int));
		compUndoRow = (int *)malloc(height*width*sizeof(int));
        for(i=0;i<height*width;i++){
            undoCol[i] = 0;
            redoCol[i] = 0;
            undoRow[i] = 0;
            redoRow[i] = 0;
            compUndoCol[i] = 0;
            compUndoRow[i] = 0;
        }
        
        playAgain = 'n';
        
        if(playAgain != 'y'){
			board = (char **)malloc(height*sizeof(char *));
			for(i=0; i<height; i++){
				board[i]=malloc(width*sizeof(char));
				for(j=0; j<width; j++)
				{
					board[i][j]= VIDE;
				}
			}
		}
		else{
			for(i=0; i<height; i++){
				for(j=0; j<width; j++){
					board[i][j]= VIDE;
				}
			}
		}
		printf("\n\n                     **** WELCOME TO THE GAME ****\n\n");
		printf("Player1 vs Player2: press 1 \n\nPlayer vs Computer: press 2 \n\n");
		choose = checkentier(choose);
        while((choose!=1 && choose!=2) || isalpha(choose)){
       
            printf("Enter 1 or 2\n");
	        printf("Player1 vs Player2: press 1 \n\nPlayer vs Computer: press 2 \n\n");
            choose = checkentier(choose);
           
        }
        if(choose == 1){
			int player=1;
            print(board);
            do{
                
	        printf("\nif you want to undo, press 0\n");
	        printf("if you want to redo, press -3, to load, press -1, to save, press -2\n");
            
                if((player==1) ||  (player==2)){
                    
                    if(player==1){
						printf("\nplayer 1 enter number of the column:");
					}
					else{
						printf("\nplayer 2 enter number of the column:");
					}
                    num = checkentier(num);
                    num = checknum(num,board,width);
                  
                    saveLoad(&num, board);
                    if(checkCol(num,board)){
                        while(num>0 && board[0][num-1]!=VIDE){
                            print(board);
                            
                            if(player==1){
								printf("Invalid input player 1. Do another move : ");
							}
							else{
								printf("Invalid input player 2. Do another move : ");
							}
							num = checkentier(num);
							num = checknum(num,board,width);
                            
                            saveLoad(&num, board);
                            if(num == 0 || num == -3){
                                break;
                            }
						}
                    }
                    if(redoCounter >= undoCounter){
                        while(num == -3){
                            print(board);
							printf("\ncannot redo!! play again");
							num = checkentier(num);
							num = checknum(num,board,width);
                            saveLoad(&num, board);
                            if(num == 0){
                                break;
                            }
                        }
                    }
                    while(num == 0 && checkEmpty(board)){
                        print(board);
                            printf("\ncannot undo! play again\n");
                            num = checkentier(num);
                            num = checknum(num,board,width);
                    
                        saveLoad(&num, board);
                        if(num == -3){
                            if(redoCounter >= undoCounter){
                                while(num == -3){
                                    print(board);
                                        printf("\ncannot redo!! play again");
                                        num = checkentier(num);
                                        num = checknum(num,board,width);
                                 
                                    if(num == 0){
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    undoRedoLimit(num,&undoCounter,&redoCounter);
                    if(player==1){
						undoRedo(&x,board,num,undoCol,undoRow,&k,&l,&z,redoCol,redoRow,&q,width);
						score1=horizontalScore(board,x)+verticalScore(board,x)+diagonal(board,x)+diagonal1(board,x);
						player=2;
                    }else{
						undoRedo(&o,board,num,undoCol,undoRow,&k,&l,&z,redoCol,redoRow,&q,width);
						score2=horizontalScore(board,o)+verticalScore(board,o)+diagonal(board,o)+diagonal1(board,o);
						player=1;
					}
                    
                    afficherScores(score1,score2);
                }
            }while(checkfull(board));

            if(score2>score1){
                high=score2;
                printf("\nPLAYER 2 WINS");
              
            }
            else if(score1==score2){
                high=score1;
                printf("\nDRAW");
            }
            else{
                high=score1;
                printf("\nPLAYER 1 WINS");
            }
        }
        else{

                printf("\nEasy (press 1), Medium (press 2), Hard (press 3)\n");
                choose = checkentier(choose);
         
            while(choose!=1 && choose!=2 && choose!=3){
				printf("Enter 1 , 2 or 3\n");
				printf("\nEasy (press 1), Medium (press 2), Hard (press 3)\n");
				choose = checkentier(choose);
            
            }
            print(board);
            do{
				printf("\nif you want to undo, press 0\n");
				printf("if you want to redo, press -3, to load, press -1, to save, press -2\n");
				printf("\nenter number of the column:");
				num = checkentier(num);
				num = checknum(num,board,width);
             
                saveLoad(&num, board);
                if(checkCol(num,board)){
                    while(num>0 && board[0][num-1]!=VIDE)
                      {
                        print(board);
                            printf("Invalid input number 3. Do another move : ");
                            num = checkentier(num);
                            num = checknum(num,board,width);
                     
                        saveLoad(&num, board);
                        if(num == 0 || num == -3){
                            break;
                        }
                      }
                }
                if(redoCounter >= compUndoCounter){
                    while(num == -3){
                        print(board);
                            printf("\ncannot redo!! play again");
                            num = checkentier(num);
                            num = checknum(num,board,width);
                 
                        saveLoad(&num, board);
                        if(num == 0){
                            break;
                        }
                    }
                }
                while(num == 0 && checkEmpty(board)){
                    print(board);
                        printf("\ncannot undo! play again");
                        num = checkentier(num);
                        num = checknum(num,board,width);
                    saveLoad(&num, board);
                    if(num == -3){
                        if(redoCounter >= compUndoCounter){
                            while(num == -3){
                                print(board);
                                printf("\ncannot redo!! play again");
                                num = checkentier(num);
                                num = checknum(num,board,width);
                             
                                saveLoad(&num, board);
                                if(num == 0){
                                    break;
                                }
                            }
                        }
                    }
                }
                undoRedoLimit(num,&undoCounter,&redoCounter);
                undoRedo(&x,board,num,undoCol,undoRow,&k,&l,&z,redoCol,redoRow,&q,width);
                score1=horizontalScore(board,x)+verticalScore(board,x)+diagonal(board,x)+diagonal1(board,x);
             
                afficherScores(score1,score2);
             
                switch(choose)
                {
                    case 1:{
                        if(num != 0 && num != -1 && num != -2){
                            Easy(board, &num);
                            compUndoCol[d++] = num-1 ;
                            compUndoRow[c++] = rowNum(num,board)+1;
                            compUndoCounter = 0;
                        }
                        if(num == 0){
                            compUndoCounter += 1;
                            c--;
                            d--;
                            board[compUndoRow[c]][compUndoCol[d]] = VIDE;
                        }
                        break;
                    }
                    case 2: {
                        if(num != 0 && num != -1 && num != -2){
                            flag=0;
                            if(Medium(board,x,&num)==1){
                            	flag=1;
                            }
                            if(flag!=1){
                            	Easy(board, &num);
                            }
                            compUndoCol[d++] = num-1 ;
                            compUndoRow[c++] = rowNum(num,board)+1;
                            compUndoCounter = 0;
                        }
                        if(num == 0){
                            compUndoCounter += 1;
                            c--;
                            d--;
                            board[compUndoRow[c]][compUndoCol[d]] = VIDE;
                        }
                        break;
                    }
                    case 3:{
                        if(num != 0 && num != -1 && num != -2){
                            Hard(board,&num);
                            compUndoCol[d++] = num-1 ;
                            compUndoRow[c++] = rowNum(num,board)+1;
                            compUndoCounter = 0;
                        }
                        if(num == 0){
                            compUndoCounter += 1;
                            c--;
                            d--;
                            board[compUndoRow[c]][compUndoCol[d]] = VIDE;
                        }
                        break;
                    }
                }
                print(board);
                score2=horizontalScore(board,o)+verticalScore(board,o)+diagonal(board,o)+diagonal1(board,o);
               
                afficherScores(score1,score2);
              
            }while(checkfull(board));
            if(score2>score1){
                high=score2;
       
                printf("\nComputer WINS\n");
               
            }
            else if(score1==score2){
                high=score1;
     
                printf("\nDRAW\n");
     
            }
            else{
                high=score1;
                printf("\nUser WINS\n");
            }
        }
        highscore(high);
   
        printf("\nif you you want to play again press y, else press any key\n");
        scanf("\n%c",&playAgain);
        
        q=0; z=0; d=0; c=0;
      
      
    }while(playAgain == 'y');
    return 0;
}

/**
 * \fn XMLformating(char* nomfichier)
 * \brief Lecture du fichier de config au format XML
 * 
 * \param nomfichier le nom du fichier de config à lire
 */
void XMLformating(char* nomfichier){
    char c, c1, c2, c3, c4, c5, c6, c7, widthTag, heightTag, highscoresTag;
    int start=0, End=0, flag1=0, flag2=0, widthflag=0, heightflag=0, highscoresflag=0;
    FILE *file= fopen(nomfichier, "r");
    if (file == NULL){
		perror("Le fichier xml ne peut être ouvert ou n'existe pas");
		exit(0);
	}
	else{
		fscanf(file,"< Configurations %c", &c);
		if(c=='>'){
			flag1=1;
			start=ftell(file);
		}
		else{
			while(fscanf(file,"%c", &c1)!=EOF){
				fscanf(file,"< Configurations %c", &c2);
				if(c2=='>'){
					flag1=1;
					start=ftell(file);
					break;
				}
			}
		}
		while(fscanf(file,"%c", &c3)!=EOF){
			fscanf(file,"< / Configurations %c", &c4);
			if(c4=='>'){
				flag2=1;
				End=ftell(file);
				break;
			}
		}
		if(flag1==1 && flag2==1)
		{
			fseek(file,start,SEEK_SET);
			while(fscanf(file,"%c", &c5)!=EOF){
				fscanf(file,"< Width >%d < / Width %c", &width, &widthTag);
				if( (widthTag=='>') && (width>=4) && ftell(file)<End ) {
					widthflag=1;
					break;
				}
			}
			fseek(file,start,SEEK_SET);
			while(fscanf(file,"%c", &c6)!=EOF){
				fscanf(file,"< Height >%d < / Height %c", &height, &heightTag);
				if( (heightTag=='>') && (height>=4) && ftell(file)<End ) {
					heightflag=1;
					break;
				}
			}
			fseek(file,start,SEEK_SET);
			while(fscanf(file,"%c", &c7)!=EOF){
				fscanf(file,"< Highscores >%d < / Highscores %c", &highscores, &highscoresTag);
				if( (highscoresTag=='>') && (highscores>=4) && ftell(file)<End ) {
					highscoresflag=1;
					break;
				}
			}
		}
		if(width==0 || widthflag==0){
			width=7;
			printf("Incorrect file format, default value of width (7) is loaded\n");
		}
		if(height==0 || heightflag==0){
			height=6;
			printf("Incorrect file format, default value of height (6) is loaded\n");
		}
		if(highscores==0 || highscoresflag==0){
			highscores=5;
			printf("Incorrect file format, default value of highscore list (5) is loaded\n");
		}
		fclose(file);
	}
}
