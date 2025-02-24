#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

/**
 * isBSTHelper - Helper function to check if a tree is a BST
 * @node: The current node
 * @minVal: The minimum value
 * @maxVal: The maximum value
 * Return: If current node's val is < the minVal or > the maxVal, returns false
 */
int isBSTHelper(struct Node* node, int minVal, int maxVal) 
{
    if (node == NULL)
        return 1;

    if (node->val <= minVal || node->val >= maxVal)
        return 0;

    return isBSTHelper(node->left, minVal, node->val) &&
           isBSTHelper(node->right, node->val, maxVal);
}

/**
 * isBST - Main function to check if a tree is a BST
 * @root: The root of binary tree
 * Return: If tree is a BST true else, false
 */
int isBST(struct Node* root) 
{
    return isBSTHelper(root, INT_MIN, INT_MAX);
}

int main() 
{
    struct Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);

    if (isBST(root))
        printf("The tree is a BST.\n");
    else
        printf("The tree is NOT a BST.\n");

    return 0;
}
