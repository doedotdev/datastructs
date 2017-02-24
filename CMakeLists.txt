cmake_minimum_required(VERSION 3.6)
project(datastructs)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES main.cpp test/bst.h)
add_executable(datastructs ${SOURCE_FILES} test/bst.h)
target_link_libraries(datastructs gtest gtest_main)