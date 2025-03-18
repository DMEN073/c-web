cmake_minimum_required(VERSION 3.10)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/../emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake" CACHE STRING "")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(HelloWebAssembly)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib) # static lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib) # dynamic lib
# add_subdirectory(${CMAKE_SOURCE_DIR}/app/emscripten_test)
# add_subdirectory(${CMAKE_SOURCE_DIR}/app/imgui_test)
add_subdirectory(${CMAKE_SOURCE_DIR}/app/simple_web_test)

