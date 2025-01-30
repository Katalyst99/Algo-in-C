#!/usr/bin/env python3
"""The module for the Average Salary"""


def calcAverageSalary(salary):
    """Function that returns the average salary of the employees"""
    if len(salary) <= 2:
        return 0

    minSalary = min(salary)
    maxSalary = max(salary)

    total = sum(salary) - minSalary - maxSalary
    count = len(salary) - 2

    return total / count


salary = [4000, 3000, 1000, 2000]
print(calcAverageSalary(salary))
