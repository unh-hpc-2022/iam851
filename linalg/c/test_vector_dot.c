
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
  vector_construct(&x, N);
  vector_construct(&y, N);

  for (int i = 0; i < x.n; i++) {
    x.data[i] = 1 + i;
  }

  for (int i = 0; i < y.n; i++) {
    y.data[i] = 2 + i;
  }

  assert(vector_dot(&x, &y) == 20.);

  vector_destruct(&x);
  vector_destruct(&y);
  return 0;
}
