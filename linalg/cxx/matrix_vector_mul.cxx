
#include "linear_algebra.h"

#include <assert.h>

void matrix_vector_mul(const matrix& A, const vector& x, vector& y)
{
  assert(A.m == y.size());
  assert(A.n == x.size());

  for (int j = 0; j < y.size(); j++) {
    y(j) = 0.;
    for (int i = 0; i < x.size(); i++) {
      y(j) += A(j, i) * x(i);
    }
  }
}
