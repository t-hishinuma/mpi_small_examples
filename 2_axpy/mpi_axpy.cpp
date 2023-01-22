#include <mpi.h>

#include <iostream>
#include <random>
#include <vector>

// axpy: y = alpha * x + y
void print_vec(std::vector<double>& vec, int rank);
void random_array(std::vector<double>& vec);

void axpy(size_t size, double alpha, double* x, double* y) {
    for (size_t i = 0; i < size; i++) {
        y[i] += alpha * x[i];
    }
}

// main is written in C++ ////////////////////////
int main(int argc, char* argv[]) {
    size_t M = 3;
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double alpha = 4.0;
    std::vector<double> x(M);
    std::vector<double> y(M);

    random_array(x);

    axpy(y.size(), alpha, x.data(), y.data());

    print_vec(y, rank);
    MPI_Finalize();
}

// utils, written in C++ ////////////////////////

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
