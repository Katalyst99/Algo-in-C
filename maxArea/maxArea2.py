#!/usr/bin/env python3
"""The module for Container With Most Water"""


def maxArea(height):
    """
    Forms a container with the max amount of water that,
    can be stored within it.
    """
    L = 0
    R = len(height) - 1
    maxWater = 0

    while L < R:
        width = R - L
        minHeight = min(height[L], height[R])
        water = width * minHeight

        maxWater = max(maxWater, water)

        # Move the pointer with the smaller height
        if height[L] < height[R]:
            L += 1
        else:
            R -= 1

    return maxWater


height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
print("Maximum water stored:", maxArea(height))
