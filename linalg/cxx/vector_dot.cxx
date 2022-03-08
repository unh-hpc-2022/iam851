
#include "linear_algebra.h"

#include <assert.h>

// ----------------------------------------------------------------------
// vector_dot
//
// returns the dot product of the two vectors
// x: first vector
// y: second vector

double vector_dot(const vector& x, const vector& y)
{
  assert(x.size() == y.size());
  double sum = 0.f;
  for (int i = 0; i < x.size(); i++) {
    sum += x(i) * y(i);
  }
  return sum;
}
