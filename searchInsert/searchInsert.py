#!/usr/bin/env python3
"""The module for Search Insert Position"""


def searchInsert(nums, target):
    """Finds the index to insert a target value in a sorted array"""
    L = 0
    R = len(nums) - 1

    while L <= R:
        mid = (L + R) // 2

        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            L = mid + 1
        else:
            R = mid - 1

    return L


nums = [1, 3, 5, 6]
target = 5
print(searchInsert(nums, target))

target = 2
print(searchInsert(nums, target))

target = 7
print(searchInsert(nums, target))

target = 0
print(searchInsert(nums, target))
