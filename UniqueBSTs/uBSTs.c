#include <stdio.h>

// Function to compute factorial
long long factorial(int num) 
{
    long long output = 1;
    for (int i = 2; i <= num; i++)
        output *= i;
    return output;
}

/**
 * uniqueBSTs - computes Catalan number directly
 * @n: The unique integer value
 * Return: The number of structurally unique BSTs
 */
int uniqueBSTs(int n) 
{
    return factorial(2 * n) / (factorial(n + 1) * factorial(n));
}

int main() 
{
    int n = 3;
    printf("Number of unique BSTs for n = %i: %i\n", n, uniqueBSTs(n));
    return 0;
}
