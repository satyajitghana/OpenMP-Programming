#include <omp.h>
#include <stdio.h>

int tid;
// Every thread gets its own tid, since its global every time #tid has the same var tid
#pragma omp threadprivate( tid )

int main(int argc, char** argv) {

    int numt;

    #pragma omp parallel default( shared )
    {
        int j;

        tid = omp_get_thread_num();

        if (tid == 0) {
            for (j = 0 ; j < 10000000 ; j++) ;
            numt = omp_get_num_threads();
        }
    }

    printf("Value of tid in main thread : %d\n", tid);

    #pragma omp parallel default( shared )
    {
        printf("Hello World from thread %d of %d.\n", tid, numt);
    }

    return 0;
}
