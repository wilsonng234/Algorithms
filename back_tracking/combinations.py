from typing import List

# Leetcode 77. Combinations

# Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
# You may return the answer in any order.


def combine(n: int, k: int) -> List[List[int]]:
    def combineHelper(combinations: List[List[int]], current=[], i=1) -> None:
        if len(current) == k:
            combinations.append(current[:])
            return
        if i > n:
            return

        current.append(i)
        combineHelper(combinations, current, i + 1)
        current.remove(i)

        combineHelper(combinations, current, i + 1)

    combinations = []
    combineHelper(combinations)

    return combinations


assert combine(4, 2) == [
    [1, 2],
    [1, 3],
    [1, 4],
    [2, 3],
    [2, 4],
    [3, 4],
]

assert combine(1, 1) == [[1]]

assert combine(5, 3) == [
    [1, 2, 3],
    [1, 2, 4],
    [1, 2, 5],
    [1, 3, 4],
    [1, 3, 5],
    [1, 4, 5],
    [2, 3, 4],
    [2, 3, 5],
    [2, 4, 5],
    [3, 4, 5],
]

print("All tests passed!")
