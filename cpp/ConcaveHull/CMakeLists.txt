cmake_minimum_required (VERSION 3.2)
project (Hull)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

ADD_LIBRARY(hull hull.c)

ADD_EXECUTABLE(main main.cpp)

TARGET_LINK_LIBRARIES (main hull)
