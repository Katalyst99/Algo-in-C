#!/usr/bin/env python3
"""The module for Minimum number of Jumps"""


def minJumps(arr):
    """Finds the min number of jumps needed to reach end of array."""
    n = len(arr)

    if n <= 1:
        return 0
    if arr[0] == 0:
        return -1

    jumps = 1
    maxReach = arr[0]
    step = arr[0]

    for i in range(1, n):
        if i == n - 1:
            return jumps

        maxReach = max(maxReach, i + arr[i])

        if i == step:
            jumps += 1
            step = maxReach

            if step <= i:
                return -1
    return -1


arr = [2, 3, 1, 1, 4]
print("Minimum jumps required:", minJumps(arr))
