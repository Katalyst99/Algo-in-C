#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int val;
    struct Node *left;
    struct Node *right;
};

// Global variables to store swapped nodes
struct Node *first = NULL, *second = NULL, *prev = NULL;

// Inorder traversal to find swapped nodes
void inorder(struct Node* root) 
{
    if (!root) return;

    inorder(root->left);

    if (prev && root->val < prev->val) 
    {
        if (!first) first = prev;
        second = root;
    }
    prev = root;

    inorder(root->right);
}

/**
 * recoverBST - Function to recover BST by swapping two nodes
 * @root: The root
 */
void recoverBST(struct Node* root) 
{
    first = second = prev = NULL;
    inorder(root);
    if (first && second) 
    {
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
}

// Helper function to create a new tree node
struct Node* new(int value) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = value;
    node->left = node->right = NULL;
    return node;
}

// Helper function to print inorder traversal
void printInorder(struct Node* root) 
{
    if (!root) return;
    printInorder(root->left);
    printf("%i ", root->val);
    printInorder(root->right);
}

int main() 
{
    struct Node* root = new(3);
    root->left = new(1);
    root->right = new(4);
    root->right->left = new(2);

    printf("Before recovery: ");
    printInorder(root);
    printf("\n");

    recoverBST(root);

    printf("After recovery: ");
    printInorder(root);
    printf("\n");

    return 0;
}
