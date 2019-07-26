#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {

    // Make the code with tid shared, fail almost everytime
    // but if you use gcc -O3 then the j loop is thrown out

    // Declare numt and tid outside the parallel block
    int numt, tid;
    
    #pragma omp parallel
    {
        int j;

        // Total Number of OMP threads
        numt = omp_get_num_threads();
        // Each threads has a thread ID
        tid = omp_get_thread_num(); // Get current thread number

        // Introduce a delay so the program now fails everytime
        for ( j = 0 ; j < 10000000 ; j++) ;

        printf("Hello World from thread %d of %d.\n", tid, numt);
    }

    return 0;
}

// Finally a Collision
// Hello World from thread 2 of 4.
// Hello World from thread 1 of 4.
// Hello World from thread 3 of 4.
// Hello World from thread 3 of 4.