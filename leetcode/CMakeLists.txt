add_executable(leetcode_0001_two_sum_tests
    0001-two-sum/tests/two_sum_tests.cpp
)

target_include_directories(leetcode_0001_two_sum_tests PRIVATE
    0001-two-sum/solutions
)

add_problem_test(0001-two-sum leetcode_0001_two_sum_tests)
