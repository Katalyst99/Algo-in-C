#!/usr/bin/env python3
"""The module for find circles algo"""
import math


def find_circle_centers(point1, point2, r):
    # Calculate the distance between the points
    d = distance(point1, point2)

    if d == 0:
        if r == 0:
            return "Radius Zero"
        else:
            return "Coincident point. Infinite solutions"

    if d > 2 * r:
        return "No intersection. Points further apart than circle diameter"

    # Calculate the midpoint between the points
    mx = (point1[0] + point2[0]) / 2
    my = (point1[1] + point2[1]) / 2

    # Calculate the distance from the midpoint to the circle center
    h = math.sqrt(r**2 - (d / 2)**2)

    # Normalize the direction vector from point1 to point2
    dx = (point2[0] - point1[0]) / d
    dy = (point2[1] - point1[1]) / d

    # Calculate the two possible circle centers
    center1 = (round(mx + h * (-dy), 4), round(my + h * dx, 4))
    center2 = (round(mx - h * (-dy), 4), round(my - h * dx, 4))

    # Return both centers as an array of arrays
    return [center1, center2]


def distance(point1, point2):
    return math.sqrt((point2[0] - point1[0])**2 + (point2[1] - point1[1])**2)


print(find_circle_centers([1, 1], [4, 5], 3))
