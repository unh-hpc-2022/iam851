
#include "linear_algebra.h"

#include <stdio.h>

vector::vector(int n_in) : data(new double[n_in]), n(n_in) {}

vector::~vector()
{
  delete[] data;
  // The below isn't necessary, but may help make certain bugs more obvious.
  // data = NULL;
  // n = 0;
}

void vector::print() const
{
  printf("{");
  for (int i = 0; i < n; i++) {
    printf(" %g", (*this)(i));
  }
  printf(" }\n");
}

int vector::size() const
{
  return n;
}

double vector::operator()(int i) const
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < n);
#endif
  return data[i];
}

double& vector::operator()(int i)
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < n);
#endif
  return data[i];
}

bool vector_is_equal(const vector& x, const vector& y)
{
  if (x.size() != y.size()) {
    return false;
  }
  for (int i = 0; i < x.size(); i++) {
    if (x(i) != y(i)) {
      return false;
    }
  }

  return true;
}
