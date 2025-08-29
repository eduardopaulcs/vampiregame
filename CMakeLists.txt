# Create project
cmake_minimum_required(VERSION 3.24)
project(vampiregame LANGUAGES CXX)

# C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies
find_package(SDL3 CONFIG REQUIRED)

# Source files
file(GLOB_RECURSE HEADERS 
    "src/*.h"
)

file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
)

# Build
add_executable(game ${SOURCES} ${HEADERS})

target_include_directories(game PRIVATE src)

target_link_libraries(game PRIVATE SDL3::SDL3)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})
