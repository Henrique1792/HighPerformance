#include <omp.h>
#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

#define Master(x) x==0 ? 1:0

int main(int argc, char *argv[]){
    //MPI_VARIABLES 
        int rank, nprocs,tag=1;
        MPI_Status *status;
    //MPI_VARIABLES 
    //OMP_VARIABLES
        int tid, nthreads;
    //OMP_VARIABLES
    int message=0;
    MPI_Init(&argc, &argv);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);
        MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
        omp_set_num_threads(nprocs-1);
        if(Master(rank)){
            MPI_Send(&message, 1, MPI_INT,rank+1, tag, MPI_COMM_WORLD);
            MPI_Recv(&message, 1, MPI_INT, nprocs-1, tag,MPI_COMM_WORLD,status);
            printf("Final message: %d\n", message);
        }else{
            MPI_Recv(&message, 1, MPI_INT, rank-1, tag,MPI_COMM_WORLD,status);
            #pragma omp parallel default(shared) private(tid,nthreads) num_threads(nprocs)
            {
                tid=omp_get_thread_num();
                nthreads=omp_get_num_threads();
            #pragma omp critical
                message++;
            }
            printf("Message from thread %d in %d: %d\n", tid,rank,message);
            if(!(rank==nprocs-1))
                MPI_Send(&message, 1, MPI_INT,rank+1, tag, MPI_COMM_WORLD);
            else
                MPI_Send(&message, 1, MPI_INT,0, tag, MPI_COMM_WORLD);
        }
            
        
        
    MPI_Finalize();
    
    return 0;
}
