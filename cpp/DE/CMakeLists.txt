cmake_minimum_required (VERSION 2.8)
project (Differential Evolution)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

ADD_LIBRARY(DESolver DESolver.hpp)
ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES (main DESolver)
