cmake_minimum_required(VERSION 3.15)
project(heaps)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Google_tests)

add_executable(heaps
        main.cpp
        ../binomial_heap/extract_min.cpp
        ../binomial_heap/log.cpp
        ../binomial_heap/copy_constructor.cpp
        ../binomial_heap/assignment_operator.cpp
        ../binomial_heap/get_min.cpp
        ../binomial_heap/meld_tree.cpp
        ../binomial_heap/insert.cpp
        ../binomial_heap/meld.cpp
        ../binomial_heap/heap_constructor_from_tree.cpp
        ../binomial_heap/binomial_tree/copy_constructor.cpp
        ../binomial_heap/binomial_tree/assignment_operator.cpp
        ../binomial_heap/binomial_tree/destructor.cpp
        ../binomial_heap/binomial_tree/unite.cpp
        ../binomial_heap/binomial_tree/log.cpp
        )