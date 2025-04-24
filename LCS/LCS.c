#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Chained hash‐set for integers

typedef struct Node {
    int key;
    struct Node *next;
} Node;

typedef struct {
    size_t capacity;
    Node **buckets;
} HashSet;

/**
 * plantHash - Allocates and initialize a hash set with a given capacity
 * @capacity: The number of buckets
 * Return: The hash set
 */
HashSet *plantHash(size_t capacity) 
{
    HashSet *set = malloc(sizeof(HashSet));
    set->capacity = capacity;
    set->buckets = calloc(capacity, sizeof(Node *));
    return set;
}

// Frees all the memory used by the hash set.
void freeHash(HashSet *set) 
{
    for (size_t i = 0; i < set->capacity; i++) 
    {
        Node *current = set->buckets[i];
        while (current) 
	{
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(set->buckets);
    free(set);
}

// Simple hash function that handles negative numbers for int keys.
static size_t hsHash(HashSet *set, int key) 
{
    unsigned int u = (unsigned int)key;
    return (u ^ (u >> 16)) % set->capacity;
}

// Returns true if the key is in the set
bool storesHash(HashSet *set, int key) 
{
    size_t idx = hsHash(set, key);
    for (Node *current = set->buckets[idx]; current; current = current->next) 
    {
        if (current->key == key) return true;
    }
    return false;
}

// Inserts key into set, if not already present.
void hsAdd(HashSet *set, int key) 
{
    if (storesHash(set, key)) return;
    size_t idx = hsHash(set, key);
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->next = set->buckets[idx];
    set->buckets[idx] = node;
}

/**
 * longestConsecSeq - Function for the length of the longest consecutive sequence
 * @nums: The unsorted array of ints
 * @numSize: The size of nums
 * Return: The length of the longest consecutive sequence
 */
int longestConsecSeq(int *nums, int numSize) 
{
    if (numSize == 0) return 0;

    HashSet *set = plantHash(numSize * 2 + 1);
    for (int i = 0; i < numSize; i++) 
    {
        hsAdd(set, nums[i]);
    }

    int longest = 0;
    for (int i = 0; i < numSize; i++) 
    {
        int n = nums[i];
        if (!storesHash(set, n - 1)) 
	{
            int len = 1;
            int current = n;
            while (storesHash(set, current + 1)) 
	    {
                current++;
                len++;
            }
            if (len > longest)
		    longest = len;
        }
    }

    freeHash(set);
    return longest;
}

int main() 
{
    int nums1[] = {100, 4, 200, 1, 3, 2};
    printf("Longest run in [100,4,200,1,3,2]: %i\n",
           longestConsecSeq(nums1, sizeof(nums1)/sizeof(nums1[0])));

    int nums2[] = {};
    printf("Longest run in []: %i\n",
           longestConsecSeq(nums2, 0));

    int nums3[] = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    printf("Longest run in [9,1,4,7,3,-1,0,5,8,-1,6]: %d\n",
           longestConsecSeq(nums3, sizeof(nums3)/sizeof(nums3[0])));
    return 0;
}
