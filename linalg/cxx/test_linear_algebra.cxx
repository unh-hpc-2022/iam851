
#include <gtest/gtest.h>

#include "linear_algebra.h"

TEST(LinearAlgebra, vector_dot)
{
  vector x = {1., 2., 3.};
  vector y = {2., 3., 4.};

  EXPECT_EQ(dot(x, y), 20.);
}

TEST(LinearAlgebra, vector_add)
{
  vector x = {1., 2., 3., 4.};
  vector y = {2., 3., 4., 5.};

  vector z = x + y;
  EXPECT_EQ(z, (vector{3., 5., 7., 9.}));
}

TEST(LinearAlgebra, matrix_vector_mul)
{
  const int N = 3;
  vector x = {1., 2., 3.};
  vector y = xt::empty<double>({3});
  matrix A(N, N);

  for (int i = 0; i < N; i++) {
    A(i, i) = 1 + i;
  }
  // add one off-diagonal non-zero element
  A(0, 1) = 1.;

  matrix_vector_mul(A, x, y);
  EXPECT_EQ(y, (vector{3., 4., 9.}));
}

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

TEST(LinearAlgebra, matrix_matrix_mul)
{
  const int m = 5, n = 5, k = 2;

  matrix A(m, k), B(k, n), C(m, n), C_ref(m, n);

  // build test matrices
  setup_test_matrices(A, B, C_ref);

  // calculate C = AB
  matrix_matrix_mul(A, B, C);

  // std::cout << "C = " << C << "\n";

  EXPECT_EQ(C, C_ref);
}
