# LeetCode

This track contains LeetCode problem notes, C++ solutions, and tests.

## Folder Standard

Each problem lives in a folder named with the LeetCode problem number and slug:

```text
0001-two-sum/
  README.md
  PROBLEM.md
  SOLUTIONS.md
  _md_images/
  solutions/
  tests/
```

- `README.md`: quick index for the problem folder.
- `PROBLEM.md`: paraphrased prompt, source link, examples, constraints, edge
  cases, and markdown image references.
- `SOLUTIONS.md`: solution explanations, complexity analysis, and worked
  examples.
- `_md_images/`: images used by markdown notes.
- `solutions/`: C++ implementations.
- `tests/`: C++ tests.

## Current Problems

| Problem | Pattern | Solutions |
| --- | --- | --- |
| [0001 Two Sum](0001-two-sum/README.md) | Hash map | One-pass hash map, two-pass hash map |
| [2196 Create Binary Tree From Descriptions](2196-create-binary-tree-from-descriptions/README.md) | Hash map, binary tree | In progress |
| [3614 Process String with Special Operations II](3614-process-string-with-special-operations-ii/README.md) | String, simulation | In progress |

## Adding A Problem

1. Copy `_template/problem-slug` to a new folder such as
   `0121-best-time-to-buy-and-sell-stock`.
2. Fill in `README.md` and `PROBLEM.md`.
3. Add `SOLUTIONS.md` when you are ready to document approaches.
4. Add focused C++ tests.
5. Register the test executable in `leetcode/CMakeLists.txt` with
   `add_problem_test(problem-slug target-name)`.
