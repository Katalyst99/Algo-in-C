#!/usr/bin/env python3
"""The module for Median of Two Sorted Arrays"""


def findMedianSortedArrays(nums1, nums2):
    """
    Function to determine the median of two sorted arrays,
    using merge and sort
    """
    merged = sorted(nums1 + nums2)
    n = len(merged)

    if n % 2 == 1:
        return merged[n // 2]
    else:
        mid1 = merged[n // 2 - 1]
        mid2 = merged[n // 2]
        return (mid1 + mid2) / 2


print(findMedianSortedArrays([1, 3], [2]))
print(findMedianSortedArrays([1, 2], [3, 4]))
