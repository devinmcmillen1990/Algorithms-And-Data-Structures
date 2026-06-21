# Problem Title

Source:
- LeetCode: https://leetcode.com/problems/problem-slug/
- NeetCode:

## Notes

- [Problem statement and examples](PROBLEM.md)
- [Solution explanations and complexity analysis](SOLUTIONS.md)

## C++ Files

- [Solution template](solutions/solution_template.cpp)
- [Tests](tests/solution_tests.cpp)

## Test Cases

- Normal case:
- Edge case:
- Constraint case:

## Running Tests

From the repo root, run only this problem's tests:

```powershell
.\scripts\test.ps1 -Problem problem-slug
```

Run the full regression suite:

```powershell
.\scripts\test.ps1
```

Register this problem's test executable in `leetcode/CMakeLists.txt` with
`add_problem_test(problem-slug target-name)`.
