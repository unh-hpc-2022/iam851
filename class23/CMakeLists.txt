
cmake_minimum_required (VERSION 3.16)

project(IntroMPI)

find_package(MPI REQUIRED)

include(cmake/CPM.cmake)

CPMAddPackage(
  NAME xtl
  GITHUB_REPOSITORY xtensor-stack/xtl
  GIT_TAG 0.7.4
  VERSION 0.7.4
)

CPMAddPackage(
  NAME xtensor
  GITHUB_REPOSITORY xtensor-stack/xtensor
  GIT_TAG 0.24.0
  VERSION 0.24.0
)

add_executable(test_derivative test_derivative.cxx derivative.cxx)
target_link_libraries(test_derivative PRIVATE MPI::MPI_CXX xtensor)

add_executable(wave_equation wave_equation.cxx derivative.cxx)
target_link_libraries(wave_equation PRIVATE MPI::MPI_CXX xtensor)

add_executable(kdv kdv.cxx)
target_link_libraries(kdv PRIVATE MPI::MPI_CXX xtensor)

add_executable(mpi_dl_test mpi_dl_test.cxx)
target_link_libraries(mpi_dl_test PRIVATE MPI::MPI_CXX xtensor)
