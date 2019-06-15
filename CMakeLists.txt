cmake_minimum_required(VERSION 3.11)
set(NAME bomberman)
project(${NAME})
add_compile_options(-g -DBOOST_NO_CXX11_SCOPED_ENUMS)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(Boost_USE_STATIC_LIBS ON) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost COMPONENTS filesystem)

find_package(Irrlicht REQUIRED)

include_directories(
		include
		cmake/include
		IRRLICHT_INCLUDE_DIRS/..
		src
		src/Entities
		src/Services
		src/Behaviour
		src/Map
		src/BoardObject
		src/Scenes
		src/Utilities
		src/Animations
		.
)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

add_executable(${NAME} ${SOURCE_FILES})

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    target_link_libraries(${NAME} ${Boost_LIBRARIES})
endif()

target_link_libraries(${NAME} ${Irrlicht_LIBRARIES} sfml-audio)
