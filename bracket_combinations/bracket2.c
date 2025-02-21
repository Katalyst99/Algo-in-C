#include <stdio.h>

/**
 * catalanNumber - Function to compute the nth Catalan number using DP
 * @num: The number pairs of parenthesis
 * Return: The total number of combinations
 */
int catalanNumber(int num) 
{
    if (num == 0 || num == 1)
	    return 1;

    int dp[num + 1];
    dp[0] = dp[1] = 1;

    for (int x = 2; x <= num; x++) 
    {
        dp[x] = 0;
        for (int y = 0; y < x; y++) 
	{
            dp[x] += dp[y] * dp[x - y - 1];
        }
    }
    return dp[num];
}

int main() 
{
    int num = 3;
    printf("Number of valid bracket combinations for %i pairs: %i\n", num, catalanNumber(num));
    return 0;
}
