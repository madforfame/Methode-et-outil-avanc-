#ifndef _SAVE_LOAD_HIGHSCORE_H_
#define _SAVE_LOAD_HIGHSCORE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int height, width, highscores;

void highscore(int high);
void saveLoad(int *num, char **board);

#endif