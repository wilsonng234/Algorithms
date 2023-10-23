from typing import List

# 322. Coin Change

# You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
# Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

# You may assume that you have an infinite number of each kind of coin.


def coinChange(coins: List[int], amount: int) -> int:
    dp = [float("inf")] * (amount + 1)
    dp[0] = 0

    for coin in coins:
        if coin <= amount:
            dp[coin] = 1

    for amount_ in range(1, len(dp)):
        for coin in coins:
            if amount_ - coin > 0:
                dp[amount_] = min(dp[amount_], dp[amount_ - coin] + 1)

    return dp[amount] if dp[amount] != float("inf") else -1


coins = [1, 2, 5]
amount = 11
assert coinChange(coins, amount) == 3

coins = [2]
amount = 3
assert coinChange(coins, amount) == -1

coins = [1]
amount = 0
assert coinChange(coins, amount) == 0

print("All tests passed!")
