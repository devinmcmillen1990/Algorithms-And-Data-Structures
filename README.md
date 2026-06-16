# Algorithms and Data Structures in C++

This repository is organized as a study notebook for LeetCode/NeetCode-style
problems in C++.

Each problem lives in its own top-level folder named with the problem number and
slug, for example:

```text
0001-two-sum/
  README.md
  images/
  solutions/
  tests/
```

## Problem Folder Standard

- `README.md`: problem summary, source links, examples, constraints, approach
  notes, complexity analysis, and image references when helpful.
- `images/`: diagrams, hand-drawn notes, screenshots, or other visual aids.
- `solutions/`: all optimal C++ solutions worth studying for the problem.
- `tests/`: standalone C++ tests for the solutions.
- Naive or brute-force ideas belong in a short supplemental note in the problem
  README unless they are worth compiling for comparison.

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

### CI Pipeline

The GitHub Actions workflow in `.github/workflows/cpp-tests.yml` builds the
project and runs the full test suite on every push and pull request.

## Current Problems

| Problem | Pattern | Solutions |
| --- | --- | --- |
| [0001 Two Sum](0001-two-sum/README.md) | Hash map | One-pass hash map, two-pass hash map |

## Adding a New Problem

1. Copy `_template/problem-slug` to a new top-level folder such as
   `0121-best-time-to-buy-and-sell-stock`.
2. Fill in the README with a concise problem summary and links to the original
   source.
3. Add every optimal solution variant that teaches a distinct idea.
4. Add focused tests for normal cases, edge cases, and constraints.
5. Register the test executable in the root `CMakeLists.txt` with
   `add_problem_test(problem-slug target-name)`.
