# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MazePather)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 23) # Specify the C standard (C23 as you mentioned earlier)

set(CMAKE_C_EXTENSIONS OFF) # Remove some annoying extensions



# Add the executable (main source file)
add_executable(maze-pather src/main.c)

# Inlcude the headers
target_include_directories(maze-pather PUBLIC ${CMAKE_SOURCE_DIR}/include) 

# Link against the static library
target_link_libraries(maze-pather /usr/lib/libglfw.so raylib glfw m pthread dl rt)

# Make sure glfw3 is actually loaded.
find_package(glfw3 REQUIRED)

# Optionally, add custom compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -O2 -pedantic -Wextra -Wshadow -g -lraylib -lm -lpthread -ldl -lrt")

