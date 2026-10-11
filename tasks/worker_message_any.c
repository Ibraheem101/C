#include <stdio.h>
#include <mpi.h>

int main() {
    int i, rank, size, value, tag = 99;
    MPI_Status status;

    MPI_Init(NULL, NULL);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        for (i = 1; i < size; i++){
            MPI_Recv(&value, 1, MPI_INT, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
            printf("Process 0 received %d from process %d\n", value, status.MPI_SOURCE);
        }
        
    }
    else {
        MPI_Send(&rank, 1, MPI_INT, 0, tag, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
