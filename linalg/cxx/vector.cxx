
#include "linear_algebra.h"

#include <stdio.h>

vector::vector(int n) : data_(n) {}

void vector::print() const
{
  printf("{");
  for (int i = 0; i < size(); i++) {
    printf(" %g", (*this)(i));
  }
  printf(" }\n");
}

int vector::size() const
{
  return data_.size();
}

double vector::operator()(int i) const
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < size());
#endif
  return data_[i];
}

double& vector::operator()(int i)
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < size());
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
