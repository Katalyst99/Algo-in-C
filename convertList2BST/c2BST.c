#include <stdio.h>
#include <stdlib.h>

// Singly-linked list.
typedef struct listNode {
    int val;
    struct listNode* next;
} listNode;

// A binary tree node.
typedef struct tNode {
    int val;
    struct tNode* left;
    struct tNode* right;
} tNode;

// Creates a new tree node
tNode* new_tNode(int val) 
{
    tNode* node = (tNode*)malloc(sizeof(tNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Determine the middle node of a linked list
listNode* findMid(listNode* head, listNode** prev) 
{
    listNode* slow = head;
    listNode* fast = head;
    *prev = NULL;

    while (fast && fast->next) 
    {
        *prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Recursive function to convert sorted list to BST
tNode* sortList2BST(listNode* head) 
{
    if (!head) return NULL;

    listNode* prev = NULL;
    listNode* mid = findMid(head, &prev);

    tNode* root = new_tNode(mid->val);
    if (head == mid)
        return root;

    if (prev)
        prev->next = NULL;

    root->left = sortList2BST(head);
    root->right = sortList2BST(mid->next);
    return root;
}

// Helper function to create new ListNode
listNode* newListNode(int val) 
{
    listNode* node = (listNode*)malloc(sizeof(listNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to print inorder traversal of tree
void inorderTraversal(tNode* root) 
{
    if (root) 
    {
        inorderTraversal(root->left);
        printf("%i ", root->val);
        inorderTraversal(root->right);
    }
}

int main() 
{
    listNode* head = newListNode(-10);
    head->next = newListNode(-3);
    head->next->next = newListNode(0);
    head->next->next->next = newListNode(5);
    head->next->next->next->next = newListNode(9);

    tNode* root = sortList2BST(head);

    printf("Inorder Traversal of BST:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
