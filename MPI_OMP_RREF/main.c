#include "utils.h"
#include "matrix.h"
#define Master(x) x==0 ? 1:0

int main(int argc, char *argv[]){
    FILE *src;
    float **matrix;
    int size;
    //MPI VARIABLES
    int rank, nprocs;
    //MPI VARIABLES
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    //every proccess in MPI will make this allocation
    matrix=createMatrix(atoi(argv[1]));


    freeMatrix(&matrix,atoi(argv[1]));
    MPI_Finalize();
    return 0;
}
