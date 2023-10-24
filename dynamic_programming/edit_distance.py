# Leetcode 72. Edit Distance

# Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

# You have the following three operations permitted on a word:
# - Insert a character
# - Delete a character
# - Replace a character


def minDistance(word1: str, word2: str) -> int:
    dp = [[0 for _ in range(len(word2) + 1)] for _ in range(len(word1) + 1)]

    for i in range(len(word1) + 1):
        dp[i][0] = i
    for i in range(len(word2) + 1):
        dp[0][i] = i

    for i in range(1, len(word1) + 1):
        for j in range(1, len(word2) + 1):
            if word1[i - 1] == word2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]  # no operation
            else:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1  # min(insert, delete)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1)  # min(replace)

    return dp[len(word1)][len(word2)]


word1 = "horse"
word2 = "ros"
assert minDistance(word1, word2) == 3

word1 = "intention"
word2 = "execution"
assert minDistance(word1, word2) == 5

print("All tests passed!")
