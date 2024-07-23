cmake_minimum_required (VERSION 3.1)

project (GameObjectLibrary)

file (GLOB SRC "./*.cpp")

include_directories (./src/include HEADER_FILE)

add_library (GOL SHARED ${SRC})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../lib)