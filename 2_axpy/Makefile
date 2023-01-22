CXXFLAGS=-O3 -Wall
all: mpi_axpy.out

mpi_axpy.out: mpi_axpy.cpp
	mpic++ $(CXXFLAGS) $< -o $@

run: mpi_axpy.out
	mpirun -np 4 $<

clean:
	rm -rf *.out
