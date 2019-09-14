#include <omp.h>
#include <stdio.h>

// #pragma omp task depend( in: <list> ) depend ( out: <list> ) depend ( inout: <list> )

int main(int argc, char** argv) {
    #pragma omp parallel
    {
        #pragma omp single
        {
            int x, y, z;

            #pragma omp task depend( out:x )
            x = init();

            #pragma omp task depend( in:x ) depend( out:y )
            y = f(x);

            #pragma omp task depend( in:x ) depend( out:z )
            z = g(x);

            #pragma omp task depend( in: y, z)
            finalize(y, z);
        }
    }

    return 0;
}
