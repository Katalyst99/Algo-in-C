#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node* next;
};

/**
 * findRemoveLoop - Detects and remove a loop in the linked list
 * @head: The head of the linked list
 */
void findRemoveLoop(struct Node* head) 
{
    struct Node *slow = head, *fast = head;

    while (fast && fast->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
	{
            break;
        }
    }

    if (!fast || !fast->next) return;

    slow = head;
    while (slow != fast) 
    {
        slow = slow->next;
        fast = fast->next;
    }

    while (fast->next != slow) 
    {
        fast = fast->next;
    }
    fast->next = NULL;
}

/**
 * printList - print the linked list
 * @head: The head of the node
 */
void printList(struct Node* head) 
{
    struct Node* tmp = head;
    while (tmp) 
    {
        printf("%i -> ", tmp->val);
        tmp = tmp->next;
    }
    printf("NULL\n");
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

    findRemoveLoop(head);

    printList(head);

    return 0;
}
