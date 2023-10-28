from typing import List

# Leetcode 90. Subsets II

# Given an integer array nums that may contain duplicates, return all possible subsets.
# The solution set must not contain duplicate subsets. Return the solution in any order.


def subsetsWithDup(nums: List[int]) -> List[List[int]]:
    def subsetsWithDupHelper(
        subsets: List[List[int]], current: List[int] = [], i=0
    ) -> None:
        subsets.append(current.copy())
        if len(current) == len(nums):
            return

        while i < len(nums):
            current.append(nums[i])
            subsetsWithDupHelper(subsets, current, i + 1)
            current.pop()

            # Skip duplicates
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                i += 1
            i += 1

    nums.sort()
    subsets = []
    subsetsWithDupHelper(subsets)

    return subsets


nums = [1, 2, 2]
assert subsetsWithDup(nums) == [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]

nums = [0]
assert subsetsWithDup(nums) == [[], [0]]

print("All tests passed!")
