#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int is_perfect(int n) {
    if (n < 2) return 0;
    int sum = 1;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            sum += d;
            int other = n / d;
            if (other != d) sum += other;
        }
    }
    return sum == n;
}

int main(int argc, char** argv) {
    int maxv = (argc >= 2) ? atoi(argv[1]) : 100000;

    clock_t start = clock();
    int count = 0;
    for (int i = 2; i <= maxv; i++) if (is_perfect(i)) count++;
    clock_t end = clock();

    printf("Q5_SERIAL TIME=%f PERFECT=%d MAX=%d\n",
           (double)(end - start) / CLOCKS_PER_SEC, count, maxv);
    return 0;
}
