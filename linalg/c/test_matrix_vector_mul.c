
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

  struct matrix A;
  matrix_construct(&A, N, N);

  for (int i = 0; i < N; i++) {
    VEC(&x, i) = 1 + i;
    MAT(&A, i, i) = 1 + i;
  }
  // add one off-diagonal non-zero element
  MAT(&A, 0, 1) = 1.;

  matrix_vector_mul(&A, &x, &y);
  assert(VEC(&y, 0) == 3. && VEC(&y, 1) == 4. && VEC(&y, 2) == 9.);

  vector_destruct(&x);
  vector_destruct(&y);
  matrix_destruct(&A);

  return 0;
}
