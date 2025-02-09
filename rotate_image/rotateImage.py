#!/usr/bin/env python3
"""The module for Rotate Image Algorithm"""


def rotateImage(matrix):
    """Function to rotate a given n x n matrix by 90 degrees clockwise."""
    n = len(matrix)

    for x in range(n):
        for y in range(x + 1, n):
            matrix[x][y], matrix[y][x] = matrix[y][x], matrix[x][y]

    for row in matrix:
        row.reverse()


matrix = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
]

rotateImage(matrix)
for row in matrix:
    print(row)
