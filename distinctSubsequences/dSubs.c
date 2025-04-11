#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * numDist - Computes the number of distinct subsequences of s that equal t
 * @s: The first string
 * @t: The second string
 * Return: The num of distinct subsequences of s that equal t
 */
long long numDist(const char *s, const char *t) 
{
    int m = strlen(s);
    int n = strlen(t);
   
    long long **dp = (long long **)malloc((m + 1) * sizeof(long long *));
    if (!dp) 
    {
        perror("Memory allocation failed");
        exit(1);
    }
    for (int i = 0; i <= m; i++) 
    {
        dp[i] = (long long *)malloc((n + 1) * sizeof(long long));
        if (!dp[i]) 
	{
            perror("Memory allocation failed");
            exit(1);
        }
    }
    
    for (int i = 0; i <= m; i++) 
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= n; j++) 
    {
        dp[0][j] = 0;
    }
    
    for (int i = 1; i <= m; i++) 
    {
        for (int j = 1; j <= n; j++) 
	{
            if (s[i - 1] == t[j - 1]) 
	    {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else 
	    {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    long long output = dp[m][n];
    
    for (int i = 0; i <= m; i++) 
    {
        free(dp[i]);
    }
    free(dp);
    
    return output;
}

int main() 
{
    char s[] = "fisfhfisthit";
    char t[] = "fish";
    
    long long ways = numDist(s, t);
    printf("Number of distinct subsequences: %lli\n", ways);
    return 0;
}
