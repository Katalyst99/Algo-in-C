#!/usr/bin/env python3
"""The module for Amicable Pairs"""
import math


def sumOfDivisors(n):
    """Returns the sum of proper divisors of n (excluding n itself)."""
    if n < 2:
        return 0
    total = 1
    sqrt_n = int(math.sqrt(n))

    for i in range(2, sqrt_n + 1):
        if n % i == 0:
            total += i
            if i != n // i:
                total += n // i
    return total


def findAmicablePairs(limit):
    """Finds all amicable pairs up to a given limit"""
    divisorSums = {}
    amicablePairs = []

    for num in range(2, limit):
        if num not in divisorSums:
            divisorSums[num] = sumOfDivisors(num)

        pair = divisorSums[num]

        if pair > num and pair < limit:
            if pair not in divisorSums:
                divisorSums[pair] = sumOfDivisors(pair)
            if divisorSums[pair] == num:
                amicablePairs.append((num, pair))

    return amicablePairs


limit = 10000
amicablePairs = findAmicablePairs(limit)
print("Amicable Pairs:", amicablePairs)
