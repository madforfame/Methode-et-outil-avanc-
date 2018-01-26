
#include "tableau.h"



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

int checkEmpty1(char **board,int num,int numOfrow)
{
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

int checkCol(int num, char **board){
    int i, counter=0;
    for(i=height-1;i>=0;i--){
        if(board[i][num-1] == VIDE){
            counter = 0;
            break;
        }
        else{
            counter = 1;
        }
    }
    return counter;
}

int checkfull(char **board)
{
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
