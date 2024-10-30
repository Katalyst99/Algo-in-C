#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/**
 * isContained - Checks if `str` contains all characters in `needle`.
 * @str: The substring to check.
 * @needle: The string containing required characters.
 * Return: True if `str` contains all characters in `needle`, otherwise False.
 */
bool isContained(const char *str, const char *needle) {
    int count[256] = {0};
    int found[256] = {0};

    // Count all characters in needle
    for (int i = 0; needle[i] != '\0'; i++) {
        count[(unsigned char)needle[i]]++;
    }

    // Count characters in str to see if it matches the count needed by needle
    for (int i = 0; str[i] != '\0'; i++) {
        found[(unsigned char)str[i]]++;
    }

    // Compare counts
    for (int i = 0; i < 256; i++) {
        if (count[i] > found[i]) {
            return false;
        }
    }
    return true;
}

/**
 * minWinSubstring - Finds the smallest substring in `str` that contains all characters in `needle`.
 * @str: The main string.
 * @needle: The substring containing required characters.
 * Return: The smallest substring or NULL if no such substring exists.
 */
const char *minWinSubstring(const char *str, const char *needle) {
    int len_str = strlen(str);
    int len_needle = strlen(needle);
    int min_len = INT_MAX;
    const char *min_substr = NULL;

    for (int start = 0; start <= len_str - len_needle; start++) {
        for (int end = start + len_needle; end <= len_str; end++) {
            int len_sub = end - start;
            char sub[len_sub + 1];
            strncpy(sub, str + start, len_sub);
            sub[len_sub] = '\0';

            if (isContained(sub, needle) && len_sub < min_len) {
                min_len = len_sub;
                min_substr = str + start;
            }
        }
    }

    if (min_len == INT_MAX) {
        printf("No such substring found.\n");
        return NULL;
    } else {
        static char result[256];
        strncpy(result, min_substr, min_len);
        result[min_len] = '\0';
        return result;
    }
}

int main() {
    const char *str = "this is a test string";
    const char *needle = "tist";

    const char *result = minWinSubstring(str, needle);
    if (result) {
        printf("Smallest substring: %s\n", result);
    }

    return 0;
}

