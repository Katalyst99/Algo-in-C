#!/usr/bin/env python3
"""The module for Recover Binary Search Tree"""


class Node:
    """Definition for a tree node"""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def recoverBST(self, root):
        """Recover BST using Morris Traversal"""
        first = second = prev = None
        current = root

        while current:
            if current.left:
                pred = current.left
                while pred.right and pred.right != current:
                    pred = pred.right

                if not pred.right:
                    pred.right = current
                    current = current.left
                else:
                    pred.right = None

                    if prev and prev.val > current.val:
                        if not first:
                            first = prev
                        second = current

                    prev = current
                    current = current.right
            else:
                if prev and prev.val > current.val:
                    if not first:
                        first = prev
                    second = current

                prev = current
                current = current.right

        if first and second:
            first.val, second.val = second.val, first.val


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
