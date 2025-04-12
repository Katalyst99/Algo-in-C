#!/usr/bin/env python3
"""The module for the Triangle algorithm"""


def minSum(triangle):
    """Computes the minimum path sum in a triangle array"""
    if not triangle:
        return 0

    for x in range(len(triangle) - 2, -1, -1):
        for y in range(len(triangle[x])):
            triangle[x][y] += min(triangle[x + 1][y], triangle[x + 1][y + 1])

    return triangle[0][0]


triangle = [
    [2],
    [3, 4],
    [6, 5, 7],
    [4, 1, 8, 3]
]
print('Minimum path sum:', minSum(triangle))
