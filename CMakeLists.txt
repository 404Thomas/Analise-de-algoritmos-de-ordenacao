cmake_minimum_required(VERSION 4.1)
project(TRABALHO_ED2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TRABALHO_ED2
        algoritmos.c
        algoritmos.h
        gerador.c
        gerador.h
        main.c)
