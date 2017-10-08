#ifndef RING_H_
#define RING_H_

#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <omp.h>

#define Master(x) x==0 ? 1:0
#define FinalProc(size,value) size==value ? 1:0
void talk(int dst,int tag, int nprocs, int *message); //easier mask for communication
void listen(int whoami,int tag, int nprocs, int *message); //easier mask for communication


#endif
