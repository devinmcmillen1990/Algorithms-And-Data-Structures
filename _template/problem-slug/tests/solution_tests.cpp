#include <cassert>
#include <iostream>
#include <vector>

#include "../solutions/solution_template.cpp"

int main() {
    Solution solution;

    std::vector<int> input{1, 2, 3};
    std::vector<int> expected{1, 2, 3};

    assert(solution.solve(input) == expected);

    std::cout << "All tests passed.\n";
    return 0;
}
