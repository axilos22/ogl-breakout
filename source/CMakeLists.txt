find_package(OpenGL REQUIRED)
set(OPENGL_INCLUDE_DIRS $ENV{OPENGL_DIR}/include)
find_package(glfw3 REQUIRED HINTS $ENV{GLFW_DIR})
find_package(glad REQUIRED)

add_executable(breakout main.cpp)

target_link_libraries(breakout PRIVATE OpenGL::GL glfw glad)

target_include_directories(breakout PRIVATE ${OPENGL_INCLUDE_DIRS})

add_subdirectory(test)
