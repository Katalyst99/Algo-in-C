#!/usr/bin/env python3
"""The module for Next Permutation"""


def nextPermutation(nums):
    """Finds the next permutation"""
    n = len(nums)
    i = n - 2

    while i >= 0 and nums[i] >= nums[i + 1]:
        i -= 1

    if i >= 0:
        j = n - 1
        while nums[j] <= nums[i]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]

    nums[i + 1:] = reversed(nums[i + 1:])


arr = [1, 3, 5, 4, 2]
nextPermutation(arr)
print(arr)
