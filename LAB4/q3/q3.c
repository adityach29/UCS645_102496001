#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define K 10     // numbers per process
#define MAXVAL 1000

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    setbuf(stdout, NULL);

    // random seed per rank
    unsigned int seed = (unsigned int)time(NULL) ^ (rank * 1234567u);
    int nums[K];

    for (int i = 0; i < K; i++) {
        nums[i] = rand_r(&seed) % (MAXVAL + 1);   // 0..1000
    }

    int local_max = nums[0], local_min = nums[0];
    for (int i = 1; i < K; i++) {
        if (nums[i] > local_max) local_max = nums[i];
        if (nums[i] < local_min) local_min = nums[i];
    }

    // For MAXLOC/MINLOC, use pair {value, rank}
    struct { int value; int rank; } in_max, out_max, in_min, out_min;
    in_max.value = local_max; in_max.rank = rank;
    in_min.value = local_min; in_min.rank = rank;

    MPI_Reduce(&in_max, &out_max, 1, MPI_2INT, MPI_MAXLOC, 0, MPI_COMM_WORLD);
    MPI_Reduce(&in_min, &out_min, 1, MPI_2INT, MPI_MINLOC, 0, MPI_COMM_WORLD);

    // (Optional) print local stats
    printf("Rank %d local_min=%d local_max=%d\n", rank, local_min, local_max);

    if (rank == 0) {
        printf("\nGLOBAL MAX = %d (from Rank %d)\n", out_max.value, out_max.rank);
        printf("GLOBAL MIN = %d (from Rank %d)\n", out_min.value, out_min.rank);
    }

    MPI_Finalize();
    return 0;
}
