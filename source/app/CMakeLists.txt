find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED HINTS $ENV{GLFW_DIR})

add_executable(breakout main.cpp)

target_link_libraries(breakout PRIVATE OpenGL::GL glfw glad)

set(OPENGL_INCLUDE_DIRS $ENV{OPENGL_DIR}/include)
target_include_directories(breakout PRIVATE ${OPENGL_INCLUDE_DIRS})
