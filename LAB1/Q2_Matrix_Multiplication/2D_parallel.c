#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 1000

int main() {
    int i, j, k;
    double *A, *B, *C;
    A = (double *)malloc(N * N * sizeof(double));
    B = (double *)malloc(N * N * sizeof(double));
    C = (double *)malloc(N * N * sizeof(double));
    if (A == NULL || B == NULL || C == NULL) {
        printf("allocation failed");
        return 1;
    }
	for (i = 0; i < N * N; i++) {
        A[i] = 2.0;
        B[i] = 4.0;
        C[i] = 0.0;
    }
    double start = omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            double sum = 0.0;
            for (k = 0; k < N; k++) {
                sum += A[i*N + k] * B[k*N + j];
            }
            C[i*N + j] = sum;
        }
    }
    double end = omp_get_wtime();
    printf("2D Threading Time = %f", end - start);
    free(A);
    free(B);
    free(C);
    return 0;
}
