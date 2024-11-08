#!/usr/bin/env python3
"""The module for implementing FizzBuzz"""


def print_fizz_buzz(n):
    """
    Prints "Fizz", "Buzz", "FizzBuzz", or the number.
    :param n: The number to be checked and printed.
    """
    if n % 3 == 0 and n % 5 == 0:
        print("FizzBuzz", end=" ")
    elif n % 3 == 0:
        print("Fizz", end=" ")
    elif n % 5 == 0:
        print("Buzz", end=" ")
    else:
        print(n, end=" ")

# Main code to print numbers from 1 to 100
if __name__ == "__main__":
    for i in range(1, 101):
        print_fizz_buzz(i)
    print()  # Print a newline at the end
