cmake_minimum_required(VERSION 3.27)
project(array_in_terminal)

set(CMAKE_CXX_STANDARD 20)

add_executable(array_in_terminal main.cpp
        src/sorts/sorts_list.h
        src/core.cpp
        src/sorts/bubble_sort.cpp
        src/sorts/heap_sort.cpp
        src/sorts/selection_sort.cpp
        src/sorts/insertion_sort.cpp
        src/sorts/merge_sort.cpp
)
