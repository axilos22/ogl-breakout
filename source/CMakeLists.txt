add_executable(Breakout
    main.cpp
    file_operations.cpp
)

target_link_libraries(Breakout PRIVATE OpenGL::GL glfw glad)

target_include_directories(Breakout
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${OPENGL_INCLUDE_DIRS}
)
