#!/usr/bin/env python3
"""The module for Check for BST"""


class Node:
    """The class Node defined"""
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def bstHelper(node, minVal, maxVal):
    """Helper function for isBST"""
    if node is None:
        return True

    if not (minVal < node.val < maxVal):
        return False

    return (bstHelper(node.left, minVal, node.val) and
            bstHelper(node.right, node.val, maxVal))


def isBST(root):
    """
    Takes the root of a binary tree as input,
    and returns true if the given binary tree is BST, else returns false.
    """
    return bstHelper(root, float('-inf'), float('inf'))


root = Node(8)
root.left = Node(3)
root.right = Node(10)
root.left.left = Node(1)
root.left.right = Node(6)
root.right.right = Node(14)

print(isBST(root))
