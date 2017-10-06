#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

int **createMatrix(int size);
void freeMatrix(int **tgt, int size);
void rFill(int **tgt, int size);
int **createMatrix(int size);
void printMatrix(int **tgt, int size);
int **multMatrix(int **m1, int **m2, int size);

#endif
