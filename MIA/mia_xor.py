#!/usr/bin/env python3
"""The module for Missing Number In Array"""


def mIa_xor(arr, n):
    """The method to find the missing number using XOR"""
    xorAll = 0
    xorArr = 0

    for i in range(1, n + 1):
        xorAll ^= i

    for number in arr:
        xorArr ^= number
    return xorAll ^ xorArr


arr = [1, 2, 4, 6, 3, 7, 8]
n = 8
print("Missing number (XOR):", mIa_xor(arr, n))
