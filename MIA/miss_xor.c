#include <stdio.h>

/**
 * miaSum - Finds the missing number in an array of integers
 * @arr: The array of size n - 1
 * @n: The max value in the range
 * Return: The missing element
 */
int miaXor(int arr[], int n) 
{
	int xorAll = 0;
	int xorArr = 0;
	int i;

	for (i = 1; i <= n; i++) 
	{
		xorAll ^= i;
	}
	for (i = 0; i < n - 1; i++) 
	{
		xorArr ^= arr[i];
	}
	return xorAll ^ xorArr;
}

int main() 
{
	int arr[] = {1, 2, 4, 5, 6};
	int n = 6;

	int mia = miaXor(arr, n);
	printf("Missing number (Sum): %i\n", mia);
	return 0;
}
