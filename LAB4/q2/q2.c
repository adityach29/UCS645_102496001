
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    setbuf(stdout, NULL);

    int local_n = N / size;                 // assume size divides 100 (use 2/4/5/10)
    int *data = NULL;

    int *local = (int*)malloc(local_n * sizeof(int));
    if (!local) { perror("malloc local"); MPI_Abort(MPI_COMM_WORLD, 1); }

    if (rank == 0) {
        data = (int*)malloc(N * sizeof(int));
        if (!data) { perror("malloc data"); MPI_Abort(MPI_COMM_WORLD, 1); }
        for (int i = 0; i < N; i++) data[i] = i + 1;
    }

    MPI_Scatter(data, local_n, MPI_INT, local, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    long long local_sum = 0;
    for (int i = 0; i < local_n; i++) local_sum += local[i];

    long long global_sum = 0;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        double avg = (double)global_sum / (double)N;
        printf("Global Sum = %lld (Expected 5050)\n", global_sum);
        printf("Average    = %.2f\n", avg);
        free(data);
    }

    free(local);
    MPI_Finalize();
    return 0;
}
