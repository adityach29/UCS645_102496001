#include <stdio.h>
#include <omp.h>
#define STEPS 100000000   
int main() {
    int i;
    double x, pi, sum = 0.0;
    double step = 1.0 / STEPS;
    double start = omp_get_wtime();
    #pragma omp parallel for private(x) reduction(+:sum)
    for (i = 0; i < STEPS; i++) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    pi = step * sum;
    double end = omp_get_wtime();
    printf("Calculated value of Pi = %.10f\n", pi);
    printf("Time taken = %f seconds\n", end - start);
    return 0;
}
