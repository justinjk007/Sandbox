cmake_minimum_required(VERSION 3.5)
project(QTlineChart)

set(CMAKE_CXX_STANDARD 11)

# Conan Setup
if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup()
else()
  # other way to get dependencies info
endif()

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main ${CONAN_LIBS})
