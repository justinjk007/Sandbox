TARGET_SOURCES(imgui
  PRIVATE
  "${CMAKE_CURRENT_LIST_DIR}/imgui.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/imgui_draw.cpp"
  "${CMAKE_CURRENT_LIST_DIR}/imgui_demo.cpp"
  PUBLIC
  "${CMAKE_CURRENT_LIST_DIR}/imgui.h"
  "${CMAKE_CURRENT_LIST_DIR}/imconfig.h"
  "${CMAKE_CURRENT_LIST_DIR}/imgui_internal.h"
  "${CMAKE_CURRENT_LIST_DIR}/stb_rect_pack.h"
  "${CMAKE_CURRENT_LIST_DIR}/stb_textedit.h"
  "${CMAKE_CURRENT_LIST_DIR}/stb_truetype.h"
  )


TARGET_INCLUDE_DIRECTORIES(imgui PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

MESSAGE("-- All files successfully linked")
