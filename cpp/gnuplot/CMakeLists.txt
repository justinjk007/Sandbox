cmake_minimum_required (VERSION 3.2)
project (gnuPlotTest)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# Boost config
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_USE_MULTITHREADED ON)
FIND_PACKAGE( Boost 1.58 COMPONENTS iostreams system filesystem program_options regex REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES(main ${Boost_LIBRARIES})
