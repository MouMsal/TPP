cmake_minimum_required(VERSION 3.23)
project(TPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(TPP TPP.cpp CPU.cpp CPU.h Memory.cpp Memory.h)
