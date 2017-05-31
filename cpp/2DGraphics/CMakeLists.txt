cmake_minimum_required (VERSION 3.5)
project (Graphics2D)

# The version number.
SET (Tutorial_VERSION_MAJOR 0)
SET (Tutorial_VERSION_MINOR 1)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

SET(CMAKE_PREFIX_PATH "C:\\Glew\\glew\\;C:\\Glfw")
SET(CMAKE_LIBRARY_PATH "C:\\Glew\\glew\\lib\\Release\\Win32\\;C:\\Glfw\\lib-vc2015")

FIND_PACKAGE (OpenGL REQUIRED)
FIND_PACKAGE (GLEW REQUIRED)

INCLUDE_DIRECTORIES (${OPENGL_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS})
LINK_LIBRARIES ( main ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${OPENGL_glu_LIBRARY})

ADD_EXECUTABLE(main main.cpp)
