
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
  vector x(N), y(N);

  matrix A(N, N);

  for (int i = 0; i < N; i++) {
    VEC(x, i) = 1 + i;
    A(i, i) = 1 + i;
  }
  // add one off-diagonal non-zero element
  A(0, 1) = 1.;

  matrix_vector_mul(A, x, y);
  assert(VEC(y, 0) == 3. && VEC(y, 1) == 4. && VEC(y, 2) == 9.);

  return 0;
}
