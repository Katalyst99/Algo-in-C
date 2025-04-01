#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

// Creates a new tree node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find index of a value in inorder array
int search(int arr[], int start, int end, int value) 
{
    for (int i = start; i <= end; i++) 
    {
        if (arr[i] == value) return i;
    }
    return -1;
}

// Recursive function to build the tree
struct Node* buildTreeHelper(int preorder[], int inorder[], int Begin, int End, int* preIdx) 
{
    if (Begin > End) return NULL;

    int rootVal = preorder[*preIdx];
    (*preIdx)++;

    struct Node* root = newNode(rootVal);

    int rootIdx = search(inorder, Begin, End, rootVal);

    root->left = buildTreeHelper(preorder, inorder, Begin, rootIdx - 1, preIdx);
    root->right = buildTreeHelper(preorder, inorder, rootIdx + 1, End, preIdx);

    return root;
}


struct Node* buildTree(int preorder[], int inorder[], int size) 
{
    int preIdx = 0;
    return buildTreeHelper(preorder, inorder, 0, size - 1, &preIdx);
}

void printInorder(struct Node* root) 
{
    if (root == NULL) return;
    printInorder(root->left);
    printf("%i ", root->val);
    printInorder(root->right);
}

int main() 
{
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int size = sizeof(preorder) / sizeof(preorder[0]);

    struct Node* root = buildTree(preorder, inorder, size);

    printf("Inorder traversal of constructed tree:\n");
    printInorder(root);
    printf("\n");
    return 0;
}
