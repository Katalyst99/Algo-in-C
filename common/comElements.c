#include <stdio.h>

/**
 * elementsCommon - Finds th elements that are common in 3 arrays.
 * @A: First sorted array
 * @n1: The size of array A
 * @B: Second sorted array
 * @n2: The size of array B
 * @C: Third sorted array
 * @n3: The size of array C
 * Return: An array containing the common element in all 3 arrays
 */
void elementsCommon(int A[], int n1, int B[], int n2, int C[], int n3) 
{
    int x = 0, y = 0, z = 0;
    int prev = -1;

    while (x < n1 && y < n2 && z < n3) 
    {
        if (A[x] == B[y] && B[y] == C[z]) {
            if (prev != A[x]) 
	    {
                printf("%i ", A[x]);
                prev = A[x];
            }
            x++;
            y++;
            z++;
        }

        else if (A[x] < B[y]) {
            x++;
        } else if (B[y] < C[z]) {
            y++;
        } else {
            z++;
        }
    }
}

int main() 
{
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int n1 = sizeof(A) / sizeof(A[0]);
    int n2 = sizeof(B) / sizeof(B[0]);
    int n3 = sizeof(C) / sizeof(C[0]);

    printf("Common Elements: ");
    elementsCommon(A, n1, B, n2, C, n3);
    printf("\n");

    return 0;
}
