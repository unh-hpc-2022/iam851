
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <assert.h>
#include <vector>

// uncomment the following to enable bounds checking
//#define BOUNDS_CHECK

// vector
//
// encapsulates what makes up a vector -- how many elements it contains (n), as
// well as the actual elements data[0] ... data[n-1]

class vector
{
public:
  vector(int n);
  void print() const;

  int size() const;
  double operator()(int i) const;
  double& operator()(int i);

private:
  std::vector<double> data_;
};

bool vector_is_equal(const vector& x, const vector& y);

// matrix
//
// encapsulates what makes up a matrix -- how many rows (m), how many columns,
// as well as the actual elements data[0] ... data[m*n-1]

struct matrix
{
  matrix(int m, int n);
  ~matrix();
  void print() const;

  double operator()(int i, int j) const;
  double& operator()(int i, int j);

  double* data;
  int m, n;
};

bool matrix_is_equal(const matrix& A, const matrix& B);

double vector_dot(const vector& x, const vector& y);
void vector_add(const vector& x, const vector& y, vector& z);
void matrix_vector_mul(const matrix& A, const vector& x, vector& y);
void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
