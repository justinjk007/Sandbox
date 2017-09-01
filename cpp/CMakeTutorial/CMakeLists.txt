CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (CMakeTutorial)

# The version number.
SET (Tutorial_VERSION_MAJOR 0)
SET (Tutorial_VERSION_MINOR 5)

# configure a header file to pass some of the CMake settings
# to the source code
CONFIGURE_FILE (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")

# include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
# add_subdirectory (MathFunctions)

ADD_LIBRARY(MathFunctions MathFunctions.cpp)
ADD_LIBRARY(subdirtest "") # Include libs from subdir

INCLUDE(subdir/CMakeLists.txt) # Include libs from subdir

ADD_EXECUTABLE(main tutorial.cpp)
TARGET_LINK_LIBRARIES (main MathFunctions subdirtest)
