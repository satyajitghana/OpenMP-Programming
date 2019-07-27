// Two different critical sections
#include <omp.h>
#include <stdio.h>

#define ARR_SIZE 10
short A[ARR_SIZE];

int main(int argc, char** argv) {

    int i, sum = 0, prod = 1;
    double t1, t2;

    // Initialize the Array
    for (i = 0 ; i < ARR_SIZE ; i++)
        A[i] = 2;

    #pragma omp parallel default(shared)
    {
        int psum = 0, pprod = 1;

        #pragma omp for
        for ( i = 0 ; i < ARR_SIZE ; i++ )
        {
            psum += A[i];
            pprod *=A[i];
        }

        // Only One Thread is allowed to enter a critical section at a given point in time

        #pragma omp critical
        sum += psum;

        #pragma omp critical
        prod *= pprod;
    }

    printf("Sum = %d, Product = %d\n", sum, prod);

    return 0;
}
