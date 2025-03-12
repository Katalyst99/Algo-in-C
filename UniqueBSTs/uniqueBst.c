#include <stdio.h>

/**
 * uniqueBSTs - Calculates the number of structurally unique BSTs
 * @n: The unique values of nodes
 * Return: The number of structurally unique BSTs
 */
int uniqueBSTs(int n) 
{
    int dp[n + 1];
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) 
    {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) 
	{
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

int main() 
{
    int n = 3;
    printf("Number of unique BSTs for n = %i: %i\n", n, uniqueBSTs(n));
    return 0;
}
