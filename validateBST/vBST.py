#!/usr/bin/env python3
"""The module for Validate Binary Search Tree"""


class Node:
    """Definition for a node"""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def isValidBST(root):
    """Determines a valid binary search tree"""
    prev = None

    def inorder(node):
        """Helper function for inorder traversal"""
        nonlocal prev
        if not node:
            return True

        if not inorder(node.left):
            return False

        if prev is not None and node.val <= prev:
            return False

        prev = node.val

        return inorder(node.right)

    return inorder(root)


root = Node(10, Node(5), Node(15, Node(6), Node(20)))
print(isValidBST(root))
