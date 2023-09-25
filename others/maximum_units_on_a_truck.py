from typing import List

# 1109. Corporate Flight Bookings

# There are n flights that are labeled from 1 to n.
# You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.
# Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.


def corp_flight_bookings(bookings: List[List[int]], n: int) -> List[int]:
    total_seats = [0] * (n + 1)

    for first_flight, last_flight, seats in bookings:
        total_seats[first_flight] += seats
        if last_flight + 1 < len(total_seats):
            total_seats[last_flight + 1] -= seats

    for i in range(1, len(total_seats)):
        total_seats[i] += total_seats[i - 1]

    return total_seats[1:]


bookings = [[1, 2, 10], [2, 3, 20], [2, 5, 25]]
n = 5
assert corp_flight_bookings(bookings, n) == [10, 55, 45, 25, 25]

bookings = [[1, 2, 10], [2, 2, 15]]
n = 2
assert corp_flight_bookings(bookings, n) == [10, 25]

print("All tests passed!")
