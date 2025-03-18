
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake" CACHE STRING "")
set(CMAKE_EXECUTABLE_SUFFIX ".html")
set(EXE_NAME emscripten_test_app)
set(EXE_PATH ${CMAKE_SOURCE_DIR}/app/emscripten_test)
add_executable(${EXE_NAME} ${EXE_PATH}/main.cpp)

set_target_properties(${EXE_NAME} PROPERTIES
    OUTPUT_NAME "index"
    LINK_FLAGS "-o index.html"
)