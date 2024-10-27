#!/usr/bin/env python3
"""The module for implementing Euclid's Algo"""


def gcd(a, b):
    """The function that returns the highest common factor of 2 numbers"""
    while b != 0:
        a, b = b, a % b
    return a


# Example usage
num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))
result = gcd(num1, num2)
print(f"The GCD of {num1} and {num2} is: {result}")
