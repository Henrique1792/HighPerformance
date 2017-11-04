#ifndef UTILS_H_
#define UTILS_H_
#include <omp.h>
#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

float *readVector(FILE *src, int *vectorSize);
void printVector(float *tgt,int size);
float **readMatrix();
float *readVector(FILE *src, int *vectorSize);
void adjustMatrix(float **tgt, int size);
float *readSolution();
void writeSolution(float *solution, int size);
#endif
