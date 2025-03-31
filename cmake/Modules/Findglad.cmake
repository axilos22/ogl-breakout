# Distributed under the GNU GENERAL PUBLIC LICENSE v3 License
# author: axilos22

if(DEFINED ENV{GLAD_DIR})
    set(glad_FOUND TRUE)
    cmake_path(CONVERT $ENV{GLAD_DIR} TO_CMAKE_PATH_LIST GLAD_DIR NORMALIZE)
    set(glad_ROOT_DIR ${GLAD_DIR})
    set(glad_INCLUDE_DIRS ${GLAD_DIR}/include)

    # Create dedicated lib
    add_library(glad SHARED ${GLAD_DIR}/src/glad.c)
    target_include_directories(glad PUBLIC ${glad_INCLUDE_DIRS})
else()
    set(glad_FOUND FALSE)
    message(SEND_ERROR "Unable to find glad. Check env variable GLAD_DIR")
endif()
