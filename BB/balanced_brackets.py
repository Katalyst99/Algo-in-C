#!/usr/bin/env python3
"""The module for Balanced Bracket algo"""


def is_balanced(s):
    """
    Checks if a string of brackets is balanced.
    
    Args:
        s (str): The input string containing brackets.
    
    Returns:
        bool: True if the string is balanced, False otherwise.
    
    This function uses a stack to track opening brackets and ensures
    each has a corresponding closing bracket that matches and is properly nested.
    """
    stack = []
    bracket_map = {')': '(', ']': '[', '}': '{'}
    
    for char in s:
        if char in bracket_map:
            top_element = stack.pop() if stack else None
            if bracket_map[char] != top_element:
                return False

        elif char in bracket_map.values():
            stack.append(char)

    return not stack

# Test cases to verify the function
if __name__ == "__main__":
    test_cases = [
        ("[]", True),
        ("][", False),
        ("[{()}]", True),
        ("[()]{}", True),
        ("{[)]}", False),
        ("", True),  # Edge case: empty string should be balanced
    ]

    # Run the test cases
    for i, (test, expected) in enumerate(test_cases):
        result = is_balanced(test)
        print(f"Test {i + 1}: {'Balanced' if result else 'Not Balanced'} (Expected: {'Balanced' if expected else 'Not Balanced'})")

