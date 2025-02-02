#!/usr/bin/env python3
"""The module for Integer to Roman"""


def intToRoman(num):
    """Function to convert integer to a roman numeral"""
    values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

    roman = ""
    i = 0

    while num > 0:
        while num >= values[i]:
            num -= values[i]
            roman += symbols[i]
        i += 1

    return roman


print(intToRoman(3))
print(intToRoman(9))
print(intToRoman(58))
print(intToRoman(1994))
