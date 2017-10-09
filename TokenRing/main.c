#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <omp.h>


#define Master(x) x==0 ? 1:0


int main(int argc, char *argv[]){
    int rank, nprocs, src, dst, flags, message=1, tag;
    MPI_Status *status; 
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
   
    tag=1;
    if(Master(rank)){
        MPI_Send(&message, 1, MPI_INT, rank+1, tag, MPI_COMM_WORLD);
        MPI_Recv(&message, 1, MPI_INT,nprocs-1, tag, MPI_COMM_WORLD, status);
        printf("Final Message: %d \n",message);
    }
    else{
        MPI_Recv(&message, 1, MPI_INT, rank-1, tag, MPI_COMM_WORLD, status);
        message++;
        if((rank+1)==nprocs)
            MPI_Send(&message, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
        else
            MPI_Send(&message, 1, MPI_INT, rank+1, tag, MPI_COMM_WORLD);
        
        printf("Message sent from %d \n",rank);
    } 
    
    
    
    MPI_Finalize();
    
    return 0;
}
