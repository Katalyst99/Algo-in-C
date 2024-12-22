#!/usr/bin/env python3
"""The module for Sorting an Array of 0s, 1s, and 2s"""


def sort012(arr, n):
    """Function using 3-way partitioning to sort"""
    low = 0
    mid = 0
    high = n - 1

    while mid <= high:
        if arr[mid] == 0:
            arr[low], arr[mid] = arr[mid], arr[low]
            low += 1
            mid += 1
        elif arr[mid] == 1:
            mid += 1
        else:
            arr[mid], arr[high] = arr[high], arr[mid]
            high -= 1


arr = [2, 0, 1, 2, 0, 1]
sort012(arr, len(arr))
print("Sorted Array:", arr)
