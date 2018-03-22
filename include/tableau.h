#ifndef BASIC

#define BASIC
#include "util.h"



int numX(char **board);
int numO(char **board);
int checkEmpty(char **board);
int checkCol(int num, char **board);
int checkEmpty1(char **board,int num,int numOfrow);
int checkfull(char **board);
int rowNum(int num, char **board);
void print(char **board);
int diagonal(char **board, char character);
int diagonal1(char **board, char character);
int horizontalScore(char **board, char character);
int verticalScore(char **board, char character);

#endif
