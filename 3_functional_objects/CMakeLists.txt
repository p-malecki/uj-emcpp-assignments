cmake_minimum_required(VERSION 3.24)
project(functional_objects)

set(CMAKE_CXX_STANDARD 17)

add_executable(functional_objects function_pointers.cpp)
add_executable(lambda_expressions lambda_expressions.cpp)
add_executable(Printer Printer.cpp)
