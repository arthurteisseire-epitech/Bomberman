cmake_minimum_required(VERSION 3.11)
set(NAME bomberman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

project(${NAME})

set(CMAKE_CXX_STANDARD 11)

#source files
set(
        SOURCE_FILES
        src/main.cpp
)

#include files
include_directories(include src)

add_executable(${NAME} ${SOURCE_FILES})

#Library definition
target_link_libraries(${NAME} m)
target_link_libraries(${NAME} GL)
target_link_libraries(${NAME} Irrlicht)
target_link_libraries(${NAME} Xxf86vm)
target_link_libraries(${NAME} Xext)
target_link_libraries(${NAME} X11)
target_link_libraries(${NAME} Xcursor)