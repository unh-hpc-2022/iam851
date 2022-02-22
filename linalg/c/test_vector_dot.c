
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
  struct vector x, y;

  x.data = calloc(N, sizeof(double));
  x.n = N;

  y.data = calloc(N, sizeof(double));
  y.n = N;

  for (int i = 0; i < x.n; i++) {
    x.data[i] = 1 + i;
  }

  for (int i = 0; i < y.n; i++) {
    y.data[i] = 2 + i;
  }

  assert(vector_dot(x.data, y.data, x.n) == 20.);

  free(x.data);
  free(y.data);

  return 0;
}
