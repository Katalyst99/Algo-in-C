#!/usr/bin/env python3
"""The module for the Two Sum Problem"""

def twoSumBrute(nums, target):
    """
    Function that finds all unique pairs of nums that add up to the target sum
    using brute force
    """
    output = []
    n = len(nums)
    for i in range(n):
        for j in range(i + 1, n):
            if nums[i] + nums[j] == target:
                output.append([nums[i], nums[j]])
    return output


nums = [3, 5, 2, -4, 8, 11]
target = 7
print(twoSumBrute(nums, target))
