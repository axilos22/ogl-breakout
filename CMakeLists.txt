cmake_minimum_required(VERSION 3.23.0)
project(Breakout VERSION 0.1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules")

find_package(OpenGL REQUIRED)
set(OPENGL_INCLUDE_DIRS $ENV{OPENGL_DIR}/include)
find_package(glfw3 REQUIRED HINTS $ENV{GLFW_DIR})
find_package(glad REQUIRED)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(source)
