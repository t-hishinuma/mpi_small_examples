CXXFLAGS=-O3 -Wall
all: mpi_matvec_commT.out

mpi_matvec_commT.out: mpi_matvec_commT.cpp
	mpic++ $(CXXFLAGS) $< -o $@

run: mpi_matvec_commT.out
	mpirun -np 2 $<

clean:
	rm -rf *.out
