cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(A5)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(A5 src/db.cpp src/main.cpp)

add_executable(my_test src/db.cpp test/test.cpp)

enable_testing()