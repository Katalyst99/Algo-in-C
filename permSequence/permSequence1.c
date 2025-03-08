#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Calculates factorial
int factorial(int n) 
{
    int f = 1;
    for (int i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

// Recursive function to find k-th permutation
void findPermutation(int n, int k, bool used[], char *output, int *pos) 
{
    if (n == 0) return;

    int f = factorial(n - 1);
    int index = (k - 1) / f;

    int count = -1;
    for (int i = 1; i <= 9; i++) 
    {
        if (!used[i]) 
	{
            count++;
            if (count == index) 
	    {
                used[i] = true;
                output[(*pos)++] = i + '0';
                findPermutation(n - 1, k - index * f, used, output, pos);
                return;
            }
        }
    }
}

// Wrapper function
void getPermutation(int n, int k, char *output) 
{
    bool used[10] = {false};
    int pos = 0;
    findPermutation(n, k, used, output, &pos);
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
