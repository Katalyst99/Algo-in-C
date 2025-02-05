#include <stdio.h>

int searchRotatedSorted(int nums[], int n, int target) 
{
    int L = 0, R = n - 1;

    while (L <= R) 
    {
        int mid = L + (R - L) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[L] <= nums[mid]) 
	{
            if (nums[L] <= target && target < nums[mid])
                R = mid - 1;
            else
                L = mid + 1;
        }
        else 
	{
            if (nums[mid] < target && target <= nums[R])
                L = mid + 1;
            else
                R = mid - 1;
        }
    }

    return -1;
}

int main() 
{
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int n = sizeof(nums) / sizeof(nums[0]);

    int i = searchRotatedSorted(nums, n, target);
    
    if (i != -1)
        printf("Target %i found at index %i\n", target, i);
    else
        printf("Target %i not found in array\n", target);

    return 0;
}
