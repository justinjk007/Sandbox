cmake_minimum_required (VERSION 3.5)
project (fileIO)

# Move needed assets
if (MSVC)
  file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/FooBar.csv
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
endif(MSVC)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/FooBar.csv
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(main main.cpp)
