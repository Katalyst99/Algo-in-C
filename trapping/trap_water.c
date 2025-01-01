#include <stdio.h>

/**
 * trappingWater - Computes how much water can be trapped between the blocks.
 * @arr: The array
 * @n: The size
 * Return: The amount of water that can be trapped between the blocks.
 */
int trappingWater(int arr[], int n) 
{
    int left = 0, right = n - 1;
    int maxL = 0, maxR = 0;
    int water = 0;

    while (left <= right) 
    {
        if (arr[left] < arr[right]) 
	{
            if (arr[left] >= maxL) 
	    {
                maxL = arr[left];
            }
	    else 
	    {
                water += maxL - arr[left];
            }
            left++;
        } else {
            if (arr[right] >= maxR) 
	    {
                maxR = arr[right];
            } 
	    else 
	    {
                water += maxR - arr[right];
            }
            right--;
        }
    }

    return water;
}

int main() 
{
    int arr[] = {3, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Water trapped: %i\n", trappingWater(arr, n));

    return 0;
}
