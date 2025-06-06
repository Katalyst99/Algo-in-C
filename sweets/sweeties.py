#!/usr/bin/env python3
"""The module for Sweets Algorithm"""


def sweets(ratings):
    """
    Uses a two-pass approach to give sweets to kids based on their ratings.
    """
    n = len(ratings)
    sweeties = [1] * n

    for i in range(1, n):
        if ratings[i] > ratings[i - 1]:
            sweeties[i] = sweeties[i - 1] + 1

    for i in range(n - 2, -1, -1):
        if ratings[i] > ratings[i + 1]:
            sweeties[i] = max(sweeties[i], sweeties[i + 1] + 1)

    return sum(sweeties)


# Test
ratings = [1, 0, 2]
print(sweets(ratings))
