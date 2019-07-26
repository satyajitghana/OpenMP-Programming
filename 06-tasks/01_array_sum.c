// Compute array sum using tasks
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
        #pragma omp for
        for (i = 0 ; i < ARR_SIZE ; i+= STEP_SIZE) {
            int j, start = i, end = i + STEP_SIZE - 1;

            printf("Computing Sum(%d, %d) from %d of %d\n",
                start, end, omp_get_thread_num(), omp_get_num_threads());

            // This code is going to be executed independently at some point in time
            // Whenever any thread is free can execute this independent piece of code
            // so thread 0 might spawn from 0 to 99 but thread 1 might actually do that task
            // You might not know how much work is to be done when executing, there tasks
            // come handy
            #pragma omp task
            {
                int psum = 0;

                printf("Task computing Sum(%d, %d) from %d of %d\n",
                    start, end, omp_get_thread_num(), omp_get_num_threads());

                for (j = start; j <= end ; j++)
                    psum += A[j];
                
                #pragma omp critical
                    sum += psum;
            }
        }
    }

    t2 = omp_get_wtime();

    printf("Sum of the array elements = %d. Time = %g\n", sum, t2-t1);

    return 0;
}
