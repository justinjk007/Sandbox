set(SOURCE
  ${SOURCE}
  ${CMAKE_CURRENT_SOURCE_DIR}/subdirtest.cpp
  PARENT_SCOPE
  )
set(HEADERS
  ${HEADERS}
  ${CMAKE_CURRENT_SOURCE_DIR}/subdirtest.hpp
  PARENT_SCOPE
  )
message("-- All subdir files SUCCESSFULLY linked")
