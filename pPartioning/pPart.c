#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/**
 * minCuts - Determines the minimum cuts needed for a palindrome partitioning of the string
 * @s: The string
 * Return: The minimum number of cuts needed for a palindrome partitioning
 */
int minCuts(char *s) 
{
    int n = strlen(s);

    if (n == 0)
	    return 0;

    bool **isPalin = malloc(n * sizeof(bool *));
    for (int i = 0; i < n; i++) 
    {
        isPalin[i] = calloc(n, sizeof(bool));
    }

    for (int end = 0; end < n; end++) 
    {
        for (int start = 0; start <= end; start++) 
	{
            if (s[start] == s[end] && (end - start <= 2 || isPalin[start + 1][end - 1])) 
	    {
                isPalin[start][end] = true;
            }
        }
    }

    int *dp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        if (isPalin[0][i]) 
	{
            dp[i] = 0;
        }
	else 
	{
            dp[i] = INT_MAX;
            for (int j = 0; j < i; j++) 
	    {
                if (isPalin[j + 1][i] && dp[j] + 1 < dp[i]) 
		{
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    int output = dp[n - 1];

    for (int i = 0; i < n; i++) free(isPalin[i]);
    free(isPalin);
    free(dp);

    return output;
}

int main() 
{
    char s[] = "aab";
    printf("Minimum cuts needed: %i\n", minCuts(s));
    return 0;
}
