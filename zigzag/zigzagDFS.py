#!/usr/bin/env python3
"""The module for Binary Tree Zigzag Level Order Traversal"""
from collections import deque


class tNode:
    """Definition for a binary tree node."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def zigzagDFS(root):
    """
    Performs a level order traversal of the binary tree while alternating,
    between adding nodes from left to right and right to left at each level.
    """
    output = []

    def dfs(tNode, level):
        """recursively traverses the tree"""
        if not tNode:
            return

        if len(output) == level:
            output.append([])

        if level % 2 == 0:
            output[level].append(tNode.val)
        else:
            output[level].insert(0, tNode.val)

        dfs(tNode.left, level + 1)
        dfs(tNode.right, level + 1)

    dfs(root, 0)
    return output


root = tNode(1)
root.left = tNode(2)
root.right = tNode(3)
root.left.left = tNode(4)
root.left.right = tNode(5)
root.right.right = tNode(6)
print(zigzagDFS(root))
