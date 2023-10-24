def longestCommonSubstring(text1: str, text2: str) -> int:
    dp = [[0 for _ in range(len(text2) + 1)] for _ in range(len(text1) + 1)]

    for i in range(1, len(text1) + 1):
        for j in range(1, len(text2) + 1):
            if text1[i - 1] == text2[j - 1]:
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else:
                dp[i][j] = 0

    return max(max(row) for row in dp)


text1 = "GeeksforGeeks"
text2 = "GeeksQuiz"
assert longestCommonSubstring(text1, text2) == 5

text1 = "abcdxyz"
text2 = "xyzabcd"
assert longestCommonSubstring(text1, text2) == 4

text1 = "zxabcdezy"
text2 = "zxabcdezy"
assert longestCommonSubstring(text1, text2) == 9

text1 = "zxabcdezy"
text2 = "yzabcdezx"
assert longestCommonSubstring(text1, text2) == 6

text1 = "zxabcdezy"
text2 = "a"
assert longestCommonSubstring(text1, text2) == 1

print("All tests passed!")
