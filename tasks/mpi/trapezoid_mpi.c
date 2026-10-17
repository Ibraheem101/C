#include <stdio.h>
#include <mpi.h>

double f(double x) {
    return x * x;
}

int main(int argc, char **argv) {
    int size, my_rank, local_n, n = 12;
    double a = 0.0, b = 6.0, h;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    h = (b - a) / n;
    local_n = n / size;

    double local_a = a + my_rank * local_n * h;
    double local_b = local_a + local_n * h;

    double local_sum = (f(local_a) + f(local_b)) / 2.0;

    for (int i = 1; i < local_n; i++) {
        double x = local_a + i * h;
        local_sum += f(x);

    }
    local_sum *= h;

    if (my_rank != 0) {
        MPI_Send(&local_sum, 1, MPI_DOUBLE, 0, 99, MPI_COMM_WORLD);
    }

    else {
        double recv;
        double sum = local_sum;
        for (int i = 1; i < size; i++){
            MPI_Recv(&recv, 1, MPI_DOUBLE, i, 99, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            sum += recv;
        }
        printf("Trapezoidal approximation: is %lf\n", sum);
    }
    MPI_Finalize();
    return 0;
}
