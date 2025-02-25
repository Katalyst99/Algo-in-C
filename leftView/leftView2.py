#!/usr/bin/env python3
"""The module for Left View of Binary Tree"""
from collections import deque


class Node:
    """Definition for a binary tree node"""
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def leftView(root):
    """Function to print the left view of a binary tree"""
    if not root:
        return []

    queue = deque([root])
    output = []

    while queue:
        levelSize = len(queue)

        for i in range(levelSize):
            node = queue.popleft()

            if i == 0:
                output.append(node.val)

            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

    return output


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.right = Node(6)
    root.left.left.left = Node(7)

    print("Left View of the Binary Tree:", leftView(root))
