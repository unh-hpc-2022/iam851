
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <ostream>
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

  int size() const;
  double operator()(int i) const;
  double& operator()(int i);

private:
  std::vector<double> data_;
};

bool operator==(const vector& x, const vector& y);
std::ostream& operator<<(std::ostream& os, const vector& v);

// matrix
//
// encapsulates what makes up a matrix -- how many rows (m), how many columns,
// as well as the actual elements data[0] ... data[m*n-1]

class matrix
{
public:
  matrix(int m, int n);

  double operator()(int i, int j) const;
  double& operator()(int i, int j);

  int m, n;

private:
  std::vector<double> data_;
};

bool operator==(const matrix& A, const matrix& B);
std::ostream& operator<<(std::ostream& os, const matrix& A);

double dot(const vector& x, const vector& y);
vector operator+(const vector& x, const vector& y);
void matrix_vector_mul(const matrix& A, const vector& x, vector& y);
void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
