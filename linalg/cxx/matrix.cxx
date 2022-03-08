
#include "linear_algebra.h"

#include <stdio.h>

matrix::matrix(int n_rows, int n_cols)
  : m_(n_rows), n_(n_cols), data_(n_rows * n_cols)
{}

std::ostream& operator<<(std::ostream& os, const matrix& A)
{
  os << "{";
  for (int i = 0; i < A.n_rows(); i++) {
    os << "{";
    for (int j = 0; j < A.n_cols(); j++) {
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
  return data_[i * n_ + j];
}

double& matrix::operator()(int i, int j)
{
#ifdef BOUNDS_CHECK
  assert(i >= 0 && i < m);
  assert(j >= 0 && j < n);
#endif
  return data_[i * n_ + j];
}

bool operator==(const matrix& A, const matrix& B)
{
  if (A.n_rows() != B.n_rows() || A.n_cols() != B.n_cols()) {
    return false;
  }

  for (int i = 0; i < A.n_rows(); i++) {
    for (int j = 0; j < A.n_cols(); j++) {
      if (A(i, j) != B(i, j)) {
        return false;
      }
    }
  }

  return true;
}
