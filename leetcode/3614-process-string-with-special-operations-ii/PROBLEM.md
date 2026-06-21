# 3614. Process String with Special Operations II: Problem

Source:
- LeetCode: https://leetcode.com/problems/process-string-with-special-operations-ii/

This file uses a paraphrased problem statement instead of copying the full
prompt text from LeetCode.

## Problem Statement

Given a string `s` containing lowercase English letters plus the special
characters `*`, `#`, and `%`, process the string from left to right to form a
result string.

The operations are:

- Lowercase letter: append it to the result.
- `*`: remove the last character from the result if one exists.
- `#`: duplicate the current result and append that duplicate to the end.
- `%`: reverse the current result.

Given an index `k`, return the character at index `k` in the final result. If
`k` is outside the final string, return `'.'`.

## Examples

### Example 1

```text
Input: s = "a#b%*", k = 1
Output: "a"
```

Processing:

```text
"a" -> "aa" -> "aab" -> "baa" -> "ba"
```

The character at index `1` is `'a'`.

### Example 2

```text
Input: s = "cd%#*#", k = 3
Output: "d"
```

Processing:

```text
"c" -> "cd" -> "dc" -> "dcdc" -> "dcd" -> "dcddcd"
```

The character at index `3` is `'d'`.

### Example 3

```text
Input: s = "z*#", k = 0
Output: "."
```

Processing removes the only character, so the final result is empty.

## Constraints And Assumptions

- `s` can contain lowercase letters and the special characters `*`, `#`, and
  `%`.
- `k` is zero-based.
- The final string can grow very large because `#` duplicates the current
  result.
- An implementation may need to reason about lengths and indexes instead of
  constructing the full result.

## Edge Cases

- `*` appears when the current result is empty.
- `#` appears when the current result is empty.
- `%` appears when the current result is empty or has length `1`.
- `k` is equal to or greater than the final result length.
- Repeated `#` operations create very large logical strings.

## Visuals

The official LeetCode problem statement for this problem does not include
example diagrams. Add your own study diagrams to `_md_images/` if helpful.

A useful diagram for this problem is a table that tracks:

```text
index | operation | logical length before | logical length after | k mapping
```
