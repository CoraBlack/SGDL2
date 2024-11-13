cmake_minimum_required(VERSION 2.2)

project (SGDL2)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)

file(GLOB src
	"${PROJECT_SOURCE_DIR}/src/*.cpp",
	"${PROJECT_SOURCE_DIR}/src/*.h"
)

include("${PROJECT_SOURCE_DIR}/SDL2/dev")
include("${PROJECT_SOURCE_DIR}/SDL2/image")

add_library(SGDL2 SHARED SRC)

target_link_libraries(SGDL2 ${SDL2_LIBRARIES})
