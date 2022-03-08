
#include "linear_algebra.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_add() function

int main(int argc, char** argv)
{
  const int N = 4;
  vector x(N), y(N), z(N), z_ref(N);

  for (int i = 0; i < x.n; i++) {
    VEC(x, i) = 1 + i;
    VEC(y, i) = 2 + i;
    VEC(z_ref, i) = 3 + 2 * i;
  }

  vector_add(x, y, z);
  assert(vector_is_equal(z, z_ref));

  // z.print();

  return 0;
}
