all: mpi_matvec.out

mpi_matvec.out: mpi_matvec.cpp
	mpic++ $< -o $@

run: mpi_matvec.out
	mpirun -np 4 $<

clean:
	rm -rf *.out
