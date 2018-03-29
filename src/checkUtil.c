#include "checkUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIDE ' '
 

    char* itoa(int val, int base){
		static char buf[32] = {0};
		int i = 30;
		for(; val && i ; --i, val /= base)
			buf[i] = "0123456789abcdef"[val % base];
		return &buf[i+1];
	}
	
	int numX(char **board,int height, int width){
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
	
	int numO(char **board,int height, int width){
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
	
	/**
	 * \fn int checkEmpty1(char **board,int num,int numOfrow)
	 * \brief Verifie si une case est valide
	 * \param board : le plateau de jeu 
	 * \param num : numero de la colonne choisie
	 * \pram numOfrow : numero de ligne du sommet de la colonne num
	 * \return 1 si la case est valide , 0 sinon 
	 */
	int checkEmpty1(char **board,int num,int numOfrow, int height, int width){
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
	
	/**
	 * \fn int checkEmpty(char **board)
	 * \brief Vérifie si le tableau de jeu est vide
	 *
	 * \param board le plateau de jeu
	 * 
	 * \return 1 si board est vide, 0 sinon
	 */
	int checkEmpty(char **board,int height, int width){
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
		
	//TESTS
	
	//numX
    
    void TestnumX_1(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        board[0][0]='X';
        board[0][1]='X';
        board[1][0]='X';
        board[1][1]='O';
        int actual = numX(board,height,width);
        int expected = 3;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    void TestnumX_2(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        board[0][0]='O';
        board[0][1]='O';
        board[1][0]='O';
        board[1][1]='O';
        int actual = numX(board,height,width);
        int expected = 0;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    void TestnumX_3(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        board[0][0]='X';
        board[0][1]='X';
        board[1][0]='X';
        board[1][1]='X';
        int actual = numX(board,height,width);
        int expected = 4;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    //numO
    
    void TestnumO_1(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        board[0][0]='X';
        board[0][1]='X';
        board[1][0]='X';
        board[1][1]='O';
        int actual = numO(board,height,width);
        int expected = 1;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    void TestnumO_2(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        board[0][0]='O';
        board[0][1]='O';
        board[1][0]='O';
        board[1][1]='O';
        int actual = numO(board,height,width);
        int expected = 4;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    void TestnumO_3(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        board[0][0]='X';
        board[0][1]='X';
        board[1][0]='X';
        board[1][1]='X';
        int actual = numO(board,height,width);
        int expected = 0;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    //checkEmpty1
    
    void TestcheckEmpty1_1(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        board[0][1]='X';
        board[1][0]='X';
        board[1][1]='X';
        int actual = checkEmpty1(board,0,0,height,width);
        int expected = 1;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    void TestcheckEmpty1_2(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        board[0][1]='X';
        board[1][0]='X';
        board[1][1]='X';
        int actual = checkEmpty1(board,1,0,height,width);
        int expected = 0;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    //checkEmpty
    
    void TestcheckEmpty_1(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        board[0][1]='X';
        board[1][0]='X';
        board[1][1]='X';
        int actual = checkEmpty(board,height,width);
        int expected = 0;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    void TestcheckEmpty_2(CuTest *tc) {
        char **board;
        int height=2;
        int width=2;
        int i, j;
        board = (char **)malloc(height*sizeof(char *));
		for(i=0; i<height; i++){
			board[i]=malloc(width*sizeof(char));
			for(j=0; j<width; j++)
			{
				board[i][j]= VIDE;
			}
		}
        int actual = checkEmpty(board,height,width);
        int expected = 1;
        CuAssertStrEquals(tc, itoa(expected,10), itoa(actual,10));
    }
    
    
   
    CuSuite* StrUtilGetSuite() {
        CuSuite* suite = CuSuiteNew();
        SUITE_ADD_TEST(suite, TestnumX_1);
        SUITE_ADD_TEST(suite, TestnumX_2);
        SUITE_ADD_TEST(suite, TestnumX_3);
        SUITE_ADD_TEST(suite, TestnumO_1);
        SUITE_ADD_TEST(suite, TestnumO_2);
        SUITE_ADD_TEST(suite, TestnumO_3);
        SUITE_ADD_TEST(suite, TestcheckEmpty1_1);
        SUITE_ADD_TEST(suite, TestcheckEmpty1_2);
        SUITE_ADD_TEST(suite, TestcheckEmpty_1);
        SUITE_ADD_TEST(suite, TestcheckEmpty_2);
        return suite;
    }
