#include <stdio.h>

/**
 * rotate - function to rotate the matrix by 90 degrees clockwise
 * @matrix: The 2D matrix
 * @n: The size
 * Return: The rotated matrix
 */

void rotate(int matrix[][3], int n) 
{
    for (int x = 0; x < n; x++) 
    {
        for (int y = x + 1; y < n; y++) 
	{
            int temp = matrix[x][y];
            matrix[x][y] = matrix[y][x];
            matrix[y][x] = temp;
        }
    }

    for (int x = 0; x < n; x++) 
    {
        for (int y = 0, z = n - 1; y < z; y++, z--) 
	{
            int temp = matrix[x][y];
            matrix[x][y] = matrix[x][z];
            matrix[x][z] = temp;
        }
    }
}

/**
 * printMatrix - Function to print the matrix
 * @matrix: The matrix
 * @n: The size
 * Return: The printed matrix
 */

void printMatrix(int matrix[][3], int n) 
{
    for (int x = 0; x < n; x++) 
    {
        for (int y = 0; y < n; y++) 
	{
            printf("%i ", matrix[x][y]);
        }
        printf("\n");
    }
}

int main() 
{
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix, 3);

    rotate(matrix, 3);

    printf("\nRotated Matrix:\n");
    printMatrix(matrix, 3);

    return 0;
}
