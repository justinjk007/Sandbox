TARGET_SOURCES(subdirtest
  PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/subdirtest.cpp"
  PUBLIC
  "${CMAKE_CURRENT_LIST_DIR}/subdirtest.hpp"
  )

TARGET_INCLUDE_DIRECTORIES(subdirtest PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

MESSAGE("-- All subdir files SUCCESSFULLY linked")
# https://crascit.com/2016/01/31/enhanced-source-file-handling-with-target_sources/
