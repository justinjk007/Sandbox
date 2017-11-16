cmake_minimum_required(VERSION 3.5)
project(QTlineChart)

set(CMAKE_CXX_STANDARD 11)

# Conan Setup
if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  # IF we are getting dependencies with conan
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup()
else()
  # other way to get dependencies info
  find_package(Qt5Widgets REQUIRED)
  find_package(Qt5Charts REQUIRED)
  set(CMAKE_AUTOMOC ON)
  set(CMAKE_AUTOUIC ON)
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  # IF we are getting dependencies with conan
  ADD_EXECUTABLE(main main.cpp)
  TARGET_LINK_LIBRARIES(main ${CONAN_LIBS})
else()
  # IF we are not using conan link libs the regular way
  ADD_EXECUTABLE(main main.cpp)
  TARGET_LINK_LIBRARIES(main Qt5::Widgets Qt5::Charts)
endif()
