#include <stdio.h>

/**
 * knapSack - Function to return max value that can be put in a knapsack of capacity W
 * @W: The max capacity of knapsack
 * @wt: The weight array
 * @val: The value array
 * @n: The number of items
 * Return: The max possible value you can get.
 */
int knapSack(int W, int wt[], int val[], int n) 
{
    int dp[W + 1];
    for (int i = 0; i <= W; i++) dp[i] = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int w = W; w >= wt[i]; w--) 
	{
            if (dp[w - wt[i]] + val[i] > dp[w])
                dp[w] = dp[w - wt[i]] + val[i];
        }
    }

    return dp[W];
}

int main() 
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Knapsack (Optimized): %i\n", knapSack(W, wt, val, n));
    return 0;
}
