#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

/**
 * partition - Function to partition list
 * @head: The head of the linked list
 * @x: The value
 * Return: The modified List
 */
Node* partition(Node* head, int x)
{
    Node smallHead = {0, NULL}, bigHead = {0, NULL};
    Node *small = &smallHead, *big = &bigHead;

    while (head) 
    {
        if (head->val < x) 
	{
            small->next = head;
            small = small->next;
        }
	else 
	{
            big->next = head;
            big = big->next;
        }
        head = head->next;
    }
    small->next = bigHead.next;
    big->next = NULL;

    return smallHead.next;
}

// Helper function to create new node
Node* newNode(int val) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print linked list
void printList(Node* head) 
{
    while (head) 
    {
        printf("%i -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void) 
{
    Node* head = newNode(1);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(5);
    head->next->next->next->next->next = newNode(2);

    printf("Original List: ");
    printList(head);

    int x = 3;
    head = partition(head, x);

    printf("Partitioned List: ");
    printList(head);

    return 0;
}
