#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

static int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    int lim = (int)sqrt((double)n);
    for (int d = 3; d <= lim; d += 2) if (n % d == 0) return 0;
    return 1;
}

int main(int argc, char** argv) {
    int maxv = (argc >= 2) ? atoi(argv[1]) : 200000;
    clock_t start = clock();

    int count = 0;
    for (int i = 2; i <= maxv; i++) if (is_prime(i)) count++;

    clock_t end = clock();
    printf("Q4_SERIAL TIME=%f PRIMES=%d MAX=%d\n",
           (double)(end - start) / CLOCKS_PER_SEC, count, maxv);
    return 0;
}
