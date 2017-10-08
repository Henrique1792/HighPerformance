#include "ring.h"




void talk(int dst,int tag, int nprocs, int *message){ 
    if(!FinalProc(nprocs,dst))
        MPI_Send(message,1,MPI_INT,dst,tag, MPI_COMM_WORLD);
    else
        MPI_Send(message,1,MPI_INT,0,tag, MPI_COMM_WORLD);
    
}
void listen(int whoami,int tag, int nprocs, int *message){ //easier mask for communication
    MPI_Status *status;
    if(!Master(whoami))
        MPI_Recv(message,1,MPI_INT,whoami-1,tag, MPI_COMM_WORLD,status);
    else
        MPI_Recv(message,1,MPI_INT,nprocs-1,tag, MPI_COMM_WORLD,status);
}
