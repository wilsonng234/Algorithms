from typing import List

# Leetcode 1143. Longest Common Subsequence

# Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
# A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

# For example, "ace" is a subsequence of "abcde".

# A common subsequence of two strings is a subsequence that is common to both strings.


def longestCommonSubsequence(text1: str, text2: str) -> int:
    dp = [[0 for _ in range(len(text2) + 1)] for _ in range(len(text1) + 1)]

    for i in range(1, len(text1) + 1):
        for j in range(1, len(text2) + 1):
            if text1[i - 1] == text2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[len(text1)][len(text2)]


text1 = "abcde"
text2 = "ace"
assert longestCommonSubsequence(text1, text2) == 3

text1 = "abc"
text2 = "abc"
assert longestCommonSubsequence(text1, text2) == 3

text1 = "abc"
text2 = "def"
assert longestCommonSubsequence(text1, text2) == 0

text1 = "bsbininm"
text2 = "jmjkbkjkv"
assert longestCommonSubsequence(text1, text2) == 1

text1 = "oxcpqrsvwf"
text2 = "shmtulqrypy"
assert longestCommonSubsequence(text1, text2) == 2

print("All tests passed!")
