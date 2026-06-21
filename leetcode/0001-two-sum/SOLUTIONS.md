# 0001. Two Sum: Solutions

## Summary

| Approach | Time | Space | File |
| --- | --- | --- | --- |
| One-pass hash map | `O(n)` | `O(n)` | `solutions/two_sum_one_pass_hash_map.cpp` |
| Two-pass hash map | `O(n)` | `O(n)` | `solutions/two_sum_two_pass_hash_map.cpp` |
| Brute force | `O(n^2)` | `O(1)` | Supplemental only |

## Solution 1: One-Pass Hash Map

Use a hash map from value to index while scanning the array once.

For each number:

1. Compute the complement: `target - nums[i]`.
2. Check whether the complement has already been seen.
3. If yes, return the stored complement index and the current index.
4. If no, store the current value and index.

This works because when we reach index `i`, every earlier index is already in the
map. If the current number completes a valid pair with any previous number, the
map can find that previous number in expected `O(1)` time.

### Complexity

- Time: `O(n)` because each number is visited once.
- Space: `O(n)` because the map may store almost every number before the answer
  is found.

### Worked Example

```text
nums = [4, 1, 9, 7]
target = 8
```

| i | nums[i] | complement | map before check | result |
| --- | --- | --- | --- | --- |
| 0 | 4 | 4 | `{}` | complement not found, store `4 -> 0` |
| 1 | 1 | 7 | `{4: 0}` | complement not found, store `1 -> 1` |
| 2 | 9 | -1 | `{4: 0, 1: 1}` | complement not found, store `9 -> 2` |
| 3 | 7 | 1 | `{4: 0, 1: 1, 9: 2}` | found `1 -> 1`, return `[1, 3]` |

The answer is `[1, 3]` because `nums[1] + nums[3] = 1 + 7 = 8`.

### Why This Is Usually Preferred

The one-pass solution is optimal and returns as soon as the pair is discovered.
It also naturally avoids reusing the current index because the current value is
stored only after checking for its complement.

## Solution 2: Two-Pass Hash Map

Build a hash map from every value to one of its indices, then scan the array a
second time looking for complements.

For each number during the second pass:

1. Compute the complement: `target - nums[i]`.
2. Look up the complement in the map.
3. Return the pair if the complement exists and its stored index is not `i`.

### Complexity

- Time: `O(n)` because each pass visits the array once.
- Space: `O(n)` because the map stores values from the array.

### Worked Example

```text
nums = [10, -2, 5, 12]
target = 3
```

First pass builds the map:

```text
{
  10: 0,
  -2: 1,
  5: 2,
  12: 3
}
```

Second pass:

| i | nums[i] | complement | lookup result | result |
| --- | --- | --- | --- | --- |
| 0 | 10 | -7 | not found | continue |
| 1 | -2 | 5 | found index `2` | return `[1, 2]` |

The check `found_index != i` is required so the solution never uses the same
array element twice.

### Duplicate Values

For `nums = [6, 6]` and `target = 12`, the map stores `6 -> 1` after the first
pass. During the second pass, index `0` looks for complement `6`, finds index
`1`, and returns `[0, 1]`. That is valid because the indices are different.

## Supplemental Note: Brute Force

The simplest approach tries every pair:

```text
for i from 0 to n - 1
    for j from i + 1 to n - 1
        if nums[i] + nums[j] == target
            return [i, j]
```

- Time: `O(n^2)` because every pair may be checked.
- Space: `O(1)` because no extra data structure is needed.

This is a useful first correctness model, but it is not the preferred solution
once hash maps are allowed.
