cmake_minimum_required(VERSION 3.27.8)
project(class_templates)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex1_Pair ex1_Pair.cpp)
add_executable(ex2_staticVector ex2_staticVector.cpp
        staticVector.h)
add_executable(ex3_dynamicVector ex3_dynamicVector.cpp
        staticVector.h
        dynamicVector.h)
add_executable(ex4_conversion ex4_conversion.cpp
        staticVector.h
        dynamicVector.h)
