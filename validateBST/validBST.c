#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Definition for a binary tree node
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

// Helper function to validate BST using range checking
bool isValidBSTHelper(struct Node* node, long min, long max) 
{
    if (!node) return true;

    if (node->val <= min || node->val >= max)
        return false;

    return isValidBSTHelper(node->left, min, node->val) &&
           isValidBSTHelper(node->right, node->val, max);
}

/**
 * isValidBST - function to check if a tree is a BST
 * @root: The root
 * Return: True, else False
 */
bool isValidBST(struct Node* root) 
{
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

// Function to create a new tree node
struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() 
{
    struct Node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->right->left = newNode(6);
    root->right->right = newNode(20);

    if (isValidBST(root))
        printf("The tree is a valid BST\n");
    else
        printf("The tree is NOT a valid BST\n");

    return 0;
}
