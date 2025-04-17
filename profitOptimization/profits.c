#include <stdio.h>

/**
 * profitMaximization - Computes the maximum profit
 * @prices: The prices of a given stock
 * @pricesSize: The size of the prices int array
 * Return: The maximum profit one can achieve
 */
int profitMaximization(int* prices, int pricesSize) 
{
    int maxProfit = 0;
    int difference = 0;

    for (int i = 1; i < pricesSize; i++) 
    {
        difference = prices[i] - prices[i - 1];
        if (difference > 0) 
	{
            maxProfit += difference;
        }
    }
    return maxProfit;
}

int main() 
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    int output = profitMaximization(prices, n);
    printf("Maximum Profit: %i\n", output);
    return 0;
}
