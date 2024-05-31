cmake_minimum_required(VERSION 3.28)
project(12_threads)

set(CMAKE_CXX_STANDARD 20)

add_executable(random random.cpp)

add_executable(ex_11_2_Mandelbrot
        mandelbrot/ex_11_2_Mandelbrot.cpp
        mandelbrot/EasyBMP.cpp
        mandelbrot/EasyBMP.h
        mandelbrot/EasyBMP_BMP.h
        mandelbrot/EasyBMP_DataStructures.h
        mandelbrot/EasyBMP_VariousBMPutilities.h
)

add_executable(futures_and_promises futures_and_promises.cpp
        futures_and_promises.h)
