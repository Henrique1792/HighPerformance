#include "matrix.h"


int **createMatrix(int size){
    if(size<=0) return NULL;
    int **rt=NULL, i;
    
    rt=(int **)malloc(size*sizeof(int));
    
    for(i=0;i<size;i++) rt[i]=(int *)malloc(size*sizeof(int));
    return rt;
}

void freeMatrix(int ***tgt,int size){
    if(tgt==NULL || *tgt==NULL || **tgt==NULL || size<=0) return;
    int i;
    
    for(i=0;i<size;i++) free(*(tgt[i]));

    free(*tgt);
    free(tgt);
    
}
void printMatrix(int **tgt,int size){
    int i,j;
    if(tgt==NULL || *tgt==NULL || size<=0) return;

    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            printf("%d ",tgt[i][j]);
        }
        printf("\n");
    }
}
