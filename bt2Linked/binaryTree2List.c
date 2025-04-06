#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct tNode {
    int val;
    struct tNode* left;
    struct tNode* right;
} tNode;

// Creates a new node
tNode* newNode(int val) 
{
    tNode* node = (tNode*)malloc(sizeof(tNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

tNode* prev = NULL;

// Recursive function to flatten the tree
void flatten(tNode* root) 
{
    if (!root) return;

    flatten(root->right);

    flatten(root->left);

    root->right = prev;
    root->left = NULL;

    prev = root;
}

// Prints flattened list
void printFlattened(tNode* root) 
{
    while (root) 
    {
        printf("%i ", root->val);
        root = root->right;
    }
    printf("\n");
}

int main() 
{
    tNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    flatten(root);

    printf("Flattened tree to linked list:\n");
    printFlattened(root);

    return 0;
}
