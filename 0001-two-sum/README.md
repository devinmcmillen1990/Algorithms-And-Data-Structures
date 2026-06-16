# 0001. Two Sum

Source:
- LeetCode: https://leetcode.com/problems/two-sum/
- NeetCode: https://neetcode.io/problems/two-integer-sum

## Problem Summary

Given an array of integers and a target value, return the indices of two
different elements whose values add up to the target. The usual version assumes
there is exactly one valid answer and that the same element cannot be used twice.

## Visuals

Add diagrams or notes to `images/` as you study. A useful diagram for this
problem is a table that tracks each number's needed complement as the array is
scanned.

## Examples

```text
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9
```

```text
Input: nums = [3, 2, 4], target = 6
Output: [1, 2]
Explanation: nums[1] + nums[2] = 2 + 4 = 6
```

## Constraints

- At least two numbers are present.
- Return two distinct indices.
- The standard LeetCode version guarantees one valid answer.

## Optimal Solutions

### Solution 1: One-Pass Hash Map

- Idea: scan once while storing values already seen. For each value, check
  whether its complement is already in the map.
- Time: `O(n)`
- Space: `O(n)`
- File: `solutions/two_sum_one_pass_hash_map.cpp`

This is the main solution to memorize because it is both asymptotically optimal
and simple.

### Solution 2: Two-Pass Hash Map

- Idea: build a value-to-index map first, then scan again looking for each
  value's complement.
- Time: `O(n)`
- Space: `O(n)`
- File: `solutions/two_sum_two_pass_hash_map.cpp`

This is also optimal, but the one-pass version is usually cleaner because it
detects the answer as soon as it becomes available.

## Supplemental Notes

### Naive Approach

Try every pair with two nested loops and return the pair whose sum equals the
target.

- Time: `O(n^2)`
- Space: `O(1)`

This is useful as a first correctness model, but it is not the preferred
implementation because the hash map versions reduce the scan to linear time.

## Test Cases

- Basic pair at the front.
- Pair after skipping earlier values.
- Duplicate values such as `[3, 3]` with target `6`.
- Negative numbers.
- Pair at the end of the array.

## Running Tests

From the repo root, run only this problem's tests:

```powershell
.\scripts\test.ps1 -Problem 0001-two-sum
```

Run the full regression suite:

```powershell
.\scripts\test.ps1
```
