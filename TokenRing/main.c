#include "ring.h"
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <omp.h>



int main(int argc, char *argv[]){
    //MPI var
    int rank,tag,nprocs,src,dst, message;
    //MPI VAR
    MPI_Init(&argc, &argv); 
        MPI_Comm_rank(MPI_COMM_WORLD,&rank);
        MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
        tag=1;
        if(Master(rank)){
            message=0;
            talk(rank+1,tag,nprocs,&message);
            listen(rank,tag,nprocs,&message);
            printf("Master Final Value: %d", message);
        }
        else{
            listen(rank,tag,nprocs,&message);
            printf("Message received from %d! %d", rank-1,message);
            talk(rank+1,tag,nprocs,&message);
        }
        
    MPI_Finalize();
    return 0;
}
