cmake_minimum_required (VERSION 3.5)
project (fileIO)

# The version number.
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 5)

# configure a header file to pass some of the CMake settings
# to the source code
# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

ADD_EXECUTABLE(main main.cpp)
