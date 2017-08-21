# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.

cmake_minimum_required(VERSION 2.8.10)
project( AlphaShapes )

set(CGAL_DIR "C:\\dev\\CGAL-4.10\\cmake\\modules")

find_package(CGAL REQUIRED)

if ( CGAL_FOUND )
  message("\nCGAL Library was found\n")
  # include( ${CGAL_USE_FILE} )
  # include( CGAL_CreateSingleSourceCGALProgram )
  # include_directories ("${CGAL_ROOT}/include/CGAL")
  # include_directories (BEFORE "../../include")
  # # create a target per cppfile
  # file(GLOB cppfiles RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
  # foreach(cppfile ${cppfiles})
  #   create_single_source_cgal_program( "${cppfile}" )
  # endforeach()
else()
  message(FATAL_ERROR "CGAL library was not found!!")
endif()
