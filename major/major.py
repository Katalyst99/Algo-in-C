#!/usr/bin/env python3
"""The module for Majority Element Algorithm"""


def majorElement(arr):
    """Function that finds the majority element in the array"""
    candidate = None
    count = 0
    for num in arr:
        if count == 0:
            candidate = num
            count = 1
        elif num == candidate:
            count += 1
        else:
            count -= 1

    count = 0
    for num in arr:
        if num == candidate:
            count += 1

    if count > len(arr) // 2:
        return candidate
    return -1


arr1 = [3, 3, 4, 2, 4, 4, 2, 4, 4]
arr2 = [3, 3, 4, 2, 4, 4, 2, 4]

print(f'Majority element in arr1: {majorElement(arr1)}')
print(f'Majority element in arr2: {majorElement(arr2)}')
