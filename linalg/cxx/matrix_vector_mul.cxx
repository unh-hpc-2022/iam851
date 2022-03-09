
#include "linear_algebra.h"

#include <assert.h>

void matrix_vector_mul(const matrix& A, const vector& x, vector& y)
{
  assert(A.n_rows() == y.size());
  assert(A.n_cols() == x.size());

  for (int j = 0; j < y.size(); j++) {
    y(j) = 0.;
    for (int i = 0; i < x.size(); i++) {
      y(j) += A(j, i) * x(i);
    }
  }
}
