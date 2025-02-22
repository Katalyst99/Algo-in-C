#!/usr/bin/env python3
"""The module for Bracket Combinations"""


def countCombos(openBrack, closeBrack, count):
    """Function to count the total bracket combinations"""
    if openBrack == 0 and closeBrack == 0:
        return 1

    total = 0

    if openBrack > 0:
        total += countCombos(openBrack - 1, closeBrack, count)

    if closeBrack > openBrack:
        total += countCombos(openBrack, closeBrack - 1, count)

    return total


def bracketCombos(n):
    """Returns the total number of bracket combinations"""
    return countCombos(n, n, 0)


num = 3
print(f"Number of valid bracket combinations for {num} pairs: {bracketCombos(num)}")
