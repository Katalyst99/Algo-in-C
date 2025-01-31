#include <stdio.h>
#include <math.h>

/**
 * findMedianSortedArrays - determines the median of two sorted arrays.
 * @nums1: The first array
 * @nums2: The second array
 * @m: The size of first array
 * @n: The size of second array
 * Return: The median of the 2 sorted arrays.
 */

double findMedianSortedArrays(int nums1[], int m, int nums2[], int n) {
    if (m > n) 
    {
	    return findMedianSortedArrays(nums2, n, nums1, m);
    }

    int low = 0, high = m;
    while (low <= high) 
    {
        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;

        int maxLX = (partitionX == 0) ? -1000000 : nums1[partitionX - 1];
        int minRX = (partitionX == m) ? 1000000 : nums1[partitionX];

        int maxLY = (partitionY == 0) ? -1000000 : nums2[partitionY - 1];
        int minRY = (partitionY == n) ? 1000000 : nums2[partitionY];

        if (maxLX <= minRY && maxLY <= minRX) 
	{
            if ((m + n) % 2 == 0)
                return (double)(fmax(maxLX, maxLY) + fmin(minRX, minRY)) / 2.0;
            else
                return (double)fmax(maxLX, maxLY);
        } else if (maxLX > minRY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    return 0.0;
}

int main() 
{
    int nums1[] = {1, 3};
    int nums2[] = {2};
    int m = sizeof(nums1) / sizeof(nums1[0]);
    int n = sizeof(nums2) / sizeof(nums2[0]);

    printf("%.5f\n", findMedianSortedArrays(nums1, m, nums2, n));
    return 0;
}
