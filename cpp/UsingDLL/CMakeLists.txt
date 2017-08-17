cmake_minimum_required(VERSION 2.8.6)
project (UseAnimalLib)

set (PROJECT_LINK_LIBS animallib.dll)
link_directories (./libs)

include_directories (./include)

#compile all *.cpp source files under src folder
file (GLOB SOURCES "src/*.cpp")

add_executable(uselib ${SOURCES})
target_link_libraries (uselib ${PROJECT_LINK_LIBS})
