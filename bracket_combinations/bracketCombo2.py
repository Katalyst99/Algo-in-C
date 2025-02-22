#!/usr/bin/env python3
"""The module for Bracket Combinations"""


def catalan_number(n):
    """Function to compute the nth Catalan number using DP"""
    if n == 0 or n == 1:
        return 1

    dp = [0] * (n + 1)
    dp[0] = dp[1] = 1

    for i in range(2, n + 1):
        dp[i] = 0
        for j in range(i):
            dp[i] += dp[j] * dp[i - j - 1]

    return dp[n]


num = 3
print(f"Number of valid bracket combinations for {num} pairs: {catalan_number(num)}")
