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
    def helperBST(node, minVal, maxVal):
        """Recursive helper function"""
        if not node:
            return True

        if not (minVal < node.val < maxVal):
            return False

        return (helperBST(node.left, minVal, node.val) and
                helperBST(node.right, node.val, maxVal))

    return helperBST(root, float('-inf'), float('inf'))


root = Node(10, Node(5), Node(15, Node(6), Node(20)))
print(isValidBST(root))
