#include "MatMul.hpp"

#include <omp.h>
#include <stdio.h>

void MatMul( int m, int n, int p, int b, double alpha, double beta, double *A, double *B, double *C )
{
    int i, j, k, ii, jj, kk ;

    #pragma omp parallel default(shared) private( j, ii, jj, kk )
    #pragma omp for collapse(2)
    for( i = 0 ; i < m ; i++ )
      for( k = 0 ; k < p ; k++ )
      {
        #pragma omp atomic
        C[i*p+k] *= beta ;
        for( j = 0 ; j < n ; j++ )
          #pragma omp atomic
          C[i*p+k] += alpha * A[j*m+i]*B[j*p+k] ;
      }
}

