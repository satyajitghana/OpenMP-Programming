// Reduce the Synchronization
#include <omp.h>
#include <stdio.h>

#define ARR_SIZE 100000000
short A[ARR_SIZE];

int main(int argc, char** argv) {
    int i, sum = 0;
    double t1, t2;

    // Initialize the Array
    for (i = 0 ; i < ARR_SIZE ; i++)
        A[i] = 1;

    t1 = omp_get_wtime();
    // Sum up the array
    #pragma omp parallel default(shared)
    {
        // Use Partial Sum
        int psum = 0;
        
        // This will distribute the work among the threads
        #pragma omp for
        for ( i = 0 ; i < ARR_SIZE ; i++)
            psum += A[i];
        
        // Synchronize to sum up the partial sums
        #pragma omp critical
        sum += psum;

        // Before the critical section was called ARR_SIZE number of times
        // Here it is only called 4 times
    }

    t2 = omp_get_wtime();

    printf("Sum of the array elements = %d. Time = %g\n", sum, t2-t1);

    return 0;
}
