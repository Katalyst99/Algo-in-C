#include <stdio.h>
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
 * leftView - Function to print the left view of a binary tree
 * @root: The root of binary tree
 */
void leftView(struct Node* root) 
{
    if (root == NULL)
        return;

    struct Node* queue[100];
    int front = 0, end = 0;
    queue[end++] = root;

    while (front < end) 
    {
        int levelSize = end - front;

        for (int i = 0; i < levelSize; i++) 
	{
            struct Node* current = queue[front++];

            if (i == 0)
                printf("%i ", current->val);

            if (current->left)
                queue[end++] = current->left;
            if (current->right)
                queue[end++] = current->right;
        }
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
    root->left->left->left = newNode(7);

    printf("Left View of the Binary Tree: ");
    leftView(root);
    printf("\n");

    return 0;
}
