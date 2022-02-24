
#include "linear_algebra.h"

void matrix_vector_mul(int n, const double A[n][n], const struct vector* x,
                       struct vector* y)
{
  for (int j = 0; j < n; j++) {
    VEC(y, j) = 0.;
    for (int i = 0; i < n; i++) {
      VEC(y, j) += A[j][i] * VEC(x, i);
    }
  }
}
