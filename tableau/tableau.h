#ifndef BASIC

#define BASIC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define VIDE ' '








int numX(char **board);
int numO(char **board);
int checkEmpty(char **board);
int checkCol(int num, char **board);
int checkEmpty1(char **board,int num,int numOfrow);
int checkfull(char **board);

#endif
