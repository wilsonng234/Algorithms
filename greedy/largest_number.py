from typing import List
from functools import reduce, cmp_to_key

# 179. Largest Number

# Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
# Children with a higher rating get more candies than their neighbors.

# Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.


def largestNumber(nums: List[int]) -> str:
    def comparator(str1: str, str2: str) -> int:
        if str1 + str2 == str2 + str1:
            return 0
        else:
            return -1 if str1 + str2 < str2 + str1 else 1

    nums_str = list(map(lambda num: str(num), nums))
    nums_str.sort(key=cmp_to_key(comparator), reverse=True)

    if nums_str[0] == "0":
        return "0"
    return reduce(lambda num1, num2: num1 + num2, nums_str)


nums = [10, 2]
assert largestNumber(nums) == "210"

nums = [3, 30, 34, 5, 9]
assert largestNumber(nums) == "9534330"

nums = [0, 0, 0]
assert largestNumber(nums) == "0"

print("All tests passed!")
