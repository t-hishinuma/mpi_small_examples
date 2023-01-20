#include <mpi.h>

#include <iostream>
#include <vector>

// MxN partitioned matrix
void generate_matrix(double* M, size_t M, size_t N) {
    for (auto i = 0; i < M; i++) {
        for (auto i = 0; i < M; i++) {
        }
    }
}

void matvec() {
    // impl.
}

int main(int argc, char* argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    std::cout << "hello" << rank << "," << size << std::endl;
    std::vector<double> M = {1, 2, 3, 4};
    MPI_Finalize();
}
