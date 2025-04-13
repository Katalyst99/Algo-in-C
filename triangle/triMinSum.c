#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * triMinSum - Computes the minimum path sum in a triangle array
 * @triangle: The triangle array
 * @triSize: The size of the the triangle array
 * @triColumnSize: The size of the the triangle column
 * Return: The minimum path sum
 */
int triMinSum(int** triangle, int triSize, int* triColumnSize) 
{
    int x = 0;
    int y = 0;
    int output = 0;

    int* dp = (int*)malloc(triColumnSize[triSize - 1] * sizeof(int));
    memcpy(dp, triangle[triSize - 1], triColumnSize[triSize - 1] * sizeof(int));

    for (x = triSize - 2; x >= 0; x--) 
    {
        for (y = 0; y < triColumnSize[x]; y++) 
	{
            dp[y] = triangle[x][y] + (dp[y] < dp[y + 1] ? dp[y] : dp[y + 1]);
        }
    }

    output  = dp[0];
    free(dp);
    return output;
}

int main() 
{
    int n;
    printf("Enter number of rows in triangle: ");
    scanf("%i", &n);

    int** triangle = (int**)malloc(n * sizeof(int*));
    int* triColumnSize = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) 
    {
        triColumnSize[i] = i + 1;
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        printf("Enter %i numbers for row %d: ", i + 1, i + 1);
        for (int j = 0; j <= i; j++) 
	{
            scanf("%d", &triangle[i][j]);
        }
    }

    int output = triMinSum(triangle, n, triColumnSize);
    printf("Minimum path sum from top to bottom: %i\n", output);

    for (int i = 0; i < n; i++) 
    {
        free(triangle[i]);
    }
    free(triangle);
    free(triColumnSize);

    return 0;
}
