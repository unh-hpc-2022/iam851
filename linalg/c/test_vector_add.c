
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
  struct vector x, y, z;
  vector_construct(&x, N);
  vector_construct(&y, N);
  vector_construct(&z, N);

  for (int i = 0; i < x.n; i++) {
    VEC(&x, i) = 1 + i;
  }

  for (int i = 0; i < y.n; i++) {
    VEC(&y, i) = 2 + i;
  }

  vector_add(&x, &y, &z);
  assert(VEC(&z, 0) == 3. && VEC(&z, 1) == 5. && VEC(&z, 2) == 7. &&
         VEC(&z, 3) == 9.);

  // vector_print(&z);

  vector_destruct(&x);
  vector_destruct(&y);
  vector_destruct(&z);

  return 0;
}
