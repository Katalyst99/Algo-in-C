#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};


struct Queue {
    struct Node* node;
    struct Queue* next;
};

// Function to create a new tree node
struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Enqueues a node into the queue
void enqueue(struct Queue** front, struct Queue** back, struct Node* node) 
{
    struct Queue* tmp = (struct Queue*)malloc(sizeof(struct Queue));
    tmp->node = node;
    tmp->next = NULL;
    
    if (*back) 
    {
        (*back)->next = tmp;
    }
    *back = tmp;
    if (*front == NULL) 
    {
        *front = *back;
    }
}

// Dequeues a node from the queue
struct Node* dequeue(struct Queue** front, struct Queue** back) 
{
    if (*front == NULL) return NULL;
    
    struct Node* node = (*front)->node;
    struct Queue* tmp = *front;
    *front = (*front)->next;
    
    if (*front == NULL) 
    {
        *back = NULL;
    }
    
    free(tmp);
    return node;
}

// Function to check if the queue is empty
bool isQueueEmpty(struct Queue* front) 
{
    return front == NULL;
}

// Prints zigzag level order traversal
void zigzagLevelOrder(struct Node* root) 
{
    if (!root) return;

    struct Queue* front = NULL;
    struct Queue* back = NULL;

    enqueue(&front, &back, root);
    bool LToR = true;

    while (!isQueueEmpty(front)) 
    {
        int level = 0;
        struct Queue* tmp = front;
        while (tmp) 
	{
            level++;
            tmp = tmp->next;
        }

        int* levelNodes = (int*)malloc(level * sizeof(int));
        struct Node* nodes[level];

        for (int i = 0; i < level; i++) 
	{
            struct Node* node = dequeue(&front, &back);
            nodes[i] = node;
            levelNodes[i] = node->val;

            if (node->left) enqueue(&front, &back, node->left);
            if (node->right) enqueue(&front, &back, node->right);
        }

        if (LToR) 
	{
            for (int i = 0; i < level; i++) 
	    {
                printf("%i ", levelNodes[i]);
            }
        } else {
            for (int i = level - 1; i >= 0; i--) 
	    {
                printf("%d ", levelNodes[i]);
            }
        }
        printf("\n");

        LToR = !LToR;
        free(levelNodes);
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

    printf("Zigzag Level Order Traversal:\n");
    zigzagLevelOrder(root);

    return 0;
}
