#include <mpi.h>

#include <iostream>
#include <vector>

// for debug
void print_matrix(double* Mat, size_t M, size_t N, int rank);

// MxN partitioned matrix
void generate_matrix(double* Mat, size_t M, size_t N, int rank, int size) {
    for (auto i = 0; i < M; i++) {
        for (auto j = 0; j < N; j++) {
            Mat[i * N + j] = rand();
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
    std::vector<double> Mat(rank * size);
    std::vector<double> Vec(size);
    MPI_Finalize();
}

// debug util////////////////////////

void print_matrix(double* Mat, size_t M, size_t N, int rank) {
    for (auto i = 0; i < M; i++) {
        for (auto j = 0; j < N; j++) {
            std::cout << Mat[i * N + j] << std::endl;
        }
    }
}
