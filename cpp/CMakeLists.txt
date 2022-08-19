cmake_minimum_required(VERSION 3.10)
set(projectName leetcode_cpp)
project(${projectName})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# link_directories (${CMAKE_SOURCE_DIR}/build/archive)

add_executable(0001_twoNum ./0001_twoNum.cpp)
add_executable(0015_threeSum ./0015_threeSum.cpp)
