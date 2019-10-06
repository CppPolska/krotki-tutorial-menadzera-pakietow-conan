cmake_minimum_required(VERSION 3.10)
project(MyProject)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(execFile main.cpp)
target_link_libraries(execFile ${CONAN_LIBS})
