#!/usr/bin/env python3
"""The module for Binary Tree Zigzag Level Order Traversal"""
from collections import deque


class tNode:
    """Definition for a binary tree node."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def zigzagLevelOrder(root):
    """
    Performs a level order traversal of the binary tree while alternating,
    between adding nodes from left to right and right to left at each level.
    """
    if not root:
        return []

    output = []
    q = deque([root])
    L2R = True

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

        if not L2R:
            levelNodes.reverse()

        output.append(levelNodes)
        L2R = not L2R

    return output


root = tNode(1)
root.left = tNode(2)
root.right = tNode(3)
root.left.left = tNode(4)
root.left.right = tNode(5)
root.right.right = tNode(6)

print(zigzagLevelOrder(root))
