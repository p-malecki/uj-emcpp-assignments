cmake_minimum_required(VERSION 3.28)
project(11_concepts)

set(CMAKE_CXX_STANDARD 20)


# Check for filesystem support
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-std=gnu++20" COMPILER_SUPPORTS_GNU20)
if(COMPILER_SUPPORTS_GNU20)
    add_compile_options(-std=gnu++20)
    message(STATUS "Using C++20 with GNU extensions")
else()
    message(FATAL_ERROR "The compiler does not support C++20 with GNU extensions.")
endif()


add_executable(ex_11_1_literals
        literals.cpp)

add_executable(ex_11_2_filesystem
        path_operations.cpp
        path_operations.h)

add_executable(ex_11_3_concepts
        concepts.cpp)


