#include "CuTest.h"
#include <stdio.h>
    
	int numX(char **board,int height, int width);
	int numO(char **board,int height, int width);
	int checkEmpty1(char **board,int num,int numOfrow, int height, int width);
	int checkEmpty(char **board, int height, int width);
	  
    void TestnumX(CuTest *tc) ;
   
    CuSuite* StrUtilGetSuite();
