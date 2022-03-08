
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
  vector x(N), y(N), z_ref(N);

  for (int i = 0; i < x.size(); i++) {
    x(i) = 1 + i;
    y(i) = 2 + i;
    z_ref(i) = 3 + 2 * i;
  }

  vector z = add(x, y);
  assert(z == z_ref);

  // z.print();

  return 0;
}
