#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Function to merge two sorted linked lists
Node* mergeTwoLists(Node* l1, Node* l2) 
{
    if (!l1) return l2;
    if (!l2) return l1;
    
    if (l1->val < l2->val) 
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Divide and conquer approach to merge k sorted lists
Node* mergeKLists(Node** lists, int left, int right) 
{
    if (left > right) return NULL;
    if (left == right) return lists[left];
    
    int mid = left + (right - left) / 2;
    Node* leftMerged = mergeKLists(lists, left, mid);
    Node* rightMerged = mergeKLists(lists, mid + 1, right);
    
    return mergeTwoLists(leftMerged, rightMerged);
}

// Helper function to create a linked list from an array
Node* createLinkedList(int* arr, int size) 
{
    Node* dummy = (Node*)malloc(sizeof(Node));
    Node* current = dummy;
    for (int i = 0; i < size; i++) 
    {
        current->next = (Node*)malloc(sizeof(Node));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printList(Node* head) 
{
    while (head) {
        printf("%i -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() 
{
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};

    Node* lists[3];
    lists[0] = createLinkedList(arr1, 3);
    lists[1] = createLinkedList(arr2, 3);
    lists[2] = createLinkedList(arr3, 2);

    printf("Merged List:\n");
    Node* merged_head = mergeKLists(lists, 0, 2);
    printList(merged_head);

    return 0;
}
