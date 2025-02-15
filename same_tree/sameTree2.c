#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/**
 * createNode - Function to create a new tree node
 * @val: The value
 * Return: The created node
 */
TreeNode* createNode(int val) 
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/**
 * sameTree - Function to check if two trees are the same
 * @p: The first binary tree
 * @q: The second binary tree
 * Return: 1, if binary trees are the same else 0.
 */
int sameTree(TreeNode* p, TreeNode* q) 
{
    if (p == NULL && q == NULL)
        return 1;
    
    if (p == NULL || q == NULL)
        return 0;
    
    if (p->val != q->val)
        return 0;
    
    return sameTree(p->left, q->left) && sameTree(p->right, q->right);
}

int main() 
{
    TreeNode* p = createNode(1);
    p->left = createNode(2);
    p->right = createNode(3);

    TreeNode* q = createNode(1);
    q->left = createNode(2);
    q->right = createNode(3);

    if (sameTree(p, q))
        printf("The trees are the same.\n");
    else
        printf("The trees are not the same.\n");

    return 0;
}
