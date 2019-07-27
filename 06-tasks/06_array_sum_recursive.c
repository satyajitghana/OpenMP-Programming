// creating tasks from single thread using single
#include <omp.h>
#include <stdio.h>

#define ARR_SIZE 6
short A[ARR_SIZE];

int do_sum(int, int);

int main(int argc, char** argv) {
    int i, sum = 0;
    double t1, t2;

    // Initialize the Array
    for (i = 0 ; i < ARR_SIZE ; i++)
        A[i] = 1;

    t1 = omp_get_wtime();
    // Sum up the array
    #pragma omp parallel
    #pragma omp single
    sum = do_sum(0, ARR_SIZE-1);

    t2 = omp_get_wtime();

    printf("Sum of the array elements = %d. Time = %g\n", sum, t2-t1);

    return 0;
}

int do_sum(int start, int end) {
    int mid, x, y, res;

    int tid = omp_get_thread_num();

    if (end == start)
        res = A[start];
    else {
        mid = (end + start) / 2;

        printf("[TID:%d], Sum(%d, %d) = Sum(%d, %d) + Sum(%d, %d)\n", tid, start, end, start, mid, mid+1, end);

        #pragma omp task shared(x)
        x = do_sum(start, mid);

        #pragma omp task shared(y)
        y = do_sum(mid+1, end);

        #pragma omp taskwait
        res = x + y;
    }

    printf("[TID:%d], Sum(%d, %d) = %d\n", omp_get_thread_num(), start, end, res);

    return res;
}
