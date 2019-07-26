#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {

    // Declare numt and tid outside the parallel block
    int numt, tid;
    
    #pragma omp parallel shared(numt, tid)
    {

        // Total Number of OMP threads
        numt = omp_get_num_threads();
        // Each threads has a thread ID
        tid = omp_get_thread_num(); // Get current thread number

        printf("Hello World from thread %d of %d.\n", tid, numt);
    }

    return 0;
}

// Finally a Collision
// Hello World from thread 2 of 4.
// Hello World from thread 1 of 4.
// Hello World from thread 3 of 4.
// Hello World from thread 3 of 4.