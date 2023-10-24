def knapsack(weights, values, capacity):
    n = len(weights)
    weights = [0] + weights
    values = [0] + values
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for j in range(1, capacity + 1):
            weight = weights[i]
            value = values[i]

            if j >= weight:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value)
            else:
                dp[i][j] = dp[i - 1][j]

    return dp[n][capacity]


weights = [5, 4, 6, 3]
values = [10, 40, 30, 50]
capacity = 10
knapsack(weights, values, capacity)
assert knapsack(weights, values, capacity) == 90

weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50
knapsack(weights, values, capacity)
assert knapsack(weights, values, capacity) == 220

print("All tests passed!")
