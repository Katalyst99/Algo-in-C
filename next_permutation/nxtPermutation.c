#include <stdio.h>

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse a part of the array
void reverse(int nums[], int start, int end) 
{
    while (start < end) 
    {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

// Function to find the next permutation
void nextPermutation(int nums[], int n) {
    int i = n - 2;

    while (i >= 0 && nums[i] >= nums[i + 1]) 
    {
        i--;
    }

    if (i >= 0) 
    {
        int j = n - 1;
        while (nums[j] <= nums[i]) 
	{
            j--;
        }
        swap(&nums[i], &nums[j]);
    }
    reverse(nums, i + 1, n - 1);
}

// Function to print the array
void printArray(int nums[], int n) 
{
    for (int i = 0; i < n; i++) {
        printf("%i ", nums[i]);
    }
    printf("\n");
}

int main() 
{
    int arr[] = {1, 3, 5, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    nextPermutation(arr, n);

    printf("Next Permutation: ");
    printArray(arr, n);

    return 0;
}
