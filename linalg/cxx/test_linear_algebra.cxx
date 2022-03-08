
#include <gtest/gtest.h>

#include "linear_algebra.h"

TEST(LinearAlgebra, vector_dot)
{
  const int N = 3;
  vector x(N), y(N);

  for (int i = 0; i < x.size(); i++) {
    x(i) = 1 + i;
  }

  for (int i = 0; i < y.size(); i++) {
    y(i) = 2 + i;
  }

  EXPECT_EQ(dot(x, y), 20.);
}

TEST(LinearAlgebra, vector_add)
{
  const int N = 4;
  vector x(N), y(N), z_ref(N);

  for (int i = 0; i < x.size(); i++) {
    x(i) = 1 + i;
    y(i) = 2 + i;
    z_ref(i) = 3 + 2 * i;
  }

  vector z = x + y;
  EXPECT_EQ(z, z_ref);
}

TEST(LinearAlgebra, matrix_vector_mul)
{
  const int N = 3;
  vector x(N), y(N);
  matrix A(N, N);

  for (int i = 0; i < N; i++) {
    x(i) = 1 + i;
    A(i, i) = 1 + i;
  }
  // add one off-diagonal non-zero element
  A(0, 1) = 1.;

  matrix_vector_mul(A, x, y);
  EXPECT_TRUE(y(0) == 3. && y(1) == 4. && y(2) == 9.);
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
