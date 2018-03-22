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

        if(num >0 && board[i][num-1] == VIDE){
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
int rowNum(int num, char **board){
    int i=0;
    for(i=0;i<height;i++){
        if(num == 0){
        	return 0;
        }
        if(board[i][num-1]!=VIDE){
        	break;
        }
    }
    return i-1;
}



void print(char **board){
    int i, j;
    for(i=0; i<height; i++){
        printf("\n+");

        for(j=0; j<width; j++){
            printf("---+");
        }
        
        printf("\n|");
   
        for(j=0; j<width; j++){
            printf(" %c |", board[i][j]);
        }
    }
    printf("\n+");

    for(i=0; i<width; i++){
        printf("---+");
    }

    printf("\n");
 
    for(i=1;i<=width;i++){
        printf("  %d ",i);
    }
   
    printf("\n\n\n");
}




int diagonal(char **board, char character){
    int u, v;
    int score1=0;
    for(u=(height-1);u>=3;u--)
    {
        for(v=0;v<(width-3);v++)
        {
            if(board[u][v] == character && board[u-1][v+1] == character && board[u-2][v+2] == character && board[u-3][v+3] == character){
                score1++;
            }
        }
    }
    return score1;
}

int diagonal1(char **board, char character){
    int u, v;
    int score1=0;
    for(u=(height-1);u>=3;u--)
    {
        for(v=(width-1);v>=3;v--)
        {
            if(board[u][v] == character && board[u-1][v-1] == character && board[u-2][v-2] == character && board[u-3][v-3] == character){
                score1++;
            }
        }
    }
    return score1;
}
int horizontalScore(char **board, char character){
    int u, v;
    int score1=0;
    for(u=0;u<height;u++)
    {
        for(v=0;v<(width-3);v++)
        {
            if(board[u][v] == character && board[u][v+1] == character && board[u][v+2] == character && board[u][v+3] == character){
                score1++;
            }
        }
    }
    return score1;
}
int verticalScore(char **board, char character){
    int u, v;
    int score1=0;
    for(v=0;v<width;v++)
    {
        for(u=0;u<(height-3);u++)
        {
            if(board[u][v] == character && board[u+1][v] == character && board[u+2][v] == character && board[u+3][v] == character){
                score1++;
            }
        }
    }
    return score1;
}
