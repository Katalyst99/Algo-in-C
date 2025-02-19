#!/usr/bin/env python3
"""The module for Recursive Backtracking Algorithm"""


def genCombinations(n, m, start=0, combination=None):
    """Recursive function to generate combinations"""
    if combination is None:
        combination = []

    if len(combination) == m:
        print(combination)
        return

    for i in range(start, n):
        combination.append(i)
        genCombinations(n, m, i + 1, combination)
        combination.pop()


n = int(input("Enter range (n): "))
m = int(input("Enter size of combination (m): "))

if m > n or m <= 0 or n <= 0:
    print("Invalid input! m should be <= n and both should be > 0.")
else:
    genCombinations(n, m)
