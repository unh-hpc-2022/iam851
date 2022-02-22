cmake_minimum_required (VERSION 3.16)

project(LinearAlgebra)

include(cmake/CPM.cmake)

include(CTest)

CPMAddPackage(
  NAME GTest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG release-1.11.0
  EXCLUDE_FROM_ALL ON
)
include(GoogleTest)

add_subdirectory(c)
