from typing import List

# Leetcode 5. Longest Palindromic Substring

# Given a string s, return the longest palindromic substring in s.


def longestPalindrome(s: str) -> str:
    if len(s) < 2:
        return s

    start, end = 0, 0
    dp = [[False for _ in range(len(s))] for _ in range(len(s))]

    for i in range(len(s)):
        dp[i][i] = True
        if i < len(s) - 1 and s[i] == s[i + 1]:
            dp[i][i + 1] = True
            start, end = i, i + 1

    for len_ in range(3, len(s) + 1):
        for row in range(len(s)):
            if row + len_ - 1 >= len(s):
                break

            col = row + len_ - 1
            if s[row] == s[col] and dp[row + 1][col - 1]:
                dp[row][col] = True
                start, end = row, col

    return s[start : end + 1]


s = "babad"
assert longestPalindrome(s) == "aba"

s = "cbbd"
assert longestPalindrome(s) == "bb"

print("All tests passed!")
