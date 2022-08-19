cmake_minimum_required(VERSION 3.10)
set(projectName v)
project(${projectName})


set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(valgrind_use_of_uninitialised_value ./valgrind_use_of_uninitialised_value.c)
add_executable(valgrind_invalid_read ./valgrind_invalid_read.c)
