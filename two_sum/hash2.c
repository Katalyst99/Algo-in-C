#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

/**
 * hashTwoSum - Finds all unique pairs of nums that add up to the target sum.
 * arr: The array
 * size: The size
 * target: The target sum
 * Return: all pairs in a nested array.
 */
void hashTwoSum(int arr[], int size, int target) 
{
	int hashMap[MAX_SIZE] = {0};
	int i;
	int comp = 0;

	printf("Pairs with the target sum %d:\n", target);
	for (i = 0; i < size; i++) 
	{
		comp = target - arr[i];
		if (hashMap[comp + MAX_SIZE / 2]) 
		{
			printf("[%i, %i]\n", arr[i], comp);
		}
		hashMap[arr[i] + MAX_SIZE / 2] = 1;
	}
}

int main() {
    int arr[] = {3, 5, 2, -4, 8, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    hashTwoSum(arr, size, target);
    return 0;
}
