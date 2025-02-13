#!/usr/bin/env python3
"""The module for Climbing Stairs"""


def climbStairs(n: int) -> int:
    """Calculates the number of ways to climb the stairs"""
    if n == 1:
        return 1
    if n == 2:
        return 2

    prev2 = 1
    prev1 = 2

    for i in range(3, n+1):
        current = prev1 + prev2
        prev2 = prev1
        prev1 = current

    return prev1


n = int(input("Enter the number of steps: "))

ways = climbStairs(n)

print(f'Number of distinct ways to climb {n} steps: {ways}')
