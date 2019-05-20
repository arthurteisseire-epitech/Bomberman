cmake_minimum_required(VERSION 3.11)
set(NAME bomberman)
project(${NAME})
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_MODULE_PATH cmake)

find_package(Irrlicht REQUIRED)

include_directories(
		include
		IRRLICHT_INCLUDE_DIR
)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_executable(${NAME} ${SOURCE_FILES})

target_link_libraries(${NAME} ${Irrlicht_LIBRARIES})


file(GLOB_RECURSE TESTS tests/*.cpp)

add_executable(units ${TESTS})

target_link_libraries(units ${Irrlicht_LIBRARIES} gtest gtest_main)
