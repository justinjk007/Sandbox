cmake_minimum_required(VERSION 3.5)
project(QTVisualize)

set(CMAKE_CXX_STANDARD 11)

# Qt Setup
find_package(Qt5 COMPONENTS Core Widgets Charts Gui REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_BINARY_DIR ON)
INCLUDE_DIRECTORIES(${QT_INCLUDE_DIRS})

ADD_LIBRARY(mainwindow mainwindow.cpp)
ADD_LIBRARY(pentagonGen pentagonGen.cpp)
ADD_LIBRARY(tilingGen tilingGen.cpp)

ADD_EXECUTABLE(main main.cpp)
QT5_USE_MODULES(main Widgets Charts Core Gui)
TARGET_LINK_LIBRARIES(main mainwindow pentagonGen tilingGen)
