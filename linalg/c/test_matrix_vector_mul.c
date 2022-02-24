
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
  struct vector x, y;
  vector_construct(&x, N);
  vector_construct(&y, N);

  for (int i = 0; i < N; i++) {
    VEC(&x, i) = 1 + i;
  }
  // clang-format off
  double A[N][N] = {{1., 1., 0.},
		            {0., 2., 0.},
		            {0., 0., 3.}};
  // clang-format on

  matrix_vector_mul(N, A, &x, &y);
  assert(VEC(&y, 0) == 3. && VEC(&y, 1) == 4. && VEC(&y, 2) == 9.);

  vector_destruct(&x);
  vector_destruct(&y);

  return 0;
}
