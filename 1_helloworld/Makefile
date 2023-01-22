CXXFLAGS=-O3 -Wall
all: mpi_hello.out

mpi_hello.out: mpi_hello.cpp
	mpic++ $(CXXFLAGS) $< -o $@

run: mpi_hello.out
	mpirun -np 4 $<

clean:
	rm -rf *.out
