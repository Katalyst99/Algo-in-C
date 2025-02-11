#!/usr/bin/env python3
"""The module for Add Binary"""


def addBinary(a, b):
    """Returns the sum of 2 binary strings as a binary string"""
    output = []
    carry = 0
    i = len(a) - 1
    j = len(b) - 1

    while i >= 0 or j >= 0 or carry:
        bitA = int(a[i]) if i >= 0 else 0
        bitB = int(b[j]) if j >= 0 else 0

        total = bitA + bitB + carry
        output.append(str(total % 2))
        carry = total // 2

        i -= 1
        j -= 1

    return ''.join(output[::-1])


print(addBinary("101", "11"))
