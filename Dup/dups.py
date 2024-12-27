#!/usr/bin/env python3
"""The module for Finding Duplicates in an Array"""


def dups(arr, n):
    """Function to find duplicates in an Array"""
    if not all(0 <= num < n for num in arr):
        raise ValueError("Array contains elements outside the range [0, N-1]")
    freq = [0] * n
    for num in arr:
        freq[num] += 1

    dupes = []
    for i in range(n):
        if freq[i] > 1:
            dupes.append(i)
    return dupes if dupes else [-1]


try:
    a = [4, 3, 2, 7, 8, 2, 3, 1]  # Update this as needed
    n = len(a)
    print(dups(a, n))  # Output: [2, 3]
except ValueError as e:
    print(e)
