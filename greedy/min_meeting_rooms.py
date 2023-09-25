from typing import List
from heapq import heappush, heappop
from math import inf

# 253. Meeting Rooms II

# Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
# For example, Given [[0, 30],[5, 10],[15, 20]], return 2.


def min_meeting_rooms(intervals: List[List[int]]) -> int:
    sorted_intervals = sorted(intervals, key=lambda interval: interval[0])
    num_meeting_rooms = 0
    meeting_rooms = []  # list of end times

    for start, end in sorted_intervals:
        earliest_time = None

        if len(meeting_rooms) > 0:
            earliest_time = meeting_rooms[0]
        else:
            earliest_time = inf

        if start < earliest_time:
            num_meeting_rooms += 1
        else:
            heappop(meeting_rooms)
        heappush(meeting_rooms, end)

    return num_meeting_rooms


intervals = [[0, 30], [5, 10], [15, 20]]
assert min_meeting_rooms(intervals) == 2

intervals = [[7, 10], [2, 4]]
assert min_meeting_rooms(intervals) == 1

intervals = [[13, 15], [1, 13]]
assert min_meeting_rooms(intervals) == 1

intervals = [[2, 11], [6, 16], [11, 16]]
assert min_meeting_rooms(intervals) == 2

print("All tests passed!")
