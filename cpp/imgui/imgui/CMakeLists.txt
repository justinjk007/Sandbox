set(SOURCE
  ${SOURCE}
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_draw.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_demo.cpp
  PARENT_SCOPE
  )
set(HEADERS
  ${HEADERS}
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui.h
  ${CMAKE_CURRENT_SOURCE_DIR}/imconfig.h
  ${CMAKE_CURRENT_SOURCE_DIR}/imgui_internal.h
  ${CMAKE_CURRENT_SOURCE_DIR}/stb_rect_pack.h
  ${CMAKE_CURRENT_SOURCE_DIR}/stb_textedit.h
  ${CMAKE_CURRENT_SOURCE_DIR}/stb_truetype.h
  PARENT_SCOPE
  )
message("-- All files successfully linked")
