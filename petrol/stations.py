#!/usr/bin/env python3
"""The module for Petrol Station"""


def canMakeCircularTrip(fuel, cost):
    """
    Uses data of fuel station locations and fuel consumption,
    to gain insight into fuel efficiency of vehicles.
    """
    totalFuel = 0
    currentFuel = 0
    start = 0

    for i in range(len(fuel)):
        netFuel = fuel[i] - cost[i]
        totalFuel += netFuel
        currentFuel += netFuel

        if currentFuel < 0:
            start = i + 1
            currentFuel = 0
    return start if totalFuel >= 0 else -1


# Test
fuel1 = [1, 2, 3, 4, 5]
cost1 = [3, 4, 5, 1, 2]
print("Start station:", canMakeCircularTrip(fuel1, cost1))

fuel2 = [2, 3, 4]
cost2 = [3, 4, 3]
print("Start station:", canMakeCircularTrip(fuel2, cost2))
