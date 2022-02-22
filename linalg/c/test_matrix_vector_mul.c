
#include "linear_algebra.h"

#include <assert.h>
#include <stdlib.h>

// ----------------------------------------------------------------------
// main
//
// test the matrix_vector_mul() function

int main(int argc, char** argv)
{
  const int N = 3;
  double* x = calloc(N, sizeof(double));
  double* y = calloc(N, sizeof(double));

  for (int i = 0; i < N; i++) {
    x[i] = 1 + i;
  }
  // clang-format off
  double A[N][N] = {{1., 1., 0.},
		            {0., 2., 0.},
		            {0., 0., 3.}};
  // clang-format on

  matrix_vector_mul(N, A, x, y);
  assert(y[0] == 3. && y[1] == 4. && y[2] == 9.);

  free(x);
  free(y);

  return 0;
}
