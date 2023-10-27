cmake_minimum_required(VERSION 3.26)
project(GenericArrayList C)

set(CMAKE_C_STANDARD 11)

add_executable(GenericArrayList main.c
        GenArrayList.h
        Boolean.h
        GenArrayList.c
)
