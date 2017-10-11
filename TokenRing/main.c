#include <mpi.h>
#include <omp.h>
#include <stdlib.h>
#include <stdio.h>


#define Master(x) x==0 ? 1:0


int main(int argc, char *argv[]){
    //MPI Variables
        int rank, nprocs, src, dst, flags, message=1, tag,i;
        MPI_Status *status; 
    //MPI Variables
   
    //OMP/MPI required variable
        int required=MPI_THREAD_SERIALIZED, provided;
    //OMP/MPI required variables
    
    //OMP Variables
       int threadID, nthreads; 
    //OMP Variables
    
    MPI_Init_thread(&argc, &argv,required, &provided);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
  
    
    if(provided < required){
        
      if (rank == 0) {
         printf("Warning:  This MPI implementation provides insufficient");
         printf(" threading support.\n");
      }
      nprocs=1;
        
    }
    //creating threads on every proccess
    {
        tag=1;
        if(Master(rank)){
            MPI_Send(&message, 1, MPI_INT, rank+1, tag, MPI_COMM_WORLD);
            MPI_Recv(&message, 1, MPI_INT,nprocs-1, tag, MPI_COMM_WORLD, status);
            printf("Final Message: %d \n",message);
        }
        else{
            #pragma omp parallel num_threads(nprocs) shared(message) private(threadID, i)
            {
                //OMP CODE GOES HERE!
                threadID=omp_get_thread_num();   // Get the thread ID
                nthreads=omp_get_num_threads();  // Get the total number of threads
                //OMP code goes here!
                

                if(Master(threadID)){
                    MPI_Recv(&message, 1, MPI_INT, rank-1, tag, MPI_COMM_WORLD, status);
                    #pragma omp critical
                        for(i=0;i<nprocs;i++)
                            message++;
                    #pragma omp barrier
                    if((rank+1)==nprocs)
                        MPI_Send(&message, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
                    else
                        MPI_Send(&message, 1, MPI_INT, rank+1, tag, MPI_COMM_WORLD);
                    
                    printf("Message sent from %d: %d \n",rank, message);
                }
                else{
                    #pragma omp critical
                        message++;
                }
            }
        } 
    }    
    
    
    MPI_Finalize();
    
    return 0;
}
