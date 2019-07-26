// Use the more convention approach for work to be done
// by a single thread - #pragma omp single

#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {

    int numt;

    #pragma omp parallel default( shared )
    {
        int j, tid;

        // any free thread executes this part
        #pragma omp single
        {
            for (j = 0 ; j < 10000000 ; j++) ;
            numt = omp_get_num_threads();
        } // synchronization
        // use #pragma omp single nowait :  to remove sync
        // use #pragma omp master : to make the master thread to run the code

        tid = omp_get_thread_num();

        printf("Hello World from thread %d of %d.\n", tid, numt);

    }

    return 0;
}
