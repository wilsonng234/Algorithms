# Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i.
# Determine the maximum value obtainable by cutting up the rod and selling the pieces.


def cutRod(prices, n):
    dp = [0] * (n + 1)

    for length1 in range(1, n + 1):
        for length2 in range(1, length1 + 1):
            dp[length1] = max(dp[length1], prices[length2 - 1] + dp[length1 - length2])

    return dp[n]


prices = [1, 5, 8, 9, 10, 17, 17, 20]
n = 8
assert cutRod(prices, n) == 22

prices = [3, 5, 8, 9, 10, 17, 17, 20]
n = 8
assert cutRod(prices, n) == 24

print("All tests passed!")
