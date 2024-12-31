#!/usr/bin/env python3
"""The module for Trapping Rain Water"""


def trappingWater(arr, n):
    """
    Function to compute how much water can be trapped between blocks during
    the rainy season.
    """
    L = 0
    R = n - 1
    maxL = 0
    maxR = 0
    water = 0

    while L <= R:
        if arr[L] < arr[R]:
            if arr[L] >= maxL:
                maxL = arr[L]
            else:
                water += maxL - arr[L]
            L += 1
        else:
            if arr[R] >= maxR:
                maxR = arr[R]
            else:
                water += maxR - arr[R]
            R -= 1

    return water


arr = [3, 0, 2, 0, 4]
n = len(arr)
print("Water trapped:", trappingWater(arr, n))
