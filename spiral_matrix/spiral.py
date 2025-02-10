#!/usr/bin/env python3
"""The module for Spiral Matrix"""


def spiral(matrix):
    """Returns all elements of the matrix in spiral order."""
    if not matrix or not matrix[0]:
        return []

    output = []
    top, btm = 0, len(matrix) - 1
    L, R = 0, len(matrix[0]) - 1

    while top <= btm and L <= R:
        for i in range(L, R + 1):
            output.append(matrix[top][i])
        top += 1

        for i in range(top, btm + 1):
            output.append(matrix[i][R])
        R -= 1

        if top <= btm:
            for i in range(R, L - 1, -1):
                output.append(matrix[btm][i])
            btm -= 1

        if L <= R:
            for i in range(btm, top - 1, -1):
                output.append(matrix[i][L])
            L += 1

    return output


matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
]

print("Spiral Order:", spiral(matrix))
