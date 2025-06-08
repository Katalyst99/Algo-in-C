#include <stdio.h>
#include <stdlib.h>

// Helper to determine the maximum of 2 integers
int max(int a, int b) 
{
	return a > b ? a : b;
}

/**
 * sweet - Function that uses a two-pass approach to give sweets to children based on their ratings.
 * @ratings: The ratings of the children
 * @rSize: The size of the ratings
 * Return: The minimum total
 */
int sweet(int* ratings, int rSize) 
{
	int* sweets;
	int i, total;

	sweets = (int*)malloc(sizeof(int) * rSize);
	for (i = 0; i < rSize; i++)
	{
		sweets[i] = 1;
	}
	for (i = 1; i < rSize; i++) 
	{
		if (ratings[i] > ratings[i - 1]) 
		{
			sweets[i] = sweets[i - 1] + 1;
		}
	}
	for (i = rSize - 2; i >= 0; i--) 
	{
		if (ratings[i] > ratings[i + 1]) 
		{
			sweets[i] = max(sweets[i], sweets[i + 1] + 1);
		}
	}

	total = 0;
	for (i = 0; i < rSize; i++) 
	{
		total += sweets[i];
	}
	free(sweets);
	return total;
}

int main() 
{
    int ratings[] = {1, 0, 2};
    int n = sizeof(ratings) / sizeof(ratings[0]);
    int output = sweet(ratings, n);
    printf("Minimum sweets needed: %i\n", output);
    return 0;
}

