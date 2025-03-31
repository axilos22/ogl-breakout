add_executable(fileop file_operations.cpp)

target_include_directories(fileop
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/..
)

add_test(NAME Runs COMMAND fileop 1 abc 222 foo bar)
add_test(NAME EMPTY_RUN COMMAND fileop 0)
add_test(NAME FILE_CHECK COMMAND fileop 1 WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

if(TEST_OPENGL)
    find_package(OpenGL REQUIRED)
    find_package(glfw3 REQUIRED HINTS $ENV{GLFW_DIR})
    find_package(glad REQUIRED)

    add_executable(opengl_tester opengl_tester.cpp)
    target_link_libraries(opengl_tester PRIVATE OpenGL::GL glfw glad)

    target_include_directories(opengl_tester
        PRIVATE
            ${OPENGL_INCLUDE_DIRS}
            ${CMAKE_CURRENT_LIST_DIR}/..
    )

    add_test(NAME OPENGL_INIT COMMAND opengl_tester 0)
    add_test(NAME GLAD_INIT COMMAND opengl_tester 1 640 480)
    add_test(NAME OPENGL_WINDOW COMMAND opengl_tester 2 640 480)
endif()
