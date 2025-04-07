#!/usr/bin/env python3
"""
The module for Flatten Binary Tree to Linked List.
"""


class Node:
    """Definition for a binary tree node."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    """The class for the algorithm's implementation"""
    def __init__(self):
        self.prev = None

    def flatBT(self, root: Node) -> None:
        """Do not return anything, modify root in-place instead."""
        if not root:
            return

        self.flatBT(root.right)
        self.flatBT(root.left)

        root.right = self.prev
        root.left = None
        self.prev = root


def printFlattened(root):
    while root:
        print(root.val, end=" -> ")
        root = root.right
    print('None')


root = Node(1)
root.left = Node(2, Node(3), Node(4))
root.right = Node(5, None, Node(6))

Solution().flatBT(root)

printFlattened(root)
