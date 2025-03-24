#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

// Queue Node
typedef struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
} QueueNode;

// Queue Structure
typedef struct {
    QueueNode *front, *back;
} Queue;

// Function to create a queue
Queue* createQueue() 
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->back = NULL;
    return q;
}

// Enqueues a tree node
void enqueue(Queue* q, struct Node* node) 
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if (!q->back) 
    {
        q->front = q->back = newNode;
    } else 
    {
        q->back->next = newNode;
        q->back = newNode;
    }
}

// Dequeues a tree node
struct Node* dequeue(Queue* q) 
{
    if (!q->front) return NULL;

    QueueNode* tmp = q->front;
    struct Node* node = tmp->treeNode;
    q->front = q->front->next;

    if (!q->front) q->back = NULL;
    free(tmp);
    return node;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue* q) 
{
    return q->front == NULL;
}

/**
 * levelOrderTraversal - Function to perform level order traversal
 * @root: The root
 */
void levelOrderTraversal(struct Node* root) 
{
    if (!root) return;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) 
    {
        int level = 0;
        QueueNode* tmp = q->front;
        
        while (tmp) 
	{
            level++;
            tmp = tmp->next;
        }

        for (int i = 0; i < level; i++) 
	{
            struct Node* node = dequeue(q);
            printf("%i ", node->val);

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        printf("\n");
    }
    free(q);
}

struct Node* newNode(int val) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() 
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    printf("Level Order Traversal:\n");
    levelOrderTraversal(root);

    return 0;
}
