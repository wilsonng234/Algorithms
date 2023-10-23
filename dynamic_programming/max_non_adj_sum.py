def maxNonAdjSum(nums):
    if len(nums) == 0:
        return 0
    if len(nums) == 1:
        return nums[0]

    maxSum = [nums[0], max(nums[0], nums[1])]

    for i in range(2, len(nums)):
        maxSum.append(max(maxSum[i - 1], maxSum[i - 2] + nums[i]))

    return maxSum[-1]


nums = []
assert maxNonAdjSum(nums) == 0

nums = [1]
assert maxNonAdjSum(nums) == 1

nums = [7, 8, 6, 3]
assert maxNonAdjSum(nums) == 13

nums = [1, 2, 3, 4, 5, 6, 7, 8]
assert maxNonAdjSum(nums) == 20

nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
assert maxNonAdjSum(nums) == 25

nums = [1, 8, 6, 3, 7]
assert maxNonAdjSum(nums) == 15

print("All tests passed!")
