from typing import List

# Leetcode 78. Subsets

# Given an integer array nums of unique elements, return all possible subsets
# The solution set must not contain duplicate subsets. Return the solution in any order.


def subsets(nums: List[int]) -> List[List[int]]:
    def subsetsHelper(subsets: List[List[int]], current: List[int] = [], i=0) -> None:
        subsets.append(current.copy())
        if len(current) == len(nums):
            return

        for x in range(i, len(nums)):
            current.append(nums[x])
            subsetsHelper(subsets, current, x + 1)
            current.pop()

    subsets = []
    subsetsHelper(subsets)

    return subsets


nums = [1, 2, 3]
assert subsets(nums) == [[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]

nums = [0]
assert subsets(nums) == [[], [0]]

print("All tests passed!")
