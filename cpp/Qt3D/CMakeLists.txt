cmake_minimum_required(VERSION 3.5)
project(QT3D)

set(CMAKE_CXX_STANDARD 11)

# Qt Setup
find_package(Qt5 COMPONENTS Widgets DataVisualization REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_BINARY_DIR ON)

add_executable(main main.cpp)
target_link_libraries(main Qt5::Widgets Qt5::DataVisualization)
