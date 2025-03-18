set(EMSCRIPTEN_PATH ${CMAKE_SOURCE_DIR}/../emsdk/upstream/emscripten/cache/sysroot/include/SDL2)
set(EXE_NAME simple_web_test_app)
set(EXE_PATH ${CMAKE_SOURCE_DIR}/app/simple_web_test)
set(IMGUI_PATH ${CMAKE_SOURCE_DIR}/3rdParty/imgui)

add_library(imgui STATIC
${IMGUI_PATH}/imgui.cpp
${IMGUI_PATH}/imgui_draw.cpp
${IMGUI_PATH}/imgui_widgets.cpp
${IMGUI_PATH}/imgui_tables.cpp
)

add_executable(${EXE_NAME} 
${EXE_PATH}/main.cpp 
${IMGUI_PATH}/backends/imgui_impl_sdl2.cpp 
${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(${EXE_NAME} PUBLIC ${IMGUI_PATH} ${EMSCRIPTEN_PATH})
target_link_libraries(${EXE_NAME} PUBLIC imgui)
target_compile_options(${EXE_NAME} PUBLIC 
"-sUSE_SDL=2")
target_link_options(${EXE_NAME} PUBLIC 
"-sUSE_SDL=2")
