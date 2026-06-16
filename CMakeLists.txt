cmake_minimum_required(VERSION 3.20)

project(AlgorithmsAndDataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

function(add_problem_test problem_slug test_target)
    add_test(NAME ${problem_slug} COMMAND ${test_target})
    set_tests_properties(${problem_slug} PROPERTIES LABELS ${problem_slug})
endfunction()

add_executable(two_sum_tests
    0001-two-sum/tests/two_sum_tests.cpp
)

target_include_directories(two_sum_tests PRIVATE
    0001-two-sum/solutions
)

add_problem_test(0001-two-sum two_sum_tests)
