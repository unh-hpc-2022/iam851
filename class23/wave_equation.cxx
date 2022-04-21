
#include "wave_equation.h"

#include <xtensor/xcsv.hpp>

#include <fstream>
#include <iostream>
#include <cassert>

int main(int argc, char** argv)
{
  const int N = 16;            // number of grid points
  const int n_timesteps = 100; // total number of steps to run
  const int output_every = 1;  // how often to write output
  const double c = 1;          // wave speed

  mpi_domain domain(MPI_COMM_WORLD);

  assert(N % domain.size() == 0); // # grid points must be divisible by # procs
  int n = N / domain.size();

  // create coordinates [0, 2pi)
  double L = 2. * M_PI; // total size of domain
  double dx = L / N;
  auto x = xt::arange<double>(domain.rank() * n, (domain.rank() + 1) * n) * dx;

  // our initial condition
  xt::xtensor<double, 1> u = sin(x);

  double dt = dx;
  for (int n = 0; n < n_timesteps; n++) {
    if (n % output_every == 0) {
      std::ofstream out("u-" + std::to_string(n) + "-" +
                        std::to_string(domain.rank()) + ".csv");
      xt::dump_csv(out, xt::stack(xt::xtuple(x, u), 1));
    }

    // advance one timestep
    auto k1 = -c * derivative(u, dx);
    auto k2 = -c * derivative(u + .5 * dt * k1, dx);
    u += dt * k2;
  }

  MPI_Finalize();
  return 0;
}
