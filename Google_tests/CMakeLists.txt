# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run
        test1.cpp
        add_operation.cpp
        random_operation_type.cpp
        test_constructor.cpp

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

        ../meta_heap/extract_min.cpp
        ../meta_heap/swap.cpp
        ../meta_heap/copy_constructor.cpp

        ../leftist_heap/rank_refresh.cpp
        ../leftist_heap/constructors.cpp
        ../leftist_heap/meld.cpp

        ../skew_heap/meld.cpp
        )
target_link_libraries(Google_Tests_run gtest gtest_main)