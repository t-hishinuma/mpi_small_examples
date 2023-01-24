#include <mpi.h>

#include <iostream>

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::cout << "hello world, my rank = " << rank << "/" << size << std::endl;

    int data = 0;

    MPI_Status stat;

    if (rank == 0) {
        data = rank;
        MPI_Send(&data, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
        std::cout << "data is " << data << ", my rank is " << rank << std::endl;
    } else if (rank == size - 1) {
        MPI_Recv(&data, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, &stat);
        data++;
        std::cout << "data is " << data << ", my rank is " << rank << std::endl;
    } else {
        MPI_Recv(&data, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, &stat);
        data++;
        MPI_Send(&data, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
        std::cout << "data is " << data << ", my rank is " << rank << std::endl;
    }

    MPI_Finalize();
}
