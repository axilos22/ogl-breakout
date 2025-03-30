cmake_minimum_required(VERSION 3.23.0)
project(Breakout VERSION 0.1.0 LANGUAGES C CXX)

# For Debug purposes
# include(CMakePrintHelpers)
# cmake_print_variables($ENV{OPENGL_DIR})
# cmake_print_variables($ENV{GLFW_DIR})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED HINTS $ENV{GLFW_DIR})

add_executable(Breakout source/main.cpp)
target_link_libraries(Breakout PRIVATE OpenGL::GL glfw)
set(OPENGL_INCLUDE_DIRS $ENV{OPENGL_DIR}/include)
target_include_directories(Breakout PRIVATE ${OPENGL_INCLUDE_DIRS})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
