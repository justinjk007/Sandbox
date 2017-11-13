cmake_minimum_required(VERSION 3.5)
project(QTTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Widgets)
list(APPEND THIRD_PARTY_LIBS Qt5::Widgets Qt5::Core)


set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h images)
add_executable(main ${SOURCE_FILES})

target_link_libraries(main Qt5::Core Qt5::Widgets Qt5::Gui)
