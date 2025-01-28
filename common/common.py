#!/usr/bin/env python3
"""The module for the Common elements"""


def elementsCommon(A, B, C):
    """Finds the elements that are common in 3 arrays."""
    x, y, z = 0, 0, 0
    common = []

    while x < len(A) and y < len(B) and z < len(C):
        if A[x] == B[y] == C[z]:
            if not common or common[-1] != A[x]:
                common.append(A[x])
            x += 1
            y += 1
            z += 1
        elif A[x] < B[y]:
            x += 1
        elif B[y] < C[z]:
            y += 1
        else:
            z += 1

    return common


# Test
A = [1, 5, 10, 20, 40, 80]
B = [6, 7, 20, 80, 100]
C = [3, 4, 15, 20, 30, 70, 80, 120]

print("Common Elements:", elementsCommon(A, B, C))
