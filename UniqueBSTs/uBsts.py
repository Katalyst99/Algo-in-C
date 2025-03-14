#!/usr/bin/env python3
"""The module for Unique Binary Search Trees"""
from math import factorial


def uniqueBSTs(n):
    """Calculates the number of structurally unique BSTs"""
    return factorial(2 * n) // (factorial(n) * factorial(n + 1))


n = 3
print(f"Number of unique BSTs for n = {n}: {uniqueBSTs(n)}")
