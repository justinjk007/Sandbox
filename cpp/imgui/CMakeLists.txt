cmake_minimum_required (VERSION 3.5)
project (imguitext)

# The version number.
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 5)

ADD_LIBRARY(imgui imgui.cpp)
ADD_LIBRARY(imgui_demo imgui_demo.cpp)
ADD_LIBRARY(imgui_draw imgui_draw.cpp)
message("-- All files successfully linked")

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES (main imgui imgui_demo imgui_draw)
