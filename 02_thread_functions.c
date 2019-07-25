#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {
    #pragma omp parallel
    {
        // Here numt and tid are local vars that are stored in thread stack

        // Total Number of OMP threads
        int numt = omp_get_num_threads();
        // Each threads has a thread ID
        int tid = omp_get_thread_num(); // Get current thread number

        printf("Hello World from thread %d of %d.\n", tid, numt);
    }

    return 0;
}
