
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <assert.h>
#include <stdbool.h>

// uncomment the following to enable bounds checking
//#define BOUNDS_CHECK

// vector
//
// encapsulates what makes up a vector -- how many elements it contains (n), as
// well as the actual elements data[0] ... data[n-1]

struct vector
{
  vector(int n);
  void print() const;

  double* data;
  int n;
};

#ifdef BOUNDS_CHECK
#define VEC(v, i)                                                              \
  (*({                                                                         \
    assert(i >= 0 && i < (v).n);                                               \
    &(v).data[i];                                                              \
  }))
#else
#define VEC(v, i) ((v).data[i])
#endif

void vector_destruct(vector& v);
bool vector_is_equal(const vector& x, const vector& y);

// matrix
//
// encapsulates what makes up a matrix -- how many rows (m), how many columns,
// as well as the actual elements data[0] ... data[m*n-1]

struct matrix
{
  matrix(int m, int n);
  void print() const;

  double* data;
  int m, n;
};

#ifdef BOUNDS_CHECK
#define MAT(A, i, j)                                                           \
  (*({                                                                         \
    assert(i >= 0 && i < (A).m);                                               \
    assert(j >= 0 && j < (A).n);                                               \
    &(A).data[(i) * (A).n + (j)];                                              \
  }))
#else
#define MAT(A, i, j) ((A).data[(i) * (A).n + (j)])
#endif

void matrix_destruct(matrix& A);
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
