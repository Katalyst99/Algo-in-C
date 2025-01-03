#!/usr/bin/env python3
"""The module for the Peak element problem"""


def peak(arr, n):
    low = 0
    high = n - 1

    while low <= high:
        mid = (low + high) // 2
        if (mid == 0 or arr[mid] >= arr[mid - 1]) and (mid == n - 1 or arr[mid] >= arr[mid + 1]):
            return mid

        if mid > 0 and arr[mid - 1] > arr[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return -1


arr = [1, 3, 20, 4, 1, 0]
n = len(arr)
idx = peak(arr, n)
print("Peak element is at index:", idx, "with value:", arr[idx])
