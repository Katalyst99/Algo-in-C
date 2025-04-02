#!/usr/bin/env python3
"""
The module for Constructing a Binary Tree from Preorder and Inorder Traversal
"""
from typing import List, Optional


class Node:
    """Definition for a binary tree node."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    """The class for the algorithm's implementation"""
    def buildTree(self, preord: List[int], inord: List[int]) -> Optional[Node]:
        """Recursive function to build the tree"""
        if not preord or not inord:
            return None

        rootValue = preord.pop(0)
        root = Node(rootValue)

        rootIdx = inord.index(rootValue)

        root.left = self.buildTree(preord, inord[:rootIdx])
        root.right = self.buildTree(preord, inord[rootIdx+1:])

        return root


def printInorder(root: Optional[Node]):
    if root is None:
        return
    printInorder(root.left)
    print(root.val, end=" ")
    printInorder(root.right)


preord = [3, 9, 20, 15, 7]
inord = [9, 3, 15, 20, 7]

solution = Solution()
treeRoot = solution.buildTree(preord, inord)

print("Inorder traversal of the constructed tree:")
printInorder(treeRoot)
print('\n')
