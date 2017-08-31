cmake_minimum_required (VERSION 3.5)
project (imguitest)

# The version number.
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 5)

add_subdirectory("${PROJECT_SOURCE_DIR}/imgui")

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES (main ${SOURCE} ${HEADERS})
