cmake_minimum_required(VERSION 3.28)
project(10_sfinae)

set(CMAKE_CXX_STANDARD 17)


add_executable(ex_10_1_sfinae
        ex_10_1_sfinae.cpp
        sfinae.h)

add_executable(ex_10_2_tag_dispatching
        ex_10_2_tag_dispatching.cpp
        tag_dispatching.h)

add_executable(ex_10_3_chrono
        ex_10_3_chrono.cpp
)




