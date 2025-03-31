#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Prints zigzag level order traversal
void zigzagLevelOrder(struct Node* root) 
{
    if (!root) return;

    struct Node* stack1[MAX_NODES], *stack2[MAX_NODES];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0 || top2 >= 0) 
    {
        while (top1 >= 0) 
	{
            struct Node* node = stack1[top1--];
            printf("%i ", node->val);
            if (node->left) stack2[++top2] = node->left;
            if (node->right) stack2[++top2] = node->right;
        }
        printf("\n");

        while (top2 >= 0) 
	{
            struct Node* node = stack2[top2--];
            printf("%i ", node->val);
            if (node->right) stack1[++top1] = node->right;
            if (node->left) stack1[++top1] = node->left;
        }
        printf("\n");
    }
}

int main() 
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    zigzagLevelOrder(root);
    return 0;
}
