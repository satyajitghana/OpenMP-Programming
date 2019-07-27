// Locks using buckets
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define INP_SIZE (1<<26)
#define HIST_SIZE (1<<20)
#define NUM_BKTS (1<<20)
#define BKT_SIZE ( HIST_SIZE / NUM_BKTS )

int hist[HIST_SIZE];
int inp[INP_SIZE];
omp_lock_t lock[NUM_BKTS];

int main(int argc, char** argv) {

    int i, key, sum = 0;
    double t1, t2;

    // Initialize the Array
    for (i = 0 ; i < HIST_SIZE ; i++) {
        hist[i] = 0;
        omp_init_lock(&(lock[i]));
    }
    for (i = 0 ; i < INP_SIZE ; i++)
        inp[i] = rand() % HIST_SIZE;

    t1 = omp_get_wtime();
    #pragma omp parallel for private(key) num_threads(64)
    for (i = 0 ; i < INP_SIZE ; i++)
    {
        key = inp[i];

        // Blocking Call
        omp_set_lock(&(lock[key / BKT_SIZE]));
        hist[key]++;
        omp_unset_lock(&(lock[key / BKT_SIZE]));
    } 
    t2 = omp_get_wtime();

    for (i = 0 ; i < NUM_BKTS ; i++) {
        omp_destroy_lock(&(lock[i]));
    }

    #pragma omp parallel for reduction(+: sum)
    for (i = 0 ; i < HIST_SIZE ; i++)
        sum += hist[i];

    printf("Sum = %d, Time = %g\n", sum, t2-t1);

    return 0;
}
