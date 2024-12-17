cmake_minimum_required(VERSION 3.29)
project(laba_sort)

set(CMAKE_CXX_STANDARD 20)

add_executable(laba_sort main.c
        sort.h
        sort.c
        logic.h
        logic.c)
