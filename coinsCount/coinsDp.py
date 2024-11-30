#!/usr/bin/env python3
"""The module for Count the Coins"""


def countChange(amount, coins):
    """
    Count the number of ways to make change for a given amount using US coins (DP version).

    Args:
    amount (int): The amount in cents.
    coins (list): A list of coin values (e.g., [25, 10, 5, 1]).

    Returns:
    int: The number of ways to make change.
    """
    dp = [0] * (amount + 1)
    dp[0] = 1

    for coin in coins:
        for i in range(coin, amount + 1):
            dp[i] += dp[i - coin]
    return dp[amount]


# Example usage
coins = [25, 10, 5, 1]
print(countChange(15, coins))  # Output: 6
