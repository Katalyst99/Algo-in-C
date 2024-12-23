#include <stdio.h>

/**
 * printArray - Helper function
 * @arr: The array
 * @n: The size of the array
 * Return: numbers in the array
 */
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

/**
 * sort012 - sorts an array of 0s, 1s, and 2s in ascending order
 * @arr: The array
 * @n: The size of the array
 * Return: sorted array
 */
void sort012(int arr[], int n) 
{
	int low = 0;
	int mid = 0;
	int high = n - 1;

	while (mid <= high) 
	{
		if (arr[mid] == 0) 
		{
            	int temp = arr[low];
            	arr[low] = arr[mid];
           	 arr[mid] = temp;
            	low++;
            	mid++;
        	} 
		else if (arr[mid] == 1) 
		{
            	mid++;
        	} else 
		{
            	int temp = arr[mid];
            	arr[mid] = arr[high];
            	arr[high] = temp;
		high--;
        	}
	}
}

int main() 
{
    int arr[] = {2, 0, 1, 2, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    sort012(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}
