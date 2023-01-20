#include <mpi.h>

#include <iostream>
#include <vector>

void generate_matrix() {}

void matvec() {
    int a = 1;
    int b = 2;
}

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::cout << "hello" << rank << "," << size << std::endl;
    std::vector<double> M = {1, 2, 3, 4};
    MPI_Finalize();
}
