#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

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
    return (sum == n);
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0) printf("Q5 ERROR: run with NP>=2\n");
        MPI_Finalize();
        return 1;
    }

    int maxv = 100000;
    if (rank == 0 && argc >= 2) maxv = atoi(argv[1]);
    MPI_Bcast(&maxv, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        double start = MPI_Wtime();

        int next = 2;
        int active = size - 1;
        int perfect = 0;

        while (active > 0) {
            int msg;
            MPI_Status st;

            MPI_Recv(&msg, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &st);
            int src = st.MPI_SOURCE;

            if (msg > 0) perfect++;

            if (next <= maxv) {
                MPI_Send(&next, 1, MPI_INT, src, 0, MPI_COMM_WORLD);
                next++;
            } else {
                int stop = 0;
                MPI_Send(&stop, 1, MPI_INT, src, 0, MPI_COMM_WORLD);
                active--;
            }
        }

        double end = MPI_Wtime();
        printf("Q5 NP=%d TIME=%f PERFECT=%d MAX=%d\n", size, end - start, perfect, maxv);
    } else {
        int req = 0;
        MPI_Send(&req, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

        while (1) {
            int n;
            MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            if (n == 0) break;

            int res = is_perfect(n) ? n : -n;
            MPI_Send(&res, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();
    return 0;
}
