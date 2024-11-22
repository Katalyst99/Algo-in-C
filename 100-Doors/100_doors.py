#!/usr/bin/python3
"""The module for 100 doors"""


def toggleDoors():
    """
    Determines the state of 100 doors after 100 passes.
    Returns a list of door numbers that remain open.
    """
    doors = [False] * 100
    for j in range(1, 101):
        for i in range(j - 1, 100, j):
            doors[i] = not doors[i]
    # Collect door numbers that are open (True)
    open_doors = [i + 1 for i in range(100) if doors[i]]
    return open_doors


open_doors = toggleDoors()
print(f"Open doors: {open_doors}")
