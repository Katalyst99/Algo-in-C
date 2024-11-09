#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * canMakeWord - Checks if a word can be spelled using a collection of blocks.
 * @word: The input word as a string.
 * 
 * Return: true if the word can be formed, false otherwise.
 */
bool canMakeWord(const char *word)
{
    // Array of blocks, each block represented as a string of two characters.
    const char *blocks[] = {
        "BO", "XK", "DQ", "CP", "NA", "GT", "RE", "TG",
        "QD", "FS", "JW", "HU", "VI", "AN", "OB", "ER",
        "FS", "LY", "PC", "ZM"
    };
    bool usedBlocks[20] = { false };  // Array to track used blocks.

    // Iterate over each letter in the word.
    for (int i = 0; i < strlen(word); i++) {
        bool foundBlock = false;
        char letter = toupper(word[i]);  // Convert to uppercase to match blocks.

        // Iterate over each block to find a match.
        for (int j = 0; j < 20; j++) {
            if (usedBlocks[j]) {
                continue;  // Skip already used blocks.
            }

            // Check if the current block contains the letter.
            if (strchr(blocks[j], letter) != NULL) {
                usedBlocks[j] = true;  // Mark the block as used.
                foundBlock = true;
                break;  // Move to the next letter.
            }
        }

        // If no block was found for the current letter, return false.
        if (!foundBlock) {
            return false;
        }
    }

    // All letters matched and blocks were available.
    return true;
}

int main(void) {
    const char *words[] = {"FAN", "BOOB", "BARK", "TREAT"};
    for (int i = 0; i < 4; i++) {
        if (canMakeWord(words[i])) {
            printf("The word '%s' can be formed using the blocks.\n", words[i]);
        } else {
            printf("The word '%s' cannot be formed using the blocks.\n", words[i]);
        }
    }
    return 0;
}
