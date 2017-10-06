#include "matrix.h"
int **createMatrix(int size){
    if(size<=0) return NULL;
    int i, j, **rt;
    
    rt=(int **)malloc(size*sizeof(int *));
    for(i=0;i<size;i++)
        rt[i]=(int *)malloc(size*sizeof(int));
    return rt;

}

void freeMatrix(int **tgt,int size){
    if(tgt==NULL || *tgt==NULL || size<=0) return;
    int i;

    for(i=0;i<size;i++)
        free(tgt[i]);

    free(tgt);
}

void rFill(int **tgt, int size){
    if(tgt==NULL || *tgt==NULL || size<=0) return;
    int i,j;

    for(i=0;i<size;i++){
        
        for(j=0;j<size;j++){
            tgt[i][j]=rand();
        }
    }
    
}

void printMatrix(int **tgt, int size){
    if(tgt==NULL || *tgt==NULL || size<=0) return;
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%d ", tgt[i][j]);
        }
        printf("\n");
    }
    
}

int **multMatrix(int **m1, int **m2, int size){
    if(m1==NULL || m2==NULL || *m1==NULL || *m2==NULL || size<=0) return NULL;
    int **rt=createMatrix(size),i,j,k;
    
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            rt[i][j]=0;
                #pragma omp for
                for(k=0;k<size;k++)
                    rt[i][j]+=m1[i][k]*m2[k][j];
        }
        
    }
    
    return rt;
}
