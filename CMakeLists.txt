cmake_minimum_required(VERSION 3.11)
set(NAME bomberman)
project(${NAME})
set(CMAKE_CXX_STANDARD 11)

#source files
set(
        SOURCE_FILES
        src/main.cpp
	src/Indie.cpp
	src/Indie.hpp
)

#include files

include_directories(include include/irrlicht src/)

add_executable(${NAME} ${SOURCE_FILES})

if(WIN32)
	target_link_libraries(${NAME} ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Windows/Irrlicht.lib)
else()
	target_link_libraries(${NAME} GL)
	target_link_libraries(${NAME} m)
	target_link_libraries(${NAME} Xxf86vm)
	target_link_libraries(${NAME} Xext)
	target_link_libraries(${NAME} Xcursor)
	target_link_libraries(${NAME} X11)
	target_link_libraries(${NAME} ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Linux/libIrrlicht.a)
endif()
