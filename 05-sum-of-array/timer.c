#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {

    printf("omp_get_wtime() = %g\n", omp_get_wtime());
    printf("omp_get_wtick() = %g\n", omp_get_wtick()); // resolution of the timer

    return 0;
}
