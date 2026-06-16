#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "../solutions/two_sum_one_pass_hash_map.cpp"
#include "../solutions/two_sum_two_pass_hash_map.cpp"

namespace {
void assertValidAnswer(
    const std::vector<int>& nums,
    int target,
    std::vector<int> actual
) {
    assert(actual.size() == 2);
    assert(actual[0] != actual[1]);
    assert(actual[0] >= 0 && actual[0] < static_cast<int>(nums.size()));
    assert(actual[1] >= 0 && actual[1] < static_cast<int>(nums.size()));
    assert(nums[actual[0]] + nums[actual[1]] == target);
}

template <typename Solver>
void runSharedCases(Solver& solver) {
    assertValidAnswer({2, 7, 11, 15}, 9, solver.twoSum({2, 7, 11, 15}, 9));
    assertValidAnswer({3, 2, 4}, 6, solver.twoSum({3, 2, 4}, 6));
    assertValidAnswer({3, 3}, 6, solver.twoSum({3, 3}, 6));
    assertValidAnswer({-3, 4, 3, 90}, 0, solver.twoSum({-3, 4, 3, 90}, 0));
    assertValidAnswer({1, 5, 8, 10, 13}, 23, solver.twoSum({1, 5, 8, 10, 13}, 23));
}
}

int main() {
    TwoSumOnePassHashMap onePass;
    TwoSumTwoPassHashMap twoPass;

    runSharedCases(onePass);
    runSharedCases(twoPass);

    std::cout << "0001-two-sum tests passed.\n";
    return 0;
}
