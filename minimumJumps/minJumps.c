#include <stdio.h>
#include <limits.h>

/**
 * minJumps - Finds the min number of jumps needed to reach end of array.
 * @array: The integer array.
 * @n: The size of the array
 * Return: -1, if end of array can not be reached.
 */
int minJumps(int arr[], int n) 
{
    if (n <= 1)
	    return 0;
    if (arr[0] == 0)
	    return -1;

    int jumps = 1;
    int maxReach = arr[0];
    int step = arr[0];

    for (int i = 1; i < n; i++) 
    {
        if (i == n - 1)
		return jumps;

        maxReach = (i + arr[i] > maxReach) ? i + arr[i] : maxReach;

        if (i == step) 
	{
            jumps++;
            step = maxReach;
            if (step <= i)
		    return -1;
        }
    }
    return -1;
}

int main() 
{
    int arr[] = {2, 3, 1, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum jumps required: %i\n", minJumps(arr, n));
    return 0;
}
