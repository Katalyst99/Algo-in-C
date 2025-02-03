#!/usr/bin/env python3
"""The module for Longest Common Prefix"""


def longestCommonPrefix(strs):
    """Finds the longest common prefix amongst an array of strings"""
    if not strs:
        return ""

    prefix = strs[0]

    for word in strs[1:]:
        while not word.startswith(prefix):
            prefix = prefix[:-1]
            if not prefix:
                return ""

    return prefix


words = ["flower", "flow", "flight"]
print("Longest Common Prefix:", longestCommonPrefix(words))

words = ["dog", "racecar", "car"]
print("Longest Common Prefix:", longestCommonPrefix(words))
