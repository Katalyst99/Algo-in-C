#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node *next;
};

/**
 * removeNthFromEnd - Function to remove nth node from end of list
 * @head: The head of a linked list
 * @n: The length of the list
 * Return: Its head
 */
struct Node* removeNthFromEnd(struct Node* head, int n) 
{
    struct Node *fast = head, *slow = head;
    
    for (int i = 0; i < n; i++) 
    {
        fast = fast->next;
    }

    if (fast == NULL) 
    {
        struct Node* tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }

    while (fast->next != NULL) 
    {
        fast = fast->next;
        slow = slow->next;
    }

    struct Node* tmp = slow->next;
    slow->next = slow->next->next;
    free(tmp);
    return head;
}

// Helper function to print the list
void printList(struct Node *head) 
{
    while (head != NULL) 
    {
        printf("%i -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// A Function to create a new node
struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() 
{
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original List: ");
    printList(head);

    int n = 2;
    head = removeNthFromEnd(head, n);

    printf("Modified List: ");
    printList(head);

    return 0;
}
