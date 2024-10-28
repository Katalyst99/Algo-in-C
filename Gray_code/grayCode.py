#!/usr/bin/env python3
"""The module for implementing gray code"""
def gray_code(encode, num):
    """Function to encode and decode a number in Gray code"""
    if encode:
        return num ^ (num >> 1)
    else:
        mask = num >> 1
        while mask != 0:
            num = num ^ mask
            mask >>= 1
        return num

# Test example
num = int(input("Enter the number: "))
encode = int(input("Enter 1 to encode or 0 to decode: "))

result = gray_code(bool(encode), num)
print(f"Result: {result}")
