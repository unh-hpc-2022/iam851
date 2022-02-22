
#include "linear_algebra.h"

#include <assert.h>
#include <stdlib.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_add() function

int main(int argc, char** argv)
{
  const int N = 4;
  double* x = calloc(N, sizeof(double));
  double* y = calloc(N, sizeof(double));
  double* z = calloc(N, sizeof(double));

  for (int i = 0; i < N; i++) {
    x[i] = 1 + i;
    y[i] = 2 + i;
  }

  vector_add(x, y, z, N);
  assert(z[0] == 3. && z[1] == 5. && z[2] == 7. && z[3] == 9.);

  free(x);
  free(y);
  free(z);

  return 0;
}
