
#include "wtime.h"

#include <cmath>
#include <iostream>

double f(double x)
{
  return std::sqrt(1. - x * x);
}

int main(int argc, char** argv)
{
  const int N = 100000000;

  double t1 = Wtime();
  double sum = 0.;
  double dx = 1. / N;
#pragma omp parallel for
  for (int i = 0; i < N; i++) {
    sum += .5 * dx * (f(i * dx) + f((i + 1) * dx));
  }
  double t2 = Wtime();
  std::cout << "time " << t2 - t1 << "\n";

  std::cout << "integral is approximately " << sum << "\n";

  return 0;
}
