#!/usr/bin/env python3
"""The module for Count the Coins"""


def countChange(amount, coins):
    """
    Count the number of ways to make change for a given amount using US coins.

    Args:
    amount (int): The amount in cents.
    coins (list): A list of coin values (e.g., [25, 10, 5, 1]).

    Returns:
    int: The number of ways to make change.
    """
    if amount == 0:
        return 1
    if amount < 0 or not coins:
        return 0
    include_coin = countChange(amount - coins[0], coins)
    exclude_coin = countChange(amount, coins[1:])

    return include_coin + exclude_coin


# Example usage
coins = [25, 10, 5, 1]
print(countChange(15, coins))
print(countChange(0, coins))
print(countChange(25, coins))
print(countChange(30, coins))
print(countChange(-15, coins))
