MPI_MAJOR=4
MPI_MINOR=0
MPI_PATCH=7
MPI_VERSION=$(MPI_MAJOR).$(MPI_MINOR).$(MPI_PATCH)

wget https://download.open-mpi.org/release/open-mpi/v$MPI_MAJOR.$MPI_MINOR/openmpi-$MPI_VERSION.tar.gz
tar xzvf openmpi-$MPI_VERSION.tar.gz
rm -rf openmpi-$MPI_VERSION.tar.gz
cd openmpi-$MPI_VERSION
./configure CC=clang CXX=clang++
make -j $(nproc)
sudo make install

echo "please set export LD_LIBRARY_PATH=/usr/local/lib/:/lib/:\$LD_LIBRARY_PATH"
