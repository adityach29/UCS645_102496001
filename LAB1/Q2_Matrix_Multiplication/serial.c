#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    const int N = 1000;
    double *A = (double*)malloc(N*N*sizeof(double));
    double *B = (double*)malloc(N*N*sizeof(double));
    double *C = (double*)malloc(N*N*sizeof(double));
    if (!A || !B || !C) { printf("Malloc failed\n"); return 1; }

    for (int i = 0; i < N*N; i++) {
        A[i] = 1.0;
        B[i] = 1.0;
        C[i] = 0.0;
    }

    double start = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i*N + k] * B[k*N + j];
            }
            C[i*N + j] = sum;
        }
    }

    double end = omp_get_wtime();
    printf("Serial MM time: %f sec\n", end - start);

    free(A); free(B); free(C);
    return 0;
}