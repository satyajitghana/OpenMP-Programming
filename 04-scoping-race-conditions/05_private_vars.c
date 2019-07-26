#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {

    int numt;

    #pragma omp parallel default( shared )
    {
        int j, tid;

        tid = omp_get_thread_num();

        if (tid == 0) {
            for (j = 0 ; j < 10000000 ; j++) ;
            numt = omp_get_num_threads();
        }

        // This will wait for all the threads to complete
        #pragma omp barrier

         printf("Hello World from thread %d of %d.\n", tid, numt);

    }

    return 0;
}
