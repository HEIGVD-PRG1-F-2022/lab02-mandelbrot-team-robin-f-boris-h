cmake_minimum_required(VERSION 3.23)
project(Mandelbrot)

set(CMAKE_CXX_STANDARD 20)

add_executable(Mandelbrot main.cpp display.h display.cpp animation.h animation.cpp mandelbrot.h mandelbrot.cpp)
