
#include "linear_algebra.h"

#include <assert.h>
#include <stdlib.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_dot() function

int main(int argc, char** argv)
{
  const int N = 3;
  double* x = calloc(N, sizeof(double));
  double* y = calloc(N, sizeof(double));

  for (int i = 0; i < N; i++) {
    x[i] = 1 + i;
    y[i] = 2 + i;
  }

  assert(vector_dot(x, y, N) == 20.);

  free(x);
  free(y);

  return 0;
}
