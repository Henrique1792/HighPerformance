/*
 *  hello world using openmp
 *
*/

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>


int main(int *argc, char *argv[]){
    int nthreads, tid;

    //Fork a team of threads givin'em their own copies of variables
    #pragma omp parallel private (nthreads, tid)
    {
        tid=omp_get_thread_num();
        printf("Hello World from %d thread!\n", tid);
        if(tid==0){
            nthreads=omp_get_num_threads();
            printf("number of threads = %d\n", nthreads);
        
        }
    }
    //All threads join here =)
    return 0;
}
