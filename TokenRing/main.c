#include <mpi.h>
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>


#define Master(x) x==0 ? 1:0


int main(int argc, char *argv[]){
    //MPI Variables
        int rank, nprocs, src, dst, flags, message=1, tag;
        MPI_Status *status; 
    //MPI Variables
   
    //OMP/MPI required variable
        int required=MPI_THREAD_FUNNELED, provided;
    //OMP/MPI required variables
    
    //OMP Variables
        
    //OMP Variables
    
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
    //OMP code goes here!
        #pragma omp parallel private (tid) shared(message)\
        num_threads(nprocs) 
        {
            message++;
        }
    //OMP code goes here!
        if((rank+1)==nprocs)
            MPI_Send(&message, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
        else
            MPI_Send(&message, 1, MPI_INT, rank+1, tag, MPI_COMM_WORLD);
        
        printf("Message sent from %d \n",rank);
    } 
    
    
    
    MPI_Finalize();
    
    return 0;
}
