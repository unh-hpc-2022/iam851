
cmake_minimum_required (VERSION 3.16)

project(IntroMPI)

find_package(MPI REQUIRED)

include(cmake/CPM.cmake)

# CPMAddPackage(
#   NAME xtl
#   GITHUB_REPOSITORY xtensor-stack/xtl
#   GIT_TAG 0.7.4
#   VERSION 0.7.4
# )

# CPMAddPackage(
#   NAME xtensor
#   GITHUB_REPOSITORY xtensor-stack/xtensor
#   GIT_TAG 0.24.0
#   VERSION 0.24.0
# )

add_executable(test_mpi test_mpi.cxx)
target_link_libraries(test_mpi PRIVATE MPI::MPI_CXX)

add_executable(test_integration_mpi test_integration_mpi.cxx)
target_link_libraries(test_integration_mpi PRIVATE MPI::MPI_CXX)
