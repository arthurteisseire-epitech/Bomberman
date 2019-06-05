cmake_minimum_required(VERSION 3.11)
set(NAME bomberman)
project(${NAME})
add_compile_options(-Wall -g -DBOOST_NO_CXX11_SCOPED_ENUMS)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Irrlicht REQUIRED)

include_directories(
		include
		cmake/include
		IRRLICHT_INCLUDE_DIR
		src
		src/Entities
		src/Services
		src/Behaviour
		src/Map
		src/BoardObject
		src/Scenes
		src/Utilities
		src/Animations
)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

add_executable(${NAME} ${SOURCE_FILES})

target_link_libraries(${NAME} ${Irrlicht_LIBRARIES} -lpthread -lboost_system -lboost_filesystem)