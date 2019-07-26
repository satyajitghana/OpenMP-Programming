// Use OpenMP Reduction to implement partial sums
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
    // OpenMP will take care of the partial sum and distribution of the loop among threads
    // #pragma omp parallel default(shared) reduction(+: sum)
    // {
    //     // This will distribute the work among the threads
    //     #pragma omp for
    //     for ( i = 0 ; i < ARR_SIZE ; i++)
    //         sum += A[i];
    // }

    // #pragma omp parallel default(shared)
    //     #pragma omp for reduction(+: sum)
    //     for ( i = 0 ; i < ARR_SIZE ; i++)
    //         sum += A[i];

    // You can now combine them
    #pragma omp parallel for default(shared) reduction(+: sum)
        for ( i = 0 ; i < ARR_SIZE ; i++)
            sum += A[i];

    t2 = omp_get_wtime();

    printf("Sum of the array elements = %d. Time = %g\n", sum, t2-t1);

    return 0;
}
