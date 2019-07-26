#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int numt, tid;
    // private means that every thread gets its own copy of the variable
    // shared means that all the threads share the same variable
    // By default the variables are shared
    #pragma omp parallel private( tid ) shared ( numt )
    {
        int j;
        numt = omp_get_num_threads();
        tid = omp_get_thread_num();

        // Introduce Delay
        for (j = 0 ; j < 10000000 ; j++) ;

        printf("Hello World from thread %d of %d.\n", tid, numt);
    }

    return 0;
}
