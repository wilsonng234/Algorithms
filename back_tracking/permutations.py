from typing import List

# Leetcode 46. Permutations

# Given an array nums of distinct integers, return all the possible permutations.
# You can return the answer in any order.


def permute(nums: List[int]) -> List[List[int]]:
    def permuteHelper(
        permutations: List[List[int]], current: List[int] = [], used: set = set()
    ) -> None:
        if len(current) == len(nums):
            permutations.append(current)
            return

        for num in nums:
            if num not in used:
                permuteHelper(permutations, current + [num], used.union({num}))

    permutations = []
    permuteHelper(permutations)

    return permutations


nums = [1, 2, 3]
assert permute(nums) == [
    [1, 2, 3],
    [1, 3, 2],
    [2, 1, 3],
    [2, 3, 1],
    [3, 1, 2],
    [3, 2, 1],
]

nums = [0, 1]
assert permute(nums) == [[0, 1], [1, 0]]

nums = [1]
assert permute(nums) == [[1]]

print("All tests passed!")
