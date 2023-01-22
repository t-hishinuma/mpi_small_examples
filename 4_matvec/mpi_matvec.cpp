#include <mpi.h>
#include <stdlib.h>

#include <iostream>
#include <random>
#include <vector>

// matvec: y = Ax

// utils
void print_vec(std::vector<double>& vec, int rank);
void random_array(std::vector<double>& vec);

void matvec(const double* local_A, const double* local_x, double* local_y,
            int local_M, int local_N, int global_N, MPI_Comm comm) {
    double* x = (double*)malloc(global_N * sizeof(double));
    MPI_Allgather(local_x, local_N, MPI_DOUBLE, x, local_N, MPI_DOUBLE, comm);

    for (size_t i = 0; i < local_M; i++) {
        double tmp = 0.0;
        for (size_t j = 0; j < global_N; j++) {
            tmp += local_A[i * global_N + j] * x[j];
        }
        local_y[i] = tmp;
    }
    free(x);
}

// main and utils are written in C++
int main(int argc, char* argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    size_t M = 3;
    size_t N = M * size;
    std::vector<double> A(M * N);
    std::vector<double> v(M);

    random_array(A);
    random_array(v);

    matvec(A.data(), v.data(), v.data(), M, M, N,
           MPI_COMM_WORLD);  // v = Av

    print_vec(v, rank);

    MPI_Finalize();
}

void print_vec(std::vector<double>& vec, int rank) {
    for (auto i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << "," << rank << std::endl;
    }
}

void random_array(std::vector<double>& array) {
    std::random_device random;
    std::mt19937 mt(random());  // FIXME
    std::uniform_real_distribution<> rand(0.0, 1.0);

    for (size_t i = 0; i < array.size(); i++) {
        array[i] = rand(mt);
    }
}
