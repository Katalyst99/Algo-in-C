#include <stdio.h>

/**
 * maxArea - Forms a container with the max amount of water that can be stored.
 * @height: The integer array
 * @n: The length of the integer array
 * Return: Maximum amount of water a container can store
 */

int maxArea(int height[], int n) 
{
    int L = 0, R = n - 1;
    int maxWater = 0;

    while (L < R) 
    {
        int width = R - L;
        int minHeight = (height[L] < height[R]) ? height[L] : height[R];
        int water = width * minHeight;

        if (water > maxWater) 
	{
            maxWater = water;
        }

        if (height[L] < height[R]) 
	{
           L++;
        } else 
	{
            R--;
        }
    }

    return maxWater;
}

int main() 
{
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height) / sizeof(height[0]);

    printf("Maximum water stored: %i\n", maxArea(height, n));

    return 0;
}

