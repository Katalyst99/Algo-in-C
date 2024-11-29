#!/usr/bin/env python3
"""The module for String Searching"""


def countSubstrings(main_str, sub_str):
    """
    Count the number of non-overlapping occurrences of a substring in a string.

    Args:
    main_str (str): The string to search within.
    sub_str (str): The substring to search for.

    Returns:
    int: The count of non-overlapping occurrences.
    """
    if not sub_str or not main_str:
        return 0

    count = 0
    i = 0

    while i < len(main_str):
        next_index = main_str.find(sub_str, i)
        if next_index == -1:
            break
        count += 1
        i = next_index + len(sub_str)

    return count


print(countSubstrings("ababab", "aba"))
print(countSubstrings("abcabcabc", "abc"))
print(countSubstrings("aaaaa", "aa"))
print(countSubstrings("hello world", " "))
print(countSubstrings("hello world", "x"))
