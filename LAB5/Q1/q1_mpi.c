#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N (1<<16)

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double a = 2.5;

    if (N % size != 0) {
        if (rank == 0) printf("Q1 ERROR: N=%d not divisible by NP=%d\n", N, size);
        MPI_Finalize();
        return 1;
    }

    int local_n = N / size;

    double *X = NULL, *Y = NULL;
    if (rank == 0) {
        X = (double*)malloc(N * sizeof(double));
        Y = (double*)malloc(N * sizeof(double));
        for (int i = 0; i < N; i++) {
            X[i] = 1.0 + (i % 100) * 0.01;
            Y[i] = 2.0 + (i % 50) * 0.02;
        }
    }

    double *localX = (double*)malloc(local_n * sizeof(double));
    double *localY = (double*)malloc(local_n * sizeof(double));

    MPI_Scatter(X, local_n, MPI_DOUBLE, localX, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(Y, local_n, MPI_DOUBLE, localY, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    double start = MPI_Wtime();

    for (int i = 0; i < local_n; i++) {
        localX[i] = a * localX[i] + localY[i];
    }

    MPI_Barrier(MPI_COMM_WORLD);
    double end = MPI_Wtime();

    double local_time = end - start;
    double max_time = 0.0;
    MPI_Reduce(&local_time, &max_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    MPI_Gather(localX, local_n, MPI_DOUBLE, X, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Q1 NP=%d TIME=%f\n", size, max_time);
        free(X); free(Y);
    }

    free(localX); free(localY);

    MPI_Finalize();
    return 0;
}
