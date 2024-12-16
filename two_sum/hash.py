#!/usr/bin/env python3
"""The module for the Two Sum Problem"""

def twoSumHash(nums, target):
    output = []
    numMap = {}

    for num in nums:
        comp = target - num
        if comp in numMap:
            output.append([num, comp])
        numMap[num] = True
    return output


nums = [3, 5, 2, -4, 8, 11]
target = 7
print(twoSumHash(nums, target))
