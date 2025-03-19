#!/usr/bin/env python3
"""The module for Recover Binary Search Tree"""


class Node:
    """Definition for a tree node"""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self):
        self.first = None
        self.second = None
        self.prev = Node(float('-inf'))

    def inorder(self, root):
        """Inorder traversal to find the swapped nodes"""
        if not root:
            return

        self.inorder(root.left)

        if self.prev.val > root.val:
            if not self.first:
                self.first = self.prev
            self.second = root

        self.prev = root
        self.inorder(root.right)

    def recoverBST(self, root):
        """Recover BST by swapping misplaced nodes"""
        self.inorder(root)
        if self.first and self.second:
            self.first.val, self.second.val = self.second.val, self.first.val


def printInorder(root):
    """Helper function to print inorder traversal"""
    if not root:
        return
    printInorder(root.left)
    print(root.val, end=" ")
    printInorder(root.right)


root = Node(3)
root.left = Node(1)
root.right = Node(4)
root.right.left = Node(2)

print("Before recovery:", end=" ")
printInorder(root)
print()

solve = Solution()
solve.recoverBST(root)

print("After recovery:", end=" ")
printInorder(root)
print()
