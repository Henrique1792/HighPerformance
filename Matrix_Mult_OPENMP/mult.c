#include "matrix.h"

/*
 *  Multiplicação de Matrizes quadradas
 *
 * */


int main (int *argc, char *argv[]){
    int s1, **m1, **m2, **rt;
    srand(time(NULL));
    printf("Please, insert matrix size: \n");
    scanf("%d", &s1);
    m1=createMatrix(s1);
    m2=createMatrix(s1);
    
    rFill(m1, s1);
    rFill(m2, s1);
    
    printf("m1: \n");
    printMatrix(m1, s1);
    printf("m2: \n");
    printMatrix(m2, s1);
   
    rt=multMatrix(m1, m2, s1);
    printf("rt: \n");
    printMatrix(rt, s1);

    freeMatrix(m1, s1);
    freeMatrix(m2, s1);
    freeMatrix(rt, s1);
    return 0;
}
