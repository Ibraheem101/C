#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank;
    int value;
    int received;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    value = rank * 10;

    if (rank == 0) {
        printf("Process 0: waiting to receive...\n");
        MPI_Recv(&received, 1, MPI_INT, 1, 99,
                 MPI_COMM_WORLD, &status);

        MPI_Ssend(&value, 1, MPI_INT, 1, 9, MPI_COMM_WORLD);
        printf("Process %d received %d\n", rank, received);

    }
    else if (rank == 1) {
        printf("Process 1: trying to send...\n");
        MPI_Ssend(&value, 1, MPI_INT, 0, 99, MPI_COMM_WORLD);

        MPI_Recv(&received, 1, MPI_INT, 0, 9,
                 MPI_COMM_WORLD, &status);
        
        printf("Process %d received %d\n", rank, received);
    }

    MPI_Finalize();
    return 0;
}
