cmake_minimum_required(VERSION 3.27)
project(variadic_templates)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})


add_executable(ex1_variadicFunctions ex1_variadicFunctions.cpp)
add_executable(ex2_proxy ex2_proxy.cpp
        Proxy.h)
add_executable(ex3_Mixins ex3_Mixins.cpp)
add_executable(ex4_MultiVector ex4_MultiVector.cpp
        MultiVector.h)


target_link_libraries(ex2_proxy ${Boost_LIBRARIES})