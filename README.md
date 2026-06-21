# Algorithms and Data Structures in C++

This repository is a C++ monorepo for algorithm practice, data structure
exploration, and problem-solving notes.

## Repository Layout

```text
.
  leetcode/
    0001-two-sum/
    2196-create-binary-tree-from-descriptions/
    3614-process-string-with-special-operations-ii/
    _template/
  data-structures/
  geeksforgeeks/
  scripts/
  CMakeLists.txt
```

## Tracks

- [LeetCode](leetcode/README.md): LeetCode problem notes, C++ solutions, and
  tests.
- [Data Structures](data-structures/README.md): C++ implementations and
  experiments with core data structures.
- [GeeksforGeeks](geeksforgeeks/README.md): practice problems from
  GeeksforGeeks.

## Problem Folder Standard

Problem-based tracks should use this shape:

```text
problem-slug/
  README.md
  PROBLEM.md
  SOLUTIONS.md
  _md_images/
  solutions/
  tests/
```

- `README.md`: quick index for the problem folder, links to notes, source
  files, and test commands.
- `PROBLEM.md`: paraphrased problem statement, source links, examples,
  constraints, edge cases, and markdown image references when helpful.
- `SOLUTIONS.md`: solution explanations, complexity analysis, worked examples,
  and supplemental notes.
- `_md_images/`: diagrams or screenshots used by markdown notes.
- `solutions/`: C++ implementations.
- `tests/`: standalone C++ tests.

Avoid copying full prompt text from coding platforms into the repo. Link to the
original source and write your own summary.

## Build and Test

This repo uses CMake and plain C++ assertions to avoid external dependencies.

### Windows Prerequisites

Install CMake and a C++ compiler before running the build commands.

```powershell
winget install --id Kitware.CMake -e
winget install --id Microsoft.VisualStudio.2022.BuildTools -e --override "--quiet --wait --add Microsoft.VisualStudio.Workload.VCTools --includeRecommended"
```

After installation, close and reopen PowerShell so the new PATH entries are
loaded. If you install Visual Studio Build Tools, the most reliable terminal is
`Developer PowerShell for VS 2022`.

### Run Tests

From the repo root, run the full regression suite:

```powershell
.\scripts\test.ps1
```

Run all tests for one problem folder:

```powershell
.\scripts\test.ps1 -Problem 0001-two-sum
```

The helper script configures CMake, builds the project, and runs CTest with the
right Visual Studio configuration.

You can also run the raw CMake commands:

```powershell
cmake --preset vs2022
cmake --build --preset debug
ctest --preset debug
```

Or:

```powershell
cmake -S . -B build
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
```

When using the Visual Studio generator, `ctest --test-dir build` needs either
`-C Debug` or a test preset. Without a configuration, CTest cannot choose between
`Debug`, `Release`, `RelWithDebInfo`, and `MinSizeRel`.

## CI Pipeline

The GitHub Actions workflow in `.github/workflows/cpp-tests.yml` builds the
project and runs the full test suite on every push and pull request.

## Adding New Work

For LeetCode, copy `leetcode/_template/problem-slug` into `leetcode/` and
register tests in `leetcode/CMakeLists.txt`.

For data structures, add implementation and test folders under
`data-structures/`, then register targets in `data-structures/CMakeLists.txt`.

For GeeksforGeeks, add problem folders under `geeksforgeeks/`, then register
targets in `geeksforgeeks/CMakeLists.txt`.
