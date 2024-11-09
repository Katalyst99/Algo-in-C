#!/usr/bin/env python3
"""The module for the ABC Problem"""


def can_make_word(word):
    blocks = [
        "BO", "XK", "DQ", "CP", "NA", "GT", "RE", "TG",
        "QD", "FS", "JW", "HU", "VI", "AN", "OB", "ER",
        "LY", "PC", "ZM"
    ]
    used_blocks = [False] * len(blocks)

    # Convert the word to uppercase to match the block format
    word = word.upper()

    for letter in word:
        found_block = False

        for i, block in enumerate(blocks):
            if used_blocks[i]:
                continue  # Skip already used blocks

            if letter in block:
                used_blocks[i] = True  # Mark block as used
                found_block = True
                break  # Stop looking for this letter

        # If no block was found for the current letter, return False
        if not found_block:
            return False

    # All letters found in unique blocks
    return True

# Test cases
words = ["FAN", "BOOB", "BARK", "TREAT"]
for word in words:
    if can_make_word(word):
        print(f"The word '{word}' can be formed using the blocks.")
    else:
        print(f"The word '{word}' cannot be formed using the blocks.")

