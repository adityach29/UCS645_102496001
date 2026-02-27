#include <mpi.h>
#include <stdio.h>

#define N 8

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    setbuf(stdout, NULL);

    if (N % size != 0) {
        if (rank == 0) printf("Error: N=%d must be divisible by processes=%d (use 1,2,4,8).\n", N, size);
        MPI_Finalize();
        return 0;
    }

    int A[N] = {1,2,3,4,5,6,7,8};
    int B[N] = {8,7,6,5,4,3,2,1};

    int local_n = N / size;
    int local_A[local_n], local_B[local_n];

    MPI_Barrier(MPI_COMM_WORLD);
    double start = MPI_Wtime();

    MPI_Scatter(A, local_n, MPI_INT, local_A, local_n, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(B, local_n, MPI_INT, local_B, local_n, MPI_INT, 0, MPI_COMM_WORLD);

    int local_dot = 0;
    for (int i = 0; i < local_n; i++) local_dot += local_A[i] * local_B[i];

    int global_dot = 0;
    MPI_Reduce(&local_dot, &global_dot, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);
    double end = MPI_Wtime();

    double local_t = end - start, Tp = 0.0;
    MPI_Reduce(&local_t, &Tp, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    printf("Rank %d local_dot=%d\n", rank, local_dot);

    if (rank == 0) {
        printf("\nDot Product = %d (Expected 120)\n", global_dot);
        printf("Execution Time (Tp) = %.6f seconds\n", Tp);
    }

    MPI_Finalize();
    return 0;
}
