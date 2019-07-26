#include <omp.h>
#include <stdio.h>

#define ARR_SIZE 100000000
short A[ARR_SIZE];

int main(int argc, char** argv) {
    int i, tid, numt, sum = 0;
    double t1, t2;

    // Initialize the Array
    for (i = 0 ; i < ARR_SIZE ; i++)
        A[i] = 1;

    t1 = omp_get_wtime();
    // Sum up the array
    #pragma omp parallel default(shared) private(i, tid)
    {
        int from, to;

        tid = omp_get_thread_num();
        numt = omp_get_num_threads();

        // Distribute the Work - compute the index range to work on
        from = (ARR_SIZE / numt) * tid;
        to = (ARR_SIZE / numt) * (tid + 1) - 1;

        // May not be divisible by equal parts, hence this
        if (tid == numt-1)
            to = ARR_SIZE - 1;

        printf("Hello from %d of %d, my range is from = %d to = %d\n",
            tid, numt, from, to);
        
        for (i = from; i <= to; i++)
        // This makes sure that no other thread is accessing this variables when
        // one thread is using this, this makes the operation atomic
        // but there's a lot of code for this critical, avoid using it in a loop
            #pragma omp critical
            sum += A[i];
    }

    t2 = omp_get_wtime();

    printf("Sum of the array elements = %d. Time = %g\n", sum, t2-t1);

    return 0;
}
