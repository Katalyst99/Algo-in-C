#include <stdio.h>

/**
 * majorElement - Identify an element that appears more than N/2 times.
 * @arr: The array
 * @n: The size of the array
 * Return: Major element, if not return -1.
 */
int majorElement(int arr[], int n) 
{
	int i, count = 0;
	int candidate = -1;

	for (i = 0; i < n; i++) 
	{
		if (count == 0) 
		{
			candidate = arr[i];
			count = 1;
		}
		else if (arr[i] == candidate) 
		{
			count++;
		}
		else 
		{
			count --;
		}
	}
	count = 0;
	for (i = 0; i < n; i++) 
	{
		if (arr[i] == candidate) 
		{
			count++;
		}
	}
	if (count > n / 2)
		return candidate;
	return -1;
}

int main() 
{
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int output = majorElement(arr, n);
    if (output != -1) {
        printf("The majority element is: %i\n", output);
    } else {
        printf("No majority element found.\n");
    }

    return 0;
}
