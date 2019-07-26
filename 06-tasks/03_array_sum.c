// private variables (after parallel)
#include <omp.h>
#include <stdio.h>

#define ARR_SIZE 600
short A[ARR_SIZE];

#define STEP_SIZE 100

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
        int tsum = 0, tid = omp_get_thread_num();
        printf("[TID:%d], A(tsum)=%x\n", omp_get_thread_num(), &tsum);
        #pragma omp for
        for (i = 0 ; i < ARR_SIZE ; i+= STEP_SIZE) {
            int j, start = i, end = i + STEP_SIZE - 1;
        
            printf("[TID:%d], Delegating Sum(%d, %d), A(tsum)=%x\n", tid, start, end, &tsum);

            #pragma omp task
            {
                int psum = 0;

                // printf("Task computing Sum(%d, %d) from %d of %d\n",
                //     start, end, omp_get_thread_num(), omp_get_num_threads());

                for (j = start; j <= end ; j++)
                    psum += A[j];

                printf("[TID:%d], Task Sum(%d, %d), A(tsum)=%x\n", tid, start, end, &tsum);
                
                #pragma omp critical
                    sum += psum;
            }
        }
    }

    t2 = omp_get_wtime();

    printf("Sum of the array elements = %d. Time = %g\n", sum, t2-t1);

    return 0;
}
