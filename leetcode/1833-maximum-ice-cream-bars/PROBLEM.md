# 1833. Maximum Ice Cream Bars: Problem

Source:
- LeetCode: https://leetcode.com/problems/maximum-ice-cream-bars/
- Daily question: https://leetcode.com/problems/maximum-ice-cream-bars/description/?envType=daily-question&envId=2026-06-21

This file uses a paraphrased problem statement instead of copying the full
prompt text from LeetCode.

## Problem Statement

Given an array `costs`, where each value is the coin cost of one ice cream bar,
and an integer `coins`, return the maximum number of ice cream bars that can be
bought.

The bars may be bought in any order.

## Examples

### Example 1

```text
Input: costs = [1, 3, 2, 4, 1], coins = 7
Output: 4
Explanation: buying bars with costs 1, 1, 2, and 3 uses all 7 coins.
```

### Example 2

```text
Input: costs = [10, 6, 8, 7, 7, 8], coins = 5
Output: 0
Explanation: every bar costs more than the available coins.
```

### Example 3

```text
Input: costs = [1, 6, 3, 1, 2, 5], coins = 20
Output: 6
Explanation: all bars can be bought because their total cost is 18.
```

## Constraints And Assumptions

- `costs.length == n`
- `1 <= n <= 100000`
- `1 <= costs[i] <= 100000`
- `1 <= coins <= 100000000`
- The bars can be purchased in any order.

## Edge Cases

- `coins` is smaller than every cost.
- `coins` is large enough to buy every bar.
- Many bars have the same cost.
- Choosing a costly bar early can reduce the count, so purchase order matters.
- `n` and `costs[i]` can both be large enough that an efficient approach matters.

## Visuals

The official LeetCode problem statement for this problem does not include
example diagrams. Add your own study diagrams to `_md_images/` if helpful.

A useful study table for this problem is:

```text
sorted cost | coins before purchase | can buy? | coins after purchase | count
```
