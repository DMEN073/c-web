set(CMAKE_EXECUTABLE_SUFFIX ".html")
set(EXE_NAME simple_web_test_app)
set(EXE_PATH ${CMAKE_SOURCE_DIR}/app/simple_web_test)
set(IMGUI_PATH ${CMAKE_SOURCE_DIR}/3rdParty/imgui)
include_directories(${CMAKE_SOURCE_DIR}/../emsdk/upstream/emscripten/cache/sysroot/include/SDL)


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
target_include_directories(${EXE_NAME} PUBLIC ${IMGUI_PATH})
target_link_libraries(${EXE_NAME} PUBLIC imgui)
# target_link_options(${EXE_NAME} PUBLIC 
#     "-sUSE_SDL=2"
#     "-sUSE_WEBGL2=1"
#     "-sFULL_ES3=1"
# )

set_target_properties(${EXE_NAME} PROPERTIES
    OUTPUT_NAME "${EXE_NAME}"
    LINK_FLAGS "-o ${EXE_NAME}.html"
)