
#include "wtime.h"

#include <xtensor/xtensor.hpp>

#include <complex>
#include <cstdio>

static int calc_pixel(std::complex<double> c)
{
  const int max_iter = 256;
  std::complex<double> z = 0.;
  int cnt;

  for (cnt = 0; cnt < max_iter; cnt++) {
    z = z * z + c;
    if (std::abs(z) >= 2.) {
      break;
    }
  }
  return cnt;
}

int main(int argc, char** argv)
{
  using namespace std::complex_literals;

  const int MX = 2000;
  const int MY = 2000;

  const std::complex<double> z0 = -2. - 1.i;
  const std::complex<double> z1 = 1. + 1.i;

  auto data = xt::empty<int, xt::layout_type::column_major>({MX, MY});

  double dx = std::real(z1 - z0) / (MX - 1);
  double dy = std::imag(z1 - z0) / (MY - 1);

  double t1 = Wtime();
#pragma omp parallel for
  for (int iy = 0; iy < MY; iy++) {
    for (int ix = 0; ix < MX; ix++) {
      std::complex<double> c = z0 + dx * ix + dy * iy * 1i;
      data(ix, iy) = calc_pixel(c);
    }
  }
  double t2 = Wtime();
  std::cout << "took " << t2 - t1 << " secs\n";

#if 0
  FILE* file = fopen("mandelbrot.asc", "w");
  for (int iy = 0; iy < MY; iy++) {
    for (int ix = 0; ix < MX; ix++) {
      std::complex<double> c = z0 + dx * ix + dy * iy * 1i;
      fprintf(file, "%g %g %d\n", std::real(c), std::imag(c), data(ix, iy));
    }
    fprintf(file, "\n");
  }
  fclose(file);
#endif
}
