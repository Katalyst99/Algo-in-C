#include <stdio.h>

/**
 * bruteTwoSum - Finds all unique pairs of nums that add up to the target sum.
 * arr: The array
 * size: The size
 * target: The target sum
 * Return: all pairs in a nested array.
 */
void bruteTwoSum(int arr[], int size, int target)
{
    printf("Pairs with the target sum %d:\n", target);

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("[%d, %d]\n", arr[i], arr[j]);
            }
        }
    }
}

int main()
{
    int arr[] = {3, 5, 2, -4, 8, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    bruteTwoSum(arr, size, target);
    return 0;
}
