#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 1000

int main() {
    int i, j, k;
    double *A, *B, *C;
    A = (double*)malloc(N * N * sizeof(double));
    B = (double*)malloc(N * N * sizeof(double));
    C = (double*)malloc(N * N * sizeof(double));
    for (i = 0; i < N*N; i++) {
        A[i] = 2.0;
        B[i] = 3.0;
        C[i] = 0.0;
    }
    double start = omp_get_wtime();
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                C[i*N + j] += A[i*N + k] * B[k*N + j];
            }
        }
    }
    double end = omp_get_wtime();
    printf("Time taken = %f", end - start);
    free(A);
    free(B);
    free(C);
    return 0;
}