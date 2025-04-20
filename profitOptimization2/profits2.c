#include <stdio.h>
#include <limits.h>

/**
 * profitMaximization - Compute max profit with at most two transactions.
 * @prices: The prices of a given stock
 * @pricesSize: The size of the prices int array
 * Return: The best total profit after the second sell
 */
int profitMaximization(int* prices, int pricesSize) 
{
    int i;
    int cost1st = INT_MAX;
    int profit1st = 0;
    int cost2nd = INT_MAX;
    int profit2nd = 0;
    int price = 0;

    for (i = 0; i < pricesSize; i++) 
    {
        price = prices[i];
        if (price < cost1st) 
            cost1st = price;
        if (price - cost1st > profit1st) 
            profit1st = price - cost1st;

        if (price - profit1st < cost2nd) 
            cost2nd = price - profit1st;
        if (price - cost2nd > profit2nd) 
            profit2nd = price - cost2nd;
    }
    return profit2nd;
}

int main() 
{
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    int output = profitMaximization(prices, n);
    printf("Maximum profit with up to two transactions: %i\n", output);
    return 0;
}
