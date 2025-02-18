#include <stdio.h>
#include <stdlib.h>

/**
 * combine - Recursive function to generate combinations
 * @start: The index to begin the search
 * @pos: The current position
 * @m: The size of each combination
 * @n: The range of numbers
 * @combination: Array holding the current combination.
 * Return: All possible combinations.
 */
void combine(int start, int pos, int m, int n, int *combination) {
    if (pos == m) 
    {
        for (int i = 0; i < m; i++) 
	{
            printf("%i ", combination[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i < n; i++) 
    {
        combination[pos] = i;
        combine(i + 1, pos + 1, m, n, combination);
    }
}

int main() 
{
    int m, n;

    printf("Enter size of combination (m): ");
    scanf("%i", &m);
    printf("Enter range (n): ");
    scanf("%i", &n);

    if (m > n || m <= 0 || n <= 0) 
    {
        printf("Invalid input! m should be <= n and both should be > 0.\n");
        return 1;
    }

    int *combination = (int *)malloc(m * sizeof(int));
    if (combination == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    combine(0, 0, m, n, combination);
    free(combination);
    return 0;
}
