#include <stdio.h>

/**
 * searchInsert - Finds the index to insert a target value in a sorted array.
 * @nums: The sorted array
 * @size: The size of array
 * @target: The target value
 * Return: The index if target is found, else the index where it would be if inserted.
 */

int searchInsert(int nums[], int size, int target) 
{
    int L = 0, R = size - 1, mid;

    while (L <= R) 
    {
        mid = (L + R) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            L = mid + 1;
        else
            R = mid - 1;
    }

    return L;
}

int main() 
{
    int nums[] = {1, 3, 5, 6};
    int size = sizeof(nums) / sizeof(nums[0]);

    int target1 = 5;
    printf("Insert position of %i: %d\n", target1, searchInsert(nums, size, target1)); // Output: 2

    int target2 = 2;
    printf("Insert position of %i: %d\n", target2, searchInsert(nums, size, target2)); // Output: 1

    int target3 = 7;
    printf("Insert position of %i: %d\n", target3, searchInsert(nums, size, target3)); // Output: 4

    int target4 = 0;
    printf("Insert position of %i: %d\n", target4, searchInsert(nums, size, target4)); // Output: 0

    return 0;
}
