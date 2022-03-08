
#include "linear_algebra.h"

#include <stdio.h>

vector::vector(int n) : data_(new double[n]), n_(n) {}

vector::~vector()
{
  delete[] data_;
  // The below isn't necessary, but may help make certain bugs more obvious.
  // data = NULL;
  // n = 0;
}

void vector::print() const
{
  printf("{");
  for (int i = 0; i < n_; i++) {
    printf(" %g", (*this)(i));
  }
  printf(" }\n");
}

int vector::size() const
{
  return n_;
}

double vector::operator()(int i) const
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < n_);
#endif
  return data_[i];
}

double& vector::operator()(int i)
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < n_);
#endif
  return data_[i];
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
