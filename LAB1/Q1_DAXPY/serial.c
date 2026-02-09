#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    const int N = 1 << 16;          // 2^16
    const double a = 2.5;
    double *X = (double*)malloc(N * sizeof(double));
    double *Y = (double*)malloc(N * sizeof(double));
    if (!X || !Y) { printf("Malloc failed\n"); return 1; }
    for (int i = 0; i < N; i++) {
        X[i] = 1.0 + i * 0.001;
        Y[i] = 2.0 - i * 0.0005;
    }

    double start = omp_get_wtime();

    for (int i = 0; i < N; i++) {
        X[i] = a * X[i] + Y[i];
    }

    double end = omp_get_wtime();
    printf("Serial time: %f seconds\n", end - start);
    free(X); free(Y);
    return 0;
}
