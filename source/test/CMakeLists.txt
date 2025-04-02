set(TEST_RESOURCE_PATH ${CMAKE_SOURCE_DIR}/resources/test)

add_executable(fileop_tester file_operations_tester.cpp)

target_link_libraries(fileop_tester PRIVATE file_operation argument_parser)

add_test(NAME Runs COMMAND fileop_tester 1 abc 222 foo bar)
add_test(NAME EMPTY_RUN COMMAND fileop_tester 0)
add_test(NAME FILE_CHECK COMMAND fileop_tester 1 WORKING_DIRECTORY ${TEST_RESOURCE_PATH})

add_executable(argument_parser_tester argument_parser_tester.cpp)
target_link_libraries(argument_parser_tester PRIVATE argument_parser)

add_test(NAME Constructor COMMAND argument_parser_tester 0)
add_test(NAME NO_ARG COMMAND argument_parser_tester 1)
add_test(NAME ONE_ARG COMMAND argument_parser_tester 2)
add_test(NAME TWO_ARGS COMMAND argument_parser_tester 3)
add_test(NAME MANY_ARGS COMMAND argument_parser_tester 4)
add_test(NAME TOO_MANY_ARGS COMMAND argument_parser_tester 5)

if(NOT ${CI})
    find_package(OpenGL REQUIRED)
    find_package(glfw3 REQUIRED HINTS $ENV{GLFW_DIR})

    add_executable(opengl_tester opengl_tester.cpp)
    target_link_libraries(opengl_tester PRIVATE OpenGL::GL glfw glad)

    add_test(NAME OPENGL_INIT COMMAND opengl_tester 0)
    add_test(NAME GLAD_INIT COMMAND opengl_tester 1)
    add_test(NAME CREATE_WINDOW COMMAND opengl_tester 2)
    set_tests_properties(GLAD_INIT CREATE_WINDOW PROPERTIES DISABLED TRUE)
endif()
