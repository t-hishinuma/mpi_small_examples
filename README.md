# mpi_small_examples
## How to build and exec.
```
make
make run
```

or

```
make run
```

### 1_helloworld
Simple hello world

### 2_axpy
Simple axpy (y = alpha * x + y);

### 3_dot
Inner product.
It uses MPI_Allreduce.

### 4_matvec
Simple, parallel matvec. It uses MPI_Allgather.
However, it needs temp. global vector.
I will impl. improved version 5_matvec_commT

### 5_matvec_commT
not implemented...
