// Include the OpenMP header file
#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Specify the block to be executed in parallel
    // Compiler Directive
    #pragma omp parallel
    {
        // Prints Hello World from each thread
        printf("Hello World\n");
    }

    return 0;
}

// OUTPUT
// COMPILE
// ╰─ gcc -fopenmp hello_world.c 
// RUN
// ╰─ ./a.out
// Hello World
// Hello World
// Hello World
// Hello World

// You can set the number of threads by the environment variable
// export OMP_NUM_THREADS=4
