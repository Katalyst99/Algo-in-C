#!/usr/bin/env python3
"""The module for Search in Rotated Sorted Array"""


def searchRotatedSorted(nums, target):
    """
    Takes an array nums and an int target as input and returns,
    the index of target in nums, or -1 if target is not in nums.
    """
    L = 0
    R = len(nums) - 1

    while L <= R:
        mid = (L + R) // 2

        if nums[mid] == target:
            return mid

        if nums[L] <= nums[mid]:
            if nums[L] <= target < nums[mid]:
                R = mid - 1
            else:
                L = mid + 1
        else:
            if nums[mid] < target <= nums[R]:
                L = mid + 1
            else:
                R = mid - 1
    return -1


nums = [4, 5, 6, 7, 0, 1, 2]
target = 0
index = searchRotatedSorted(nums, target)
print(f"Target {target} found at index {index}" if index != -1 else f"Target {target} not found")
