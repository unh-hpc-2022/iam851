
add_library(linalg_cxx vector_dot.cxx matrix_vector_mul.cxx
  matrix_matrix_mul.cxx)
target_link_libraries(linalg_cxx PUBLIC xtensor)

add_executable(test_linear_algebra test_linear_algebra.cxx)
target_link_libraries(test_linear_algebra PRIVATE GTest::gtest GTest::gtest_main linalg_cxx)
gtest_discover_tests(test_linear_algebra)
