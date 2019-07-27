// Two different critical sections
#include <omp.h>
#include <stdio.h>

#define ARR_SIZE 10
short A[ARR_SIZE];

int main(int argc, char** argv) {

    int i, sum = 0, prod = 1;
    double t1, t2;

    // Initialize the Array
    for (i = 0 ; i < ARR_SIZE ; i++)
        A[i] = 2;

    #pragma omp parallel default(shared)
    {
        int psum = 0, pprod = 1;

        #pragma omp for
        for ( i = 0 ; i < ARR_SIZE ; i++ )
        {
            psum += A[i];
            pprod *=A[i];
        }

        // Only One Thread is allowed to enter a critical section at a given point in time

        // You can name the critical section, this will prevent that two threads enter critical section1 together or section2
        // But you can have one thread in section1 and one in section2

        #pragma omp critical (section1)
        {
            printf("In Critical Section 1\n");
            for (int j = 0 ; j < 1e7 ; j++);
            sum += psum;
            printf("Out Critical Section 1\n");
        }

        #pragma omp critical (section2)
        {
            printf("In Critical Section 2\n");
            for (int j = 0 ; j < 1e7 ; j++);
            prod *= pprod;
            printf("Out Critical Section 2\n");
        }
    }

    printf("Sum = %d, Product = %d\n", sum, prod);

    return 0;
}
