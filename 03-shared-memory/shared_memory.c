#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int flag_even = 0, flag_odd = 0;

    #pragma omp parallel num_threads(10)
    {
        if (omp_get_thread_num() % 2 == 0) {
            flag_odd = 1;
            if (flag_even == 0)
                printf("Thread Even %d wins\n", omp_get_thread_num());
        } else {
            flag_even = 1;
            if (flag_odd == 0)
                printf("Thread Odd %d wins\n", omp_get_thread_num());
        }
    }

    return 0;
}
