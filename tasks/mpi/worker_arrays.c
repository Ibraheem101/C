#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int count, my_rank, comm_sz, buffer[10];
    MPI_Status status;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if (my_rank == 0) {
        for (int i = 0; i < comm_sz - 1; i++) {
            MPI_Recv(buffer, 10, MPI_INT, MPI_ANY_SOURCE, 50, MPI_COMM_WORLD, &status);
            MPI_Get_count(&status, MPI_INT, &count);
            printf("Received %d elements from process %d with tag %d\n", count, status.MPI_SOURCE, status.MPI_TAG);
        
            printf("Data: ");

            for (int j = 0; j < count; j++) {
                printf("%d ", *(buffer + j));
        }

        printf("\n");
        }

        
    }
    else if (my_rank == 1) {
        int numbers[] = {10, 11};
        MPI_Send(numbers, 2, MPI_INT, 0, 50, MPI_COMM_WORLD);
    }

    else if (my_rank == 2) {
        int numbers[] = {20, 21, 22};
        MPI_Send(numbers, 3, MPI_INT, 0, 50, MPI_COMM_WORLD);
    }

    else if (my_rank == 3) {
        int numbers[] = {30, 31, 32, 33};
        MPI_Send(numbers, 4, MPI_INT, 0, 50, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
