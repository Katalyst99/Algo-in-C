#include <stdio.h>
#include <limits.h> // For INT_MIN

/**
 * maxSubArrSum - uses Kadane's algo to find the contiguous sub-array which has max sum.
 * @arr - The array
 * @n: The number of integers
 * Return: The sum of subarray with max sum
 */
int maxSubArrSum(int arr[], int n) 
{
	int current = 0;
	int max = INT_MIN;
	int i;

	for (i = 0; i < n; i++) 
	{
		current += arr[i];
		if (current > max)
			max = current;
		if (current < 0)
			current = 0;
	}
	return max;
}

int main() 
{
	int arr[] = {1, -2, 3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	int output = maxSubArrSum(arr, n);
	printf("Maximum sum of contiguous subarray: %i\n", output);
	return 0;
}
