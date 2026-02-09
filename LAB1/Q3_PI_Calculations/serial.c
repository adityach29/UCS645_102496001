#include <stdio.h>
#include <omp.h>

int main() {
    static long num_steps = 100000000;  
    double step = 1.0 / (double)num_steps;
    double sum = 0.0;

    double start = omp_get_wtime();

    for (long i = 0; i < num_steps; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    double pi = step * sum;

    double end = omp_get_wtime();
    printf("Serial pi = %.15f\n", pi);
    printf("Serial time = %f sec\n", end - start);
    return 0;
}