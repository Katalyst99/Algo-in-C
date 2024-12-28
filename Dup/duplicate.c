#include <stdio.h>
#include <stdlib.h>

/**
 * dups - Finds duplicates in an array
 * @arr: The array
 * @n: The size of the array
 * @result_size: The resultant size
 * Return: List of elements in ascending order.
 */
int* dups(int arr[], int n, int* result_size) 
{
    int* freq = (int*)calloc(n, sizeof(int));
    if (freq == NULL) 
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] < 0 || arr[i] >= n) 
	{
            printf("Error: Element %i at index %i is out of range [0, %i)\n", arr[i], i, n);
            free(freq);
            *result_size = -1;
            return NULL;
        }
        freq[arr[i]]++;
    }

    int* duplicates = (int*)malloc(n * sizeof(int));
    int dup_count = 0;

    for (int i = 0; i < n; i++) 
    {
        if (freq[i] > 1) 
	{
            duplicates[dup_count++] = i;
        }
    }
    free(freq);
    if (dup_count == 0) 
    {
        duplicates[0] = -1;
        dup_count = 1;
    }

    *result_size = dup_count;
    return duplicates;
}

int main() {
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result_size = 0;
    int* output = dups(arr, n, &result_size);

    if (result_size == -1) 
    {
        return EXIT_FAILURE;
    }
    printf("Duplicates: ");
    for (int i = 0; i < result_size; i++) 
    {
        printf("%i ", output[i]);
    }
    printf("\n");
    free(output);
    return EXIT_SUCCESS;
}
