cmake_minimum_required (VERSION 3.16)

project(HelloCpp)

add_library(stuff greeting.cxx factorial.cxx)

add_executable(hello hello.cxx)
target_link_libraries(hello PRIVATE stuff)
