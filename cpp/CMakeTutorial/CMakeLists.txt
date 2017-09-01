cmake_minimum_required (VERSION 3.5)
project (CMakeTutorial)

# The version number.
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 5)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

# include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
# add_subdirectory (MathFunctions)

ADD_SUBDIRECTORY("${PROJECT_SOURCE_DIR}/subdir")

ADD_LIBRARY(MathFunctions MathFunctions.cpp)

ADD_EXECUTABLE(Tutorial tutorial.cpp)
TARGET_LINK_LIBRARIES (Tutorial MathFunctions ${HEADERS} ${SOURCE})
