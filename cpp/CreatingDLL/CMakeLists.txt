cmake_minimum_required (VERSION 3.2)
project (CreatingDLL)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

include (GenerateExportHeader)

add_library(MyLibrary ${LIB_TYPE} ${srcs})
GENERATE_EXPORT_HEADER( MyLibrary
  BASE_NAME MyLibrary
  EXPORT_MACRO_NAME MyLibrary_EXPORT
  EXPORT_FILE_NAME MyLibrary_Export.h
  STATIC_DEFINE MyLibrary_BUILT_AS_STATIC
  )

ADD_EXECUTABLE(main main.cpp)
