cmake_minimum_required(VERSION 3.29)
project(glulum)

set(CMAKE_CXX_STANDARD 20)
set(SRC_FILES src/main.cpp)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)

add_executable(chip8_emulator ${SRC_FILES})

if(TARGET SDL2::SDL2main)
    target_link_libraries(chip8_emulator PRIVATE SDL2::SDL2main)
endif()

target_link_libraries(chip8_emulator PRIVATE SDL2::SDL2)