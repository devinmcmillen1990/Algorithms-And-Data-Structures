#include <stdexcept>
#include <unordered_map>
#include <vector>

class TwoSumTwoPassHashMap {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> valueToIndex;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            valueToIndex[nums[i]] = i;
        }

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const int complement = target - nums[i];
            const auto found = valueToIndex.find(complement);

            if (found != valueToIndex.end() && found->second != i) {
                return {i, found->second};
            }
        }

        throw std::invalid_argument("No two sum solution exists.");
    }
};
