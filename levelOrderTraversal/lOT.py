#!/usr/bin/env python3
"""The module for Binary Tree Level Order Traversal"""
from collections import deque


class Node:
    """Definition for a tree node"""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def levelOrder(root):
    """Function to perform level order traversal"""
    if not root:
        return []

    output = []
    q = deque([root])

    while q:
        level = len(q)
        levelNodes = []

        for _ in range(level):
            node = q.popleft()
            levelNodes.append(node.val)

            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

        output.append(levelNodes)

    return output


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.right = Node(6)

print(levelOrder(root))
