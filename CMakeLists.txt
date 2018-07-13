cmake_minimum_required(VERSION 3.9)
project(pepe2024 C)

set(CMAKE_C_STANDARD 99)

add_executable(pepe2024 main.c coder.c decoder.c bits.c define.h auth.c save.c pathfinder.c pathfinder.h)