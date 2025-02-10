#include <stdio.h>

void spiral(int matrix[][4], int m, int n) 
{
    int top = 0, btm = m - 1, L = 0, R = n - 1;
    
    while (top <= btm && L <= R) 
    {
        for (int i = L; i <= R; i++)
            printf("%i ", matrix[top][i]);
        top++;
        
        for (int i = top; i <= btm; i++)
            printf("%d ", matrix[i][R]);
        R--;

        if (top <= btm) 
	{
            for (int i = R; i >= L; i--)
                printf("%i ", matrix[btm][i]);
            btm--;
        }

        if (L <= R) 
	{
            for (int i = btm; i >= top; i--)
                printf("%d ", matrix[i][L]);
            L++;
        }
    }
}

int main() 
{
    int matrix[3][4] = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };

    printf("Spiral Order: ");
    spiral(matrix, 3, 4);
    printf("\n");

    return 0;
}
