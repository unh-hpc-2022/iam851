
#include <mpi.h>

int main(int argc, char** argv)
{
  MPI_Init(&argc, &argv);

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int test = 0;
  if (rank == 0) {
    test = 99;
  }

  printf("Hello %d/%d test = %d\n", rank, size, test);
  // or if you like it C++-y
  // std::cout << "Hello " << rank << "/" << size << "test = " << test << "\n";
  MPI_Finalize();
  return 0;
}
