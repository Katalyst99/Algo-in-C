#include <stdio.h>
#include <stdlib.h>

// Calculates factorial
int factorial(int n) 
{
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

/**
 * getPermutation - Generates the k-th permutation
 * @n: The total number of digits
 * @k: The desired index of the permutation sequence
 * Return: The k-th permutation
 */
void getPermutation(int n, int k, char *output) 
{
    int f = factorial(n);
    int nums[n];
    
    for (int i = 0; i < n; i++) 
    {
        nums[i] = i + 1;
    }
    k--;
    int pos = 0;
    
    for (int i = n; i > 0; i--) 
    {
        f /= i;
        int index = k / f;
        output[pos++] = nums[index] + '0';

        for (int j = index; j < n - 1; j++) 
	{
            nums[j] = nums[j + 1];
        }

        k %= f;
    }
    output[pos] = '\0';
}

int main() 
{
    int n = 3, k = 4;
    char output[10];

    getPermutation(n, k, output);
    printf("The %i-th permutation of %d numbers is: %s\n", k, n, output);

    return 0;
}
