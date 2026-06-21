#include <stdexcept>
#include <unordered_map>
#include <vector>

class TwoSumOnePassHashMap {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> valueToIndex;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const int complement = target - nums[i];
            const auto found = valueToIndex.find(complement);

            if (found != valueToIndex.end()) {
                return {found->second, i};
            }

            valueToIndex[nums[i]] = i;
        }

        throw std::invalid_argument("No two sum solution exists.");
    }
};
