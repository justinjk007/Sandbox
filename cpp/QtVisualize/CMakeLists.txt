cmake_minimum_required(VERSION 3.5)
project(QTVisualize)

set(CMAKE_CXX_STANDARD 11)

# Qt Setup
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Charts REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

ADD_LIBRARY(mainwindow mainwindow.cpp)

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main mainwindow Qt5::Widgets Qt5::Charts Qt5::Core Qt5::Gui)
