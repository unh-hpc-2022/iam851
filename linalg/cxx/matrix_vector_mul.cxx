
#include "linear_algebra.h"

#include <assert.h>

vector dot(const matrix& A, const vector& x)
{
  assert(A.shape(1) == x.size());

  vector y = xt::zeros<double>({A.shape(0)});
  for (int j = 0; j < y.size(); j++) {
    for (int i = 0; i < x.size(); i++) {
      y(j) += A(j, i) * x(i);
    }
  }

  return y;
}
