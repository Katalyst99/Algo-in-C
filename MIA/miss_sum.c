#include <stdio.h>

/**
 * miaSum - Finds the missing number in an array of integers
 * @arr: The array of size n - 1
 * @n: The max value in the range
 * Return: The missing element
 */
int miaSum(int arr[], int n) 
{
	int total = n * (n + 1) / 2;
	int i, actual = 0;

	for (i = 0; i < n - 1; i++) 
	{
		actual += arr[i];
	}
	return total - actual;
}

int main() 
{
	int arr[] = {1, 2, 4, 5, 6};
	int n = 6;

	int mia = miaSum(arr, n);
	printf("Missing number (Sum): %i\n", mia);
	return 0;
}
