#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int comm_sz, count, my_rank, tag = 0;
    int numbers[5] = {10, 20, 30, 40, 50};
    int values[100];
    
    MPI_Init(&argc, &argv);

    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if (my_rank == 3) {
        MPI_Send(numbers, 5, MPI_INT, 0, tag, MPI_COMM_WORLD);
    }
    else if (my_rank == 0) {
        MPI_Recv(values, 10, MPI_INT, 3, tag, MPI_COMM_WORLD, &status);

        MPI_Get_count(&status, MPI_INT, &count);

        printf("Process %d received %d integers\n", my_rank, count);
    }

    MPI_Finalize();
    return 0;
}
