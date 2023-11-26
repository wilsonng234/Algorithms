from typing import List

# 221. Maximal Square

# Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.


def maximalSquare(matrix: List[List[str]]) -> int:
    dp = [[0 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
    max_side = 0
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            if matrix[i][j] == "1":
                dp[i][j] = 1
                max_side = 1

    for i in range(1, len(matrix)):
        for j in range(1, len(matrix[0])):
            if dp[i][j] == 1:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1

            max_side = max(max_side, dp[i][j])

    return max_side * max_side


matrix = [
    ["1", "0", "1", "0", "0"],
    ["1", "0", "1", "1", "1"],
    ["1", "1", "1", "1", "1"],
    ["1", "0", "0", "1", "0"],
]
assert maximalSquare(matrix) == 4

matrix = [["0", "1"], ["1", "0"]]
assert maximalSquare(matrix) == 1

matrix = [["0"]]
assert maximalSquare(matrix) == 0

print("All tests passed!")
