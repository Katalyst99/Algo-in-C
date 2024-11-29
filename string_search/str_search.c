#include <stdio.h>
#include <string.h>

/**
 * count_non_overlapping_occurrences - Counts non-overlapping occurrences of a substring in a string.
 * @main_str: The main string to search within.
 * @sub_str: The substring to search for.
 * 
 * Return: The count of non-overlapping occurrences.
 */
int countSubstrings(const char *main_str, const char *sub_str)
{
    if (!main_str || !sub_str || strlen(sub_str) == 0) {
        return 0;
    }

    int count = 0;
    const char *pos = main_str;

    while ((pos = strstr(pos, sub_str)) != NULL)
    {
        count++;
        pos += strlen(sub_str);
    }
    return count;
}

int main() 
{
    printf("%d\n", countSubstrings("ababab", "aba")); // Output: 1
    printf("%d\n", countSubstrings("abcabcabc", "abc")); // Output: 3
    printf("%d\n", countSubstrings("aaaaa", "aa")); // Output: 2
    printf("%d\n", countSubstrings("hello world", " ")); // Output: 1
    printf("%d\n", countSubstrings("hello world", "x")); // Output: 0
    return 0;
}
