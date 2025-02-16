#!/usr/bin/env python3
"""The module for Decoding Ways"""


def numDecodings(s: str) -> int:
    """Calculates the number of ways to decode a string"""
    if not s or s[0] == '0':
        return 0

    dp = [0] * (len(s) + 1)
    dp[0] = 1
    dp[1] = 1

    for i in range(2, len(s) + 1):
        # Check single digit
        singleDigit = int(s[i - 1:i])
        if 1 <= singleDigit <= 9:
            dp[i] += dp[i - 1]

        twoDigits = int(s[i - 2:i])
        if 10 <= twoDigits <= 26:
            dp[i] += dp[i - 2]

    return dp[len(s)]


encoded = "11116"
output = numDecodings(encoded)
print(f"Number of ways to decode '{encoded}': {output}")
