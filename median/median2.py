#!/usr/bin/env python3
"""The module for Median of Two Sorted Arrays"""


def findMedianSortedArrays(nums1, nums2):
    """
    Function to determine the median of two sorted arrays,
    using 2 pointers.
    """
    merged = []
    i = 0
    j = 0

    while i < len(nums1) and j < len(nums2):
        if nums1[i] < nums2[j]:
            merged.append(nums1[i])
            i += 1
        else:
            merged.append(nums2[j])
            j += 1

    merged.extend(nums1[i:])
    merged.extend(nums2[j:])

    n = len(merged)
    if n % 2 == 1:
        return merged[n // 2]
    else:
        return (merged[n // 2 - 1] + merged[n // 2]) / 2


print(findMedianSortedArrays([1, 3], [2]))
print(findMedianSortedArrays([1, 2], [3, 4]))
