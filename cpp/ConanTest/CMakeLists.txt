project(FoundationTimer)
cmake_minimum_required(VERSION 2.8.12)

# Conan Setup
if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup()
else()
  # other way to get dependencies info
endif()

ADD_EXECUTABLE(timer timer.cpp)
TARGET_LINK_LIBRARIES(timer ${CONAN_LIBS})
