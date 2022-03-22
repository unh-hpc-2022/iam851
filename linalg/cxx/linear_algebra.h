
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

// uncomment below to get bounds checking
// #define XTENSOR_ENABLE_ASSERT 1

#include <xtensor/xtensor.hpp>
#include <xtensor/xio.hpp>

using vector = xt::xtensor<double, 1>;
using matrix = xt::xtensor<double, 2, xt::layout_type::column_major>;

double dot(const vector& x, const vector& y);
vector dot(const matrix& A, const vector& x);
void matrix_matrix_mul(const matrix& A, const matrix& B, matrix& C);

// ----------------------------------------------------------------------
// other useful stuff

#include <sys/time.h>
#include <stdlib.h>

static inline double Wtime(void)
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec / 1e6;
}

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
