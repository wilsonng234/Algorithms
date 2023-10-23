from typing import List

# 1235. Maximum Profit in Job Scheduling

# We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
# You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

# If you choose a job that ends at time X you will be able to start another job that starts at time X.


def findClosestCompatibleJob(jobs, startTime, left, right):
    if left > right:
        return -1
    if left == right:
        return left if jobs[left][1] <= startTime else -1
    if left + 1 == right:
        if jobs[right][1] <= startTime:
            return right
        if jobs[left][1] <= startTime:
            return left
        return -1

    mid = left + (right - left) // 2

    # compatible
    if jobs[mid][1] <= startTime:
        return findClosestCompatibleJob(jobs, startTime, mid, right)
    # incompatible
    return findClosestCompatibleJob(jobs, startTime, left, mid - 1)


def jobScheduling(startTime: List[int], endTime: List[int], profit: List[int]) -> int:
    dp = [0] * (len(startTime) + 1)
    jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
    closestCompatibleJob = [-1] * len(jobs)

    for i in range(len(jobs)):
        startTime, endTime, profit = jobs[i]
        closestCompatibleJob[i] = findClosestCompatibleJob(jobs, startTime, 0, i - 1)

        if closestCompatibleJob[i] == -1:
            dp[i + 1] = max(dp[i], profit)
        else:
            dp[i + 1] = max(dp[i], dp[closestCompatibleJob[i] + 1] + profit)

    return dp[-1]


startTime = [1, 2, 3, 3]
endTime = [3, 4, 5, 6]
profit = [50, 10, 40, 70]
assert jobScheduling(startTime, endTime, profit) == 120

startTime = [1, 2, 3, 4, 6]
endTime = [3, 5, 10, 6, 9]
profit = [20, 20, 100, 70, 60]
assert jobScheduling(startTime, endTime, profit) == 150

startTime = [1, 1, 1]
endTime = [2, 3, 4]
profit = [5, 6, 4]
assert jobScheduling(startTime, endTime, profit) == 6

print("All tests passed!")
