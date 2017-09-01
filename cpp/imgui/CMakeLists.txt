cmake_minimum_required (VERSION 3.5)
project (imguitest)

# The version number.
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 5)

add_subdirectory("${PROJECT_SOURCE_DIR}/imgui")

ADD_EXECUTABLE(main main.cpp)
TARGET_LINK_LIBRARIES (main ${SOURCE} ${HEADERS} glew32 glew32s glfw3 SDL2 SDL2main SDL2test OpenGL32)

TARGET_INCLUDE_DIRECTORIES (main SYSTEM PUBLIC ${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES (${PROJECT_SOURCE_DIR}/libs)
