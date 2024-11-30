#include <stdio.h>

/**
 * countChange - Counts the ways to make change using coins.
 * @amount: The amount in cents.
 * @coins: Array of coin denominations.
 * @num_coins: Number of coin denominations.

 * Return: The number of ways to make change.
 */
int countChange(int amount, int coins[], int num_coins)
{
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;  // Base case: one way to make 0 cents

    for (int i = 0; i < num_coins; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

int main()
{
    int coins[] = {25, 10, 5, 1};
    int num_coins = sizeof(coins) / sizeof(coins[0]);
    int amount = 15;
    printf("%d\n", countChange(amount, coins, num_coins));  // Output: 6
    return 0;
}
