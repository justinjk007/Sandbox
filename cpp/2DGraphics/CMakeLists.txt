cmake_minimum_required (VERSION 3.5)
project (Graphics2D)

# The version number.
SET (Tutorial_VERSION_MAJOR 0)
SET (Tutorial_VERSION_MINOR 1)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

SET(CMAKE_PREFIX_PATH "C:\\Glew\\glew\\")
SET(CMAKE_LIBRARY_PATH "d:\\Glew\\glew\\lib\\Release\\Win32\\")

FIND_PACKAGE (OpenGL REQUIRED)
FIND_PACKAGE (GLEW REQUIRED)

INCLUDE_DIRECTORIES (${OPENGL_INCLUDE_DIRS})
INCLUDE_DIRECTORIES (${GLEW_INCLUDE_DIRS})
LINK_LIBRARIES ( main ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES})

ADD_EXECUTABLE(main main.cpp)
