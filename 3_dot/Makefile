CXXFLAGS=-O3 -Wall
all: mpi_dot.out

mpi_dot.out: mpi_dot.cpp
	mpic++ $(CXXFLAGS) $< -o $@

run: mpi_dot.out
	mpirun -np 4 $<

clean:
	rm -rf *.out
