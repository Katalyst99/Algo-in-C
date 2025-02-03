#include <stdio.h>
#include <string.h>

/**
 * longestCommonPrefix - Finds the longest common prefix string
 * @str: An array of strings
 * @n: The size
 * Return: If no common prefix, return an empty string.
 */

char* longestCommonPrefix(char str[][50], int n) 
{
    if (n == 0) return "";

    static char prefix[50];
    strcpy(prefix, str[0]);

    for (int i = 1; i < n; i++) 
    {
        int j = 0;
        while (prefix[j] && str[i][j] && prefix[j] == str[i][j]) 
	{
            j++;
        }
        prefix[j] = '\0';

        if (prefix[0] == '\0') return "";
    }
    return prefix;
}

int main() 
{
    char str[][50] = {"flower", "flow", "flight"};
    int n = sizeof(str) / sizeof(str[0]);

    printf("Longest Common Prefix: %s\n", longestCommonPrefix(str, n));
    return 0;
}
