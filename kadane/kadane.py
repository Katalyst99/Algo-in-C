#!/usr/bin/env python3
"""The module for Kadane's Algorithm"""


def maxSubArrSum(arr):
    """
    Function uses Kadane's algorithm to find the max sum of a contiguous,
    sub-array in an array of integers.
    """
    current = 0
    maxSum = float('-inf')
    for number in arr:
        current += number
        if current > maxSum:
            maxSum = current
        if current < 0:
            current = 0
    return maxSum


arr = [1, -2, 3, 4, -1, 2, 1, -5, 4]
output = maxSubArrSum(arr)
print(f'Maximum sum of contiguous subarray: {output}')
