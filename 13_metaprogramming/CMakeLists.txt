cmake_minimum_required(VERSION 3.28)
project(13_metaprogramming)

set(CMAKE_CXX_STANDARD 20)


add_executable(ex1_KlasyRekurencyjne ex1_KlasyRekurencyjne.cpp
        ex1_compilation_time_functions.h)
add_executable(ex2_constinit ex2_constinit.cpp
        ex2_power_pascal.h)
add_executable(ex3_IntegerList ex3_IntegerList.cpp
        ex3_IntegerList.h)

