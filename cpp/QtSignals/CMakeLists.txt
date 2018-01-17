cmake_minimum_required(VERSION 3.5)
project(QTSignals)

set(CMAKE_CXX_STANDARD 11)

# Qt Setup
find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_BINARY_DIR ON)

ADD_EXECUTABLE(main main.cpp mainwindow.cpp backend.cpp mainwindow.ui)
TARGET_LINK_LIBRARIES(main Qt5::Widgets)
