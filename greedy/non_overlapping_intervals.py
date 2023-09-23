from typing import List


# Leetcode 435. Non-overlapping Intervals
# Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
def erase_overlap_intervals(intervals: List[List[int]]) -> int:
    intervals.sort(key=lambda interval: interval[1])
    cnt = -1
    cur_end = intervals[0][1]

    for interval in intervals:
        if interval[0] >= cur_end:
            cur_end = interval[1]
        else:
            cnt += 1

    return cnt


intervals = [[1, 2], [2, 3], [3, 4], [1, 3]]
assert erase_overlap_intervals(intervals) == 1

intervals = [[1, 2], [1, 2], [1, 2]]
assert erase_overlap_intervals(intervals) == 2

intervals = [[1, 2], [2, 3]]
assert erase_overlap_intervals(intervals) == 0

print("All tests passed!")
