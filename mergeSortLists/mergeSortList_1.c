#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Min-Heap structure
typedef struct {
    Node** arr;
    int size;
} MinHeap;

// Function to swap two nodes in the heap
void swap(Node** a, Node** b) 
{
    Node* tmp = *a;
    *a = *b;
    *b = tmp;
}

// Function to maintain heap property
void heapify(MinHeap* heap, int i) 
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left]->val < heap->arr[smallest]->val)
        smallest = left;
    if (right < heap->size && heap->arr[right]->val < heap->arr[smallest]->val)
        smallest = right;

    if (smallest != i) 
    {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapify(heap, smallest);
    }
}

// Extract the minimum element from the heap
Node* extractMin(MinHeap* heap) 
{
    if (heap->size == 0)
        return NULL;
    
    Node* root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    
    return root;
}

// Inserts a node into the heap
void insertHeap(MinHeap* heap, Node* node) 
{
    if (!node) return;
    
    heap->size++;
    int i = heap->size - 1;
    heap->arr[i] = node;

    while (i > 0 && heap->arr[(i - 1) / 2]->val > heap->arr[i]->val) 
    {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

/**
 * mergeKLists - Function to merge K sorted linked lists
 * @lists: An array of k linked lists
 * @k: The size
 * Return: Merged linked lists into 1 sorted linked list
 */
Node* mergeKLists(Node** lists, int k) 
{
    MinHeap heap;
    heap.size = 0;
    heap.arr = (Node**)malloc(k * sizeof(Node*));

    for (int i = 0; i < k; i++) 
    {
        if (lists[i])
            insertHeap(&heap, lists[i]);
    }

    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->next = NULL;
    Node* current = dummy;

    while (heap.size > 0) 
    {
        Node* smallest = extractMin(&heap);
        current->next = smallest;
        current = current->next;

        if (smallest->next)
            insertHeap(&heap, smallest->next);
    }
    free(heap.arr);
    return dummy->next;
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
    while (head) 
    {
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
    Node* merged_head = mergeKLists(lists, 3);
    printList(merged_head);

    return 0;
}
