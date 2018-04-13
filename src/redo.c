/**
 * \file 
 * \brief methodes de undo redo
 */



#include "redo.h"

/**
 * \fn void undoRedoLimit(int num, int *undoCounter, int *redoCounter)
 * \brief vérification de pouvoir faire un redo 
 * \param num :  0 pour le undo , -3 pour le redo
 * \param undocounter : nombre de undo réalisé 
 * \param redoCounter : nombre de redo réalisé 
 * 
 */

void undoRedoLimit(int num, int *undoCounter, int *redoCounter){
    if(num == 0){
        *undoCounter += 1;
    }
    else if(num == -3){
        *redoCounter += 1;
    }
    else{
        *undoCounter = 0;
        *redoCounter = 0;
    }
}

/**
 * \fn void undoRedo(char *x, char **board, int num, int *undoCol,
               int *undoRow, int *k, int *l, int *z,
               int *redoCol, int *redoRow, int *q, int width)

 * \brief manipulation des undo redo
 * \param x : le charactere à inserer
 * \param board : le plateau de jeu
 * \param num : entree de joueur
 * \param undoCol : tableau indiquant les colonnes des jetons insérés depuis le debut de la partie 
 * \param undoRow : tableau indiqaunt les lignes des jetons insérés depuis le debut de la partie
 * \param k : pointeur sur la variable contenant le nombre de cases restantes dans la dernière colonne jouée
 * \param q : pointeur sur l'indice des  tableaux undoCol undoRow
 * \param l : nombre de cases vides de la colonne num dans board
 * \param z : pointeur sur l'indice des  tableaux RedoCol redoRow
 * \param redoCol : tableau indiquant les colonnes des jetons insérés depuis le debut de la partie 
 * \param redoRow : tableau indiqaunt les lignes des jetons insérés depuis le debut de la partie
 * \param width : la largeur du plateau de jeu
 * 
 * 
 */

void undoRedo(char *x, char **board, int num, int *undoCol,
               int *undoRow, int *k, int *l, int *z,
               int *redoCol, int *redoRow, int *q, int width){
        static int ccounter = 0, dcounter = 0;
        if(num != 0 && !checkCol(num, board) && num != -3 && !(num<-3) && !(num>width) && !(num == -2)){
            undoCol[*q] = num-1;
           
            *k = rowNum(num, board);
            undoRow[*q] = *k;
           
        }
        

        if(num != 0 && !checkCol(num, board) && num != -3 && !(num<-3) && !(num>width) && !(num == -2)){
            redoCol[*z] = num-1;
            *l = rowNum(num, board);
            redoRow[*z] = *l;
            *z+=1;
                
         
        }
        if(num == 0){
            ccounter +=1;
            board[undoRow[(*q-1)]][undoCol[(*q-1)]] = VIDE;
            board[undoRow[(*q-1)]][undoCol[(*q-1)]] = VIDE;
            print(board);
            *q-=1;
            *z-=1;
        }
        else if(num == -3){
            dcounter += 1;
            if((dcounter <= ccounter)){
                board[redoRow[*z]][redoCol[*z]] = *x;
                print(board);
                *q+=1;
                undoCol[*q] = redoCol[*z+1];
                undoRow[*q] = redoRow[*z+1];
                *z+=1;
            }
        }
        else if(num == -1){
 #ifndef KLEE
            printf("Game Loaded Successfully");
            #endif
     
        }
        else if(num == -2){
  #ifndef KLEE
            printf("Game saved Successfully");
            #endif
            print(board);
  
        }
        else{
            *q+=1;
            player(board,num,*x);
            ccounter = 0;
            dcounter = 0;
        }
}
