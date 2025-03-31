add_library(argument_parser arg_parser.cpp)
target_include_directories(argument_parser PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_library(file_operation file_operations.cpp)
target_include_directories(file_operation PUBLIC ${CMAKE_CURRENT_LIST_DIR})
