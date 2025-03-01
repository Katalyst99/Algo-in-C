#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

/**
 * detectLoop - Function to detect a loop in a linked list
 * @head: The head of the linked list
 * Return: 1, If linked list contains loop, else return 0
 */
int detectLoop(struct Node* head) 
{
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) 
	{
            return 1;
        }
    }
    return 0;
}

// Function to create a new node
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

    head->next->next->next->next->next = head->next->next;

    if (detectLoop(head)) 
    {
        printf("Loop detected!\n");
    }
    else 
    {
        printf("No loop detected.\n");
    }

    return 0;
}
