
#include "linear_algebra.h"

#include <stdio.h>

matrix::matrix(int m, int n) : m(m), n(n), data_(m * n) {}

std::ostream& operator<<(std::ostream& os, const matrix& A)
{
  os << "{";
  for (int i = 0; i < A.m; i++) {
    os << "{";
    for (int j = 0; j < A.n; j++) {
      os << " " << A(i, j);
    }
    os << " }, ";
  }
  os << "}";

  return os;
}

double matrix::operator()(int i, int j) const
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < m);
  assert(j >= 0 && j < n);
#endif
  return data_[i * n + j];
}

double& matrix::operator()(int i, int j)
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < m);
  assert(j >= 0 && j < n);
#endif
  return data_[i * n + j];
}

bool operator==(const matrix& A, const matrix& B)
{
  if (A.m != B.m || A.n != B.n) {
    return false;
  }

  for (int i = 0; i < A.m; i++) {
    for (int j = 0; j < A.n; j++) {
      if (A(i, j) != B(i, j)) {
        return false;
      }
    }
  }

  return true;
}
