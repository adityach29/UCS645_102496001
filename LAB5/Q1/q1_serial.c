#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N (1<<16)

int main() {
    double *X = (double*)malloc(N * sizeof(double));
    double *Y = (double*)malloc(N * sizeof(double));
    double a = 2.5;

    for (int i = 0; i < N; i++) {
        X[i] = 1.0 + (i % 100) * 0.01;
        Y[i] = 2.0 + (i % 50) * 0.02;
    }

    clock_t start = clock();
    for (int i = 0; i < N; i++) X[i] = a * X[i] + Y[i];
    clock_t end = clock();

    printf("Q1_SERIAL TIME=%f\n", (double)(end - start) / CLOCKS_PER_SEC);

    free(X); free(Y);
    return 0;
}
