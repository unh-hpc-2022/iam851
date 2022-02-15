cmake_minimum_required (VERSION 3.16)

project(Hello)

# It's not a real meaningful library, so I'm not giving it a real
# meaningful name ("stuff") either...
add_library(stuff greeting.c factorial.c)

add_executable(hello hello.c)
target_link_libraries(hello stuff)
