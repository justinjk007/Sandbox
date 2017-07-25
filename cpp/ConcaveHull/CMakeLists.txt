cmake_minimum_required (VERSION 3.2)
project (clitest)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

ADD_LIBRARY(hullfinder hullfinder.cpp)

ADD_EXECUTABLE(main main.cpp)

TARGET_LINK_LIBRARIES (main hullfinder)
