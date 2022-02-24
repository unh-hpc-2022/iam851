
#include <stdio.h>

void foo(double* p)
{
  printf("foot before p = %g %g\n", p[0], p[1]);
  p[0] = 10.;
  printf("foot after p = %g %g\n", p[0], p[1]);
}

int main()
{
  double p[2] = {99., 199.};
  printf("main before p = %g %g\n", p[0], p[1]);
  foo(p);
  printf("main after p = %g %g\n", p[0], p[1]);

  return 0;
}
