#!/usr/bin/env python3
"""The module for Palindrome Partitioning"""


def minCuts(s):
    """Computes the minimum cuts needed for a palindrome partitioning"""
    n = len(s)
    if n <= 1:
        return 0

    isPalindrome = [[False] * n for _ in range(n)]

    for end in range(n):
        for start in range(end + 1):
            if s[start] == s[end] and (end - start <= 2 or isPalindrome[start + 1][end - 1]):
                isPalindrome[start][end] = True

    cuts = [0] * n
    for i in range(n):
        if isPalindrome[0][i]:
            cuts[i] = 0
        else:
            cuts[i] = float('inf')
            for j in range(1, i + 1):
                if isPalindrome[j][i]:
                    cuts[i] = min(cuts[i], cuts[j - 1] + 1)
    return cuts[-1]


print(minCuts("aab"))
print(minCuts("a"))
print(minCuts("abccbc"))
