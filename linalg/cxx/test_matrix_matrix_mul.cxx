
#include "linear_algebra.h"

#include <algorithm>
#include <cassert>
#include <iostream>

// ----------------------------------------------------------------------
// setup_test_matrices
//
// initializes the two matrices A, B, and the reference solution C_ref

static void setup_test_matrices(matrix& A, matrix& B, matrix& C_ref)
{
  // the test matrices are diagonal, which isn't really good,
  // a more general test case would be better.

  // the matrices are initialized to zero, so we only set the non-zero elements
  // on the diagonal
  for (int i = 0; i < std::min(A.n_rows(), A.n_cols()); i++) {
    A(i, i) = i;
  }
  for (int i = 0; i < std::min(B.n_rows(), B.n_cols()); i++) {
    B(i, i) = i;
  }
  for (int i = 0;
       i < std::min(std::min(C_ref.n_rows(), C_ref.n_cols()), A.n_cols());
       i++) {
    C_ref(i, i) = i * i;
  }
}

// ----------------------------------------------------------------------
// main
//
// test the mat_vec_mul() function

int main(int argc, char** argv)
{
  const int m = 5, n = 5, k = 2;

  matrix A(m, k), B(k, n), C(m, n), C_ref(m, n);

  // build a test matrix
  setup_test_matrices(A, B, C_ref);

  // calculate C = AB
  matrix_matrix_mul(A, B, C);

  // std::cout << "C = " << C << "\n";

  // the resulting vector for this test should equal our reference result
  assert(C == C_ref);

  return 0;
}
