#!/usr/bin/env python3
"""The module for Missing Number In Array"""


def mIa_sum(arr, n):
    """The method to find the missing number using sum formula"""
    total = n * (n + 1) // 2
    actual = sum(arr)
    return total - actual


arr = [1, 2, 4, 6, 3, 7, 8]
n = 8
print("Missing number (Sum):", mIa_sum(arr, n))
