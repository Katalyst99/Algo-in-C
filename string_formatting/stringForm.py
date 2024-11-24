#!/usr/bin/python3
"""The module for formatting words"""


def format_words(words):
    """
    Formats a list of words into a specific string structure.

    Args:
    words (list of str): List of input words.

    Returns:
    str: Formatted string as per the rules.
    """
    if not words:
        return "{}"

    if len(words) == 1:
        return f"{{{words[0]}}}"

    if len(words) == 2:
        return f"{{{words[0]} and {words[1]}}}"

    return f"{{{', '.join(words[:-1])} and {words[-1]}}}"


print(format_words([]))                    # Output: "{}"
print(format_words(["ABC"]))               # Output: "{ABC}"
print(format_words(["ABC", "DEF"]))        # Output: "{ABC and DEF}"
print(format_words(["ABC", "DEF", "G"]))   # Output: "{ABC, DEF and G}"
print(format_words(["A", "B", "C", "D"]))  # Output: "{A, B, C and D}"
