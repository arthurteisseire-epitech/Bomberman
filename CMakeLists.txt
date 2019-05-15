cmake_minimum_required(VERSION 3.11)
set(NAME bomberman)
project(${NAME})
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_MODULE_PATH cmake)

find_package(Irrlicht REQUIRED)

#source files
file(
		GLOB_RECURSE
		SOURCE_FILES
		src/*.cpp
)

#include files
include_directories(
		include
		IRRLICHT_INCLUDE_DIR
)

add_executable(${NAME} ${SOURCE_FILES})

target_link_libraries(${NAME} ${IRRLICHT_LIBRARIES})
