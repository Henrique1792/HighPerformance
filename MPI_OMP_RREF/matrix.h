#ifndef MATRIX_H_
#define MATRIX_H_
#include <stdlib.h>
#include <stdio.h>



int **createMatrix(int size);
void freeMatrix(int ***tgt,int size);
void printMatrix(int **tgt,int size);


#endif
