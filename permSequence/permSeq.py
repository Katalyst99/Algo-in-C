#!/usr/bin/env python3
"""The module for Permutation Sequence"""
from math import factorial


def getPermutation(n: int, k: int) -> str:
    """Generates the k-th permutation"""
    nums = list(range(1, n + 1))
    k -= 1
    output = []

    for i in range(n, 0, -1):
        f = factorial(i - 1)
        index = k // f
        output.append(str(nums[index]))
        nums.pop(index)
        k %= f

    return "".join(output)


n, k = 3, 4
print(getPermutation(n, k))
