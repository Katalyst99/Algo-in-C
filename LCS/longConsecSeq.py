#!/usr/bin/env python3
"""The module for Longest Consecutive Sequence"""


def LCS(nums):
    """Returns the length of the longest consecutive elements sequence"""
    numSet = set(nums)
    longest = 0

    for n in numSet:
        if n - 1 not in numSet:
            length = 1
            current = n

            while current + 1 in numSet:
                current += 1
                length += 1

            longest = max(longest, length)

    return longest


if __name__ == "__main__":
    print(LCS([100, 4, 200, 1, 3, 2]))
    print(LCS([]))
    print(LCS([9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6]))
