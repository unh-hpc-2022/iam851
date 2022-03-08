
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
  vector x(N), y(N);

  for (int i = 0; i < x.n; i++) {
    x(i) = 1 + i;
  }

  for (int i = 0; i < y.n; i++) {
    y(i) = 2 + i;
  }

  assert(vector_dot(x, y) == 20.);

  return 0;
}
