
#include "linear_algebra.h"

#include <assert.h>

void matrix_vector_mul(const matrix& A, const vector& x, vector& y)
{
  assert(A.m == y.n);
  assert(A.n == x.n);

  for (int j = 0; j < y.n; j++) {
    y(j) = 0.;
    for (int i = 0; i < x.n; i++) {
      y(j) += A(j, i) * x(i);
    }
  }
}
