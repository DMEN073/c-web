
set(EXE_NAME imgui_test_app)
set(EXE_PATH ${CMAKE_SOURCE_DIR}/app/imgui_test)
set(IMGUI_PATH ${CMAKE_SOURCE_DIR}/3rdParty/imgui)
set(CMAKE_EXECUTABLE_SUFFIX ".html")

add_library(imgui STATIC
${IMGUI_PATH}/imgui.cpp
${IMGUI_PATH}/imgui_draw.cpp
${IMGUI_PATH}/imgui_widgets.cpp
${IMGUI_PATH}/imgui_tables.cpp
)
add_executable(${EXE_NAME} ${EXE_PATH}/main.cpp)

target_include_directories(${EXE_NAME} PUBLIC ${IMGUI_PATH})
target_link_libraries(${EXE_NAME} PUBLIC imgui)
set_target_properties(${EXE_NAME} PROPERTIES
    OUTPUT_NAME "${EXE_NAME}"
    LINK_FLAGS "-o ${EXE_NAME}.html"
)
