#ifndef REDO
#define REDO 

#include "util.h"
#include "tableau.h"
#include "player.h"
void undoRedoLimit(int num, int *undoCounter, int *redoCounter);

void undoRedo(char *x, char **board, int num, int *undoCol,
               int *undoRow, int *k, int *l, int *z,
               int *redoCol, int *redoRow, int *q, int width);

#endif