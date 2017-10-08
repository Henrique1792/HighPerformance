/*
 *  Hello World using MPI 
 *
 *
 *
*/
#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>

#define Master(x) x==0 ? 1:0

int main(int argc, char*argv[]){
    int rank, nprocs, src, dst, tag, ping, pong; 
    char message[]="Hello World";
    char *buff;
    MPI_Status * status;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    
    tag=1;
    if(Master(rank)){      //rank==0
        MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
        for(dst=1;dst<nprocs;dst++) //Broadcasting
            MPI_Send(message, sizeof(message)+1, MPI_CHAR, dst, tag, MPI_COMM_WORLD);
         
        for(src=1;src<nprocs;src++){
            MPI_Recv(&pong, 1, MPI_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, status);
            printf("Pong received from slave!\n");
        }            
    }else{          //rank!=0
        src=0;
        ping=1;
        buff=(char *)malloc(sizeof(message)+1); //Receive message
        MPI_Recv(buff,sizeof(message)+1, MPI_CHAR, src, tag, MPI_COMM_WORLD, status);
        printf("%s from master! ID: %d\n", buff, rank);
        free(buff);
        
        dst=0;
        MPI_Send(message,1 , MPI_CHAR, dst, tag, MPI_COMM_WORLD);
    }
    
    MPI_Finalize();
    return 0;
}
