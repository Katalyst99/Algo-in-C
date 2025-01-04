#include <stdio.h>

/**
 * peak - Finds the peak element or elements
 * @arr: The array
 * @n: The size
 * Return: The index of any one of its peak elements.
 */
int peak(int arr[], int n) 
{
    int low = 0, high = n - 1;
    int mid = 0;

    while (low <= high) 
    {
        mid = (low + high) / 2;

        if ((mid == 0 || arr[mid] >= arr[mid - 1]) &&
            (mid == n - 1 || arr[mid] >= arr[mid + 1])) 
	{
            return mid;
        }

        if (mid > 0 && arr[mid - 1] > arr[mid]) 
	{
            high = mid - 1;
        } 
	else 
	{
            low = mid + 1;
        }
    }

    return -1;
}

int main() 
{
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int idx = peak(arr, n);
    printf("Peak element is at index: %i with value: %i\n", idx, arr[idx]);
    return 0;
}
