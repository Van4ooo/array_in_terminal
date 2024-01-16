cmake_minimum_required(VERSION 3.27)
project(sort_visualization)

set(CMAKE_CXX_STANDARD 20)

add_executable(sort_visualization main.cpp
        src/sorts_list.h
        src/core.cpp
        src/bubble_sort.cpp
        src/heap_sort.cpp
        src/selection_sort.cpp
        src/insertion_sort.cpp
        src/merge_sort.cpp
)
