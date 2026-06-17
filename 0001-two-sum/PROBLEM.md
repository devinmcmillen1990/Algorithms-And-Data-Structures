# 0001. Two Sum: Problem

Source:
- LeetCode: https://leetcode.com/problems/two-sum/
- NeetCode: https://neetcode.io/problems/two-integer-sum

This file intentionally uses a paraphrased problem statement instead of copying
the full prompt text from the original sites.

## Problem Statement

Given a list of integers and a target sum, find two different positions in the
list whose values add up to the target. Return the two indices.

The standard version of the problem guarantees that exactly one valid pair
exists. An element cannot be paired with itself.

## Examples

### Example 1

```text
Input: nums = [4, 1, 9, 7], target = 8
Output: [1, 3]
Explanation: nums[1] + nums[3] = 1 + 7 = 8.
```

### Example 2

```text
Input: nums = [10, -2, 5, 12], target = 3
Output: [1, 2]
Explanation: nums[1] + nums[2] = -2 + 5 = 3.
```

### Example 3

```text
Input: nums = [6, 6], target = 12
Output: [0, 1]
Explanation: duplicate values are allowed, but the indices must be different.
```

## Constraints And Assumptions

- The input contains at least two numbers.
- Return two distinct indices.
- Exactly one valid answer exists in the standard LeetCode version.
- The returned index order does not matter unless the platform requires one.

## Edge Cases

- The answer uses duplicate values.
- The answer includes a negative number.
- The answer is found at the beginning or end of the array.
- The complement is equal to the current value, so the same index must not be
  reused.

## Visuals

Add diagrams or notes to `images/` as you study. A useful diagram for this
problem is a table with these columns:

```text
index | value | complement needed | values already seen
```
