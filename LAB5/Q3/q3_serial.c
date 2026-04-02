#include <stdio.h>
#include <time.h>

#define N 500000000LL

int main() {
    double multiplier = 2.0;
    volatile double sum = 0.0;
    double b = 2.0 * multiplier;

    clock_t start = clock();
    for (long long i = 0; i < N; i++) sum += 1.0 * b;
    clock_t end = clock();

    printf("Q3_SERIAL TIME=%f DOT=%0.3f\n",
           (double)(end - start) / CLOCKS_PER_SEC, (double)sum);
    return 0;
}
