cmake_minimum_required(VERSION 3.9)
project(lab4)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab4 main.cpp Point.cpp Point.h Shape.cpp Shape.h Color.cpp Color.h Matrix.cpp Matrix.h x11context.cpp x11context.h Line.cpp Line.h Triangle.cpp Triangle.h)