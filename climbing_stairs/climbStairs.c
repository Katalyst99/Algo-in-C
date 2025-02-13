#include <stdio.h>

/**
 * climbStairs - Calculates the number of ways to climb the stairs
 * @n: The number of ways
 * Return: The number of distinct ways to climb
 */

int climbStairs(int n) 
{
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    int prev2 = 1;
    int prev1 = 2;
    int current = 0;
    
    for (int i = 3; i <= n; i++) 
    {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int main() 
{
    int n;
    printf("Enter the number of steps: ");
    scanf("%d", &n);

    int ways = climbStairs(n);
    printf("Number of distinct ways to climb %i steps: %i\n", n, ways);
    
    return 0;
}
