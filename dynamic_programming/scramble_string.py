# Leetcode 87. Scramble String

# We can scramble a string s to get a string t using the following algorithm:

# 1. If the length of the string is 1, stop.
# 2. If the length of the string is > 1, do the following:
# Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
# Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
# Apply step 1 recursively on each of the two substrings x and y.

# Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.


def isScramble(s1: str, s2: str) -> bool:
    return memoization(s1, s2)


def bruteForce(s1: str, s2: str) -> bool:
    if s1 == s2:
        return True

    for split_point in range(1, len(s1)):
        x, y = s1[:split_point], s1[split_point:]

        # s = x + y
        if bruteForce(x, s2[:split_point]) and bruteForce(y, s2[split_point:]):
            return True
        # s = y + x
        if bruteForce(y, s2[: len(y)]) and bruteForce(x, s2[len(y) :]):
            return True

    return False


def memoization(s1: str, s2: str, memo: dict = {}) -> bool:
    key = s1 + "," + s2

    if key not in memo:
        if s1 == s2:
            memo[key] = True
            return True

        memo[key] = False
        for split_point in range(1, len(s1)):
            x, y = s1[:split_point], s1[split_point:]

            # s = x + y
            if memoization(x, s2[:split_point]) and memoization(y, s2[split_point:]):
                memo[key] = True
                return True
            # s = y + x
            if memoization(y, s2[: len(y)]) and memoization(x, s2[len(y) :]):
                memo[key] = True
                return True

    return memo[key]


s1 = "great"
s2 = "rgeat"
assert isScramble(s1, s2) == True


s1 = "abcde"
s2 = "caebd"
assert isScramble(s1, s2) == False

s1 = "a"
s2 = "a"
assert isScramble(s1, s2) == True

print("All tests passed!")
